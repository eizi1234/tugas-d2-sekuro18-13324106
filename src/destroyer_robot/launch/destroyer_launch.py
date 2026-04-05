
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='destroyer_robot',
            executable='auto_mode_destroyer',
            name='destroyer_auto',
            output='screen'
        ),
        Node(
            package='destroyer_robot',
            executable='check_move_destroyer',
            name='destroyer_check',
            output='screen'
        ),
])

