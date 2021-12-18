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
  long duration = 0;
  long distance = 0;

  if (time_span > SCAN_FREQ) {
    digitalWrite(TRIGGER, LOW);
    delay(5);
    digitalWrite(TRIGGER, HIGH);
    delay(10);
    digitalWrite(TRIGGER, LOW);
    duration = pulseIn(ECHO, HIGH);
    Serial.println(duration);
    distance = ((duration/2.) *0.03432)+0.5; // +0.5 zum Runden
    Serial.print("Entfernung: ");
    Serial.print(entfernung);
    Serial.println(" cm");
  }

}
