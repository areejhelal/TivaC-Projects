#include "STD_Types.h"
#include "RightDoor.h"
#include "DoorSensor.h"

ERROR_STATUS RightDoor_Init()
{
    ERROR_STATUS error=DoorSensor_Init(RDOOR_CH);
	return error;	
}

ERROR_STATUS RightDoor_getStatus(u8 *Status)
{
    ERROR_STATUS error=DoorSensor_ReadStatus(RDOOR_CH,Status);
    return error;
}
