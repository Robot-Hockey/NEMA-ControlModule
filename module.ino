// defines pins numbers
const int stepPin = 12; 
const int dirPin = 26;

int should_run = 0;
int real_state = 0;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
    print(should_run);
    print(real_state);

    if(Serial.available()){
        int state = Serial.read();

        if(state == 1 && real_state != 1){
            digitalWrite(dirPin,HIGH);
            
            if(real_state == 2){
                // Should change dir
                delayMicroseconds(450);
                digitalWrite(stepPin,LOW);
            }

            should_run = 1;
            real_state = 1;
        }else if(state == 2 && real_state != 2){
            digitalWrite(dirPin,LOW);

            if(real_state == 1){
                // Should change dir
                delayMicroseconds(450);
                digitalWrite(stepPin,LOW);
            }
            
            should_run = 1;
            real_state = 2;
        }else{
            should_run = 0;
            real_state = state;
        }
    }

    if(should_run){
        delayMicroseconds(450);
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(450);
        digitalWrite(stepPin,LOW);
    }
}