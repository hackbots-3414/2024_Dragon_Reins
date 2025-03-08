# Dragon Reins / Dragon Scales: Custom Driver and Operator controllers
## Parts
### Dragon Reins (Driver)
- Apem HF22S10 single button joystick (2)
- Arduino Pro Micro
- Razer Green Clicky Switch Gen-3 (2)

### Dragon Scales (Operator)


# button to pins

## Left Stick
| Apem Joystick Pin | Apem Wire Color | Arduino Micro Pin |
| ----------------- | --------------- | ----------------- |
| 1 | Black | GND - Left Bottom |
| 2 | Red | VCC |
| 4 | Blue | A1 |
| 6 | Yellow | A0 |
| 9 | Orange | 9 |
| 10 | White | GND - Left Top |

## Right Stick
| Apem Joystick Pin | Apem Wire Color | Arduino Micro Pin |
| ----------------- | --------------- | ----------------- |
| 1 | Black | GND  - Right | 
| 2 | Red | VCC |
| 4 | Blue | A3 |
| 6 | Yellow | A2 |
| 9 | Orange | 8 |
| 10 | White | GND - Left Top |

## Trigger Switches
| Arduino Pin | Button | Wire Color |
| ----------- | ------ | ------- |
| GND - Left Top | Left and Right common | White |
| 6 | Left trigger | Green |
| 7 | Right trigger | Green |





### scratch
- 0 -> purple, 16
- 1 -> blue, 14
- 2 -> green, 15
- 3 -> yellow, 2
- 4 -> orange, 8,9
- 2 -> red, VCC
- 


# libraries
 micheal adams "button" library
 
 the gamepad library in this repo
