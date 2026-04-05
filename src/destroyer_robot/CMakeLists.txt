cmake_minimum_required(VERSION 3.8)
project(destroyer_robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

Set(DEPS rclcpp geometry_msgs std_msgs)

add_executable(auto_mode_destroyer src/auto_mode_destroyer.cpp)
ament_target_dependencies(auto_mode_destroyer ${DEPS})
add_executable(drive_mode_destroyer src/drive_mode_destroyer.cpp)
ament_target_dependencies(drive_mode_destroyer ${DEPS})
add_executable(check_move_destroyer src/check_move_destroyer.cpp)
ament_target_dependencies(check_move_destroyer ${DEPS})
add_executable(move_destroyer src/move_destroyer.cpp)
ament_target_dependencies(move_destroyer ${DEPS})

install (TARGETS
   auto_mode_destroyer
   drive_mode_destroyer
   check_move_destroyer
   move_destroyer
   DESTINATION lib/${PROJECT_NAME}
)

install (DIRECTORY launch
   DESTINATION share/${PROJECT_NAME}
)

ament_package()
