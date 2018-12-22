EESchema Schematic File Version 4
LIBS:QI_Charger-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 10 11
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
L Custom_Library:NXQ1TXH5_101J U?
U 1 1 5C1EA6C0
P 5330 3430
F 0 "U?" H 6230 2380 50  0000 R CNN
F 1 "NXQ1TXH5_101J" H 5330 3430 50  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-32-1EP_5x5mm_Pitch0.5mm" H 5330 3430 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/NXP%20PDFs/NXQ1TXH5.pdf" H 5330 3430 50  0001 C CNN
F 4 "568-12937-1-ND" H 5330 3430 50  0001 C CNN "Digi-Key PN"
	1    5330 3430
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1EA743
P 5330 4610
F 0 "#PWR?" H 5330 4360 50  0001 C CNN
F 1 "GND" H 5330 4460 50  0000 C CNN
F 2 "" H 5330 4610 50  0001 C CNN
F 3 "" H 5330 4610 50  0001 C CNN
	1    5330 4610
	1    0    0    -1  
$EndComp
Wire Wire Line
	5330 4610 5330 4570
Wire Wire Line
	5330 4570 5280 4570
Wire Wire Line
	5080 4570 5080 4530
Wire Wire Line
	5330 4570 5380 4570
Wire Wire Line
	5580 4570 5580 4530
Connection ~ 5330 4570
Wire Wire Line
	5180 4530 5180 4570
Connection ~ 5180 4570
Wire Wire Line
	5180 4570 5080 4570
Wire Wire Line
	5280 4530 5280 4570
Connection ~ 5280 4570
Wire Wire Line
	5280 4570 5180 4570
Wire Wire Line
	5380 4530 5380 4570
Connection ~ 5380 4570
Wire Wire Line
	5380 4570 5480 4570
Wire Wire Line
	5480 4530 5480 4570
Connection ~ 5480 4570
Wire Wire Line
	5480 4570 5580 4570
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1EAF55
P 3770 4600
AR Path="/5BB27BA3/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5BB27BB5/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5BB27BF7/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5C1DE17A/5C1EAF55" Ref="C?"  Part="1" 
AR Path="/5C1E3A0B/5C1EAF55" Ref="C?"  Part="1" 
F 0 "C?" H 3795 4700 50  0000 L CNN
F 1 "0.1uF" H 3795 4500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3808 4450 50  0001 C CNN
F 3 "" H 3795 4700 50  0001 C CNN
F 4 "0603" H 3620 4700 50  0000 R CNN "display_footprint"
F 5 "50V" H 3620 4600 50  0000 R CNN "Voltage"
F 6 "X7R" H 3620 4500 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 4195 5100 60  0001 C CNN "Digi-Key PN"
	1    3770 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1EAFD9
P 3770 4750
F 0 "#PWR?" H 3770 4500 50  0001 C CNN
F 1 "GND" H 3770 4600 50  0000 C CNN
F 2 "" H 3770 4750 50  0001 C CNN
F 3 "" H 3770 4750 50  0001 C CNN
	1    3770 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1F071E
P 4290 4370
F 0 "#PWR?" H 4290 4120 50  0001 C CNN
F 1 "GND" H 4290 4220 50  0000 C CNN
F 2 "" H 4290 4370 50  0001 C CNN
F 3 "" H 4290 4370 50  0001 C CNN
	1    4290 4370
	1    0    0    -1  
$EndComp
Wire Wire Line
	4290 4370 4290 4330
Wire Wire Line
	4290 4330 4330 4330
Text GLabel 4330 3930 0    50   UnSpc ~ 0
QI_OSC_1
Text GLabel 4330 4030 0    50   UnSpc ~ 0
QI_OSC_2
Wire Wire Line
	4330 4230 3770 4230
