#define CLOCK_PIN 12
#define DATA_PIN  11 
#define LATCH_PIN 10 

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  digitalWrite(CLOCK_PIN, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(DATA_PIN,LOW);
  digitalWrite(LATCH_PIN,LOW);
}
void clk(void)
{
    digitalWrite(CLOCK_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(CLOCK_PIN, LOW);
    delayMicroseconds(500);
}

void latch(void)
{
    digitalWrite(LATCH_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(LATCH_PIN, LOW);
}

void data_send(byte data)
{
  byte x = 0;
  for(byte i=0 ; i<8 ; i++)
  {   
    x = (data >> i) & 0x01;
    digitalWrite(DATA_PIN, x);
    clk();
  }
  latch();
}
// the loop function runs over and over again forever
void loop() {
  
  data_send(0b10000000);
  delay(200);
  data_send(0b01000000);
  delay(200);
  data_send(0b00100000);
  delay(200);
  data_send(0b00010000);
  delay(200);
  data_send(0b00001000);
  delay(200);
  data_send(0b00000100);
  delay(200);
  data_send(0b00000010);
  delay(200);
  data_send(0b00000001);
  delay(200);

  
}
