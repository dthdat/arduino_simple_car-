# Arduino Simple Car

This is a simple autonomous car built with Arduino, created for the F-Race 2023 competition. It follows a line using IR sensors and basic motor control logic.

## Features

- Line-following with IR sensors  
- DC motor control via L298N driver  
- Manual tuning for speed and direction  

## Hardware Used

- Arduino Uno  
- L298N Motor Driver  
- 2 DC motors  
- 5 IR sensors  
- Li-ion or LiPo battery  

## Getting Started

1. Clone the repo:
   ```bash
   git clone https://github.com/dthdat/arduino_simple_car-.git
   ```

2. Open `robot111.ino` in the Arduino IDE.  

3. Upload to Arduino Uno.  

4. Power the motors and place the car on a black line track.

## Notes

- Code is written for a specific sensor layout (5 IR sensors).  
- Tuning is manual—no PID or advanced control.  
- Built and tested under competition constraints.

## License

MIT License.


## Image
![Robot Car](/xe.jpg)
