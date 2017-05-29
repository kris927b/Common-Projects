EESchema Schematic File Version 2
LIBS:amplifier-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:amplifier_lib
LIBS:amplifier-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATmega328P_XplainedMini U2
U 1 1 58F9BD38
P 5150 3550
F 0 "U2" H 4800 5800 60  0000 C CNN
F 1 "ATmega328P_XplainedMini" H 4800 3350 60  0000 C CNN
F 2 "xplainedBrd:xplained_board" H 5150 3550 60  0001 C CNN
F 3 "" H 5150 3550 60  0001 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
$Sheet
S 7250 4150 950  1500
U 58F9CBF8
F0 "analogCircuit" 60
F1 "analogCircuit.sch" 60
F2 "LEFT_IN" I L 7250 4350 60 
F3 "RIGHT_IN" I L 7250 4500 60 
F4 "CS_0" I L 7250 4700 60 
F5 "CS_1" I L 7250 4850 60 
F6 "CS_2" I L 7250 5000 60 
F7 "MOSI" I L 7250 5300 60 
F8 "SCK" I L 7250 5450 60 
F9 "CS_3" I L 7250 5150 60 
F10 "LEFT_OUT" I R 8200 5300 60 
F11 "RIGHT_OUT" I R 8200 5450 60 
$EndSheet
$Comp
L MCCOG21605D U3
U 1 1 58FDA076
P 8700 2800
F 0 "U3" H 7750 4300 60  0000 C CNN
F 1 "MCCOG21605D" H 7750 3200 60  0000 C CNN
F 2 "LCD:MCCOG21605D" H 8700 2800 60  0001 C CNN
F 3 "" H 8700 2800 60  0001 C CNN
	1    8700 2800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR10
U 1 1 58FDA171
P 5650 3700
F 0 "#PWR10" H 5650 3550 50  0001 C CNN
F 1 "+5V" H 5650 3840 50  0000 C CNN
F 2 "" H 5650 3700 50  0000 C CNN
F 3 "" H 5650 3700 50  0000 C CNN
	1    5650 3700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR7
U 1 1 58FDA1A5
P 3950 3700
F 0 "#PWR7" H 3950 3550 50  0001 C CNN
F 1 "+5V" H 3950 3840 50  0000 C CNN
F 2 "" H 3950 3700 50  0000 C CNN
F 3 "" H 3950 3700 50  0000 C CNN
	1    3950 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 58FDA1DB
P 5800 3550
F 0 "#PWR11" H 5800 3300 50  0001 C CNN
F 1 "GND" H 5800 3400 50  0000 C CNN
F 2 "" H 5800 3550 50  0000 C CNN
F 3 "" H 5800 3550 50  0000 C CNN
	1    5800 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR5
U 1 1 58FDA1F3
P 3800 3550
F 0 "#PWR5" H 3800 3300 50  0001 C CNN
F 1 "GND" H 3800 3400 50  0000 C CNN
F 2 "" H 3800 3550 50  0000 C CNN
F 3 "" H 3800 3550 50  0000 C CNN
	1    3800 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3700 3950 3750
Wire Wire Line
	3950 3750 4050 3750
Wire Wire Line
	4050 3750 4050 3550
Wire Wire Line
	4050 3550 4100 3550
Wire Wire Line
	5500 3550 5550 3550
Wire Wire Line
	5550 3550 5550 3750
Wire Wire Line
	5550 3750 5650 3750
Wire Wire Line
	5650 3750 5650 3700
Wire Wire Line
	5800 3550 5800 3450
Wire Wire Line
	5800 3450 5500 3450
Wire Wire Line
	4100 3450 3800 3450
Wire Wire Line
	3800 3450 3800 3550
$Comp
L +5V #PWR13
U 1 1 58FDA28A
P 7200 2050
F 0 "#PWR13" H 7200 1900 50  0001 C CNN
F 1 "+5V" H 7200 2190 50  0000 C CNN
F 2 "" H 7200 2050 50  0000 C CNN
F 3 "" H 7200 2050 50  0000 C CNN
	1    7200 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2050 7200 2100
