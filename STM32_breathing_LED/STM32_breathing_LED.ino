#include <math.h>

int brightness1 = 0;               //亮度
int fadeAmount1 = 5;               //亮度增幅值
int brightness2 = 0;
int fadeAmount2 = 5;
int brightness3 = 255;
int fadeAmount3 = 255;
int save1 = 0;                    //時間保留值
int times1 = 0 ;                  //頻率
int save2 = 0;
int times2 = 0 ;
int save3 = 0;
int times3 = 0 ;

void setup()  {
  Serial.begin(115200);   //序列埠傳輸速率設為115200
  pinMode(PA8, OUTPUT);    //GREEN
  pinMode(PB6, OUTPUT);    //BLUE
  pinMode(PC13, OUTPUT);    //default
}

void loop()  {
  times1 = millis() - save1 ;                                 //時間差(頻率) = 現在Arduino時間 - 上次保留時間
  times2 = millis() - save2 ;
  times3 = millis() - save3 ;

  if (times1 >= 10) {                                         //頻率設30ms
    if (brightness1 <= 0 || brightness1 >= 255  ) {           //假如當亮度小等於0或者大等於255
      fadeAmount1 = -fadeAmount1 ;                            //將亮度增幅值加上負號，使值能在0~255內
    }
    brightness1 = brightness1 + fadeAmount1;                  //增加亮度

    if (brightness1 > 255) {                                  //設保護值，當亮度大於255時，就直接等於255，以避免亮度值爆表造成LED有不正常閃光
      brightness1 = 255;
    }
    if (brightness1 < 0) {                                    //設保護值，當亮度小PA於0時，就直接等於0，以避免亮度值爆表造成LED有不正常閃光
      brightness1 = 0;
    }
    analogWrite(PA8, brightness1);                             //設輸出PIN10的值為亮度值
    Serial.println(brightness1);                            //序列埠印出亮度值
    save1 = millis() ;                                        //保留時間 = 現在Arduino時間
  }

  if (times2 >= 20) {
    if (brightness2 <= 0 || brightness2 >= 255 ) {
      fadeAmount2 = -fadeAmount2 ;
    }
    if (brightness2 > 255) {
      brightness2 = 255;
    }
    if (brightness2 < 0) {
      brightness2 = 0;
    }
    brightness2 = brightness2 + fadeAmount2;
    analogWrite(PB6, brightness2);
    save2 = millis() ;
  }

  if (times3 >= 500) {
    if (brightness3 <= 0 || brightness3 >= 255 ) {
      fadeAmount3 = -fadeAmount3 ;
    }
    if (brightness3 > 255) {
      brightness3 = 255;
    }
    if (brightness3 < 0) {
      brightness3 = 0;
    }
    brightness3 = brightness3 + fadeAmount3;
    digitalWrite(PC13, brightness3);
    save3 = millis() ;
  }
}
