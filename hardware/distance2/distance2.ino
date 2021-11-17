#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);  // 블루투스를 사용하기 위해 BT 이름으로 선언
SoftwareSerial bt2Serial(5, 4);  // 블루투스를 사용하기 위해 BT 이름으로 선언
SoftwareSerial bt3Serial(6, 7);

// 스위치 1~5
#define BTN_PIN1 A0
#define BTN_PIN2 A1
#define BTN_PIN3 A2
#define BTN_PIN4 A3
#define BTN_PIN5 A4

// 연결핀 변수 설정
int VibPin = 11; // 진동 모터
int trigPin = 13; // 초음파 거리 센서 trigPin
int echoPin = 12; // 초음파 거리 센서 echoPin
int flag = 0;

void setup(){
 
  Serial.begin(9600);  // 시리얼 통신을 위해 시리얼 통신속도를 9600으로 설정  
  btSerial.begin(9600);  // 블루투스 통신을 위해 블루투스 통신속도를 9600으로 설정
  bt2Serial.begin(9600);
  bt3Serial.begin(9600);
  
  pinMode(VibPin, OUTPUT); // 진동 모터
  pinMode(echoPin, INPUT); // 초음파 거리 센서 echoPin 입력    
  pinMode(trigPin, OUTPUT); // 초음파 거리 센서 trigPin 출력
  pinMode(BTN_PIN1, INPUT_PULLUP); // 버튼핀 
  pinMode(BTN_PIN2, INPUT_PULLUP);
  pinMode(BTN_PIN3, INPUT_PULLUP);
  pinMode(BTN_PIN4, INPUT_PULLUP);
  pinMode(BTN_PIN5, INPUT_PULLUP);
}
 
