// solenoid1

/* 작동
1. Jetson에서 자모음 data 받아옴
2. 자모음 func 호출 및 솔레노이드 작동
*/

#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial BTSerial(2, 3);

int Relaypin1 = 4;
int Relaypin2 = 5;
int Relaypin3 = 6;
int Relaypin4 = 7;
int Relaypin5 = 8;
int Relaypin6 = 9;
int Relaypin7 = 10;
int Relaypin8 = 11;
int Relaypin9 = 12; 
int Relaypin10 = 13; 
int Relaypin11 = A0; 
int Relaypin12 = A1;
int Relaypin13 = A2;  
int Relaypin14 = A3;  
int Relaypin15 = A4;  
int Relaypin16 = A5;  



void setup()
{
  Serial.begin(9600);
  pinMode(Relaypin1,OUTPUT);         // 릴레이 제어 1번핀을 출력으로 설정
  pinMode(Relaypin2,OUTPUT);         // 릴레이 제어 2번핀을 출력으로 설정
  pinMode(Relaypin3,OUTPUT);         // 릴레이 제어 3번핀을 출력으로 설정
  pinMode(Relaypin4,OUTPUT);         // 릴레이 제어 4번핀을 출력으로 설정
  pinMode(Relaypin5,OUTPUT);         // 릴레이 제어 5번핀을 출력으로 설정
  pinMode(Relaypin6,OUTPUT);         // 릴레이 제어 6번핀을 출력으로 설정
  pinMode(Relaypin7,OUTPUT);         // 릴레이 제어 7번핀을 출력으로 설정
  pinMode(Relaypin8,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin9,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin10,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin11,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin12,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin13,OUTPUT);         // 릴레이 제어 8번핀을 출력으로 설정
  pinMode(Relaypin14,OUTPUT);
  pinMode(Relaypin15,OUTPUT);
  pinMode(Relaypin16,OUTPUT);
  BTSerial.begin(9600);
  func0();
}


void loop() {
  if(BTSerial.available())
    { 
      delay(5); 
      while(BTSerial.available())
      { 
        char c;
        c = BTSerial.read();
        Serial.write(c);
        if (c == 'z') {
          func0();
        }
        if (c == 'A') {
          func1();
        }
        if (c == 'B') {
          func2();
        }
        if (c == 'C') {
          func3();
        }
        if (c == 'D') {
          func4();
        }
        if (c == 'E') {
          func5();
        }
        if (c == 'F') {
          func6();
        }
        if (c == 'G') {
          func7();
        }
        if (c == 'H') {
          func8();
        }
        if (c == 'I') {
          func9();
        }
        if (c == 'J') {
          func10();
        }
        if (c == 'K') {
          func11();
        }
        if (c == 'L') {
          func12();
        }
        if (c == 'M') {
          func13();
        }
        if (c == 'N') {
          func14();
        }
        if (c == 'O') {
          func15();
        }
        if (c == 'P') {
          func16();
        }
        if (c == 'Q') {
          func17();
        }
        if (c == 'R') {
          func18();
        }
        if (c == 'S') {
          func19();
        }
        if (c == 'T') {
          func20();
        }
        if (c == 'U') {
          func21();
        }
        if (c == 'V') {
          func22();
        }
        if (c == 'W') {
          func23();
        }
        if (c == 'X') {
          func24();
        }
        if (c == 'Y') {
          func25();
        }
        if (c == 'Z') {
          func26();
        }
        if (c == 'a') {
          func27();
        }
        if (c == 'b') {
          func28();
        }
        if (c == 'c') {
          func29();
        }
        if (c == 'd') {
          func30();
        }
        if (c == 'e') {
          func31();
        }
        if (c == 'f') {
          func32();
        }
        if (c == 'g') {
          func33();
        }
        if (c == 'h') {
          func34();
        }
        if (c == 'i') {
          func35();
        }
        if (c == 'j') {
          func36();
        }
        if (c == 'k') {
          func37();
        }
        if (c == 'l') {
          func38();
        }
        if (c == 'm') {
          func39();
        }
        if (c == 'n') {
          func40();
        }
      }
    }
   
}

//전체  HIGH
void func0() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(500);
  return;
}

//ㄱ
void func1() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㄴ
void func2() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㄷ
void func3() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㄹ
void func4() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅁ
void func5() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅂ
void func6() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅅ
void func7() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, LOW);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅇ
void func8() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅈ
void func9() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅊ
void func10() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, LOW);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅋ
void func11() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅌ
void func12() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅍ
void func13() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅎ
void func14() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㄲ
void func15() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㄸ
void func16() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅉ
void func17() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, LOW);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, LOW);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅃ
void func18() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅆ
void func19() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, LOW);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅏ
void func20() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅑ
void func21() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅓ
void func22() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅕ
void func23() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅗ
void func24() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅛ
void func25() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅜ
void func26() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, LOW);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅠ
void func27() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, LOW);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅡ
void func28() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, LOW);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅣ
void func29() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅘ
void func30() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, LOW);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅙ
void func31() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, LOW);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅚ
void func32() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, LOW);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅟ
void func33() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, LOW);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅝ
void func34() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, LOW);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅞ
void func35() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, LOW);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅖ
void func36() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅒ
void func37() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅔ
void func38() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, LOW);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, HIGH);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, LOW);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅐ
void func39() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, LOW);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, LOW);   //Turn off relay
  digitalWrite(Relaypin9, LOW);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, HIGH);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, LOW);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}

//ㅢ
void func40() {
  digitalWrite(Relaypin1, HIGH);   //Turn off relay
  digitalWrite(Relaypin2, HIGH);   //Turn off relay
  digitalWrite(Relaypin3, HIGH);   //Turn off relay
  digitalWrite(Relaypin4, HIGH);   //Turn off relay
  digitalWrite(Relaypin5, HIGH);   //Turn off relay
  digitalWrite(Relaypin6, HIGH);   //Turn off relay
  digitalWrite(Relaypin7, HIGH);   //Turn off relay
  digitalWrite(Relaypin8, HIGH);   //Turn off relay
  digitalWrite(Relaypin9, HIGH);   //Turn off relay
  digitalWrite(Relaypin10, HIGH);   //Turn off relay
  digitalWrite(Relaypin11, LOW);   //Turn off relay
  digitalWrite(Relaypin12, LOW);   //Turn off relay
  digitalWrite(Relaypin13, HIGH);   //Turn off relay
  digitalWrite(Relaypin14, HIGH);   //Turn off relay
  digitalWrite(Relaypin15, HIGH);   //Turn off relay
  digitalWrite(Relaypin16, HIGH);   //Turn off relay
  delay(4000);
  func0();
  return;
}
