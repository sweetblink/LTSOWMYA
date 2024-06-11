// Define pins for ultrasonic sensor
const int trigPin = 5; // Trigger pin of ultrasonic sensor
const int echoPin = 4; // Echo pin of ultrasonic sensor

// Define pin for LED
const int ledPin = 2; // Pin connected to LED

// Define variables
long duration; // Time taken for the ultrasonic pulse to return
int distance; // Distance measured by the ultrasonic sensor

void setup() {
  pinMode(trigPin, OUTPUT); // Set trigPin as an output
  pinMode(echoPin, INPUT); // Set echoPin as an input
  pinMode(ledPin, OUTPUT); // Set ledPin as an output
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  // Send a 10us pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // If an object is detected within 50cm, turn on the LED
  if (distance < 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(100); // Delay before the next measurement
}
