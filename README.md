STM32_with_ArduinoIDE 
========================================

##  硬體部分

        1.STM32F103
        2.FTDI
        3.Mini USB

## 電路連接

# 1.使用 FTDI 連 STM32F103

        FTDI_VCC --> MCU_5V
        FTDI_GND --> MCU_G
        FTDI_TXD --> MCU_A10(USART1_RX)
        FTDI_RXD --> MCU_A9(USART1_TX)

* 接腳部份有問題 請參考 tool 裡面 stm32f103 的 datasheet

### MCU TO LED

        MCU_A8(TIM1_CH1) --> 220Ω --> LED(長+) --> LED(短-) --> GND
        MCU_B6(TIM4_CH1) --> 220Ω --> LED(長+) --> LED(短-) --> GND

* 電路圖
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/FTDI_STM32_LED.png)

* 最終示意圖(圖為小編的亂中有序天橋建築工法，如有問題不負責任):
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/circuit.jpg)

## 環境建置

        1.請先下載 Arduino IDE ，並安裝好
        2.到GitHub上下載支援包
        
* [支援包傳送門](https://github.com/rogerclarkmelbourne/Arduino_STM32.git)
    
        3.下載完後請解壓縮至路徑Arduino底下，範例: C:\Arduino\hardware 底下
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/01.PNG)

        4.接著在 檔案/偏好設定 額外的開發板網址輸入: http://dan.drown.org/stm32duino/package_STM32duino_index.json
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/03.PNG)

        5.在 開發板/開發板管理員 上面輸入STM32F1 將開發包安裝
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/02.PNG)

        6.開啟Arduino IDE 在 工具/開發板 底下 便可以選擇 Generic STM32F103C series
        7.要用FTDI傳送記得 將Upload method 設為Serial
        8.(port記得連COMX，X因設備不同而異)
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/serial.png)
## 執行程式

        執行前記得將jumper放在boot0接1 進入Programming Mode
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/mode.jpg)

        執行 程式 STM32_breathing_LED.ino 就可達到我們要的呼吸燈了
        也可使用 STM32_Serial.py 和 STM32_Serial.ino 來進行通訊(因設備不同COM_PORT可能有差異，小編內設為COM8)
        記得燒錄成功後，要再燒錄別的程式前先按 RESET 。


# 2.使用 Micro USB 連 STM32F103

## 環境建置

* 記得要在 Programming Mode，FTDI 端也要連線
* 將 tool 裡面的 en.flasher-stm32.zip 解壓縮，並照預設路徑執行安裝檔案
* C:\Program Files (x86)\STMicroelectronics\Software\Flash Loader Demo 可找到執行檔 STMFlashLoader Demo.exe

        1.選擇 com_port 。

![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/com_port.PNG)

        2.接下來連點 next 直到這個畫面，第二點的 Download to device 裡面路徑選到 tool 裡面的 bin 檔。
![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/bin.png)

        3.最後 next ，讓他安裝完便可來到最後一步
        4.在 C:\Program Files (x86)\Arduino\hardware\Arduino_STM32-master\drivers\win  底下執行
        install_drivers.bat  和  install_STM_COM_drivers.bat

## Arduino IDE

### 兄弟恭喜來到最後了

* 在上述步驟都完成後，我們便可將 Mini USB 拔下來換插 MicroUSB 了 
* 切記並切換到 "" Operating Mode ""

        確認是否連接上

![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/device.png)

        最後在 Arduino IDE 上 TOOLS 裡面將 Upload method 設為 bootloader (port 記得連 COMX ， X 因設備不同而異)
        這樣就能透過 Micro USB 燒錄程式到 STM32F103 了!! Congratulations !! 


# 3.使用 ST-LINK 連 STM32F103

* 切記切換到 "" Programming Mode "" 按下RESET燒錄

         電路連接 :

         ST-Link _SWDIO  --> MCU _SWDIO
         ST-Link _GND    --> MCU _GND
         ST-Link _SWCLK  --> MCU _SWCLK
         ST-Link _3.3V   --> MCU _3.3V

         Arduino IDE 上 TOOLS 裡面將 Upload method 設為 STLink(序列埠不用設)
         即可執行程式了。

![image](https://github.com/VirtuosoRoboticsOfficial/STM32_with_ArduinoIDE/blob/master/picture/dog.jpg)