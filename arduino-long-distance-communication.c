/*
 * Course: Arduino Long Distance Communication
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Long Distance Communication" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-long-distance-communication/
 * Repository: https://github.com/engasm89/arduino-long-distance-communication
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

// Simulate long-distance framed communication with retries and ACKs
#include <stdio.h> // Logs
#include <string.h> // Frame building

static int send_frame(const char* data) { // Send frame
  printf("TX: [%s]\n", data); // Log TX
  int ack = (strlen(data) % 2 == 0); // Simulate ACK for even length
  printf("RX: ACK=%d\n", ack); // Log ACK
  return ack; // Return ACK flag
}

int main(void) { // Program entry point
  printf("Arduino Long Distance Communication\n"); // Title
  const char* frames[] = {"HELLO","STATUS","PAYLOAD123","PING"}; // Frames
  for (int i = 0; i < 4; ++i) { // Iterate frames
    int ok = send_frame(frames[i]); // Send
    if (!ok) { // On failure
      printf("Retrying...\n"); // Retry log
      send_frame(frames[i]); // Retry once
    } // End failure handling
  } // End loop
  return 0; // Exit
} // End of main function
