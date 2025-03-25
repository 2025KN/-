#include <Wire.h>				//I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>	//I2C LCD 라이브러리
#define TRIG 13  //TRIG을 13으로 지정
#define ECHO 12 

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()  //한번만 호출됨
{
  Serial.begin(9600); 
  //데이터 통신 () 안쪽은 통신속도, 통신속도는 주고받는 속도가 같아야 함
  pinMode(TRIG, OUTPUT); //TRIG(13번 핀)을 OUTPUT모드로 설정
  pinMode(ECHO, INPUT);
  lcd.init();			    //I2C LCD 초기화
  lcd.backlight();		//백라이트 켜기
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()  //계속 반복하여 호출됨
{
  long duration, distance;
  
  digitalWrite(TRIG, LOW); //트리거를 기본적으로 LOW상태로 지정
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);  //센서의 요구 조건 10마이크로세컨드
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH); 
  //pulseIn은 핀(ECHO)이 어떤 상태(HIGH)로 있었던 시간을 알려줌
  distance = duration /58.2; 
  //ECHO가 켜있던 시간을 수식을 이용하여 cm로 변환
  
  
  lcd.setCursor(0,0);
  lcd.print(distance);
  lcd.print(" Cm");
  delay(1000);
  lcd.clear();
  

}