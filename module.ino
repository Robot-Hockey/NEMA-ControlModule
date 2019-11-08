// defines pins numbers
const int step_pin_x = 12; 
const int dir_pin_x = 26;

const int step_pin_y1 = 14; 
const int dir_pin_y1 = 25;

const int step_pin_y2 = 27; 
const int dir_pin_y2 = 33;

int should_run_x = 0;
int real_state_x = '0';

int should_run_y = 0;
int real_state_y = '0';

int spd = 380;

void setup() {
  pinMode(step_pin_x,OUTPUT);
  pinMode(dir_pin_x,OUTPUT);

  pinMode(step_pin_y1,OUTPUT);
  pinMode(dir_pin_y1,OUTPUT);

  pinMode(step_pin_y2,OUTPUT);
  pinMode(dir_pin_y2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
    // Serial.println(should_run_x);
    // Serial.println(real_state_x);

    if(Serial.available()){
        int state_x = Serial.read();
        int state_y = Serial.read();

        if(state_x == '1' && real_state_x != '1'){
            digitalWrite(dir_pin_x,HIGH);
            
            if(real_state_x == 2){
                // Should change dir
                delayMicroseconds(spd);
                digitalWrite(step_pin_x,LOW);
            }

            should_run_x = 1;
            real_state_x = '1';
        }else if(state == '2' && real_state_x != '2'){
            digitalWrite(dir_pin_x,LOW);

            if(real_state_x == '1'){
                // Should change dir
                delayMicroseconds(spd);
                digitalWrite(step_pin_x,LOW);
            }
            
            should_run_x = 1;
            real_state_x = '2';
        }else if{
            should_run_x = 0;
            real_state_x = state;
        }

        if(state_y == '1' && real_state_y != '1'){
            digitalWrite(dir_pin_y1,HIGH);
            digitalWrite(dir_pin_y2,LOW);
            
            if(real_state_y == 2){
                // Should change dir
                delayMicroseconds(spd);
                digitalWrite(step_pin_y1,LOW);
                digitalWrite(step_pin_y2,LOW);
            }

            should_run_y = 1;
            real_state_y = '1';
        }else if(state == '2' && real_state_y != '2'){
            digitalWrite(dir_pin_y1,LOW);
            digitalWrite(dir_pin_y2,HIGH);

            if(real_state_y == '1'){
                // Should change dir
                delayMicroseconds(spd);
                digitalWrite(step_pin_y1,LOW);
                digitalWrite(step_pin_y2,LOW);
            }
            
            should_run_y = 1;
            real_state_y = '2';
        }else if{
            should_run_y = 0;
            real_state_y = state;
        }
    }

    if(should_run_x){
        delayMicroseconds(spd);
        digitalWrite(step_pin_x,HIGH); 
        delayMicroseconds(spd);
        digitalWrite(step_pin_x,LOW);
    }

    if(should_run_y){
        delayMicroseconds(spd);
        digitalWrite(step_pin_y1,HIGH);
        digitalWrite(step_pin_y2,HIGH); 
        delayMicroseconds(spd);
        digitalWrite(step_pin_y1,LOW);
        digitalWrite(step_pin_y2,LOW);
    }
}