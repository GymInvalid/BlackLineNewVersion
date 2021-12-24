int LeftAn = 11;
int LeftDig = 9;
int RightAn = 10;
int RightDig = 13;
int LeftDat = 5;
int RightDat = 6;
int LeftDatFar = 8;
int RightDatFar = 7;
int flag = 0;

void setup() {
  pinMode(LeftAn, OUTPUT);
  pinMode(RightAn, OUTPUT);
  pinMode(LeftDig, OUTPUT);
  pinMode(RightDig, OUTPUT);
  pinMode(LeftDat, INPUT);
  pinMode(RightDat, INPUT);
  pinMode(LeftDatFar, INPUT);
  pinMode(RightDatFar, INPUT);
}

void Left(int speedR, int speedL) { //Налево
  analogWrite(LeftAn, speedL);
  analogWrite(RightAn, speedR);
  digitalWrite(RightDig, HIGH);
}

void LeftLow(int speedR, int speedL) { //Налево с меньшим углом
  analogWrite(LeftAn, speedL);
  analogWrite(RightAn, speedR);
  digitalWrite(RightDig, HIGH);
  digitalWrite(LeftDig, LOW);
}

void Right(int speedL, int speedR) { //Направо
  analogWrite(LeftAn, speedL);
  analogWrite(RightAn, speedR);
  digitalWrite(LeftDig, HIGH);
}

void RightLow(int speedL, int speedR) {
  analogWrite(LeftAn, speedL);
  analogWrite(RightAn, speedR);
  digitalWrite(LeftDig, HIGH);
  digitalWrite(RightDig, LOW);
}

void Front(int speedF) { //Прямо
  analogWrite(LeftAn, speedF);
  analogWrite(RightAn, speedF);
  digitalWrite(LeftDig, HIGH);
  digitalWrite(RightDig, HIGH);
}

void CheckLines() {
  Front(135);

  if (digitalRead(LeftDatFar) == HIGH && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW)
  {
  flag = 1;
  Left(130, 0);
  }

  if (digitalRead(LeftDatFar) == HIGH && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW && flag == 1)
  {
  Left(130, 0);
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == HIGH && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW)
  {
  flag = 1;
  LeftLow(130, 100);
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == HIGH && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW && flag == 1)
  {
  LeftLow(130, 100);
  }

  if (digitalRead(LeftDatFar) == HIGH && digitalRead(LeftDat) == HIGH && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW)
  {
  flag = 1;
  Left(130, 0);
  }

  if (digitalRead(LeftDatFar) == HIGH && digitalRead(LeftDat) == HIGH && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == LOW && flag == 1)
  {
  Left(130, 0);
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == HIGH)
  {
  flag = 2;
  Right(130, 0);
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == LOW && digitalRead(RightDatFar) == HIGH && flag == 2)
  {
  Right(130, 0);
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == HIGH && digitalRead(RightDatFar) == LOW)
  {
  flag = 2;
  RightLow(130, 100); 
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == HIGH && digitalRead(RightDatFar) == LOW && flag == 2)
  {
  RightLow(130, 100); 
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == HIGH && digitalRead(RightDatFar) == HIGH)
  {
  flag = 2;
  RightLow(130, 0); 
  }

  if (digitalRead(LeftDatFar) == LOW && digitalRead(LeftDat) == LOW && digitalRead(RightDat) == HIGH && digitalRead(RightDatFar) == HIGH && flag == 2)
  {
  RightLow(130, 0); 
  }
}

void loop() {
  CheckLines();
}
