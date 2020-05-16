
#include "std_types.h"
#include "LAMP_interface.h"
#include "RightDoor.h"
#include "LeftDoor.h"


ERROR_STATUS Lighting_init(void)
{
    ERROR_STATUS error=lamp_Init();
    return error;
}

void LightningRunnable(void)
{
	ERROR_STATUS error;
	u8 temp1,temp2;
	error=LeftDoor_getStatus(&temp1);
	if(error==ERROR_NOK)
	{
		while(1);
	}
	error=RightDoor_getStatus(&temp2);
	if(error==ERROR_NOK)
	{
		while(1);
	}
	if(temp1==DOOR_OPEN||temp2==DOOR_OPEN)
	{
		error=lamp_Update(LAMP_ON);
	}
	else
	{
		error=lamp_Update(LAMP_OFF);
	}
	if(error==ERROR_NOK)
	{
		while(1);
	}
}
