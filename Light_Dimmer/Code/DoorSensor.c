/*Author : Areej Ayman Helal 
  Date : 26/2/2020
  Version : V1.0   */

/* Function Description : DoorSensor_init used to initialize the pin direction 
   input : Sensor_channel  
   return value : ERROR_STATUS */

#include "GPIO.h"
#include "DoorSensor.h"

ERROR_STATUS DoorSensor_Init(u8 Sensor_channel)
{
	u8 error_Value;
	/* To set the DoorSensor pin */
	switch(Sensor_channel)
	{
		case CH0:
			error_Value = GPIO_Init(SENSOR_CH0_PORT,SENSOR_CH0_PIN,SENSOR_CH0_MODE);
		break;
		case CH1:
			error_Value = GPIO_Init(SENSOR_CH1_PORT,SENSOR_CH1_PIN,SENSOR_CH1_MODE);
		break;
	}
	return error_Value;
}

/* Function Description : DoorSensor_ReadStatus used to get the door sensor status 
   input : Sensor_channel , Status 
   return value : ERROR_STATUS */
ERROR_STATUS DoorSensor_ReadStatus (u8 Sensor_Ch ,u8 *Status)
{
	u8 error_Value ;
	/*to check the status of the DoorSensor */
	switch(Sensor_Ch)
	{
		case CH0:
			error_Value = GPIO_ReadPin(SENSOR_CH0_PORT,SENSOR_CH0_PIN,Status);
		break;
		case CH1:
			error_Value = GPIO_ReadPin(SENSOR_CH1_PORT,SENSOR_CH1_PIN,Status);
		break;
	}
	return error_Value;
}
	
