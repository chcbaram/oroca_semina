//----------------------------------------------------------------------------
//    프로그램명 	: I2C 관련 함수
//
//    만든이     	: 
//
//    날  짜     	: 
//    
//    최종 수정  	:
//
//    MPU_Type		:
//
//    파일명     	: Hw_I2C.c
//----------------------------------------------------------------------------


//----- 헤더파일 열기
//
#define  HW_I2C_LOCAL


#include "Hw_I2C.h"





/*---------------------------------------------------------------------------
     TITLE   : Hw_I2C_Init
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void Hw_I2C_Init( void )
{
	//-- I/O 초기화
	//
	#if HW_I2C_USE_SW_I2C == 1
	Hw_I2C_SW_Init();	
	#else
	Hw_I2C_HW_Init();		
	#endif
}





/*---------------------------------------------------------------------------
     TITLE   : Hw_I2C_Write
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
u16 Hw_I2C_Write( u8 Ch, u16 i2c_addr, u8 *pdata, u16 len )
{
	u16 Ret;
	
	#if HW_I2C_USE_SW_I2C == 1
	
	Ret = Hw_I2C_SW_Write( Ch, i2c_addr, pdata, len );
	
	#else

	Ret = Hw_I2C_HW_Write( Ch, i2c_addr, pdata, len );
	
	#endif

    return Ret;
}




/*---------------------------------------------------------------------------
     TITLE   : Hw_I2C_Read
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
u16 Hw_I2C_Read( u8 Ch, u16 i2c_addr, u8 *pdata, u16 len )
{
	u16 Ret;

	#if HW_I2C_USE_SW_I2C == 1
	
	Ret = Hw_I2C_SW_Read( Ch, i2c_addr, pdata, len );	
	
	#else
	
	#endif
	
    return Ret;
}



