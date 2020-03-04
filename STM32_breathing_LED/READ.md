breathing_LED 
========================================

##  硬體部分

        1.STM32F103(blue pill)
        2.FTDI
        3.Mini USB
        4.Micro USB

## 電路連接


        FTDI_VCC --> MCU_5V
        FTDI_GND --> MCU_G
        FTDI_TXD --> MCU_A10(USART1_RX)
        FTDI_RXD --> MCU_A9(USART1_TX)

* 接腳部份有問題 請參考 tool 裡面 stm32f103 的 datasheet

### bluepill TO LED

        MCU_A8(TIM1_CH1) --> 220Ω --> LED(長+) --> LED(短-) --> GND
        MCU_B6(TIM4_CH1) --> 220Ω --> LED(長+) --> LED(短-) --> GND

* 電路圖
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/FTDI_STM32_LED-1.png)

* 最終示意圖(圖為小編的亂中有序天橋建築工法，如有問題不負責任):
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/circuit.jpg)

        線路接好就可以執行 程式 STM32_breathing_LED.ino 達到我們要的呼吸燈了。
