#include "GPIO.h"

#define GPIO_PORTF_DATA_R       (*((volatile u32 *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile u32 *)0x40025400))
#define GPIO_PORTF_PUR_R        (*((volatile u32 *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile u32 *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile u32 *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile u32 *)0x40025524))
#define GPIO_LOCK_KEY           0x4C4F434B  

#define SYSCTL_RCGC2_R          (*((volatile u32 *)0x400FE108))

#define GPIO_PORTE_DATA_R       (*((volatile u32 *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile u32 *)0x40024400))
#define GPIO_PORTE_PUR_R        (*((volatile u32 *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile u32 *)0x4002451C))
#define GPIO_PORTE_CR_R         (*((volatile u32 *)0x40024524))


#define GPIO_PORTD_DATA_R       (*((volatile u32 *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile u32 *)0x40007400))
#define GPIO_PORTD_PUR_R        (*((volatile u32 *)0x40007510))
#define GPIO_PORTD_DEN_R        (*((volatile u32 *)0x4000751C))
#define GPIO_PORTD_CR_R         (*((volatile u32 *)0x40007524))

#define GPIO_PORTC_DATA_R       (*((volatile u32 *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile u32 *)0x40006400))
#define GPIO_PORTC_PUR_R        (*((volatile u32 *)0x40006510))
#define GPIO_PORTC_DEN_R        (*((volatile u32 *)0x4000651C))
#define GPIO_PORTC_CR_R         (*((volatile u32 *)0x40006524))

#define GPIO_PORTB_DATA_R       (*((volatile u32 *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile u32 *)0x40005400))
#define GPIO_PORTB_PUR_R        (*((volatile u32 *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile u32 *)0x4000551C))
#define GPIO_PORTB_CR_R         (*((volatile u32 *)0x40005524))

#define GPIO_PORTA_DATA_R       (*((volatile u32 *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile u32 *)0x40004400))
#define GPIO_PORTA_PUR_R        (*((volatile u32 *)0x40004510))
#define GPIO_PORTA_DEN_R        (*((volatile u32 *)0x4000451C))
#define GPIO_PORTA_CR_R         (*((volatile u32 *)0x40004524))




ERROR_STATUS GPIO_Init(u8 Port,u8 Pin,u8 Direction)
{
    volatile u32 delay;
    if(Port=='A' || Port=='B' || Port=='C' || Port=='D' || Port=='E' || Port=='F')
    {
        if(Pin<8)
        {
            switch(Port)
            {
            case 'A':
                SYSCTL_RCGC2_R |= 0x00000001;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTA_CR_R  |= 1<<Pin;
                GPIO_PORTA_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTA_DIR_R &= ~(1<<Pin);
                    GPIO_PORTA_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTA_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }

                break;

            case 'B':
                SYSCTL_RCGC2_R |= 0x00000002;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTB_CR_R  |= 1<<Pin;
                GPIO_PORTB_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTB_DIR_R &= ~(1<<Pin);
                    GPIO_PORTB_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTB_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }
                break;

            case 'C':
                SYSCTL_RCGC2_R |= 0x00000004;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTC_CR_R  |= 1<<Pin;
                GPIO_PORTC_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTC_DIR_R &= ~(1<<Pin);
                    GPIO_PORTC_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTC_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }
                break;

            case 'D':
                SYSCTL_RCGC2_R |= 0x00000008;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTD_CR_R  |= 1<<Pin;
                GPIO_PORTD_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTD_DIR_R &= ~(1<<Pin);
                    GPIO_PORTD_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTD_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }
                break;

            case 'E':
                SYSCTL_RCGC2_R |= 0x00000010;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTE_CR_R  |= 1<<Pin;
                GPIO_PORTE_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTE_DIR_R &= ~(1<<Pin);
                    GPIO_PORTE_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTE_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }
                break;

            case 'F':
                SYSCTL_RCGC2_R |= 0x00000020;
                delay = SYSCTL_RCGC2_R;
                GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
                GPIO_PORTF_CR_R  |= 1<<Pin;
                GPIO_PORTF_DEN_R |= 1<<Pin;

                if(Direction==0)
                {
                    GPIO_PORTF_DIR_R &= ~(1<<Pin);
                    GPIO_PORTF_PUR_R |= (1<<Pin);
                }
                else if(Direction==1)
                {
                    GPIO_PORTF_DIR_R |= (1<<Pin);
                }
                else
                {
                    return ERROR_NOK;
                }
                break;

            }
        }
        else
        {
            return ERROR_NOK;
        }
    }
    else
    {
        return ERROR_NOK;
    }
    return ERROR_OK;
}


ERROR_STATUS GPIO_WritePin(u8 Port,u8 Pin,u8 Value)
{

    if(Port=='A' || Port=='B' || Port=='C' || Port=='D' || Port=='E' || Port=='F')
    {
        if(Pin<8)
        {
            switch(Port)
            {
            case 'A':
                if(Value==1)
                {
                    GPIO_PORTA_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTA_DATA_R &= ~(1<<Pin);
                }
                break;


            case 'B':
                if(Value==1)
                {
                    GPIO_PORTB_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTB_DATA_R &= ~(1<<Pin);
                }
                break;


            case 'C':
                if(Value==1)
                {
                    GPIO_PORTC_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTC_DATA_R &= ~(1<<Pin);
                }
                break;


            case 'D':
                if(Value==1)
                {
                    GPIO_PORTD_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTD_DATA_R &= ~(1<<Pin);
                }
                break;

            case 'E':
                if(Value==1)
                {
                    GPIO_PORTE_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTE_DATA_R &= ~(1<<Pin);
                }
                break;


            case 'F':
                if(Value==1)
                {
                    GPIO_PORTF_DATA_R |= 1<<Pin;
                }
                else if(Value==0)
                {
                    GPIO_PORTF_DATA_R &= ~(1<<Pin);
                }
                break;

            }
        }
        else
        {
            return ERROR_NOK;
        }
    }
    else
    {
        return ERROR_NOK;
    }
    return ERROR_OK;
}

ERROR_STATUS GPIO_ReadPin(u8 Port,u8 Pin,u8 *Value)
{
    if(Port=='A' || Port=='B' || Port=='C' || Port=='D' || Port=='E' || Port=='F')
    {
        if(Pin<8)
        {
            switch(Port)
            {
            case 'A':
                *Value=((GPIO_PORTA_DATA_R & 1<<Pin)>>Pin);
                break;

            case 'B':
                *Value=((GPIO_PORTB_DATA_R & 1<<Pin)>>Pin);
                break;

            case 'C':
                *Value=((GPIO_PORTC_DATA_R & 1<<Pin)>>Pin);
                break;

            case 'D':
                *Value=((GPIO_PORTD_DATA_R & 1<<Pin)>>Pin);
                break;

            case 'E':
                *Value=((GPIO_PORTE_DATA_R & 1<<Pin)>>Pin);
                break;

            case 'F':
                *Value=((GPIO_PORTF_DATA_R & 1<<Pin)>>Pin);
                break;

            }
        }
        else
        {
            return ERROR_NOK;
        }
    }
    else
    {
        return ERROR_NOK;
    }
    return ERROR_OK;
}
