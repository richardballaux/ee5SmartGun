#ifndef _CONFIG_H
#define _CONFIG_H

#include "helper.h"

/**CHOOSE TYPE OF GUN**/
//#define SCAR
#define FiveSeven
//#define DEMOGUN

/**IF YOU WANT TO DEBUG, ENABLE THIS**/
#define DEBUGDATA
#define DEBUGUDP
#define DEBUGWIFI
//#define DEBUGRFID

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
#define IP_Address 192, 168, 137, 40

/**PINS DIVISION**/
#define analogTrigger A0
#define pushBtnMagazine D5
#define rotaryPin1 D6
#define rotaryPin2 D7
#define rfidPinRx D1

/*******************************/

/**CHOOSE SENSORS OF GUNS, DEFAULT:**/
#ifdef SCAR
  #define pushButton
  #define trigger
  #define magazineReader
  #define rotaryEncoder
  #define slider
  #define gunType 128
#endif

#ifdef FiveSeven
  #define pushButton
  #define trigger
  #define magazineReader
  #define slider
  #define gunType 64
#endif

#ifdef DEMOGUN
  #define trigger
  #define gunType 0
#endif

#endif
