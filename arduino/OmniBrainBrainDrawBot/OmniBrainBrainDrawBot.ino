#include <Wire.h>
#include <Flash.h>
#include <stdio.h>
// #include <OmniBrainBrainUIU.h>

#define Stick_H 1
#define Stick_V 0

#define Servo_H 5
#define Servo_V 6



#define F_CPU 16000000
#define PRESCALER 64;
#define PRESCALER_BITS (1<<CS22) | (1<<CS20)

#define NR_SERVOS 2

FLASH_ARRAY(int, plt_table,
/* armadillo.hpgl */
0x1028,0x2f4,0x501b,0x2d8,0x5011,0x2b9,0x500c,0x296,0x500b,0x272,0x500e,0x24c,0x5015,0x227,0x501f,0x203,0x502c,0x1e0,
0x503d,0x1c0,0x5050,0x1a5,0x5066,0x18e,0x507e,0x17c,0x5099,0x171,0x50b6,0x16e,0x50d5,0x173,0x50f6,0x182,0x5109,0x192,
0x5118,0x1a8,0x5123,0x1c3,0x512c,0x1e3,0x5134,0x22d,0x5133,0x27f,0x512a,0x2d3,0x511c,0x320,0x510a,0x361,0x50f6,0x38e,
0x50f0,0x369,0x50e1,0x349,0x50ca,0x32e,0x50ae,0x318,0x508f,0x307,0x506c,0x2fb,0x504a,0x2f5,0x5028,0x2f4,0x10f6,0x3b7,
0x514d,0x35d,0x517e,0x324,0x51af,0x2e8,0x51db,0x2a9,0x5200,0x26c,0x5218,0x232,0x521f,0x217,0x5221,0x1fe,0x5257,0x21e,
0x527a,0x23f,0x5285,0x250,0x528c,0x260,0x528f,0x271,0x528f,0x282,0x5284,0x2a4,0x526f,0x2c6,0x5251,0x2e6,0x522b,0x306,
0x51d4,0x341,0x5178,0x374,0x50f6,0x3b7,0xfc1,0x309,0x4f81,0x3ce,0x4f64,0x439,0x4f4d,0x4a7,0x4f41,0x516,0x4f40,0x54e,
0x4f42,0x585,0x4f4a,0x5bc,0x4f56,0x5f3,0x4f67,0x629,0x4f7e,0x65d,0x4f93,0x681,0x4fae,0x6a3,0x4fcc,0x6c4,0x4fed,0x6e1,
0x5011,0x6fb,0x5035,0x710,0x5058,0x720,0x507a,0x72b,0x50a0,0x72e,0x50cf,0x72d,0x50ff,0x72d,0x512a,0x735,0x5141,0x740,
0x5153,0x74e,0x516d,0x76e,0x5186,0x790,0x5198,0x7a1,0x51af,0x7b1,0x51c9,0x787,0x51e3,0x75e,0x51f8,0x734,0x51ff,0x71c,
0x5202,0x702,0x51e8,0x6c7,0x51d6,0x69c,0x51ce,0x67c,0x51cb,0x655,0x51c1,0x626,0x519f,0x5bc,0x5174,0x555,0x5148,0x505,
0x5134,0x4e3,0x5122,0x4bd,0x5102,0x46e,0x50e5,0x41c,0x50c6,0x3cc,0x50b3,0x3a7,0x509e,0x384,0x5085,0x364,0x5069,0x348,
0x5047,0x330,0x5021,0x31d,0x4ff4,0x310,0x4fc1,0x309,0x1070,0x466,0x5085,0x473,0x5096,0x485,0x50a3,0x49c,0x50a9,0x4b3,
0x50a9,0x4cb,0x50a0,0x4df,0x508e,0x4ee,0x5070,0x4f6,0x5052,0x4f3,0x503e,0x4e7,0x5034,0x4d4,0x5034,0x4bc,0x503a,0x4a2,
0x5048,0x48a,0x505a,0x475,0x5070,0x466,0xf79,0x2f4,0x4f5c,0x31c,0x4f41,0x34b,0x4f28,0x380,0x4f10,0x3ba,0x4efc,0x3f8,
0x4eea,0x439,0x4edc,0x47d,0x4ed1,0x4c2,0x4eca,0x507,0x4ec8,0x54b,0x4ecb,0x58d,0x4ed3,0x5cd,0x4ee1,0x608,0x4ef5,0x63f,
0x4f10,0x671,0x4f31,0x69b,0x4ee3,0x6de,0x4e96,0x719,0x4e47,0x74d,0x4df2,0x77d,0x4eb7,0x7e5,0x4f79,0x855,0x4fca,0x87e,
0x5025,0x8a6,0x5075,0x8cd,0x5092,0x8df,0x50a4,0x8ef,0x5065,0x907,0x501e,0x919,0x4fd1,0x923,0x4f83,0x924,0x4f37,0x91e,
0x4ef0,0x90e,0x4ed0,0x902,0x4eb2,0x8f4,0x4e98,0x8e3,0x4e82,0x8d0,0x4e4b,0x89a,0x4e30,0x876,0x4e28,0x863,0x4e25,0x850,
0x4e1d,0x827,0x4e0a,0x7ea,0x4df2,0x7b1,0x4de7,0x79c,0x4ddd,0x792,0x4dbb,0x786,0x4d90,0x782,0x4d5d,0x783,0x4d26,0x788,
0x4cb9,0x795,0x4c60,0x79c,0x4c95,0x7cc,0x4cce,0x7fa,0x4d48,0x852,0x4e3a,0x8ef,0x4df1,0x900,0x4da4,0x909,0x4d56,0x909,
0x4d0b,0x901,0x4cc7,0x8ee,0x4ca9,0x8e0,0x4c8e,0x8d0,0x4c77,0x8be,0x4c63,0x8a8,0x4c55,0x88f,0x4c4b,0x874,0x4c48,0x850,
0x4c4c,0x82c,0x4c4f,0x807,0x4c4b,0x7e4,0x4c44,0x7ce,0x4c3b,0x7bc,0x4c26,0x7a2,0x4c11,0x78d,0x4bfe,0x773,0x4bf1,0x765,
0x4bdb,0x756,0x4b9c,0x736,0x4b59,0x715,0x4b3e,0x706,0x4b2b,0x6f8,0x4b1c,0x6e4,0x4b0f,0x6cd,0x4afe,0x693,0x4af6,0x64e,
0x4af4,0x603,0x4af8,0x5b6,0x4afe,0x56c,0x4b0c,0x4f6,0x4b1d,0x46e,0x4b33,0x3e7,0x4b41,0x3a4,0x4b53,0x363,0x4b68,0x325,
0x4b82,0x2ea,0x4ba7,0x29c,0x4bc8,0x24d,0x4c0a,0x1b1,0x4c2f,0x165,0x4c59,0x11a,0x4c8b,0xd1,0x4cc7,0x8c,0x4d02,0xbb,
0x4d3c,0xef,0x4db1,0x15c,0x4dec,0x191,0x4e29,0x1c4,0x4e68,0x1f1,0x4eab,0x217,0x4ecb,0x22b,0x4ee9,0x245,0x4f23,0x285,
0x4f79,0x2f4,0xa3b,0x672,0x4a6e,0x670,0x4a92,0x66b,0x4aaa,0x664,0x4ab8,0x657,0x4abd,0x645,0x4abd,0x62a,0x4ab6,0x5d8,
0x4ab7,0x59b,0x4abf,0x562,0x4ac7,0x52a,0x4acb,0x4f1,0x4ace,0x4b5,0x4ad5,0x47b,0x4aea,0x414,0x4afc,0x3ae,0x4b06,0x376,
0x4b13,0x346,0x4b33,0x2f3,0x4b56,0x2a1,0x4b7c,0x249,0x4ba3,0x1e4,0x4bc8,0x194,0x4c06,0x122,0x4c4d,0xa9,0x4c90,0x44,
0x4bf6,0x2f,0x4b5d,0x1e,0x4ac0,0x14,0x4a1c,0x10,0x49e7,0x13,0x49a1,0x1c,0x4952,0x2a,0x4900,0x3e,0x48b4,0x57,
0x4874,0x76,0x485b,0x87,0x4848,0x9a,0x483c,0xaf,0x4838,0xc4,0x4835,0x154,0x4835,0x1e6,0x4838,0x22d,0x4840,0x273,
0x484d,0x2b5,0x4861,0x2f4,0x487d,0x333,0x489a,0x36a,0x48dd,0x3d6,0x4940,0x45f,0x4979,0x4af,0x49a0,0x4ec,0x4a0f,0x5b4,
0x4a18,0x5cc,0x4a1d,0x5e4,0x4a22,0x613,0x4a28,0x643,0x4a2f,0x65a,0x4a3b,0x672,0x593,0x620,0x4583,0x5bd,0x457d,0x549,
0x4581,0x4cb,0x4590,0x449,0x45a9,0x3ca,0x45ba,0x38e,0x45ce,0x355,0x45e4,0x320,0x45fd,0x2f0,0x4619,0x2c6,0x4638,0x2a2,
0x4651,0x283,0x466a,0x25a,0x4695,0x212,0x46ca,0x1ce,0x46e3,0x1ad,0x46f7,0x18d,0x470d,0x16a,0x4729,0x149,0x474b,0x12a,
0x476f,0x10e,0x47b8,0xdf,0x47f3,0xbf,0x47f4,0x141,0x47f7,0x1c0,0x4801,0x23b,0x4812,0x2b0,0x482d,0x31e,0x4840,0x353,
0x4855,0x386,0x486f,0x3b7,0x488d,0x3e6,0x48af,0x413,0x48d6,0x43d,0x48fb,0x465,0x4921,0x493,0x496b,0x4fc,0x49aa,0x56c,
0x49c3,0x5a3,0x49d7,0x5d8,0x49e1,0x5fc,0x49e7,0x61d,0x49e9,0x63c,0x49e8,0x657,0x49e3,0x670,0x49da,0x687,0x49ce,0x69c,
0x49c0,0x6b0,0x499b,0x6d2,0x496e,0x6f1,0x48ff,0x72b,0x4943,0x75a,0x4996,0x78d,0x4a48,0x7f8,0x4afd,0x875,0x4b5c,0x8ae,
0x4b88,0x8c3,0x4bb1,0x8d0,0x4b3a,0x8e5,0x4aed,0x8ef,0x4a9c,0x8f6,0x4a4c,0x8f7,0x4a03,0x8f1,0x49e2,0x8ea,0x49c5,0x8e1,
0x49ad,0x8d5,0x4999,0x8c6,0x496f,0x8a4,0x494c,0x88e,0x493c,0x882,0x492e,0x873,0x4920,0x85e,0x4913,0x840,0x4901,0x803,
0x48f3,0x7be,0x48ec,0x777,0x48ea,0x735,0x48c5,0x743,0x4898,0x74f,0x4866,0x759,0x4832,0x760,0x47ff,0x762,0x47d0,0x760,
0x47a9,0x758,0x478c,0x74a,0x47d7,0x7ac,0x4834,0x816,0x4899,0x87e,0x48ff,0x8da,0x4873,0x8db,0x482d,0x8d8,0x47eb,0x8ce,
0x47b0,0x8bb,0x4796,0x8ad,0x477e,0x89b,0x476a,0x886,0x4759,0x86d,0x474d,0x84f,0x4744,0x82c,0x4743,0x7f9,0x4746,0x7ad,
0x4744,0x768,0x473e,0x752,0x473a,0x74c,0x4734,0x74a,0x470e,0x747,0x46e9,0x73d,0x46c7,0x730,0x46a7,0x71f,0x4672,0x6f7,
0x464d,0x6ce,0x4565,0x76c,0x44ee,0x7b6,0x4473,0x7f8,0x440c,0x82c,0x4395,0x861,0x4357,0x879,0x4319,0x88c,0x42dd,0x898,
0x42a3,0x89d,0x4239,0x8a2,0x41cb,0x8a7,0x41ac,0x8a4,0x418d,0x89a,0x416e,0x88a,0x4151,0x876,0x4137,0x85d,0x4124,0x842,
0x4116,0x823,0x4112,0x803,0x410d,0x7e2,0x4101,0x7bf,0x40da,0x776,0x40ae,0x72d,0x408c,0x6ed,0x4059,0x678,0x4042,0x643,
0x402f,0x60b,0x4086,0x697,0x40da,0x728,0x412e,0x7b8,0x4183,0x840,0x416c,0x7f8,0x415a,0x7b0,0x4140,0x71f,0x4128,0x68c,
0x4119,0x641,0x4107,0x5f7,0x4120,0x63b,0x4136,0x684,0x415f,0x720,0x4188,0x7bf,0x419e,0x80c,0x41b6,0x855,0x41a8,0x818,
0x41a0,0x7d6,0x419c,0x791,0x419d,0x74b,0x41a2,0x705,0x41aa,0x6c0,0x41c1,0x63f,0x41bd,0x69a,0x41c3,0x707,0x41d2,0x771,
0x41dd,0x79f,0x41ea,0x7c5,0x4200,0x7fa,0x4208,0x808,0x4211,0x80f,0x421f,0x80f,0x4233,0x80b,0x427a,0x7f8,0x42b8,0x7e6,
0x42ef,0x7d1,0x435d,0x79c,0x4412,0x73f,0x4466,0x70d,0x44bb,0x6cf,0x44f5,0x69b,0x452b,0x668,0x455f,0x63d,0x4579,0x62c,
0x4593,0x620
);

