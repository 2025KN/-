#define TRIG 13  //TRIG을 13으로 지정
#define ECHO 12 

void setup()  //한번만 호출됨
{
  Serial.begin(9600); 
  //데이터 통신 () 안쪽은 통신속도, 통신속도는 주고받는 속도가 같아야 함
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(TRIG, OUTPUT); //TRIG(13번 핀)을 OUTPUT모드로 설정
  pinMode(ECHO, INPUT);
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
  
  Serial.print(distance);
  Serial.println(" Cm");
  
  //거리가 100Cm 이상이면 빨간 LED On, 그 외에는 초록색 LED On
  if (distance >=100)
  {
    digitalWrite(11, HIGH);
    digitalWrite(6, LOW);
  }
  else
  {
     digitalWrite(6, HIGH);
     digitalWrite(11, LOW);
  }

  delay(1000);  //아래 내용이 더 이상 없을 때, 1초마다 정보 받기
  
  /*
  digitalWrite(11, HIGH);  //11번 핀의 상태를 HIGH로 지정
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  digitalWrite(6, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  */
  
}
