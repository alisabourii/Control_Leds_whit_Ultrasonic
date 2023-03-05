int const echo = 7;
int const trig = 8;

void setup() {
  Serial.begin(9600);
 for(int i=2; i<= 6; i++)
  pinMode(i, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);


}

void loop() {
  int dic = Distance();
  Serial.println(dic);
    if(dic > 26 && dic <= 31)
      Control_leds(2);
    else if(dic > 20 && dic <= 25)
      Control_leds(3);
   else if(dic > 15 && dic <= 21)
      Control_leds(4);
   else if(dic > 10 && dic <= 16)
    Control_leds(5);
  else if(dic > 3 && dic <= 11)
    Control_leds(6);  
  else
     Control_leds(-2);
}

float Distance(){
  digitalWrite(trig,1);
  delay(1);
  digitalWrite(trig,0);

  int sure = pulseIn(echo, 1);
  float msf = (sure / 2)/28.97;
  return msf;
  delay(150);
  }
void Control_leds(int count){
  for(int i=2; i<=6; i++){
    digitalWrite(i,0);}
    
  for(int i=2; i<=count; i++){
    digitalWrite(i,1);}
  if(count == 31){
    for(int i=2; i<=6; i++){
    digitalWrite(i,0);}
  }
}