// servo controll
volatile int ServoValues[NR_SERVOS];
volatile int ServoIDS[NR_SERVOS];

int MAX_H_PERIMETER = 140;

int SERVO_CENTER_V = 140;
int SERVO_CENTER_H = 147;

int MILLISEC_BASE = 0;
int SERVO_CENTER = 0;


int calb_groundlevel = 0;

int stickHSamples[5] = {0,0,0,0,0};
int stickVSamples[5] = {0,0,0,0,0};

byte stickSampleCounter = 0;

int stickHThreshold = 4; // default threshold value
int stickVThreshold = 4; // default threshold value

int stickH = 0;
int stickV = 0;

int stickHCenter = 0;
int stickVCenter = 0;

int botMode = 0;

int botMoveVectorX = 0;
int botMoveVectorY = 0;
int botMovePhi = 0;

int drawLineCounter = 0;

byte servoLock = B00000000;

//#############################################################################
//#############################################################################
// UIU vriables
//#############################################################################

// UI Shiftregister unit pin configuration
#define SREG_DS   9 // shift register datainput
#define SREG_OE   8 // shift register output enable
#define SREG_ST   7 // shift register storage register clock
#define SREG_MR   4 // shift register master reset
#define SREG_SH   3 // shift register clock

#define PIN_UIU_BTN_IN 2
#define PIN_UIU_BUZZER 11


