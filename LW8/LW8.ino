int ledrot=10;
int ledgelb=11;
int ledgruen=12;
int cnt=0;
int state=1;
char mode = '0';

void setup(){
  pinMode(ledrot, OUTPUT);
  pinMode(ledgelb, OUTPUT);
  pinMode(ledgruen, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  while(Serial.available()){
    char temp = Serial.read();
    if(temp != '\n'){
      mode = temp;
      Serial.print("Mode: ");
      Serial.print(mode);
      Serial.print('\n');
    }
  }

  cnt++;
  if(cnt==100)
  {
    cnt=0;
    Statemachine();
  }

  delay(10);
}

void Statemachine(){
  switch(mode){
    case 'N':
      switch(state)
        {
          case 1:
          digitalWrite(ledrot, HIGH);
          digitalWrite(ledgelb, LOW);
          digitalWrite(ledgruen, LOW);
          state++;
          break;

          case 2:
          digitalWrite(ledrot, LOW);
          digitalWrite(ledgelb, HIGH);
          digitalWrite(ledgruen, LOW);
          state++;
          break;

          case 3:
          digitalWrite(ledrot, LOW);
          digitalWrite(ledgelb, LOW);
          digitalWrite(ledgruen, HIGH);
          state++;
          break;

          case 4:
          digitalWrite(ledrot, LOW);
          digitalWrite(ledgelb, HIGH);
          digitalWrite(ledgruen, LOW);
          state=1;
          break;
       }
    break;

   case 'S':
      if(state%2==0){
        digitalWrite(ledrot, LOW);
        digitalWrite(ledgelb, HIGH);
        digitalWrite(ledgruen, LOW);
      }
      else{
        digitalWrite(ledrot, LOW);
        digitalWrite(ledgelb, LOW);
        digitalWrite(ledgruen, LOW);
      }
      if(state == 4){
        state=1;
      }
      else{
        state++;
      }
      break;
      
    case 'R':
      digitalWrite(ledrot, HIGH);
      digitalWrite(ledgelb, LOW);
      digitalWrite(ledgruen, LOW);
      break;

    case 'G':
      digitalWrite(ledrot, LOW);
      digitalWrite(ledgelb, LOW);
      digitalWrite(ledgruen, HIGH);
      break;
  }
}
