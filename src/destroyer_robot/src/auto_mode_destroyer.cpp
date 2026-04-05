#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std::chrono_literals;

namespace destroyer_robot {
class DestroyerAuto : public rclcpp::Node
{
public:
  DestroyerAuto()
  : Node("destroyer_auto")
  {
    std::srand(std::time(nullptr));
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/autonomous_destroyer", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&DestroyerAuto::auto_destroyer, this));
    RCLCPP_INFO(this->get_logger(), "Auto Destroyer Mendeteksi Musuh, serang dia pukimak!");
  }

private:
  void auto_destroyer()
  {
    geometry_msgs::msg::Twist msg;
    int pilih = std::rand() % 6;
    if (pilih == 0) {
      msg.linear.x = 5.0;   // maju
    }
    else if (pilih == 1) {
      msg.linear.x = -5.0;  // mundur
    }
    else if (pilih == 2) {
      msg.linear.y = 5.0;   // kiri
    }
    else if (pilih == 3) {
      msg.linear.y = -5.0;  // kanan
    }
    else if (pilih == 4) {
      msg.angular.z = 1.0;  // putar kiri
    }
    else {
      msg.angular.z = -1.0; // putar kanan
    }
    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Gerakan dipilih: %d", pilih);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<destroyer_robot::DestroyerAuto>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