// shiftregister array index matrix
#define SREG_INDEX_LED_BTN_Red 0
#define SREG_INDEX_LED_BTN_Blue 8

#define SREG_INDEX_LED_BAR_1 1
#define SREG_INDEX_LED_BAR_2 2
#define SREG_INDEX_LED_BAR_3 3
#define SREG_INDEX_LED_BAR_4 4
#define SREG_INDEX_LED_BAR_5 5
#define SREG_INDEX_LED_BAR_6 6
#define SREG_INDEX_LED_BAR_7 7
#define SREG_INDEX_LED_BAR_8 9
#define SREG_INDEX_LED_BAR_9 11

#define SREG_INDEX_BUTTON_Red 15
#define SREG_INDEX_BUTTON_Blue 10

#define SREG_INDEX_PROGRAMM_SW_1 14
#define SREG_INDEX_PROGRAMM_SW_2 13
#define SREG_INDEX_PROGRAMM_SW_3 12

byte UIUshiftRegisterBuffer[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte UIULedModes[11] = {4,4,1,2,3,4,5,4,4,4,4};

byte UIULedMatrix[11] = {
  SREG_INDEX_LED_BTN_Red,
  SREG_INDEX_LED_BTN_Blue,
  SREG_INDEX_LED_BAR_1,
  SREG_INDEX_LED_BAR_2,
  SREG_INDEX_LED_BAR_3,
  SREG_INDEX_LED_BAR_4,
  SREG_INDEX_LED_BAR_5,
  SREG_INDEX_LED_BAR_6,
  SREG_INDEX_LED_BAR_7,
  SREG_INDEX_LED_BAR_8,
  SREG_INDEX_LED_BAR_9
};

byte UIUButtonState[5] = {4,0,0,0,0};
byte UIUButtonMatrix[5] = {
  SREG_INDEX_BUTTON_Red,
  SREG_INDEX_BUTTON_Blue,
  SREG_INDEX_PROGRAMM_SW_1,
  SREG_INDEX_PROGRAMM_SW_2,
  SREG_INDEX_PROGRAMM_SW_3};

byte UIUBuzzerSound = 0;
int UIUBuzzerSoundCounter = 0;

boolean serialMsg = false;

int encA,encB,encC,current_Vx,current_Vy,current_omegaMini,target_x,target_y;

void setup(void) {
  

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  

  MILLISEC_BASE = F_CPU/64/1000;
  SERVO_CENTER = MILLISEC_BASE / 2;
  
  pinMode(Servo_H, OUTPUT);
  pinMode(Servo_V, OUTPUT);

  InitServo();

  clibrateStick();

  UIShiftRegisterSetup(); // init UIU

  delay(1000);
  Wire.begin(); // join I2C bus as master
  // Serial.begin(19200);
  Serial.begin(57600);
  Serial.println("system online...");

  Serial.print("Mem: "); Serial.println(availableMemory());
  int maximum = -1000;
  for (int i=0; i<plt_table.count(); ++i)
    Serial.print(plt_table[i]);
  Serial.print("Peak: "); Serial.println(maximum);
}


int availableMemory() 
{
  int size = 1024;
  byte *buf;
  while ((buf = (byte *) malloc(--size)) == NULL);
  free(buf);
  return size;
}


void InitServo() {
  noInterrupts();
  ServoIDS[0] = Servo_H;
  ServoIDS[1] = Servo_V;

  int i = 0;
  for(i=0; i<NR_SERVOS; i++)
    ServoValues[i] = SERVO_CENTER;  
  
  // interrup setup
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = MILLISEC_BASE + ServoValues[0];
  TIMSK1 |= (1<<OCIE1A);
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1<<CS11); // CTC mode
  TCCR1B |= (1<<CS10); // CTC mode
  interrupts();
}

