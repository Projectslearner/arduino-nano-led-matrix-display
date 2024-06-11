/*
    Project name : LED Matrix Display
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-led-matrix-display
*/

// Define the number of rows and columns in the LED matrix
const int numRows = 8;
const int numCols = 8;

// Define the pins connected to the rows and columns of the LED matrix
int rowPins[numRows] = {2, 3, 4, 5, 6, 7, 8, 9};
int colPins[numCols] = {10, 11, 12, 13, A0, A1, A2, A3};

void setup() {
  // Set the row pins as outputs and the column pins as inputs
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], OUTPUT);
  }
}

void loop() {
  // Example: Display a pattern on the LED matrix
  int pattern[numRows][numCols] = {
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}
  };

  // Display the pattern on the LED matrix
  for (int col = 0; col < numCols; col++) {
    digitalWrite(colPins[col], HIGH);
    for (int row = 0; row < numRows; row++) {
      digitalWrite(rowPins[row], pattern[row][col]);
    }
    delay(1); // Adjust the delay as needed
    digitalWrite(colPins[col], LOW);
  }
}
