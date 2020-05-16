/*Author : Donia Mohamed Mahmoud 
  Date : 25/2/2020
  Version : V1.0   */

/* Function Description : Lamp_init used to initialize the pin direction 
   input : no input  
   return value : ERROR_STATUS */

#include "GPIO.h"
#include "LAMP_interface.h"



ERROR_STATUS lamp_Init(void)
{
	u8 error_Value;
	/* To set the LAMP pin */
	error_Value=GPIO_Init(LAMP_PORT,LAMP_PIN,LAMP_MODE);
	return error_Value;
}

/* Function Description : Lamp_update used to set the led on or off 
   input : lamp_channel , status 
   return value : ERROR_STATUS */
ERROR_STATUS lamp_Update (u8 status)
{
	u8 error_Value;
	/*to check the status of the Lamp */
	if(status == LAMP_ON)
	{
		error_Value=GPIO_WritePin(LAMP_PORT,LAMP_PIN,LAMP_ON);
	}
	else
	{
		error_Value=GPIO_WritePin(LAMP_PORT,LAMP_PIN,LAMP_OFF);
	}
	return error_Value;
}
	