Wire Wire Line
	3770 4230 3770 4450
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F1D43
P 2950 4600
AR Path="/5BB27BA3/5C1F1D43" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F1D43" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F1D43" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F1D43" Ref="R?"  Part="1" 
F 0 "R?" H 2870 4600 50  0000 R CNN
F 1 "10k" V 2950 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2950 4600 50  0001 C CNN
F 3 "" H 2950 4600 50  0001 C CNN
F 4 "0603" H 3050 4680 50  0000 L CNN "display_footprint"
F 5 "1%" H 3050 4600 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3060 4520 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 3250 5000 60  0001 C CNN "Digi-Key PN"
	1    2950 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1F1ECF
P 2950 4750
F 0 "#PWR?" H 2950 4500 50  0001 C CNN
F 1 "GND" H 2950 4600 50  0000 C CNN
F 2 "" H 2950 4750 50  0001 C CNN
F 3 "" H 2950 4750 50  0001 C CNN
	1    2950 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4450 2950 4130
Wire Wire Line
	2950 4130 4330 4130
Text GLabel 2870 4130 0    50   Input ~ 0
QI_STANDBY
Wire Wire Line
	2870 4130 2950 4130
Connection ~ 2950 4130
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1F27FA
P 1030 3160
AR Path="/5BB27BA3/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5BB27BB5/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5BB27BF7/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5C1DE17A/5C1F27FA" Ref="C?"  Part="1" 
AR Path="/5C1E3A0B/5C1F27FA" Ref="C?"  Part="1" 
F 0 "C?" H 1055 3260 50  0000 L CNN
F 1 "1nF" H 1055 3060 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1068 3010 50  0001 C CNN
F 3 "" H 1055 3260 50  0001 C CNN
F 4 "478-1215-1-ND" H 1455 3660 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 880 3260 50  0000 R CNN "display_footprint"
F 6 "50V" H 880 3160 50  0000 R CNN "Voltage"
F 7 "X7R" H 880 3060 50  0000 R CNN "Dielectric"
	1    1030 3160
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F2A56
P 4030 3160
AR Path="/5BB27BA3/5C1F2A56" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F2A56" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F2A56" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F2A56" Ref="R?"  Part="1" 
F 0 "R?" H 3950 3160 50  0000 R CNN
F 1 "R" V 4030 3160 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4030 3160 50  0001 C CNN
F 3 "" H 4030 3160 50  0001 C CNN
F 4 "0603" H 4130 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 4130 3160 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4140 3080 50  0000 L CNN "Wattage"
F 7 "" H 4330 3560 60  0001 C CNN "Digi-Key PN"
	1    4030 3160
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F2AEE
P 3280 3160
AR Path="/5BB27BA3/5C1F2AEE" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F2AEE" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F2AEE" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F2AEE" Ref="R?"  Part="1" 
F 0 "R?" H 3200 3160 50  0000 R CNN
F 1 "R" V 3280 3160 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3280 3160 50  0001 C CNN
F 3 "" H 3280 3160 50  0001 C CNN
F 4 "0603" H 3380 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 3380 3160 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3390 3080 50  0000 L CNN "Wattage"
F 7 "" H 3580 3560 60  0001 C CNN "Digi-Key PN"
	1    3280 3160
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F2C1E
P 2530 3160
AR Path="/5BB27BA3/5C1F2C1E" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F2C1E" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F2C1E" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F2C1E" Ref="R?"  Part="1" 
F 0 "R?" H 2450 3160 50  0000 R CNN
F 1 "R" V 2530 3160 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2530 3160 50  0001 C CNN
F 3 "" H 2530 3160 50  0001 C CNN
F 4 "0603" H 2630 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 2630 3160 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2640 3080 50  0000 L CNN "Wattage"
F 7 "" H 2830 3560 60  0001 C CNN "Digi-Key PN"
	1    2530 3160
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F2C29
P 1780 3160
AR Path="/5BB27BA3/5C1F2C29" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F2C29" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F2C29" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F2C29" Ref="R?"  Part="1" 
F 0 "R?" H 1700 3160 50  0000 R CNN
F 1 "R" V 1780 3160 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1780 3160 50  0001 C CNN
F 3 "" H 1780 3160 50  0001 C CNN
F 4 "0603" H 1880 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 1880 3160 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1890 3080 50  0000 L CNN "Wattage"
F 7 "" H 2080 3560 60  0001 C CNN "Digi-Key PN"
	1    1780 3160
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1F578B
P 1030 3310
F 0 "#PWR?" H 1030 3060 50  0001 C CNN
F 1 "GND" H 1030 3160 50  0000 C CNN
F 2 "" H 1030 3310 50  0001 C CNN
F 3 "" H 1030 3310 50  0001 C CNN
	1    1030 3310
	1    0    0    -1  
