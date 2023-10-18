# Lab 2 - ESP32 GPIO and FreeRTOS task

## Mô tả

- Mục tiêu:
    + Tìm hiểu lí thuyết về FreeRTOS, FreeRTOS Task, Life cycle của một task, các phương thức làm việc với task trong ngôn ngữ lập trình và Scheduling.
    + Làm quen với GPIO trên vi điều khiển ESP32.
- Thực hiện:
    + Áp dụng lí thuyết vừa tìm hiểu hiện thực một chương trình bao gồm hai task và sử dụng FreeRTOS để lập lịch quản lí task
    + Task 1: hoạt động tuần hoàn (cyclic task) theo một chu kì nhất định.
    + Task 2: thực hiện hành động khi nhận tín hiệu từ nút nhấn (acyclic task)

## Tính năng 

- Điều khiển bật/tắt LED bằng nút nhấn

## Thông tin

- IDE sử dụng: VSCode
- Hệ điều hành: Window
- Yêu cầu: VSCode IDE: cài đặt công cụ ESP-IDF và nhúng vào terminal bằng config User Setting trong VSCode
- Chân điều khiển LED: GPIO 12
- Chân nhận tín hiệu của nút nhấn: GPIO 13 

## Cài đặt

1. Cài đặt môi trường như yêu cầu (các bước cài đặt trong file báo cáo, bỏ qua các bước gõ lệnh vào terminal)
2. Clone project về máy tính local
3. Cắm mạch vào máy tính
4. Mở project trong VSCode, chỉ đường dẫn đến folder của project trong terminal
5. Gõ lệnh "idf.py fullclean" để xóa đường dẫn cũ build chương trình của project.
6. Gõ lệnh "idf.py -p (PORT) flash monitor" vào terminal để nạp code vào mạch với (PORT) là cổng COM tương ứng


