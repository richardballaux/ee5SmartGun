#ifndef _CONFIG_H
#define _CONFIG_H
#endif

#include "helper.h"


/**WIFI CONFIG**/
#ifndef STASSID
#define STASSID "LAPTOP_Olivier"
#define STAPSK  "valencia"
#endif

/**UDP CONFIG**/
#define localPort 4210
//IP Shivam
//#define IP_Address 192, 168, 137, 165
//IP Olivier
#define IP_Address 192,168,137,1


/**PINS DIVISION**/
#define pushBtnMagazine D5
#define rotaryPin1 D6
#define rotaryPin2 D7