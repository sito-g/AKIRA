#define lm 5//left motor
#define rm 6//right motor
int leftdistance();
int rightdistance();
void setup() {
  pinMode(2,INPUT);//left IR sensor
  pinMode(3,INPUT);//middle IR sensor
  pinMode(4,INPUT);//right IR sensor
  pinMode(5,OUTPUT);//left motor
  pinMode(6,OUTPUT);//right motor
  pinMode(9,OUTPUT);//left motor
  pinMode(10,OUTPUT);//right motor
   Serial.begin(9600);
}
void loop() {
  int LIR,MIR,RIR;
   //int d1,d2;
  LIR=digitalRead(2);//left IR sensor
   MIR=digitalRead(3); //middle IR sensor
   RIR=digitalRead(4);//right IR sensor
   if((LIR==1 && MIR==0 && RIR==1)){
    Serial.println("forward");
    digitalWrite(lm,1);
    digitalWrite(rm,1);
     digitalWrite(9,1);
    digitalWrite(10,1);
    }
       if((LIR==0 && MIR==1 && RIR==1) || (LIR==0 && MIR==0 && RIR==1) ){
    Serial.println("turn left");
    digitalWrite(lm,0);
    digitalWrite(rm,1);
     digitalWrite(9,1);
    digitalWrite(10,1);
    }
       if((LIR==1 && MIR==1 && RIR==0) ||(LIR==1 && MIR==0 && RIR==0)){
    Serial.println("turn right");
    digitalWrite(lm,1);
    digitalWrite(rm,0);
     digitalWrite(9,1);
    digitalWrite(10,1);
    }
}