$EndComp
Wire Wire Line
	4330 3530 4030 3530
Wire Wire Line
	4030 3530 4030 3310
Wire Wire Line
	4330 3630 3280 3630
Wire Wire Line
	3280 3630 3280 3310
Wire Wire Line
	4330 3730 2530 3730
Wire Wire Line
	2530 3730 2530 3310
Wire Wire Line
	4330 3830 1780 3830
Wire Wire Line
	1780 3830 1780 3310
Wire Wire Line
	1030 3010 1030 2930
Wire Wire Line
	1030 2930 1780 2930
Wire Wire Line
	4030 3010 4030 2930
Connection ~ 4030 2930
Wire Wire Line
	4030 2930 4330 2930
Wire Wire Line
	3280 3010 3280 2930
Connection ~ 3280 2930
Wire Wire Line
	3280 2930 4030 2930
Wire Wire Line
	2530 3010 2530 2930
Connection ~ 2530 2930
Wire Wire Line
	2530 2930 3280 2930
Wire Wire Line
	1780 3010 1780 2930
Connection ~ 1780 2930
Wire Wire Line
	1780 2930 2530 2930
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1F8C36
P 1030 2700
AR Path="/5BB27BA3/5C1F8C36" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1F8C36" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1F8C36" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1F8C36" Ref="R?"  Part="1" 
F 0 "R?" H 950 2700 50  0000 R CNN
F 1 "R" V 1030 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1030 2700 50  0001 C CNN
F 3 "" H 1030 2700 50  0001 C CNN
F 4 "0603" H 1130 2780 50  0000 L CNN "display_footprint"
F 5 "1%" H 1130 2700 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1140 2620 50  0000 L CNN "Wattage"
F 7 "" H 1330 3100 60  0001 C CNN "Digi-Key PN"
	1    1030 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1030 2850 1030 2930
Connection ~ 1030 2930
$Comp
L power:+5V #PWR?
U 1 1 5C1F946A
P 1030 2550
F 0 "#PWR?" H 1030 2400 50  0001 C CNN
F 1 "+5V" H 1030 2690 50  0000 C CNN
F 2 "" H 1030 2550 50  0001 C CNN
F 3 "" H 1030 2550 50  0001 C CNN
	1    1030 2550
	1    0    0    -1  
$EndComp
Text GLabel 4330 2630 0    50   Output ~ 0
QI_LED_R
Text GLabel 4330 2730 0    50   Output ~ 0
QI_LED_G
Text GLabel 4330 2830 0    50   Output ~ 0
QI_LED_BUZZ
Text GLabel 4330 2530 0    50   Input ~ 0
QI_NTC
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1FA6E7
P 6740 4920
AR Path="/5BB27BA3/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5BB27BB5/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5BB27BF7/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5C1DE17A/5C1FA6E7" Ref="C?"  Part="1" 
AR Path="/5C1E3A0B/5C1FA6E7" Ref="C?"  Part="1" 
F 0 "C?" H 6765 5020 50  0000 L CNN
F 1 "C" H 6765 4820 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6778 4770 50  0001 C CNN
F 3 "" H 6765 5020 50  0001 C CNN
F 4 "0603" H 6590 5020 50  0000 R CNN "display_footprint"
F 5 "50V" H 6590 4920 50  0000 R CNN "Voltage"
F 6 "X7R" H 6590 4820 50  0000 R CNN "Dielectric"
	1    6740 4920
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1FAD3A
P 6740 4580
AR Path="/5BB27BA3/5C1FAD3A" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1FAD3A" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1FAD3A" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1FAD3A" Ref="R?"  Part="1" 
F 0 "R?" H 6660 4580 50  0000 R CNN
F 1 "R" V 6740 4580 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6740 4580 50  0001 C CNN
F 3 "" H 6740 4580 50  0001 C CNN
F 4 "0603" H 6840 4660 50  0000 L CNN "display_footprint"
F 5 "1%" H 6840 4580 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6850 4500 50  0000 L CNN "Wattage"
F 7 "" H 7040 4980 60  0001 C CNN "Digi-Key PN"
	1    6740 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	6740 4770 6740 4730
