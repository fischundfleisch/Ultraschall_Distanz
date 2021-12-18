const int TRIGGER = 7;
const int ECHO = 6;
const unsigned long SCAN_FREQ = 10UL*1000UL;

unsigned long scan_timer_ =0;

void setup() {
Serial.begin(9600);
pinMode(TRIGGER, OUTPUT);
pinMode(ECHO, INPUT);
}

void loop() {
  unsigned long act_time = millis();
  unsigned long time_span = act_time - scan_timer_;
  long dauer = 0;
  long entfernung = 0;

  if (time_span > SCAN_FREQ) {
    digitalWrite(TRIGGER, LOW);
    delay(5);
    digitalWrite(TRIGGER, HIGH);
    delay(10);
    digitalWrite(TRIGGER, LOW);
    dauer = pulseIn(ECHO, HIGH);
    entfernung = (dauer/2) *0.03432; // oder: entfernung = (dauer/2)L * 0.03432L?
    Serial.print("Entfernung: ");
    Serial.print(entfernung);
    Serial.println(" cm);
  }

}