Wire Wire Line
	7200 2100 7250 2100
$Comp
L BC547 Q1
U 1 1 58FDA2B5
P 7050 2500
F 0 "Q1" H 7250 2575 50  0000 L CNN
F 1 "BC547" H 7250 2500 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 7250 2425 50  0000 L CIN
F 3 "" H 7050 2500 50  0000 L CNN
	1    7050 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2300 7150 2200
Wire Wire Line
	7150 2200 7250 2200
$Comp
L GND #PWR12
U 1 1 58FDA342
P 7150 3100
F 0 "#PWR12" H 7150 2850 50  0001 C CNN
F 1 "GND" H 7150 2950 50  0000 C CNN
F 2 "" H 7150 3100 50  0000 C CNN
F 3 "" H 7150 3100 50  0000 C CNN
	1    7150 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2700 7150 2750
Wire Wire Line
	6800 3000 6800 2500
Wire Wire Line
	6800 2500 6850 2500
Wire Wire Line
	8250 1500 8400 1500
Wire Wire Line
	8400 1400 8400 2200
Wire Wire Line
	8400 1800 8250 1800
Wire Wire Line
	8400 2200 8250 2200
Connection ~ 8400 1800
Connection ~ 8400 1500
$Comp
L +5V #PWR14
U 1 1 58FDA483
P 8400 1400
F 0 "#PWR14" H 8400 1250 50  0001 C CNN
F 1 "+5V" H 8400 1540 50  0000 C CNN
F 2 "" H 8400 1400 50  0000 C CNN
F 3 "" H 8400 1400 50  0000 C CNN
	1    8400 1400
	1    0    0    -1  
$EndComp
NoConn ~ 8250 1600
NoConn ~ 8250 1700
$Comp
L GND #PWR15
U 1 1 58FDA4AE
P 8550 1950
F 0 "#PWR15" H 8550 1700 50  0001 C CNN
F 1 "GND" H 8550 1800 50  0000 C CNN
F 2 "" H 8550 1950 50  0000 C CNN
F 3 "" H 8550 1950 50  0000 C CNN
	1    8550 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1900 8550 1900
Wire Wire Line
	8550 1900 8550 1950
Wire Wire Line
	8250 2100 8300 2100
Wire Wire Line
	8300 2100 8300 3000
Wire Wire Line
	8250 2000 8350 2000
Wire Wire Line
	8350 2000 8350 2850
$Comp
L R R3
U 1 1 58FDA595
P 8550 2400
F 0 "R3" V 8630 2400 50  0000 C CNN
F 1 "2.7k" V 8550 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8480 2400 50  0001 C CNN
F 3 "" H 8550 2400 50  0000 C CNN
	1    8550 2400
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 58FDA5C4
P 8550 2600
F 0 "R4" V 8630 2600 50  0000 C CNN
F 1 "2.7k" V 8550 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8480 2600 50  0001 C CNN
F 3 "" H 8550 2600 50  0000 C CNN
	1    8550 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 2400 8350 2400
Connection ~ 8350 2400
Wire Wire Line
	8400 2600 8300 2600
Connection ~ 8300 2600
Wire Wire Line
	8800 2600 8700 2600
Wire Wire Line
	8800 2300 8800 2600
Wire Wire Line
	8800 2400 8700 2400
Connection ~ 8800 2400
$Comp
L +5V #PWR16
U 1 1 58FDA6E1
P 8800 2300
F 0 "#PWR16" H 8800 2150 50  0001 C CNN
F 1 "+5V" H 8800 2440 50  0000 C CNN
F 2 "" H 8800 2300 50  0000 C CNN
F 3 "" H 8800 2300 50  0000 C CNN
	1    8800 2300
	1    0    0    -1  
$EndComp
Text GLabel 8450 2850 2    60   Input ~ 0
SDA
Text GLabel 8450 3000 2    60   Input ~ 0
SCL
Wire Wire Line
	8350 2850 8450 2850
Wire Wire Line
	8300 3000 8450 3000
