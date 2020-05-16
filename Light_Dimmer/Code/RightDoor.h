#include "DoorSensor.h"

#define RDOOR_CH CH0
#define DOOR_OPEN NOT_PRESSED
#define DOOR_CLOSED PRESSED
ERROR_STATUS RightDoor_Init();
ERROR_STATUS RightDoor_getStatus(u8 *Status);
