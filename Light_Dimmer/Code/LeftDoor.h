#include "DoorSensor.h"


#define LDOOR_CH CH1
#define DOOR_OPEN NOT_PRESSED
#define DOOR_CLOSED PRESSED
ERROR_STATUS LeftDoor_Init();
ERROR_STATUS LeftDoor_getStatus(u8 *Status);