Text GLabel 5700 1650 2    60   Output ~ 0
SDA
Text GLabel 5700 1500 2    60   Output ~ 0
SCL
Wire Wire Line
	5500 1650 5700 1650
Wire Wire Line
	5500 1550 5500 1550
Wire Wire Line
	5500 1550 5700 1500
Wire Wire Line
	5700 1500 5700 1500
$Comp
L EC12E1240405 U1
U 1 1 58FDA909
P 2850 3200
F 0 "U1" H 2850 3800 60  0000 C CNN
F 1 "EC12E1240405" H 2850 3200 60  0000 C CNN
F 2 "rotary:Encoder EC12E" H 2850 3200 60  0001 C CNN
F 3 "" H 2850 3200 60  0001 C CNN
	1    2850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2800 4100 2800
Wire Wire Line
	3200 2900 4100 2900
Wire Wire Line
	3200 3000 3850 3000
Wire Wire Line
	3850 3000 3850 3050
$Comp
L GND #PWR6
U 1 1 58FDAA6B
P 3850 3050
F 0 "#PWR6" H 3850 2800 50  0001 C CNN
F 1 "GND" H 3850 2900 50  0000 C CNN
F 2 "" H 3850 3050 50  0000 C CNN
F 3 "" H 3850 3050 50  0000 C CNN
	1    3850 3050
	1    0    0    -1  
$EndComp
Text GLabel 5850 2450 2    60   Output ~ 0
CS_0
Wire Wire Line
	5500 2450 5850 2450
Text GLabel 5550 2350 2    60   Output ~ 0
CS_1
Text GLabel 5850 2250 2    60   Output ~ 0
CS_2
Wire Wire Line
	5500 2350 5550 2350
Wire Wire Line
	5500 2250 5850 2250
Text GLabel 5550 2150 2    60   Output ~ 0
MOSI
Text GLabel 5550 1950 2    60   Output ~ 0
SCK
Wire Wire Line
	5550 1950 5500 1950
Wire Wire Line
	5500 2150 5550 2150
Text GLabel 7100 4700 0    60   Input ~ 0
CS_0
Text GLabel 7100 4850 0    60   Input ~ 0
CS_1
Text GLabel 7100 5000 0    60   Input ~ 0
CS_2
Text GLabel 7100 5300 0    60   Input ~ 0
MOSI
Text GLabel 7100 5450 0    60   Input ~ 0
SCK
Wire Wire Line
	7100 4700 7250 4700
Wire Wire Line
	7100 4850 7250 4850
Wire Wire Line
	7100 5000 7250 5000
Wire Wire Line
	7100 5300 7250 5300
Wire Wire Line
	7100 5450 7250 5450
$Comp
L R R1
U 1 1 5900779A
P 6550 3000
F 0 "R1" V 6630 3000 50  0000 C CNN
F 1 "5K6" V 6550 3000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6480 3000 50  0001 C CNN
F 3 "" H 6550 3000 50  0000 C CNN
	1    6550 3000
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5900780C
P 7150 2900
F 0 "R2" V 7230 2900 50  0000 C CNN
F 1 "47R" V 7150 2900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7080 2900 50  0001 C CNN
F 3 "" H 7150 2900 50  0000 C CNN
	1    7150 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	6700 3000 6800 3000
Wire Wire Line
	6400 3000 5500 3000
Wire Wire Line
	7150 3050 7150 3100
Text GLabel 7100 5150 0    60   Input ~ 0
CS_3
Wire Wire Line
	7100 5150 7250 5150
$Comp
L JACK_2P J2
U 1 1 590ACC54
P 4450 5650
F 0 "J2" H 4100 5450 50  0000 C CNN
F 1 "JACK_2P" H 4300 5900 50  0000 C CNN
F 2 "conektor:JACK_3,5mm_5pin" H 4450 5650 50  0001 C CNN
F 3 "" H 4450 5650 50  0000 C CNN
	1    4450 5650
	1    0    0    -1  
