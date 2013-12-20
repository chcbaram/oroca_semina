//----------------------------------------------------------------------------
//    프로그램명   : GLcd Menu 관련 함수
//
//    만든이     	: Cho Han Cheol
//
//    날  짜     	: 
//    
//    최종 수정  	: 
//
//    MPU_Type  :
//
//    파일명     	: Ap_Menu.h
//----------------------------------------------------------------------------



//----- 헤더파일 열기
//
#define  AP_MENU_LOCAL

#include "Ap_Menu.h"

  

//-- 내부 선언
//



//-- 내부 변수
//

  

//-- 내부 함수
//
void Ap_Menu_ShowMenu(void);


u16 Exam_Pwm_Value = 0;


u16 Exam_LED_TickDelay = 100;  

void Exam_LED_Tick( void )
{
	static u16 Cnt = 0;

	Cnt++;

	if( Cnt >= Exam_LED_TickDelay )
	{
		Cnt = 0;

		Hw_Led_Toggle(0);
	}
}


/*---------------------------------------------------------------------------
     TITLE   : Ap_Menu_ShowMenu
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void Ap_Menu_ShowMenu(void)
{
	u8 key;

	Lb_printf("\n\n");
	Lb_printf("*******************************************************\n");
	Lb_printf("                      MENU                             \n");
	Lb_printf("*******************************************************\n");
	Lb_printf("* 1. LED +                                            *\n");
	Lb_printf("* 2. LED -                                            *\n");
	Lb_printf("* 3. PWM                                              *\n");
	Lb_printf("* 4. DHT11                                            *\n");
	Lb_printf("* 5.                                                  *\n");
	Lb_printf("* 6.                                                  *\n");
	Lb_printf("* 7.                                                  *\n");
	Lb_printf("* 8.                                                  *\n");
	Lb_printf("* 9.                                                  *\n");
	Lb_printf("* m.  Menu                                            *\n");
	Lb_printf("*******************************************************\n");
	Lb_printf("\n");
}





/*---------------------------------------------------------------------------
     TITLE   : Ap_Menu_GetCmd
     WORK    : 
     ARG     : void
     RET     : 
				u8 : 눌려진 메뉴키 데이터 
---------------------------------------------------------------------------*/
u8 Ap_Menu_GetCmd(void)
{
	u8  key;
	

	Lb_printf(">> ");

    key=get_byte();
	
	Lb_printf("\n");
	
    return key;
}




/*---------------------------------------------------------------------------
     TITLE   : Ap_Menu_ExeCmd
     WORK    : 
     ARG     : void
     RET     : 
				u8 : 눌려진 메뉴키 데이터 
---------------------------------------------------------------------------*/
u8 Ap_Menu_ExeCmd(void)
{
	u8 key;
	u8 Status;
	static u8 ExeFirst = TRUE;
	u16 Ret;
	static u8  Count    = 0;	
	static s8  CircleX  = 0;	
	u8 I2C_Data[20];	
	s16 Temperature;	
	s16 x;
    s16 y;
    u16 i;

    HW_MPU6050_DATA_OBJ MPU6050_Data;


	if( ExeFirst == TRUE )
	{
		Ap_Menu_ShowMenu();		

    	Hw_Timer_Set  ( HW_TIMER_CH_LED, 10, LOOP_TIME, Exam_LED_Tick, NULL );
    	Hw_Timer_Start( HW_TIMER_CH_LED );            
	}

    while( (key = Ap_Menu_GetCmd()) != 0 )
    {
        switch(key)
        {
           case '1':
           		Exam_LED_TickDelay += 10;

           		if( Exam_LED_TickDelay > 100 ) Exam_LED_TickDelay = 100;

          		Lb_printf("LED Delay %d ms \n", Exam_LED_TickDelay*10);

               	break;

           case '2':
           		if( Exam_LED_TickDelay >= 10 ) Exam_LED_TickDelay -= 10;
           		
          		Lb_printf("LED Delay %d ms \n", Exam_LED_TickDelay*10);
				break;

           case '3':    
           		Exam_Pwm_Value += 5;

           		if( Exam_Pwm_Value > 100 ) Exam_Pwm_Value = 0;

          		Lb_printf("PWM Duty %d \n", Exam_Pwm_Value); 
          		Hw_Pwm_SetPercent(0, Exam_Pwm_Value);

               break; 

           case '4':
           		Lb_printf("H : %d, T : %d \n", Hw_DHT11_GetHumidity(), Hw_DHT11_GetTemperature() );
               break;  

           case '5':
               break;  

           case '6':
               break;  

           case '7':
               break;  

           case '8':
               break;

           case '9': 
               break;

           case '0':
               break;

			case 'm':
			case 'M':
				Ap_Menu_ShowMenu();
				break;
				
           default :
               break;
        }
    }
    
    return key;
}
