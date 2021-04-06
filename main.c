#include"STD_TYPES.h"
#include"bit.h"
#include"avr/delay.h"
#include"ADC_Config.h"
#include"DIO_Interface.h"
#include"ADC_Interface.h"
void main (void)
{u16 Digital_value=0;
u16 Analog_value=0;
	ADC_VidInit();
	DIO_VidSetPinDirection(PORTD,PIN0,1);
	while (1)
	{
		Digital_value=ADC_U16ReadChannel(ADC0);
		Analog_value=((Digital_value * 5000UL)/1024);
		if((Analog_value>=1500)&&(Analog_value<3000))
			DIO_VidSetPinValue(PORTD,PIN0,1);
		else
			DIO_VidSetPinValue(PORTD,PIN0,0);

	}
}


