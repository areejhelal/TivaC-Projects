#include "STD_Types.h"
#include "LeftDoor.h"
#include "DoorSensor.h"

ERROR_STATUS LeftDoor_Init()
{
	ERROR_STATUS error=DoorSensor_Init(LDOOR_CH);
	return error;	
}

ERROR_STATUS LeftDoor_getStatus(u8* Status)
{
	ERROR_STATUS error=DoorSensor_ReadStatus(LDOOR_CH,Status);
	return error;
}
