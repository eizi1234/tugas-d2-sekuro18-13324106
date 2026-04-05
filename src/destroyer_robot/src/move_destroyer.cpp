#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/string.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace destroyer_robot
{

class DestroyerMove : public rclcpp::Node
{
public:
  DestroyerMove()
  : Node("destroyer_move")
  {
   twist_sub_ = this->create_subscription<geometry_msgs::msg::Twist>("/power_destroyer", 10, std::bind(&DestroyerMove::twist_diterima, this, _1));
   mode_sub_ = this->create_subscription<std_msgs::msg::String>("/move_type", 10, std::bind(&DestroyerMove::mode_diterima,this,_1));
  RCLCPP_INFO (this->get_logger(),"sang penghitaman massal aktif");
  }

private:
  void twist_diterima(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
   std::string orientasi ="";
   if (msg->linear.x > 0) orientasi += "Maju ";
   if (msg->linear.x < 0) orientasi += "Mundur ";
   if (msg->linear.y > 0) orientasi += "Geser Kiri ";
   if (msg->linear.y < 0) orientasi += "Geser Kanan ";
   if (msg->angular.z > 0) orientasi += "putar ke Kiri ";
   if (msg->angular.z < 0) orientasi += "putar Kanan yes ";

   if (orientasi.empty()) orientasi ="Berhenti, jgn lanjut";
   RCLCPP_INFO (this->get_logger(), "Arah Gerak: %s", orientasi.c_str());
//tambah omni-directional. Berarti kita tinggal tambah FL BR dll, kemudian hitung matriks2nya, tapi gapake matriks
   //hotung invers dan omni
   double vx = msg->linear.x;
   double vy = msg->linear.y;
   double vz = msg->angular.z;
//berdasarkan foto ppt day2
   double BL = vx + vy - vz;//karna ini matriks, jadi ada +-
   double BR = vx - vy - vz;
   double FL = vx - vy - vz;
   double FR = vx + vy + vz;
   RCLCPP_INFO (this->get_logger(), "Arah Putaran ~ FL: %.2f | BL: %.2f | BR: %.2f | FR: %.2f", FL, BL, BR, FR);
  }
  void mode_diterima(const std_msgs::msg::String::SharedPtr msg)
  {
   RCLCPP_INFO(this->get_logger(), "si otak jawa aktif: %s", msg->data.c_str());
  }
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twist_sub_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr mode_sub_;
};

}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv); auto node = 
  std::make_shared<destroyer_robot::DestroyerMove>(); 
  rclcpp::spin(node); rclcpp::shutdown(); return 0;
}