$Comp
L power:GND #PWR?
U 1 1 5C1FBE63
P 6740 5070
F 0 "#PWR?" H 6740 4820 50  0001 C CNN
F 1 "GND" H 6740 4920 50  0000 C CNN
F 2 "" H 6740 5070 50  0001 C CNN
F 3 "" H 6740 5070 50  0001 C CNN
	1    6740 5070
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1FC808
P 6740 3220
AR Path="/5BB27BA3/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5BB27BB5/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5BB27BF7/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5C1DE17A/5C1FC808" Ref="C?"  Part="1" 
AR Path="/5C1E3A0B/5C1FC808" Ref="C?"  Part="1" 
F 0 "C?" H 6765 3320 50  0000 L CNN
F 1 "C" H 6765 3120 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6778 3070 50  0001 C CNN
F 3 "" H 6765 3320 50  0001 C CNN
F 4 "0603" H 6590 3320 50  0000 R CNN "display_footprint"
F 5 "50V" H 6590 3220 50  0000 R CNN "Voltage"
F 6 "X7R" H 6590 3120 50  0000 R CNN "Dielectric"
	1    6740 3220
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1FC813
P 6740 2880
AR Path="/5BB27BA3/5C1FC813" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5C1FC813" Ref="R?"  Part="1" 
AR Path="/5C1DE17A/5C1FC813" Ref="R?"  Part="1" 
AR Path="/5C1E3A0B/5C1FC813" Ref="R?"  Part="1" 
F 0 "R?" H 6660 2880 50  0000 R CNN
F 1 "R" V 6740 2880 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6740 2880 50  0001 C CNN
F 3 "" H 6740 2880 50  0001 C CNN
F 4 "0603" H 6840 2960 50  0000 L CNN "display_footprint"
F 5 "1%" H 6840 2880 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6850 2800 50  0000 L CNN "Wattage"
F 7 "" H 7040 3280 60  0001 C CNN "Digi-Key PN"
	1    6740 2880
	1    0    0    -1  
$EndComp
Wire Wire Line
	6740 3070 6740 3030
$Comp
L power:GND #PWR?
U 1 1 5C1FC81B
P 6740 3370
F 0 "#PWR?" H 6740 3120 50  0001 C CNN
F 1 "GND" H 6740 3220 50  0000 C CNN
F 2 "" H 6740 3370 50  0001 C CNN
F 3 "" H 6740 3370 50  0001 C CNN
	1    6740 3370
	1    0    0    -1  
$EndComp
Wire Wire Line
	6740 2730 6740 2530
Wire Wire Line
	6740 2530 6410 2530
Wire Wire Line
	6330 2630 6410 2630
Wire Wire Line
	6410 2630 6410 2530
Connection ~ 6410 2530
Wire Wire Line
	6410 2530 6330 2530
Wire Wire Line
	6740 4430 6740 4230
Wire Wire Line
	6740 4230 6410 4230
Wire Wire Line
	6330 4330 6410 4330
Wire Wire Line
	6410 4330 6410 4230
Connection ~ 6410 4230
Wire Wire Line
	6410 4230 6330 4230
$EndSCHEMATC
