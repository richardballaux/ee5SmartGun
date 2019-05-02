#ifndef _CONFIG_H
#define _CONFIG_H

#include "helper.h"


/**IF YOU WANT TO DEBUG, ENABLE THIS**/
#define DEBUG 

/**WIFI CONFIG**/
#ifndef STASSID
//#define STASSID "LAPTOP_Olivier"
//#define STAPSK  "valencia"
#define STASSID "tpcpcS9+"
#define STAPSK  "popopower"
#endif

/**UDP CONFIG**/
#define localPort 4210
//IP Shivam
//#define IP_Address 192, 168, 137, 56
#define IP_Address 192, 168, 43, 143
//IP Olivier
//#define IP_Address 192,168,137,1
//IP Roy
//#define IP_Address 192,168,137,219


/**PINS DIVISION**/
#define analogTrigger A0
#define pushBtnMagazine D5
#define rotaryPin1 D6
#define rotaryPin2 D7
#define rfidPinRx D1

#endif
