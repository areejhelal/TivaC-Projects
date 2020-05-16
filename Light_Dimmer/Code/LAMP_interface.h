/*Author : Donia Mohamed Mahmoud 
  Date : 25/2/2020
  Version : V1.0   */

#include "std_types.h"


/*LAMP PORT*/
#define LAMP_PORT   'F'
/* LAMP PIN */
#define LAMP_PIN    3
/*LAMP MODE */
#define LAMP_MODE   1

/*LAMP status */
#define LAMP_ON  1
#define LAMP_OFF 0


/* Function Description : Lamp_init used to initialize the pin direction 
   input : void 
   return value : ERROR_STATUS */
ERROR_STATUS lamp_Init(void);


/* Function Description : Lamp_update used to set the led on or off 
   input : lamp_channel , status 
   return value : ERROR_STATUS */
ERROR_STATUS lamp_Update (u8 status);
