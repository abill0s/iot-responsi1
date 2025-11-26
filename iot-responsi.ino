int pirPin = 2;
int ldrPin = A0;

int threshold = 500;  // batas gelap/terang

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int pirState = digitalRead(pirPin);

  bool gelap = ldrValue < threshold;
  bool gerakan = pirState == HIGH;

  Serial.print("Cahaya: ");
  Serial.print(ldrValue);
  
  Serial.print(" | Gelap: ");
  Serial.print(gelap ? "Ya" : "Tidak");

  Serial.print(" | Gerakan: ");
  Serial.print(gerakan ? "Ya" : "Tidak");

  // Logika jika ingin melakukan sesuatu
  if (gelap && gerakan) {
    Serial.print(" | Status: Deteksi GERAK dalam GELAP!");
  }

  Serial.println();
  delay(100);
}
