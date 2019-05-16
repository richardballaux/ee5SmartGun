#ifndef _CONFIG_H
#define _CONFIG_H

#include "helper.h"

/**CHOOSE TYPE OF GUN**/
#define SCAR
//#define FIVESEVEN
//#define DEMOGUN

/**IF YOU WANT TO DEBUG, ENABLE THIS**/
//#define DEBUGDATA
//#define DEBUGUDP
//#define DEBUGWIFI
//#define DEBUGRFID
//#define DEBUGTRIGGER
#define DEBUGCOCKINGHANDLE

/**WIFI CONFIG**/
#ifndef STASSID
#define STASSID "LAPTOP_Olivier"
#define STAPSK  "valencia"
//#define STASSID "tpcpcS9+"
//#define STAPSK  "popopower"
//#define STASSID "telenet-ACA5AE9"
//#define STAPSK "fTpZz2ny2bpu"
#endif

/**UDP CONFIG**/
#define localPort 4210
//#define IP_Address 192, 168, 137, 40
#define IP_Address 192, 168, 137, 116

/**PINS DIVISION**/
#define analogTrigger A0
#define pushBtnMagazine D5
#define rotaryPin1 D6
#define rotaryPin2 D7
#define rfidPinRx D1
#define pushBtnReset D4
#define cockingSensor1 D2
#define cockingSensor2 D3

/*******************************/

/**CHOOSE SENSORS OF GUNS, DEFAULT:**/
#ifdef SCAR
  #define PUSHBUTTON
  #define TRIGGER
  #define MAGAZINEREADER
  #define ROTARYENCODER
  #define COCKINGHANDLE
  #define GUNTYPE 128
#endif

#ifdef FIVESEVEN
  #define PUSHBUTTON
  #define TRIGGER
  #define MAGAZINEREADER
  #define ROTARYENCODER
  #define GUNTYPE 64
#endif

#ifdef DEMOGUN
  #define TRIGGER
  #define GUNTYPE 0
#endif

#endif
