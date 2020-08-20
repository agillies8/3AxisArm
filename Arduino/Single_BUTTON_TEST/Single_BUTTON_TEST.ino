#include <ros.h>
#include <std_msgs/String.h>

#define BUTTON 8

ros::NodeHandle node_handle;

std_msgs::String button_msg;

ros::Publisher button_publisher("button_press", &button_msg);

void setup()
{
  pinMode(BUTTON, INPUT);
  
  node_handle.initNode();
  node_handle.advertise(button_publisher);
}

void loop()
{ 
  if (digitalRead(BUTTON) == HIGH) {
    button_msg.data = "IM PRESSING THE BUTTON!!!!";
  } else {
    button_msg.data = "NOT pressed";
  }

  button_publisher.publish( &button_msg );
  node_handle.spinOnce();
  
  delay(100);
}
