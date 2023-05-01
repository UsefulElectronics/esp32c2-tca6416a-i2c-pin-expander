/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  main.c
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Apr 30, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "main.h"
#include "i2c_config.h"
#include "tca6416a.h"
/* PRIVATE STRUCTURES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/


static const char *TAG = "i2c-simple-example";
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/
static void display_handle_task(void* param);
/* FUNCTION PROTOTYPES -------------------------------------------------------*/

void app_main(void)
{
    uint8_t data[2];
    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    //All pins outout
    i2c_register_write_byte(TCA6416A_ADDR, TCAREG_CONFIG0,(uint16_t) 0x0000 );

    xTaskCreate(display_handle_task, "Display time Handler", 10000, NULL, 4, NULL);
}
/**
 * @brief Seven segment handler task
 */
static void display_handle_task(void* param)
{
    uint8_t counter = 0;

	TickType_t xLastWakeTime = xTaskGetTickCount();

	while(1)
	{
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(250));

        i2c_register_write_byte(TCA6416A_ADDR, TCAREG_OUTPUT0,(uint16_t) tca6416a_display_number(counter++));

        if(TWO_DIGIT_LIMIT < counter)
        {
            counter = 0;
        }
	}
}

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/




