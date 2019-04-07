int f1 = A0;
int f2 = A1;
int f3 = A2;
int f4 = A3;

int yin = A5;
int xin = A4;

int uT = 768;
int lT = 256;

void setup() {
  // put your setup code here, to run once:

  pinMode(f1, INPUT);
  pinMode(f2, INPUT);
  pinMode(f3, INPUT);
  pinMode(f4, INPUT);

  Serial.begin(9600);
}


void loop() {

  int v1 = analogRead(f1);
  int v2 = analogRead(f2);
  int v3 = analogRead(f3);
  //int v4 = analogRead(f4);

  int m1 = map(v1, 0, 435, 0, 100);
  int m2 = map(v2, 0, 450, 0, 100);
  int m3 = map(v3, 0, 430, 0, 100);
  //int m4 = map(v4, 0, 380, 0, 100);

  int x = analogRead(xin);
  int y = analogRead(yin);


  
  int out = 0;

  if (x < uT && x > lT && y > uT) {
    out += 64;
      //Serial.print("Forward ");
  }
  if (x < uT && x > lT && y < lT) {
    out += 32;
      //Serial.print("Backward ");
  }


  if (y < uT && y > lT && x > uT) {
    out += 16;
      //Serial.print("Left ");
    
  }

  if (y < uT && y > lT && x < lT) {
    out += 8;
      //Serial.print("Right ");
    
  }


  if (m2 < 75){
    out += 2;
    //Serial.print(" yAxisUP ");
  }else{
    if (m1 < 75){
      out += 4;
      //Serial.print(" yAxisDown ");
    }else{
      //Serial.print(" yAxisStraight ");
    }
  }

  if (m3 < 75){
    out += 1;
    //Serial.print(" armClose ");
  }else{
    //Serial.print(" armOpen ");
  }
  
  Serial.write(out);
  delay(50);

}
