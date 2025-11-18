// Simulate long-distance framed communication with retries and ACKs
#include <stdio.h> // Logs
#include <string.h> // Frame building

static int send_frame(const char* data) { // Send frame
  printf("TX: [%s]\n", data); // Log TX
  int ack = (strlen(data) % 2 == 0); // Simulate ACK for even length
  printf("RX: ACK=%d\n", ack); // Log ACK
  return ack; // Return ACK flag
}

int main(void) { // Entry
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
} // End main
