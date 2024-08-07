#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t kRecvPin = D2;  // GPIO pin connected to the IR receiver module

IRrecv irrecv(kRecvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received IR code
    Serial.println(results.value, HEX);

    irrecv.resume();  // Receive the next value
  }
}