void clibrateStick() {
  stickHSamples[0]=analogRead(Stick_H);
  Serial.println(stickHSamples[0]);
  stickHSamples[1]=analogRead(Stick_H);
  Serial.println(stickHSamples[1]);
  stickHSamples[2]=analogRead(Stick_H);
  Serial.println(stickHSamples[2]);
  stickHSamples[3]=analogRead(Stick_H);
  Serial.println(stickHSamples[3]);
  stickHSamples[4]=analogRead(Stick_H);
  Serial.println(stickHSamples[4]);
  stickH = (stickHSamples[0]+stickHSamples[1]+stickHSamples[2]+stickHSamples[3]+stickHSamples[4])/5;
  Serial.println(stickH);

  stickVSamples[0]=analogRead(Stick_V);
  Serial.println(stickVSamples[0]);
  stickVSamples[1]=analogRead(Stick_V);
  Serial.println(stickVSamples[1]);
  stickVSamples[2]=analogRead(Stick_V);
  Serial.println(stickVSamples[2]);
  stickVSamples[3]=analogRead(Stick_V);
  Serial.println(stickVSamples[3]);
  stickVSamples[4]=analogRead(Stick_V);
  Serial.println(stickVSamples[4]);
  stickV = (stickVSamples[0]+stickVSamples[1]+stickVSamples[2]+stickVSamples[3]+stickVSamples[4])/5;
  Serial.println(stickV);

  stickHCenter = stickH;
  stickVCenter = stickV;  
}


byte dutyCircle_footBrainCom = 0;
byte modeReset = 0;

void loop(void) {
  serialMsg = false;

  // digitalWrite(10,HIGH); // debug pin out


  serialParser();

  if(dutyCircle_footBrainCom%500==0) {
    stickPositionReadSampler();
  }



  if(botMode==0) modeSelectMode();
  
  if(dutyCircle_footBrainCom%50==0) {
    /*
    programm codes
    100 draw mode
    */
    
    // 100
    if(botMode==1) drawMode();

    // 001
    if(botMode==4) {
      doStickMotion(0,-150,2,2);
      botMoveVectorX = stickHPos();
      botMoveVectorY = stickVPos();
      driveByStick();
    }

    if(UIUButtonState[0]==1) {
      // red button pressed
      sendDataToFootBrain_stopAllMoation();
      botMode = 0;
      drawLineCounter = 0;

      sendDataToFootBrain_ClearCurrentPosition();
    }
  }
  modeReset = 0;
  

  // digitalWrite(10,LOW);  // debug pin out
  if(serialMsg) Serial.println();
  
  dutyCircle_footBrainCom++;

  UIUMasterControler();
}

