# Lab 1 - Introduction to ESP32 and ESP-IDF

## Mô tả

- Mục tiêu:
  + Tìm hiểu ESP32, NodeMCU ESP32 board, FreeRTOS, ESP-IDF.
  + Làm quen với ESP32.
- Thực hiện:
  + Nạp code ví dụ "Hello world!" cho ESP32 development board qua Arduino IDE và Visual Studio Code IDE.

## Tính năng 

- In ra cửa sổ monitor chữ "Hello world!" và thông tin mạch ESP32 rồi khởi động lại mạch sau 10 giây.

## Thông tin

- IDE sử dụng: Arduino IDE (folder Arduino) và VSCode (folder VSCode)
- Hệ điều hành: Window
- Yêu cầu:
    + Arduino IDE: cài đặt thư viện "esp32 by Espressif Systems
    + VSCode IDE: cài đặt công cụ ESP-IDF và nhúng vào terminal bằng config User Setting trong VSCode

## Cài đặt

### Đối với Aruduino IDE
1. Cài đặt môi trường như yêu cầu (các bước cài đặt trong file báo cáo)
2. Clone project về máy tính local
3. Mở file .ino trong Arduino IDE
4. Cắm mạch vào máy tính, chọn board và cổng COM tương ứng
5. Nhấn build và upload trên giao diện Arduino IDE để nạp code xuống mạch
6. Chọn serial monitor, baudrate 115200 để quan sát kết quả
![Serial monitor](https://drive.google.com/file/d/1bJFrgOB3G597uSm2_N1FJSSLwh92999C/view?usp=share_link) 




