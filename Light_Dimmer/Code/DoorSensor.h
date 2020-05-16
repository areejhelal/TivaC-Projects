#include "std_types.h"


#define CH0 0
#define CH1 1

#define SENSOR_CH0_PORT 'F'
#define SENSOR_CH0_PIN   0
#define SENSOR_CH0_MODE  0

#define SENSOR_CH1_PORT 'F'
#define SENSOR_CH1_PIN   4
#define SENSOR_CH1_MODE  0

#define PRESSED         0
#define NOT_PRESSED     1



ERROR_STATUS DoorSensor_Init(u8 Sensor_channel);
ERROR_STATUS DoorSensor_ReadStatus (u8 Sensor_Ch ,u8 *Status);


