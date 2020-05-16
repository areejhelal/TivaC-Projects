
#include "std_types.h"
#include "LAMP_interface.h"
#include "RightDoor.h"
#include "LeftDoor.h"

#include "Lightning.h"

void main(void)
{
    ERROR_STATUS error;

    error=RightDoor_Init();

    if(ERROR_NOK==error)
        while(1);

    error=LeftDoor_Init();

    if(ERROR_NOK==error)
            while(1);
   error=Lighting_init();

   if(ERROR_NOK==error)
           while(1);

    while(1)
    {
        LightningRunnable();
    }

}

