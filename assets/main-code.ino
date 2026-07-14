
const int trigPin = 3;
const int echoPin = 4;   
const int buzzerPin = 1;  

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  
  // 3. Hitung jarak dalam centimeter (cm)
  int distance = duration * 0.034 / 2;
  
  if (distance > 0 && distance < 50) {
    digitalWrite(buzzerPin, HIGH); } 
  else if (distance >= 50 && distance <= 200) {
    int delayTime = map(distance, 50, 200, 50, 500); // memetakan jarak ke tempo delay
    digitalWrite(buzzerPin, HIGH);
    delay(50); 
    digitalWrite(buzzerPin, LOW);
    delay(delayTime);
  } 
  else {
    digitalWrite(buzzerPin, LOW);
  }
  
  delay(50);
}