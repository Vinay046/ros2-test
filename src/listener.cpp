#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void chatterCallback(const std_msgs::msg::String::SharedPtr msg) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I heard: '%s'", msg->data.c_str());
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("listener");
    auto subscription = node->create_subscription<std_msgs::msg::String>("chatter", 10, chatterCallback);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