void serialParser() {
  static char cmd[32];
  static byte charCount = 0;
  static byte humanmode = 1;

  int r,x,y,phi;

  if(Serial.available()) {
    // if any char in serial buffer available then do the parsing

    char c;
    c = Serial.read(); // read one char from serial buffer

    if((c==8) && (charCount>0)) charCount--; // backspace

    if(c>=32) { // char in num char range then add char to cmd array
      cmd[charCount] = c;
      charCount++;
    }

    if((c==0x0D) || (c==0x0A) || (charCount>30)) {
      // if the char is NL(New Line 0x0A) 
      // or CR (carriage return 0x0D) 
      // or cmd array buffer limit reached
      // parse the cmd buffer

      cmd[charCount]=0; // clear the last char in cmd buffer

      if(charCount>=1) { // prevent empty cmd buffer parsing

        switch(cmd[0]) {
          case '?':
            // show command listup
            Serial.println("s <-- stop all motion now\n");
            Serial.println("gr1000,-100,100 <-- goto relative x=100, y=-100\n");
            Serial.println("ga1000,-100,100 <-- goto absolute x=100, y=-100\n");
            Serial.println("rp <-- read current absolute x,y,phi values\n");
            Serial.println("re <-- read current a,b,c encoder values\n");
            Serial.println("rt <-- read current x,y target values\n");
            Serial.println("");
            Serial.println("ENCOM MX 16-923 USER # 0176835");
            Serial.println("END OF LINE");
            break;

          case 's':
            sendDataToFootBrain_stopAllMoation();
            botMode = 0;
            drawLineCounter = 0;

            sendDataToFootBrain_ClearCurrentPosition();
            break;

          case 'g':
            if(charCount>=2) {
              switch(cmd[1]) {
                case 'r':
                  // relative goto parser
                  
                  r = sscanf_P(&cmd[2],PSTR("%i,%i,%i"),&x,&y,&phi);
                  if(r==3) {
                    Serial.println(x);
                    Serial.println(y);
                    Serial.println(phi);
                    Serial.println(r);  
                  } else {
                    Serial.println("grXXX,YYY,PHI");
                  }
                  break;

                case 'a':
                  // absolute goto parser
                  
                  r = sscanf_P(&cmd[2],PSTR("%i,%i,%i"),&x,&y,&phi);
                  if(r==3) {
                    Serial.println(x);
                    Serial.println(y);
                    Serial.println(phi);
                    Serial.println(r);

                    sendDataToFootBrain_targetPosition(x,y);
                    sendDataToFootBrain_setSpeed(0.1);
                    sendDataToFootBrain_executeTargetValues();
                  } else {
                    Serial.println("gaXXX,YYY,PHI");
                  }
                  break;

                case 'c':
                  // clear all values
                  sendDataToFootBrain_ClearCurrentPosition();
                  Serial.println("values cleared");
                  break;

                default:
                  Serial.println("valid commands gc,gr,ga");
                  break;
              }
            }
            
            break; // case 'g'

          case 'r':
            if(charCount>=2){
              switch(cmd[1]) {
                case 'm':
                  // change to direct mode
                  humanmode = 0;
                  break;
                case 'p':
                  requestBrainCurrentStatus();
                  Serial.print("rp ");
                  Serial.print(current_Vx);
                  Serial.print(",");
                  Serial.print(current_Vy);
                  Serial.print(",");
                  Serial.println(current_omegaMini);

                  break;
                case 'e':
                  requestBrainCurrentStatus();
                  Serial.print("re ");
                  Serial.print(encA);
                  Serial.print(",");
                  Serial.print(encB);
                  Serial.print(",");
                  Serial.println(encC);
                  break;
                case 't':
                  requestBrainCurrentStatus();
                  Serial.print("rt ");
                  Serial.print(target_x);
                  Serial.print(",");
                  Serial.println(target_y);
                  break;
              }  
            }
            
            break;


          default:
            Serial.println("hae?\a");
            break;

        }
      }
      charCount = 0;
      if(humanmode==1) Serial.print(">");
    }
  }
}

void drawMode() {

  /*
  static int drawTimerStart = 0;

  static int lastStickHPos = 0;

  
    
  botMoveVectorY = 50;
  botMovePhi = 0;
  sendDataToFootBrain();


  botMoveVectorY = 0;
  botMovePhi = 0;
  sendDataToFootBrain();


  botMoveVectorX = 0;
  botMoveVectorY = -50;  // -70
  botMovePhi = 25;
  // botMovePhi = lastStickHPos*10;
 
  sendDataToFootBrain();
  */

  

  if(drawLineCounter==0) {
    sendDataToFootBrain_targetPosition(0,1000);
    sendDataToFootBrain_setSpeed(0.1);
    sendDataToFootBrain_executeTargetValues();
    // delay(10);
    drawLineCounter++;  
    penUp();
  }

  if(drawLineCounter%10000==1) {
    // delay(10);
    requestBrainCurrentStatus();
  }

  drawLineCounter++;
  
  // if(drawLineCounter>10000) drawLineCounter = 0;
}

void driveByStick() {

  // Serial.println(botMoveVectorX);
  // Serial.println(botMoveVectorY);
  
  if(botMoveVectorX<10) botMoveVectorX = 0;
  if(botMoveVectorY<10) botMoveVectorY = 0;



  sendDataToFootBrain_targetPosition(botMoveVectorX,botMoveVectorY);
  sendDataToFootBrain_setSpeed(0.1);
  sendDataToFootBrain_executeTargetValues();
  
  requestBrainCurrentStatus();
}



