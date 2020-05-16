#include "std_types.h"

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7


ERROR_STATUS GPIO_Init(u8 Port,u8 Pin,u8 Direction);
ERROR_STATUS GPIO_WritePin(u8 Port,u8 Pin,u8 Value);
ERROR_STATUS GPIO_ReadPin(u8 Port,u8 Pin,u8 *Value);
