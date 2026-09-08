# Smart Plant Care System

An Arduino project that checks soil moisture and reacts to it automatically — LED + buzzer alert, plus a relay standing in for a water pump.

## Methodology

Tested the soil sensor's raw readings in three conditions (open air, water, soil) to get real numbers instead of guessing a threshold. Air = 1023, water = 381, soil = 533. Set the dry/wet cutoff at the midpoint of air and water — 702.

Built it one piece at a time: sensor first, then LEDs, then buzzer, then relay — testing each part before adding the next.

Logic: reading above 702 = dry (red LED, relay on, buzzer off). Reading 702 or below = wet (green LED, relay off, buzzer on).

## Parts used

Arduino Uno R3, soil moisture sensor, 1 red LED, 1 green LED, 2 resistors, piezo buzzer, relay module, breadboard, jumper wires.

## Wiring

| Component | Arduino pin |
|---|---|
| Soil sensor — AO | A0 |
| Green LED | 8 |
| Red LED | 9 |
| Buzzer | 7 |
| Relay — IN | 6 |

## Outcome

Working system that reads soil moisture in real time and gives a visual + audible alert with automatic relay switching, calibrated using my own measured values rather than copied defaults.
