const int outputPin = 2;

byte data[] = {0x55, 0xAA, 0xFF};

enum Encoding { NRZ_L, NRZI };

void encodeNRZL(byte* data, int length) {
  for (int i = 0; i < length; i++) {
    for (int bit = 7; bit >= 0; bit--) {
      bool bitVal = (data[i] >> bit) & 0x01;
      bitval = !bitval;
      digitalWrite(outputPin, bitVal); // High for 0, Low for 1
      delay(1); // Adjust timing for baud rate
    }
  }
}

void encodeNRZI(byte* data, int length) {
  bool lastBit = false;
  for (int i = 0; i < length; i++) {
    for (int bit = 7; bit >= 0; bit--) {
      bool bitVal = (data[i] >> bit) & 0x01;
      if (bitVal) {
        lastBit = !lastBit;
      }
      digitalWrite(outputPin, lastBit); // High for 1, Low for 0
      delay(1); // Adjust timing for baud rate
    }
  }
}

void setup() {
    pinMode(outputPin, OUTPUT);
    Serial.begin(9600);

    Serial.println("NRZL Encoding data...");
    encodeNRZL(data, sizeof(data));
    Serial.println("Data encoded");

    Serial.println("NRZI Encoding data...");
    encodeNRZI(data, sizeof(data));
    Serial.println("Data encoded");
}

void loop() {
    // Nothing to do here
}
