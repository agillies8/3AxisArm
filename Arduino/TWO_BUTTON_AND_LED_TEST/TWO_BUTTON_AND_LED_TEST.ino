#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16MultiArray.h>

#define BUTTON1 8
#define BUTTON2 9
#define LED1 12
#define LED2 13

ros::NodeHandle node_handle;

std_msgs::String button_msg_1;
std_msgs::String button_msg_2;
std_msgs::Int16MultiArray axisCommands;

void subscriberCallback(const std_msgs::Int16MultiArray& axisCommands) {
  if (axisCommands.data[0]  == 1) {
    digitalWrite(LED1, HIGH); 
  } else {
    digitalWrite(LED1, LOW);
  }
  if (axisCommands.data[1]  == 1) {
    digitalWrite(LED2, HIGH); 
  } else {
    digitalWrite(LED2, LOW);
  }
  
}



ros::Publisher button_publisher_1("button_press_1", &button_msg_1);
ros::Publisher button_publisher_2("button_press_2", &button_msg_2);

ros::Subscriber<std_msgs::Int16MultiArray> led_subscriber("axis_commands", &subscriberCallback);


void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);


  node_handle.initNode();
  node_handle.advertise(button_publisher_1);
  node_handle.advertise(button_publisher_2);
  node_handle.subscribe(led_subscriber);

}

void loop()
{ 
  if (digitalRead(BUTTON1) == HIGH) {
    button_msg_1.data = "Pressed";
  } else {
    button_msg_1.data = "NOT pressed";
  }


    if (digitalRead(BUTTON2) == HIGH) {
    button_msg_2.data = "Pressed";
  } else {
    button_msg_2.data = "NOT pressed";
  }

  button_publisher_1.publish( &button_msg_1 );
  button_publisher_2.publish( &button_msg_2 );
  node_handle.spinOnce();
  
  delay(100);
}
