// to blink the LED

byte ledPin = 2;

void InitiateLED (){
    pinMode(ledPin,OUTPUT);
}

void Blink(int num){
    for(int i=0;i<num;++i){
        digitalWrite(ledPin,HIGH);
        delay(100);
        digitalWrite(ledPin,LOW);
        delay(100);
    }
}