void loop(){
  
  // object name
  Serial.println('-1');
  if (digitalRead(BTN_PIN1) == LOW)
  {
    Serial.println('1');
    delay(1000);
  }

  // ocr
  if (digitalRead(BTN_PIN2) == LOW)
  {
    Serial.println('2');
    delay(1000);
  }

  // info
  if (digitalRead(BTN_PIN3) == LOW)
  {
    Serial.println('3');
    delay(1000);
  }

  // 솔레노이드
  if (digitalRead(BTN_PIN4) == LOW) {
    Serial.println("4");
    delay(1000);
  }

  // csr
  if (digitalRead(BTN_PIN5) == LOW)
  {
    Serial.println('5');
    delay(1000);
  }

  // 초음파 거리 센서 + 진동 모듈
  long duration, distance;

  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // trigPin에서 초음파 발생        
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // echoPin 이 HIGH를 유지한 시간을 저장
  distance = (((float)(340 * duration) / 1000) / 2) / 10; // 거리 계산

  //Serial.print("Duration: "); //시리얼모니터에 Echo가 HIGH인 시간을 표시
  //Serial.print(duration);
  //Serial.print("Distance(cm): "); // 물체와 초음파 센서간 거리를 표시        
  //Serial.println(distance);
  delay(100);

  if (distance <= 40) // 특정 거리 내 진입
  {
    analogWrite(VibPin, 255 - distance * 8);
    delay(500); // Wait for 1000 millisecond(s)
    analogWrite(VibPin, 0);
    delay(500); // Wait for 1000 millisecond(s)
  }
  else
  {
    analogWrite(VibPin, 0); // 진동 모터 LOW
    delay(1000);
   }
   
  int c = Serial.read();
  //Serial.println(c);
  if (c ==1){
    btSerial.write('A');
    bt2Serial.write('A');
    bt3Serial.write('A');
  }
  if (c ==2){
    btSerial.write('B');
    bt2Serial.write('B');
    bt3Serial.write('B');
  }
  if (c ==3){
    btSerial.write('C');
    bt2Serial.write('C');
    bt3Serial.write('C');
  }
  if (c ==4){
    btSerial.write('D');
    bt2Serial.write('D');
    bt3Serial.write('D');
  }
  if (c ==5){
    btSerial.write('E');
    bt2Serial.write('E');
    bt3Serial.write('E');
  }
  if (c ==6){
    btSerial.write('F');
    bt2Serial.write('F');
    bt3Serial.write('F');
  }
  if (c ==7){
    btSerial.write('G');
    bt2Serial.write('G');
    bt3Serial.write('G');
  }
  if (c ==8){
    btSerial.write('H');
    bt2Serial.write('H');
    bt3Serial.write('H');
  }
  if (c ==9){
    btSerial.write('I');
    bt2Serial.write('I');
    bt3Serial.write('I');
  }
  if (c ==10){
    btSerial.write('J');
    bt2Serial.write('J');
    bt3Serial.write('J');

  }
  if (c ==11){
    btSerial.write('K');
    bt2Serial.write('K');
    bt3Serial.write('K');
  }
  if (c ==12){
    btSerial.write('L');
    bt2Serial.write('L');
    bt3Serial.write('L');
  }
  if (c ==13){
    btSerial.write('M');
    bt2Serial.write('M');
    bt3Serial.write('M');
  }
  if (c ==14){
    btSerial.write('N');
    bt2Serial.write('N');
    bt3Serial.write('N');
  }
  if (c ==15){
    btSerial.write('O');
    bt2Serial.write('O');
    bt3Serial.write('O');
  }
  if (c ==16){
    btSerial.write('P');
    bt2Serial.write('P');
    bt3Serial.write('P');
  }
  if (c ==17){
    btSerial.write('Q');
    bt2Serial.write('Q');
    bt3Serial.write('Q');
  }
  if (c ==18){
    btSerial.write('R');
    bt2Serial.write('R');
    bt3Serial.write('R');
  }
  if (c ==19){
    btSerial.write('S');
    bt2Serial.write('S');
    bt3Serial.write('S');
  }
  if (c ==20){
    btSerial.write('T');
    bt2Serial.write('T');
    bt3Serial.write('T');
  }
  if (c ==21){
    btSerial.write('U');
    bt2Serial.write('U');
    bt3Serial.write('U');
  }
  if (c ==22){
    btSerial.write('V');
    bt2Serial.write('V');
    bt3Serial.write('V');
  }
  if (c ==23){
    btSerial.write('W');
    bt2Serial.write('W');
    bt3Serial.write('W');
  }
  if (c ==24){
    btSerial.write('X');
    bt2Serial.write('X');
    bt3Serial.write('X');
  }
  if (c ==25){
    btSerial.write('Y');
    bt2Serial.write('Y');
    bt3Serial.write('Y');
  }
  if (c ==26){
    btSerial.write('Z');
    bt2Serial.write('Z');
    bt3Serial.write('Z');
  }
  if (c ==27){
    btSerial.write('a');
    bt2Serial.write('a');
    bt3Serial.write('a');
  }
  if (c ==28){
    btSerial.write('b');
    bt2Serial.write('b');
    bt3Serial.write('b');
  }
  if (c ==29){
    btSerial.write('c');
    bt2Serial.write('c');
    bt3Serial.write('c');
  }
  if (c ==30){
    btSerial.write('d');
    bt2Serial.write('d');
    bt3Serial.write('d');
  }
  if (c ==31){
    btSerial.write('e');
    bt2Serial.write('e');
    bt3Serial.write('e');
  }
  if (c ==32){
    btSerial.write('f');
    bt2Serial.write('f');
    bt3Serial.write('f');
  }
  
  if (c ==33){
    btSerial.write('g');
    bt2Serial.write('g');
    bt3Serial.write('g');
  }
  if (c ==34){
    btSerial.write('h');
    bt2Serial.write('h');
    bt3Serial.write('h');
  }
  if (c ==35){
    btSerial.write('i');
    bt2Serial.write('i');
    bt3Serial.write('i');
  }
  if (c ==36){
    btSerial.write('j');
    bt2Serial.write('j');
    bt3Serial.write('j');
    
  }
  if (c ==37){
    btSerial.write('k');
    bt2Serial.write('k');
    bt3Serial.write('k');
  }
  if (c ==38){
    btSerial.write('l');
    bt2Serial.write('l');
    bt3Serial.write('l');
  }
  if (c ==39){
    btSerial.write('m');
    bt2Serial.write('m');
    bt3Serial.write('m');
  }
  if (c ==40){
    btSerial.write('n');
    bt2Serial.write('n');
    bt3Serial.write('n');
  }

    
}
