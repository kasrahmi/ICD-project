const int outputPin = 2;

byte data[] = {0x55, 0xAA, 0xFF};

enum Encoding { NRZ_L, NRZI };

void encodeNRZL(byte* data, int length) {
  for (int i = 0; i < length; i++) {
    for (int bit = 7; bit >= 0; bit--) {
      bool bitVal = (data[i] >> bit) & 0x01;
      digitalWrite(outputPin, bitVal); // High for 1, Low for 0
      delay(1); // Adjust timing for baud rate
    }
  }
}

void setup() {
    pinMode(outputPin, OUTPUT);
    Serial.begin(9600);

    Serial.println("Encoding data...");
    encodeNRZL(data, sizeof(data));
    Serial.println("Data encoded");
}

void loop() {
    // Nothing to do here
}