$EndComp
$Comp
L JACK_2P J1
U 1 1 590ACD64
P 4450 4800
F 0 "J1" H 4100 4600 50  0000 C CNN
F 1 "JACK_2P" H 4300 5050 50  0000 C CNN
F 2 "conektor:JACK_3,5mm_5pin" H 4450 4800 50  0001 C CNN
F 3 "" H 4450 4800 50  0000 C CNN
	1    4450 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 590ACE57
P 5100 5100
F 0 "#PWR8" H 5100 4850 50  0001 C CNN
F 1 "GND" H 5100 4950 50  0000 C CNN
F 2 "" H 5100 5100 50  0000 C CNN
F 3 "" H 5100 5100 50  0000 C CNN
	1    5100 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5850 5100 5850
Text GLabel 5300 4600 2    60   Output ~ 0
LEFT_IN
Text GLabel 5300 4900 2    60   Output ~ 0
RIGHT_IN
Text GLabel 5300 5450 2    60   Input ~ 0
LEFT_OUT
Text GLabel 5300 5750 2    60   Input ~ 0
RIGHT_OUT
Wire Wire Line
	4900 5450 5300 5450
Wire Wire Line
	4900 5750 5300 5750
Wire Wire Line
	4900 4900 5300 4900
Wire Wire Line
	4900 4600 5300 4600
Text GLabel 7100 4350 0    60   Input ~ 0
LEFT_IN
Text GLabel 7100 4500 0    60   Input ~ 0
RIGHT_IN
Wire Wire Line
	7100 4350 7250 4350
Wire Wire Line
	7100 4500 7250 4500
Text GLabel 8350 5300 2    60   Output ~ 0
LEFT_OUT
Text GLabel 8350 5450 2    60   Output ~ 0
RIGHT_OUT
Wire Wire Line
	8200 5300 8350 5300
Wire Wire Line
	8200 5450 8350 5450
Text GLabel 5850 2050 2    60   Output ~ 0
CS_3
Wire Wire Line
	5850 2050 5500 2050
$Comp
L R R31
U 1 1 591A09C4
P 3300 2550
F 0 "R31" V 3380 2550 50  0000 C CNN
F 1 "200K" V 3300 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3230 2550 50  0001 C CNN
F 3 "" H 3300 2550 50  0000 C CNN
	1    3300 2550
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 591A0A3C
P 3550 2550
F 0 "R32" V 3630 2550 50  0000 C CNN
F 1 "200K" V 3550 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3480 2550 50  0001 C CNN
F 3 "" H 3550 2550 50  0000 C CNN
	1    3550 2550
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 591A0ACE
P 3300 3250
F 0 "C9" H 3325 3350 50  0000 L CNN
F 1 "100n" H 3325 3150 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 3338 3100 50  0001 C CNN
F 3 "" H 3300 3250 50  0000 C CNN
	1    3300 3250
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 591A0B5E
P 3550 3250
F 0 "C10" H 3575 3350 50  0000 L CNN
F 1 "100n" H 3575 3150 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 3588 3100 50  0001 C CNN
F 3 "" H 3550 3250 50  0000 C CNN
	1    3550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2700 3300 3100
Connection ~ 3300 2800
Wire Wire Line
	3550 2700 3550 3100
Connection ~ 3550 2900
$Comp
L +5V #PWR1
U 1 1 591A12C0
P 3300 2300
F 0 "#PWR1" H 3300 2150 50  0001 C CNN
F 1 "+5V" H 3300 2440 50  0000 C CNN
F 2 "" H 3300 2300 50  0000 C CNN
F 3 "" H 3300 2300 50  0000 C CNN
	1    3300 2300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR3
U 1 1 591A1338
P 3550 2300
F 0 "#PWR3" H 3550 2150 50  0001 C CNN
F 1 "+5V" H 3550 2440 50  0000 C CNN
F 2 "" H 3550 2300 50  0000 C CNN
F 3 "" H 3550 2300 50  0000 C CNN
	1    3550 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2300 3550 2400
Wire Wire Line
	3300 2300 3300 2400
