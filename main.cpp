#include <Arduino.h>
const int ledX = 13;  // LED for output X (Pin 13)
const int ledY = 12;  // LED for output Y (Pin 12)

// Variables to store the states of X and Y
int X = 0;
int Y = 0;

// Function to toggle the state of a JK flip-flop
int JK_flipflop(int J, int K, int Q) {
  if (J == 0 && K == 0) return Q;  // No change
  if (J == 0 && K == 1) return 0;  // Reset
  if (J == 1 && K == 0) return 1;  // Set
  if (J == 1 && K == 1) return !Q; // Toggle
}

void setup() {
  // Set the LED pins as outputs
  pinMode(ledX, OUTPUT);
  pinMode(ledY, OUTPUT);

  // Initialize the LEDs
  digitalWrite(ledX, LOW);
  digitalWrite(ledY, LOW);
}

void loop() {
  // JK flip-flop logic for both X and Y
  X = JK_flipflop(1, 1, X);  // JK flip-flop for X with J=1, K=1 (toggles every iteration)
  Y = JK_flipflop(1, 1, Y);  // JK flip-flop for Y with J=1, K=1 (toggles every iteration)

  // Update the LEDs to represent the states of X and Y
  digitalWrite(ledX, X);
  digitalWrite(ledY, Y);
}

