# Dragon Reins / Dragon Scales: Custom Driver and Operator controllers
### Dragon Reins (Driver)
- Apem HF22S10 single button joystick (2)
- Apem 505-442 Switch Hardware HARNESS HF BUTTONS & DUAL (2) 
- SparkFun Electronics DEV-12640 Arduino Pro Micro

### Dragon Scales (Operator)
- Raspberry Pi Pico (original - 2020 series)
- Twidec Rocker Toggle Switch 12V / 20A Red LED Light (ASW-07DRRMZ)
- Custom printed circuit board (PCB)

### Shared
- Razer B0CCG8J9NR Green Clicky Switch Gen-3
- Razer B0973PKNRW Phantom Keycap Upgrade Set: Unique Stealth Design - Black
# button to pins

## Left Stick
| Apem Joystick Pin | Apem Wire Color | Arduino Micro Pin |
| ----------------- | --------------- | ----------------- |
| 1 | Black | GND - Right |
| 2 | Red | VCC |
| 4 | Blue | A1 |
| 6 | Yellow | A0 |
| 9 | Orange | 9 |
| 10 | White | GND - Left Bottom |

## Right Stick
| Apem Joystick Pin | Apem Wire Color | Arduino Micro Pin |
| ----------------- | --------------- | ----------------- |
| 1 | Black | GND  - Right | 
| 2 | Red | VCC |
| 4 | Blue | A3 |
| 6 | Yellow | A2 |
| 9 | Orange | 16 |
| 10 | White | GND - Left Bottom |

## Trigger Switches
| Arduino Pin | Button | Wire Color |
| ----------- | ------ | ------- |
| GND Left-Bottom | Left and Right common | White |
| 5 | Left trigger | Green |
| 4 | Right trigger | Green |





### scratch
- 0 -> purple, 16
- 1 -> blue, 14
- 2 -> green, 15
- 3 -> yellow, 2
- 4 -> orange, 8,9
- 2 -> red, VCC
- 


# libraries
- micheal adams "button" library
- the gamepad library in this repo