$Comp
L GND #PWR4
U 1 1 591A14C6
P 3550 3550
F 0 "#PWR4" H 3550 3300 50  0001 C CNN
F 1 "GND" H 3550 3400 50  0000 C CNN
F 2 "" H 3550 3550 50  0000 C CNN
F 3 "" H 3550 3550 50  0000 C CNN
	1    3550 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 591A153E
P 3300 3550
F 0 "#PWR2" H 3300 3300 50  0001 C CNN
F 1 "GND" H 3300 3400 50  0000 C CNN
F 2 "" H 3300 3550 50  0000 C CNN
F 3 "" H 3300 3550 50  0000 C CNN
	1    3300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3550 3300 3400
Wire Wire Line
	3550 3400 3550 3550
$Comp
L GND #PWR9
U 1 1 591A4F37
P 5100 5950
F 0 "#PWR9" H 5100 5700 50  0001 C CNN
F 1 "GND" H 5100 5800 50  0000 C CNN
F 2 "" H 5100 5950 50  0000 C CNN
F 3 "" H 5100 5950 50  0000 C CNN
	1    5100 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 5850 5100 5950
Wire Wire Line
	5100 5100 5100 5000
Wire Wire Line
	5100 5000 4900 5000
$Comp
L CONN_01X04 P1
U 1 1 591A6C25
P 5050 6800
F 0 "P1" H 5050 7050 50  0000 C CNN
F 1 "CONN_01X04" V 5150 6800 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 5050 6800 50  0001 C CNN
F 3 "" H 5050 6800 50  0000 C CNN
	1    5050 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR19
U 1 1 591A6E40
P 4750 7050
F 0 "#PWR19" H 4750 6800 50  0001 C CNN
F 1 "GND" H 4750 6900 50  0000 C CNN
F 2 "" H 4750 7050 50  0000 C CNN
F 3 "" H 4750 7050 50  0000 C CNN
	1    4750 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 6950 4750 6950
Wire Wire Line
	4750 6950 4750 7050
Wire Wire Line
	4850 6850 4500 6850
$Comp
L -12VA #PWR17
U 1 1 591A707E
P 4600 6550
F 0 "#PWR17" H 4600 6400 50  0001 C CNN
F 1 "-12VA" H 4600 6690 50  0000 C CNN
F 2 "" H 4600 6550 50  0000 C CNN
F 3 "" H 4600 6550 50  0000 C CNN
	1    4600 6550
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR18
U 1 1 591A7119
P 4750 6450
F 0 "#PWR18" H 4750 6300 50  0001 C CNN
F 1 "+12V" H 4750 6590 50  0000 C CNN
F 2 "" H 4750 6450 50  0000 C CNN
F 3 "" H 4750 6450 50  0000 C CNN
	1    4750 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 6450 4750 6650
Wire Wire Line
	4750 6650 4850 6650
Wire Wire Line
	4600 6550 4600 6750
Wire Wire Line
	4600 6750 4850 6750
Text GLabel 4500 6850 0    60   Output ~ 0
VIN_5V
Text GLabel 4050 2650 0    60   Input ~ 0
VIN_5V
Wire Wire Line
	4050 2650 4100 2650
NoConn ~ 4900 4700
NoConn ~ 4900 4800
NoConn ~ 4900 5550
NoConn ~ 4900 5650
NoConn ~ 4100 1500
NoConn ~ 4100 1600
NoConn ~ 4100 2050
NoConn ~ 4100 2150
NoConn ~ 4100 2250
NoConn ~ 4100 2350
NoConn ~ 4100 2450
NoConn ~ 4100 2550
NoConn ~ 4100 3000
NoConn ~ 4100 3100
NoConn ~ 4100 3200
NoConn ~ 4100 3300
NoConn ~ 5500 3300
NoConn ~ 5500 3200
NoConn ~ 5500 3100
NoConn ~ 5500 2900
NoConn ~ 5500 2800
NoConn ~ 5500 2700
NoConn ~ 5500 2600
NoConn ~ 5500 1850
NoConn ~ 5500 1750
$EndSCHEMATC
