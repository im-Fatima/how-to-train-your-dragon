#include <PS4Controller.h>

// Input values
float throttle = 0;
float yaw = 0;
float pitch = 0;
float roll = 0;

void setup() {
  Serial.begin(115200);
  // Replace with your PS4 controller's MAC address (optional)
  PS4.begin();  // Just PS4.begin() if already paired
  Serial.println("PS4 Controller Started");
}

void loop() {
  if (PS4.isConnected()) {
    // Map joystick values
    // Throttle: right trigger (R2) from 0 to 255
    throttle = PS4.RStickY();

    // Yaw: right stick horizontal
    yaw = PS4.RStickX();

    // Pitch: left stick vertical
    pitch = PS4.LStickY();

    // Roll: left stick horizontal
    roll = PS4.LStickX();

    // Print values
    Serial.print("Throttle: "); Serial.print(throttle);
    Serial.print(" | Yaw: "); Serial.print(yaw);
    Serial.print(" | Pitch: "); Serial.print(pitch);
    Serial.print(" | Roll: "); Serial.println(roll);

    delay(100);  // Avoid flooding Serial
  }
}
