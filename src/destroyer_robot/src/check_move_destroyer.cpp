#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace destroyer_robot
{

class DestroyerCheck : public rclcpp::Node
{
  //TODO: Implementasi node check_move_destroyer
public:
  DestroyerCheck()
  : Node("destroyer_check"), last_drive_time_(this->now())
  { //kita subscribe
    drive_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("/drive_destroyer", 10, std::bind(&DestroyerCheck::drive_diterima, this, _1));
    auto_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("/autonomous_destroyer",10, std::bind(&DestroyerCheck::auto_diterima, this,_1));
    power_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/power_destroyer",10);
    type_pub_ = this->create_publisher<std_msgs::msg::String>("/move_type",10);
    RCLCPP_INFO(this->get_logger(),"Cek segera aktif untuk membantu kalian");
  }

private:
  void drive_diterima(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
   last_drive_time_ = this->now();
   power_pub_->publish(*msg);
   std_msgs::msg::String type_msg;
   type_msg.data ="Driver";
   type_pub_->publish(type_msg);
   RCLCPP_INFO(this->get_logger(), "Diterima drai driver: linear.x=%.2f, linear.y=%.2f, yaw=%.2f", msg->linear.x, msg->linear.y, msg->angular.z);
  }

  void auto_diterima(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
  //cek keyboard
  auto elapsed = (this->now() - last_drive_time_).seconds();
  if (elapsed < 1.0){ //tinggalin auto kalaw masi pk keyboard
  return;
  }
  power_pub_->publish(*msg);
  
  std_msgs::msg::String type_msg;
  type_msg.data ="Autonomous";
  type_pub_->publish(type_msg);
  RCLCPP_INFO(this->get_logger(),"diterima dari auto: linear.x=%.2f, linear.y=%.2f, yaw=%.2f", msg->linear.x, msg->linear.y, msg->angular.z);
 }

rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr drive_sub_;
rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr auto_sub_;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr power_pub_;
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr type_pub_; 
rclcpp::Time last_drive_time_;
};    
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<destroyer_robot::DestroyerCheck>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
