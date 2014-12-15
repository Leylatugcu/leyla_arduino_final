
const int ledPin = 12;
String message;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Initializing!");
}

void loop(){
  while(Serial.available()){
    char c= Serial.read();
    if(c!= ','){
      message+= c;
    } else {
      processMessage(message);
      message= "";
    }    
  }
  delay(500);
}

void processMessage(String const &message){
  if(message.length()){
    int number= message.toInt();
    Serial.println("integer: "+ String(number));
    light(number);
  }
}

void light(int n){
  for (int i = 0; i < n; i++)  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