void requestBrainCurrentStatus() {

  byte serialdata[17];
  
  servoLock=B00000001;
  delayMicroseconds(10);
  
  Wire.requestFrom(3, 17);

  while(Wire.available())    // slave may send less than requested
  {
    for(int i=0; i<17; i++) {
      serialdata[i] = Wire.read();  
    }
  }
  
  servoLock=B00000000;
  
  // Serial.print(serialdata[0]);
  // Serial.print(serialdata[1]);
  // Serial.print(serialdata[2]);

  int targetIntTemp = 0;
  char intTemp[2] = {0,0};

  // serialdata[0] = tm_execute_target_motion; // batt status 0-255

  intTemp[0] = serialdata[1];
  intTemp[1] = serialdata[2];

  targetIntTemp = *((int *)intTemp);
  encA = float(targetIntTemp);


  intTemp[0] = serialdata[3];
  intTemp[1] = serialdata[4];

  targetIntTemp = *((int *)intTemp);
  encB = float(targetIntTemp);


  intTemp[0] = serialdata[5];
  intTemp[1] = serialdata[6];

  targetIntTemp = *((int *)intTemp);
  encC = float(targetIntTemp);


  intTemp[0] = serialdata[7];
  intTemp[1] = serialdata[8];

  targetIntTemp = *((int *)intTemp);
  current_Vx = float(targetIntTemp);


  intTemp[0] = serialdata[9];
  intTemp[1] = serialdata[10];

  targetIntTemp = *((int *)intTemp);
  current_Vy = float(targetIntTemp);


  intTemp[0] = serialdata[11];
  intTemp[1] = serialdata[12];

  targetIntTemp = *((int *)intTemp);
  current_omegaMini = float(targetIntTemp);


  // target values
  intTemp[0] = serialdata[13];
  intTemp[1] = serialdata[14];

  target_x = *((int *)intTemp);


  intTemp[0] = serialdata[15];
  intTemp[1] = serialdata[16];

  target_y = *((int *)intTemp);
  
  
  // batt status(1 byte), x pos(2 byte), y pos(2 byte), phi(2 byte), yawrate(2 byte)
}

void receiveEvent(int howMany)
{

  char serialdata[9] = {0,0,0,0,0,0,0,0,0};
  serialdata[0] = Wire.read();
  serialdata[1] = Wire.read();
  serialdata[2] = Wire.read();
  serialdata[3] = Wire.read();
  serialdata[4] = Wire.read();
  serialdata[5] = Wire.read();
  serialdata[6] = Wire.read();
  serialdata[7] = Wire.read();
  serialdata[8] = Wire.read();


  for(byte i=0; i<9; i++) {
    Serial.print(serialdata[i]);  
  }
  Serial.println();
  // parseSerialData(serialdata);
 
}


void sendDataToFootBrain_stopAllMoation() {
  char serialdata[5] = {0,0,0,0,0};
  serialdata[0] = 1;
  sendWirePacket(serialdata);
}

void sendDataToFootBrain_ClearCurrentPosition() {
  char serialdata[5] = {0,0,0,0,0};
  serialdata[0] = 5;
  sendWirePacket(serialdata);
}

void sendDataToFootBrain_targetPosition(int targetX, int targetY) {
  char serialdata[5] = {0,0,0,0,0};
  serialdata[0] = 4;
  serialdata[1] = lowByte(targetX); // targetX
  serialdata[2] = highByte(targetX);
  serialdata[3] = lowByte(targetY); // targetY
  serialdata[4] = highByte(targetY);
  sendWirePacket(serialdata);
}

void sendDataToFootBrain_setSpeed(float speed) {
  int tmp_speed = int(speed*100.0);
  char serialdata[5] = {0,0,0,0,0};
  serialdata[0] = 6;
  serialdata[1] = lowByte(tmp_speed); // tmp_speed
  serialdata[2] = highByte(tmp_speed);
  sendWirePacket(serialdata);
}

void sendDataToFootBrain_executeTargetValues() {
  char serialdata[5] = {0,0,0,0,0};
  serialdata[0] = 2;
  sendWirePacket(serialdata); 
}

void sendWirePacket(char sd[5]) {
  servoLock=B00000001; // enable servo lock
  delayMicroseconds(10);
  
  // sending motion command via i2c
  Wire.beginTransmission(3);
  Wire.write(sd[0]);     
  Wire.write(sd[1]);
  Wire.write(sd[2]);
  Wire.write(sd[3]);
  Wire.write(sd[4]);
  Wire.endTransmission();
  
  servoLock=B00000000; // release servo lock
}

void serialOutServoInfo() {
  serialMsg = true;
  Serial.print("servo: [");
  Serial.print(ServoValues[0]);
  Serial.print(" - ");
  Serial.print(ServoValues[1]);
  Serial.print("] ");
}


void penDown() {
  doStickMotion(0,-50,2,2);
}


void penUp() {
  doStickMotion(0,50,2,2);
}

// -------------------------------------------------------------
// stick routines

void stickPositionReadSampler() {
  // read analog joystick values
  stickHSamples[stickSampleCounter]=analogRead(Stick_H);
  if(stickSampleCounter==2) {
    stickH = (stickHSamples[0]+stickHSamples[1]+stickHSamples[2])/3;
  }

  stickVSamples[stickSampleCounter]=analogRead(Stick_V);
  if(stickSampleCounter==2) {
    stickV = (stickVSamples[0]+stickVSamples[1]+stickVSamples[2])/3;
  }

  stickSampleCounter++;
  if(stickSampleCounter>2) stickSampleCounter = 0;
}

int stickHPos() {
  return stickH-stickHCenter; 
}

int stickVPos() {
  return stickV-stickVCenter; 
}

// -------------------------------------------------------------
// basic servo motion routines


