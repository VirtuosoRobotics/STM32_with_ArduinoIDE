class LED {
  public:
    unsigned long last_time = 0;
    int brightness = 0;
    bool increasing = true;         //是或否 1或0
    bool breath = true;
    int breathing_delayY = 10;
    int maxbright = 225;
    int minbright = 0;
    int fadeamount = 10;
    int delaytime = 50;
    int pin;

    LED(int led_pin) {                //宣告 led_pin為整數 PIN腳輸出
      pin = led_pin;
      pinMode(pin, OUTPUT);
    }

    void lightbright() {
      if (breath) {
        if (millis() - last_time > delaytime) {           //arduino時間-最新時間>50

          if (increasing) {
            brightness = brightness + fadeamount;
          }
          else {
            brightness = brightness - fadeamount;
          }
          if (brightness > maxbright) {                 //亮度>255 執行否(0) 減亮度
            increasing = false;
            analogWrite(pin, maxbright);
          } else if (brightness < minbright) {          //亮度<0 執行是(1) 加亮度
            increasing = true;
            analogWrite(pin, minbright);
          } else {
            analogWrite(pin, brightness);
          }
          last_time = millis();                         //最新時間=arduino時間
        }
      }
      else {
        analogWrite(pin, minbright);
      }
    }
};

//
LED light_G(PA8);                             //設定10為輸出
LED light_B(PB6);                             //設定11為輸出
LED light_W(PC13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  String bb = "";                                 //bb設為字串
  String cc = "";
  String dd = "";
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {                     //序列埠有東西時便執行
    char s1 = Serial.read();                        //第一個字元s1讀取序列埠的第一個字元
    char c1;
    char x1;
    char p1;
    char p2;
    char p3;
    char e1;
    //Serial.println(s1);
    if (s1 == 's') {                              //字串第一個為s時,下列字元依序讀取
      delay(20);
      c1 = Serial.read();
      x1 = Serial.read();
      p1 = Serial.read();
      p2 = Serial.read();
      p3 = Serial.read();
      e1 = Serial.read();

      //Serial.println(c1);
      //Serial.println(x1);
      //Serial.println(p1);
      //Serial.println(p2);


      if (c1 == 'd') {
        if (e1 == 'e') {                          //先判斷字尾是否為e再判斷顏色和讀取延遲時間!!(精簡化)
          bb = bb + p1;                           //字元依序加進bb這個字串裡
          bb = bb + p2;
          bb = bb + p3;

          cc = cc + s1;
          cc = cc + c1;
          cc = cc + x1;
          cc = cc + p1;
          cc = cc + p2;
          cc = cc + p3;
          cc = cc + e1;

          Serial.println(cc);

          int new_delay_time = bb.toInt();        //宣告新變數為整數 = 將bb從字串轉為整數
          if (x1 == 'g') {                         //x1這個字元讀取到r時，變更改light_R頻率
            light_G.delaytime = new_delay_time;
          }
          if (x1 == 'b') {                          //x1這個字元讀取到y時，變更改light_G頻率
            light_B.delaytime = new_delay_time;
          }
          if (x1 == 'w') {
            light_W.delaytime = new_delay_time;
          }
        }
      }
      else if (c1 == 'c') {
        if (p2 == 'e') {                          //先判斷字尾是否為e再判斷顏色和讀取延遲時間!!(精簡化)
          dd = dd + s1;
          dd = dd + c1;
          dd = dd + x1;
          dd = dd + p1;
          dd = dd + p2;

          Serial.println(dd);

          if (x1 == 'g') {                         //x1這個字元讀取到r時，變更改light_R頻率
            if (p1 == '1') {
              light_G.breath = true;
            }
            else if (p1 == '0') {
              light_G.breath = false;
            }
          }
          if (x1 == 'b') {                          //x1這個字元讀取到y時，變更改light_G頻率
            if (p1 == '1') {
              light_B.breath = true;
            }
            else if (p1 == '0') {
              light_B.breath = false;
            }
          }
          if (x1 == 'w') {
            if (p1 == '1') {
              light_W.breath = true;
            }
            else if (p1 == '0') {
              light_W.breath = false;
            }
          }
        }
      }
    }
  }
  light_G.lightbright();             //不能該在判斷式內，應不斷執行(在Serial.available>0裡面一開始就不會亮)
  light_B.lightbright();
  light_W.lightbright();
}
