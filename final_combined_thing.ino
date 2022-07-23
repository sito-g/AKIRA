
#define lm 5//left motor
#define rm 6//right motor
int leftdistance();
int rightdistance();

void setup() {
 
   pinMode(7,OUTPUT);//left ultra trig
   pinMode(8,INPUT);//left ultra echo
      pinMode(11,OUTPUT);//right ultra trig
   pinMode(12,INPUT);//right ultra echo
    pinMode(5,OUTPUT);//left motor
   pinMode(6,OUTPUT);//right motor
      pinMode(9,OUTPUT);//left motor
   pinMode(10,OUTPUT);//right motor
   Serial.begin(9600);

}
void loop() {
 
 int LIR,MIR,RIR;
 int d1,d2;
   
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
    if(LIR==1 && MIR==1 && RIR==1){
      d1=leftdistance();
      d2=rightdistance();
      if(LIR==1 && MIR==1 && RIR==1 && (d1<16 || d2<16)){
        ultrasonic();

      }
    }
}
void ultrasonic(){
    int d1,d2;
 d1=leftdistance();
 d2=rightdistance();
 
 if((d1<16 && d2<16)){
    Serial.println("forward");
       digitalWrite(lm,1);
    digitalWrite(rm,1);
  analogWrite(9,255);
   analogWrite(10,255);
   
    }
 else  if((d1>16 &&  d2<16 ) ){
  Serial.println("turn left");
    digitalWrite(lm,1);
    digitalWrite(rm,1);
    analogWrite(9,120);
    analogWrite(10,255);
 
    }
   else if((d1<16 && d2>16)){
    Serial.println("turn right");
    digitalWrite(lm,1);
    digitalWrite(rm,1);
     analogWrite(9,255);
    analogWrite(10,120);
    }
   
    }

int leftdistance(){
    digitalWrite(7,0);
   delayMicroseconds(2);
   digitalWrite(7,1);
     delayMicroseconds(10);
   digitalWrite(7,0);
  int t1=pulseIn(8,HIGH);
 
  int distance1=t1/58.2;
   return (distance1);
}
 int rightdistance(){
    digitalWrite(11,0);
     delayMicroseconds(2);
      digitalWrite(11,1);
     delayMicroseconds(10);
    int t2=pulseIn(12,HIGH);
 
  int distance2=t2/58.2;
   return (distance2);
   
  }
