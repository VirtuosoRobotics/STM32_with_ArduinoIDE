import serial
from time import sleep
import sys



COM_PORT = 'COM8'  # 請自行修改序列埠名稱
BAUD_RATES = 9600
ser = serial.Serial(COM_PORT, BAUD_RATES)

try:
    while True:
        # 接收用戶的輸入值並轉成小寫
        # 下面為指令部分 Ex : sdg500e 綠燈頻率改為500ms ， sdb100e 藍燈頻率改為100ms 。
        # 底下 快速鍵 能快速開關燈
        choice = input('輸入指令 sdg/b/w 000e or scg/b/w 1/0e :  ').lower() 
         
        if len(choice) > 7: 
            print ('Error! Only 7 characters allowed!')                
        elif choice == '1':
            print('傳送綠燈ON')
            ser.write(b'scg1e')
            sleep(0.5)
        elif choice == '2':
            print('傳送綠燈OFF')
            ser.write(b'scg0e')
            sleep(0.5)
        elif choice == '4':
            print('傳送藍燈ON')
            ser.write(b'scb1e')
            sleep(0.5)
        elif choice == '5':
            print('傳送藍燈OFF')
            ser.write(b'scb0e')
            sleep(0.5)
        elif choice == '7':
            print('傳送紅燈ON')
            ser.write(b'scw1e')
            sleep(0.5) 
        elif choice == '8':
            print('傳送紅燈OFF')
            ser.write(b'scw0e')
            sleep(0.5) 
        elif choice == 'e':
            ser.close()
            print('再見！')
            sys.exit()
        
        else:
            bytes_utf_8 = choice.encode(encoding="utf-8")
            sleep(0.2) 
        
            ser.write(bytes_utf_8) # 訊息必須是位元組類型
            sleep(0.2)              # 暫停0.5秒，再執行底下接收回應訊息的迴圈
        
        
        
        while ser.in_waiting:
            mcu_feedback = ser.readline().decode()  # 接收回應訊息並解碼
            print('控制板回應：', mcu_feedback)
            sleep(0.3)
            '''
            ser.close()
            sys.exit()
            '''


except KeyboardInterrupt:
    ser.close()
    print('再見！')