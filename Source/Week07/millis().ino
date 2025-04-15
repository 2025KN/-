void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long loopCnt = 0;
  static unsigned long nextMil = millis() + 1000;

  loopCnt++;

  if(millis() > nextMil) {
    nextMil = millis() +1000;
    Serial.println(loopCnt);
    loopCnt = 0;
  }
}