byte doStickMotion(int targetH,int targetV,int speedH, int speedV) {
  /* 
  0 = executing motion
  11 = h target postion reached
  12 = v target postion reached
  13 = h & v target position reached
  21 = while moving to h target blocked
  22 = while moving to v target blocked
  */
  byte motionResult = 0; 
  
  int deltaH = 0;
  int deltaV = 0;

  int stepH = 0;
  int stepV = 0;

  targetH = targetH+SERVO_CENTER_H;
  targetV = targetV+SERVO_CENTER_V;

  deltaH = targetH-ServoValues[1];
  if(abs(deltaH)<speedH) {
    stepH = 0;
    ServoValues[1] = targetH;
    motionResult = 11;
  } else {
    if(deltaH>0) 
      stepH = speedH;
    else
      stepH = -speedH;
  }

  deltaV = targetV-ServoValues[0];
  if(abs(deltaV)<speedV) {
    stepV = 0;
    ServoValues[0] = targetV;
    motionResult = 12;
  } else {
    if(deltaV>0) 
      stepV = speedV;
    else
      stepV = -speedV;
  }

  if(abs(deltaV)==0 && abs(deltaH)==0) {
    motionResult = 13;
  }

  // check stick collision
  if(stickHThresholdPass()!=0) motionResult = 21;
  if(stickVThresholdPass()!=0) motionResult = 22;

  // change servo value only if required
  
  if(motionResult<13) {
    ServoValues[1]+=stepH;
    ServoValues[0]+=stepV;  
  }

  return motionResult;
}


byte stickHThresholdPass() {
  byte result = 0;
  int stickPos = stickH-stickHCenter;
  if(abs(stickPos)>stickHThreshold) {
    if(stickPos>0) result = 1;
    if(stickPos<0) result = 2;
  }
  return result;
}

byte stickVThresholdPass() {
  byte result = 0;
  int stickPos = stickV-stickVCenter;
  if(abs(stickPos)>stickVThreshold) {
    if(stickPos>0) result = 1;
    if(stickPos<0) result = 2;
  }
  return result;
}



ISR(TIMER1_COMPA_vect) //TIMER1_COMPA_vect
{
  // main servo puls interrupt routine
  if(servoLock!=B00000011) { // execute only if servo unlocked. prevent generating incorrect servo impulse.  
    static int CurrentServoID = 0;
    digitalWrite(10,HIGH); // set debug pin to high
    digitalWrite(ServoIDS[CurrentServoID],LOW); // set previews servo pin to low

    if(++CurrentServoID>=NR_SERVOS) {
      CurrentServoID = 0; // next servo id increment and bound
      if(servoLock==B00000001) servoLock=B00000011;
    }

    if(servoLock==B00000000) {
      digitalWrite(ServoIDS[CurrentServoID],HIGH); // set current servo pin to high
      OCR1A = MILLISEC_BASE + ServoValues[CurrentServoID]; // set timer interrupt to set current servo pin to low
      digitalWrite(10,LOW); // set debug pin to low  
    }
    
  }
}





// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
// UIU functions



void modeSelectMode() {
  // main menu function
  byte sw = 0;

  // set LED to default menu values
  UIULedModes[0] = 1;
  UIULedModes[1] = 4;
  UIULedModes[2] = 0;
  UIULedModes[3] = 0;

  UIULedModes[4] = 0;
  UIULedModes[5] = 0;
  UIULedModes[6] = 0;
  UIULedModes[7] = 0;

  UIULedModes[8] = 0;
  UIULedModes[9] = 0;
  UIULedModes[10] = 0;
  UIULedModes[11] = 0;

  // set switch bit 
  if(UIUButtonState[2]==1) sw = sw | B00000001;
  if(UIUButtonState[3]==1) sw = sw | B00000010;
  if(UIUButtonState[4]==1) sw = sw | B00000100;

  if(UIUButtonState[1]==1) {
    // if blue enter button pressed start selected programm mode
    botMode = sw;
    UIULedModes[0] = 4;
    UIULedModes[1] = 2;
    if(sw!=0) {
      sw = sw + 1;
      UIULedModes[sw] = 2;
    }
    modeReset = 1;
  } else if(sw!=0){
    // else just set selection LED to blink
    sw = sw + 1;
    UIULedModes[sw] = 4;
  }
}

void  UIShiftRegisterSetup() {
  // set buzzer and button pin mode
  pinMode(PIN_UIU_BUZZER, OUTPUT);
  pinMode(PIN_UIU_BTN_IN, INPUT);

  // set shiftregister pin
  pinMode(SREG_DS, OUTPUT);
  pinMode(SREG_MR, OUTPUT);
  pinMode(SREG_SH, OUTPUT);
  pinMode(SREG_ST, OUTPUT);
  pinMode(SREG_OE, OUTPUT);

  // init shiftregister
  digitalWrite(SREG_DS, LOW); //LOW active
  digitalWrite(SREG_MR, HIGH); //LOW active
  digitalWrite(SREG_SH, LOW); //LOW active
  digitalWrite(SREG_ST, LOW); //LOW active
  digitalWrite(SREG_OE, LOW); //LOW active

  // reset shift register
  digitalWrite(SREG_OE, HIGH); //LOW active
  digitalWrite(SREG_MR, LOW); //LOW active
  digitalWrite(SREG_OE, LOW); //LOW active
  digitalWrite(SREG_MR, HIGH); //LOW active

  digitalWrite(SREG_DS,LOW);
  digitalWrite(SREG_SH,LOW);
  digitalWrite(SREG_ST,LOW);
}

void UIUPushRegister() {
  byte iInv = 0;
  digitalWrite(SREG_DS,LOW);
  digitalWrite(SREG_SH,LOW);
  digitalWrite(SREG_ST,LOW);

  
  for(byte i=0; i<16; i++) {
    digitalWrite(SREG_DS,LOW);
    iInv = 15-i;
    if(UIUshiftRegisterBuffer[iInv]==1) digitalWrite(SREG_DS,HIGH);
    digitalWrite(SREG_SH,HIGH);
    digitalWrite(SREG_SH,LOW);
  }
  digitalWrite(SREG_ST,LOW);
  digitalWrite(SREG_ST,HIGH);
}


