#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <termios.h>
#include <unistd.h>

using namespace std::chrono_literals;

namespace destroyer_robot
{

class DestroyerDrive : public rclcpp::Node
{
public:
  DestroyerDrive()
  : Node("destroyer_drive")
  {
   publisher_=this->create_publisher<geometry_msgs::msg::Twist>("/destroyer_drive",10);
   tcgetattr(STDIN_FILENO, &original_terminal_);
   struct termios raw = original_terminal_;
   raw.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &raw);

  RCLCPP_INFO(this->get_logger(), "drive penghancur - pencet arrow untuk MENGHITAMKAN MUSUH");
  RCLCPP_INFO(this->get_logger(), "KELUAR DARI SINI! CTRL+C"); //TAMBAHAN BIAR DESTROYER PENGHITAM BAGUS
  }
~DestroyerDrive()

{//buat ngembaliin terminal saat ketika node mati
    tcsetattr(STDIN_FILENO, TCSANOW, &original_terminal_);
}

void run()//serang mas
{
  while (rclcpp::ok()){
   char c = getchar();
   geometry_msgs::msg::Twist msg;
   bool valid = true;

  if (c== '\x1b'){
    char c2 =getchar();
    char c3 =getchar();//pencet objek di keyboard
    if (c2 =='['){
     if (c3 == 'A'){
       msg.linear.x = 5.0;
     } else if (c3 =='B') {
       msg.linear.y = 5.0;
     } else if (c3 =='C') {
       msg.linear.y = 5.0;
     } else if (c3 =='D') {
       msg.linear.y = 5.0;
     } else {
       valid = false;
     }
   }
  } else if (c == 'R'||c == 'r') {
    msg.angular.z = -1.0;
  } else if (c == 'l'||c == 'L') {
    msg.angular.z = 1.0;
  } else if (c == 'b'||c == 'B') { //berhenti, bukan stop
    //kan berhenti jadi dikosongin
  } else {
    valid = false;
  }

  if (valid) {
     publisher_->publish(msg);
     RCLCPP_INFO(this->get_logger(),"didapat! linear.x=%.1f, linear.y=%.1f, angular.z=%.1f",msg.linear.x, msg.linear.y, msg.angular.z);
  }

  rclcpp::spin_some(this->get_node_base_interface());
  }
 }
private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  struct termios original_terminal_;
};
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<destroyer_robot::DestroyerDrive>();
  node ->run();
  rclcpp::shutdown();
  return 0;
}

