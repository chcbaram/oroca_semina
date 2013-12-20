//----------------------------------------------------------------------------
//    프로그램명 	: GLcd Menu 관련 함수 헤더
//
//    만든이     	: 
//
//    날  짜     	: 
//    
//    최종 수정  	: 
//
//    MPU_Type	:
//
//    파일명     	: AP_Menu.h
//----------------------------------------------------------------------------




                                                                                                 
#ifndef  _AP_MENU_H
#define  _AP_MENU_H



#include "Ap.h"



#ifdef   AP_MENU_LOCAL
#define  EXT_AP_MENU_DEF
#else
#define  EXT_AP_MENU_DEF     extern
#endif


EXT_AP_MENU_DEF u8 Ap_Menu_ExeCmd(void);

#endif
                                                                                                 
                                                                                                 

