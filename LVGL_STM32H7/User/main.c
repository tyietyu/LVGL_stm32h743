#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/SDRAM/sdram.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/KEY/key.h"
#include "./BSP/MPU/mpu.h"
#include "./BSP/TOUCH/touch.h"
#include "./BSP/TIMER/btim.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lv_demo_stress.h"
#include "lv_demo_music.h"


int main(void)
{
    sys_cache_enable();                        /* ��L1-Cache */
    HAL_Init();                                /* ��ʼ��HAL�� */
    sys_stm32_clock_init(160, 5, 2, 4);        /* ����ʱ��, 400Mhz */
    delay_init(400);                           /* ��ʱ��ʼ�� */
    usart_init(115200);                        /* ���ڳ�ʼ�� */
    mpu_memory_protection();                   /* ������ش洢���� */
    led_init();                                /* ��ʼ��LED */
    sdram_init();                              /* ��ʼ��SDRAM */
    key_init();                                /* ��ʼ��KEY */
   
	btim_timx_int_init(10-1,9000-1);
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	
//	lv_obj_t* switch_obj=lv_switch_create(lv_scr_act());
//	lv_obj_set_size(switch_obj,120,60);
//	lv_obj_align(switch_obj,LV_ALIGN_CENTER,0,0);
	
	//lv_demo_stress();
	lv_demo_music();
	
	while(1)
	{
		delay_ms(5);
		lv_timer_handler();
	}

   
}


