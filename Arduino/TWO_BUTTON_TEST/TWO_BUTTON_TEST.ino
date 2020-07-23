#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>

#define BUTTON1 8
#define BUTTON2 9


ros::NodeHandle node_handle;

std_msgs::String button_msg_1;
std_msgs::String button_msg_2;


ros::Publisher button_publisher_1("button_press_1", &button_msg_1);
ros::Publisher button_publisher_2("button_press_2", &button_msg_2);


void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  
  node_handle.initNode();
  node_handle.advertise(button_publisher_1);
  node_handle.advertise(button_publisher_2);

}

void loop()
{ 
  if (digitalRead(BUTTON1) == HIGH) {
    button_msg_1.data = "Pressed";
  } else {
    button_msg_1.data = "NOT pressed";
  }

  button_publisher_1.publish( &button_msg_1 );
  node_handle.spinOnce();

    if (digitalRead(BUTTON2) == HIGH) {
    button_msg_2.data = "Pressed";
  } else {
    button_msg_2.data = "NOT pressed";
  }

  button_publisher_2.publish( &button_msg_2 );
  node_handle.spinOnce();
  
  delay(100);
}
