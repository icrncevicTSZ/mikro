const int A=2;
const int B=3;
const int C=4;
const int D=5;
const int E=6;
const int F=7;
const int G=8;
const int DP=9;
int tipkalo1=12;
int tipkalo2=13;
void setup() {
 pinMode(A,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(D,OUTPUT);
 pinMode(E,OUTPUT);
 pinMode(F,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(DP,OUTPUT);
 pinMode(tipkalo1,INPUT_PULLUP);
 pinMode(tipkalo2,INPUT_PULLUP);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(DP,HIGH);


}

void loop() {
  if(digitalRead(tipkalo1)==LOW){
    digitalWrite(A,LOW);
    digitalWrite(G,LOW);
    digitalWrite(D,LOW);
  }else{
    digitalWrite(A,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(D,HIGH);
  }
  if(digitalRead(tipkalo2)==LOW){
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    digitalWrite(E,LOW);
    digitalWrite(F,LOW);
    delay(500);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    delay(500);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    delay(500);
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    delay(500);
    digitalWrite(E,HIGH);
    digitalWrite(D,LOW);
    delay(500);
    digitalWrite(F,HIGH);
    digitalWrite(E,LOW);
    delay(500);
    digitalWrite(F,LOW);
    digitalWrite(A,HIGH);
    delay(500);
    
    
  }else{
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
    digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
  }
}
