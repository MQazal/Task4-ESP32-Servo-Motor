#include <ESP32Servo.h>

// SERVO
#define SPWM 2
int pos = 0; // Variable where the arm's position will be stored (in degrees)
Servo servo;

//BUTTONS
#define Button1 13 // Green Button ==> D13 pin
#define Button2 4 // Blue Button ==> D4 pin
#define Button3 12 // Black Button ==> D12 pin
#define Button4 14 // Yellow Button ==> D14 pin
#define Button5 19 // Gray Button ==> D19 pin
#define Button6 21 // Red Button ==> D21 pin
#define Button7 35 // White Button ==> D35 pin

bool button1_last_state = HIGH;
bool button2_last_state = HIGH;
bool button3_last_state = HIGH;
bool button4_last_state = HIGH;
bool button5_last_state = HIGH;
bool button6_last_state = HIGH;
bool button7_last_state = HIGH;

void moveServoToPosition(int newPos) {
  pos = newPos;
  servo.write(pos);
  Serial.print("Position: ");
  Serial.println(pos);
  delay(300); // Debounce delay
}

void setup()
{
  Serial.begin(9600);

  // Initialize buttons with internal pullup resistors
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);
  pinMode(Button5, INPUT_PULLUP);
  pinMode(Button6, INPUT_PULLUP);
  pinMode(Button7, INPUT_PULLUP);

  // Attach the servo to the PWM pin
  servo.attach(SPWM);
  servo.write(pos); // Initialize the servo position to 0 (leftmost)
}

void loop() {
  bool button1_current_state = digitalRead(Button1);
  bool button2_current_state = digitalRead(Button2);
  bool button3_current_state = digitalRead(Button3);
  bool button4_current_state = digitalRead(Button4);
  bool button5_current_state = digitalRead(Button5);
  bool button6_current_state = digitalRead(Button6);
  bool button7_current_state = digitalRead(Button7);

  if (button1_last_state == HIGH && button1_current_state == LOW) {
    moveServoToPosition(30);
  }

  if (button2_last_state == HIGH && button2_current_state == LOW) {
    moveServoToPosition(60);
  }

  if (button3_last_state == HIGH && button3_current_state == LOW) {
    moveServoToPosition(90);
  }

  if (button4_last_state == HIGH && button4_current_state == LOW) {
    moveServoToPosition(120);
  }

  if (button5_last_state == HIGH && button5_current_state == LOW) {
    moveServoToPosition(150);
  }

  if (button6_last_state == HIGH && button6_current_state == LOW) {
    moveServoToPosition(180);
  }

  if (button7_last_state == HIGH && button7_current_state == LOW) {
    moveServoToPosition(0);
  }

  button1_last_state = button1_current_state;
  button2_last_state = button2_current_state;
  button3_last_state = button3_current_state;
  button4_last_state = button4_current_state;
  button5_last_state = button5_current_state;
  button6_last_state = button6_current_state;
  button7_last_state = button7_current_state;
}
