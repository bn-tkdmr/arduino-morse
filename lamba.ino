const char* morsAlfabesi[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

char alfabe[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char message[] = "bb";

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  char* p = message;
  while (*p != '\0') {
    readLetter(*p);
    delay(2000);
    p++;
  }
  delay(5000);
}

void readLetter(char c) {
  c = toupper(c);
  for (int i = 0; i < 26; i++) {
    if (alfabe[i] == c) {
      const char* karakter = morsAlfabesi[i];
      for (int j = 0; karakter[j] != '\0'; j++) {
        switch (karakter[j]) {
          case '.':
            digitalWrite(13, HIGH);
            delay(500);
            digitalWrite(13, LOW);
            delay(500);
            break;
          case '-':
            digitalWrite(13, HIGH);
            delay(1000);
            digitalWrite(13, LOW);
            delay(500);
            break;
        }
      }
      break;
    }
  }
}
