//the 256 values in the lookup table aren't necessary
//you can also reduce it to ~ 48 without real
//difference in characteristic
uint8_t sin_tbl[256] =
{
  128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,
  185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,228,
  230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,
  253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,
  250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,
  220,218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,
  170,167,165,162,158,155,152,149,146,143,140,137,134,131,128,124,121,118,115,
  112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,
  47,44,42,40,37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,
  4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,
  20,21,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,
  76,79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,
};


const int ledPin = 13; 
const uint8_t phase1Pin = 21;
const uint8_t phase2Pin = 22;
const uint8_t phase3Pin = 23;
const uint8_t enableL6234Pin = 20;

uint8_t phase = 0;

int incomingByte = 0; // for incoming serial data

void setup() {
Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(ledPin, OUTPUT);
  pinMode(phase1Pin, OUTPUT);
  pinMode(phase2Pin, OUTPUT);
  pinMode(phase3Pin, OUTPUT);
  pinMode(enableL6234Pin, OUTPUT);
  
  digitalWrite(enableL6234Pin, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  // send data only when you receive data:
  if (Serial.available() > 0) {
  // read the incoming byte:
  i_speed = Serial.parseInt();
  // i_speed= atoi(incomingByte);
  // say what you got:
  Serial.print("set speed to: ");
  Serial.println(i_speed, DEC);
  // Serial.println(i_speed);
  }
  */


//more delay means slower rpm
  delay(1);

//you  can also do +=4 to get faster rotation (skipping ahead in the lookup table)
  phase+=1;
 
 //the neat little trick here is that the sin_tbl values are
 //uint8_t  thus 256 causes an overflow and thus is 0 again!
 //thx Samu
 
 //According to the documentation on pjrc https://www.pjrc.com/teensy/td_pulse.html
 //the teensy 3.0 pwm frequency is 488.28 Hz.

 //in a possible future version this should be made higher for
 //even smoother operation
 
 //the 3 generated phases are shifted approximately 120° (should be exactly 120°)

  analogWrite(phase1Pin, sin_tbl[phase]);
  analogWrite(phase3Pin, sin_tbl[uint8_t(phase+85)]);
  analogWrite(phase2Pin, sin_tbl[uint8_t(phase+171)]);
}