void UIUMasterControler() {
  
  static byte switchRegister=0;
  

  // low to all button
  UIUshiftRegisterBuffer[SREG_INDEX_BUTTON_Blue] = 0;
  UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_1] = 0;
  UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_2] = 0;
  UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_3] = 0;
  UIUshiftRegisterBuffer[SREG_INDEX_BUTTON_Red] = 0;

  switch(switchRegister) {
    case 0: UIUshiftRegisterBuffer[SREG_INDEX_BUTTON_Blue] = 1; break;
    case 2: UIUshiftRegisterBuffer[SREG_INDEX_BUTTON_Red] = 1; break;
    case 4: UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_1] = 1; break;
    case 6: UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_2] = 1; break;
    case 8: UIUshiftRegisterBuffer[SREG_INDEX_PROGRAMM_SW_3] = 1; break;
  }



  UIUPushRegister(); 

  byte buttonState = digitalRead(PIN_UIU_BTN_IN);


  if(buttonState && switchRegister==2) {
    UIUButtonState[0] = 1;
    UIUStartBuzzerSound(3);
  } else if(switchRegister==2){
    UIUButtonState[0] = 0;
  }

  if(buttonState && switchRegister==0) {
    UIUButtonState[1] = 1;
    UIUStartBuzzerSound(4);
  } else if(switchRegister==0) {
    UIUButtonState[1] = 0;
  }


  if(buttonState && switchRegister==4) {
    UIUButtonState[2] = 1;
  } else if(switchRegister==4) {
    UIUButtonState[2] = 0;
  }


  if(buttonState && switchRegister==6) {
    UIUButtonState[3] = 1;
  } else if(switchRegister==6) {
    UIUButtonState[3] = 0;
  }

  if(buttonState && switchRegister==8) {
    UIUButtonState[4] = 1;
  } else if(switchRegister==8) {
    UIUButtonState[4] = 0;
  }

  switchRegister++;
  if(switchRegister>20) switchRegister = 0;

  UIULedControler();

  if(UIUBuzzerSound>0) UIUDoBuzzerSound();
}

// -------------------------------------------------------------
// sound subroutines

void UIUStartBuzzerSound(byte sound) {
  if(UIUBuzzerSound==0) {
    switch(sound) {
      case 1: UIUBuzzerSoundCounter = 200; break;
      case 2: UIUBuzzerSoundCounter = 1000; break;
      case 3: UIUBuzzerSoundCounter = 750; break;
      case 4: UIUBuzzerSoundCounter = 1500; break;
      case 5: UIUBuzzerSoundCounter = 500; break;
      case 6: UIUBuzzerSoundCounter = 2000; break;
    }
    UIUBuzzerSound = sound;  
  }
}

void UIUDoBuzzerSound() {
  switch(UIUBuzzerSound) {
    case 1: UIUBuzzerSoundBeep(1000); break;
    case 2: UIUBuzzerSoundBeep(50); break;
    case 3: UIUBuzzerRandom(5); break;
    case 4: UIUBuzzerRandom(10); break;
    case 5: UIUBuzzerRandom(20); break;
    case 6: UIUBuzzerPiu(); break;
  }
}


void UIUBuzzerSoundBeep(int freq) {
  if(UIUBuzzerSoundCounter%50==0) tone(PIN_UIU_BUZZER,freq,20);
  UIUBuzzerSoundCounter--;
  if(UIUBuzzerSoundCounter<0) UIUBuzzerSound = 0;
}

void UIUBuzzerPiu() {
  static int height=300;
  if(UIUBuzzerSoundCounter%5==0) {
    height-=1;
    if(height<10) height = 300;
    int t = random(5,height);
    t = t*10;
    tone(PIN_UIU_BUZZER,t,5);
  }
  UIUBuzzerSoundCounter--;
  if(UIUBuzzerSoundCounter<0) UIUBuzzerSound = 0;
}

void UIUBuzzerRandom(int baseMultiplyer) {
  if(UIUBuzzerSoundCounter%250==0) {
    int t = random(50,100);
    t = t*baseMultiplyer;
    tone(PIN_UIU_BUZZER,t,50);
  }
  UIUBuzzerSoundCounter--;
  if(UIUBuzzerSoundCounter<0) UIUBuzzerSound = 0;
}



// end: sound subroutines
// -------------------------------------------------------------



// -------------------------------------------------------------
// LED blink pattern subroutines
void UIULedControler() {
  static byte ledIndex = 0;
  static int UIU_master_led_counter = 0;

  byte LEDMode = UIULedModes[ledIndex];


  // Serial.println(UIU_master_led_counter);

  switch(LEDMode) {
    case 0: UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 0; break;
    case 1: UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 1; break;
    case 2: 
      if(UIU_master_led_counter%25==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 1; 
      if(UIU_master_led_counter%50==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 0; 
      break;
    case 3: 
      if(UIU_master_led_counter%100==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 1; 
      if(UIU_master_led_counter%200==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 0; 
      break;
    case 4: 
      if(UIU_master_led_counter%200==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 1; 
      if(UIU_master_led_counter%400==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 0; 
      break;
    case 5: 
      if(UIU_master_led_counter%200==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 1; 
      if(UIU_master_led_counter%300==0) UIUshiftRegisterBuffer[UIULedMatrix[ledIndex]] = 0; 
      break;
  }

  ledIndex++;
  if(ledIndex==12) {
    UIU_master_led_counter++;
    ledIndex = 0;
  }
}

// END: LED blink pattern subroutines
// -------------------------------------------------------------

