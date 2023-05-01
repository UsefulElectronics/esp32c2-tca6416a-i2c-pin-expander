/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  tca6416.c
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Apr 30, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "tca6416a.h"

/* PRIVATE STRUCTURES --------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/
const uint16_t segment1[SEG_CHAR_MAX_COUNT] = 
{
    SEG1A | SEG1B | SEG1C | SEG1D | SEG1E | SEG1F,          //0
    SEG1C | SEG1B,                                          //1
    SEG1A | SEG1B | SEG1G | SEG1E | SEG1D,                  //2
    SEG1A | SEG1B | SEG1G | SEG1D | SEG1C,                  //3
    SEG1F | SEG1B | SEG1G | SEG1C,                            //4
    SEG1A | SEG1F | SEG1G | SEG1C | SEG1D,                  //5
    SEG1A | SEG1C | SEG1G | SEG1E | SEG1D | SEG1F,          //6
    SEG1A | SEG1B | SEG1C,                                  //7
    SEG1A | SEG1B | SEG1C | SEG1D | SEG1E | SEG1F | SEG1G,  //8
    SEG1A | SEG1B | SEG1C | SEG1D | SEG1F | SEG1G           //9
};

const uint16_t segment2[SEG_CHAR_MAX_COUNT] = 
{
    SEG2A | SEG2B | SEG2C | SEG2D | SEG2E | SEG2F,          //0
    SEG2C | SEG2B,                                          //1
    SEG2A | SEG2B | SEG2G | SEG2E | SEG2D,                  //2
    SEG2A | SEG2B | SEG2G | SEG2D | SEG2C,                  //3
    SEG2F | SEG2B | SEG2G | SEG2C,                          //4
    SEG2A | SEG2F | SEG2G | SEG2C | SEG2D,                  //5
    SEG2A | SEG2C | SEG2G | SEG2E | SEG2D | SEG2F,          //6
    SEG2A | SEG2B | SEG2C,                                  //7
    SEG2A | SEG2B | SEG2C | SEG2D | SEG2E | SEG2F | SEG2G,  //8
    SEG2A | SEG2B | SEG2C | SEG2D | SEG2F | SEG2G           //9
};

uint8_t tca6416a_display_value = 0;
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
/**
 * @brief   Map the givent number value to 7 seg representation  
 * 
 * @param   number  :   Value to display
 *  
 * @return  uint16_t:   Segment representation of the passed value
 */
uint16_t tca6416a_display_number(uint8_t number)
{
    uint16_t retVal = 0;

    if(ONE_DIGIT_LIMIT >= number)
    {
        tca6416a_display_value = number;

        retVal = segment1[number];

        return retVal;
    }
    else if(ONE_DIGIT_LIMIT < number && TWO_DIGIT_LIMIT >= number )
    {
        tca6416a_display_value = number;

        retVal = segment1[number % 10] | segment2[number / 10];

        return retVal;
    }
    retVal = TCA6416A_INVALID;
    return retVal;
}
/**
 * @brief   return the current value that is showing on the display
 * 
 * @return  uint16_t :  current display value
 */
uint16_t tca6416a_get_current_display(void)
{
    return tca6416a_display_value;
}
/*************************************** USEFUL ELECTRONICS*****END OF FILE****/