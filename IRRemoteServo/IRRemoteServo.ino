#include <IRremote.h>
#include <Servo.h> 

Servo myservo;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    String s = String(results.value, HEX); 
    if(s != "ffffffff"){
      Serial.println(s);
    }
    
    if(s == "ff22dd"){
      myservo.write(2370);  // set servo counter clockwise
    }
    else if(s == "ffc23d"){
      myservo.write(570);  // set servo clockwise
    }
    else if(s == "ff02fd"){
      myservo.write(1420);  // set servo to mid-point 
    }
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
