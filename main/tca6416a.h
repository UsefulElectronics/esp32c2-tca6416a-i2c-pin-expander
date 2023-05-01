/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  tca6416a.h
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Apr 30, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/

#ifndef TCA6416A_H_
#define TCA6416A_H_


/* INCLUDES ------------------------------------------------------------------*/
#include "system_common.h"
/* MACROS --------------------------------------------------------------------*/
#define TCAREG_CONFIG0          0x06        /*!< GPIO mode select configuration command*/
#define TCAREG_OUTPUT0          0x02        /*!< GPIO output register*/
#define TCA6416A_ADDR           0x20        /*!< Slave address of the TCA6416A pin expander */

#define SEG1A                   (uint16_t)(1 << 2 )
#define SEG1B                   (uint16_t)(1 << 0 )   
#define SEG1C                   (uint16_t)(1 << 15)
#define SEG1D                   (uint16_t)(1 << 13)
#define SEG1E                   (uint16_t)(1 << 11)
#define SEG1F                   (uint16_t)(1 << 4 )
#define SEG1G                   (uint16_t)(1 << 1 )
#define SEG1DP                  (uint16_t)(1 << 12)

#define SEG2A                   (uint16_t)(1 << 7 )
#define SEG2B                   (uint16_t)(1 << 6 )
#define SEG2C                   (uint16_t)(1 << 10)
#define SEG2D                   (uint16_t)(1 << 9 )
#define SEG2E                   (uint16_t)(1 << 8 )
#define SEG2F                   (uint16_t)(1 << 3 )
#define SEG2G                   (uint16_t)(1 << 14)
#define SEG2DP                  (uint16_t)(1 << 5 )

#define SEG_CHAR_MAX_COUNT      20
#define ONE_DIGIT_LIMIT         9
#define TWO_DIGIT_LIMIT         99
#define TCA6416A_INVALID       0xFFFF
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/
/**
 * @brief   Map the givent number value to 7 seg representation  
 * 
 * @param   number  :   Value to display
 *  
 * @return  uint16_t:   Segment representation of the passed value
 */
uint16_t tca6416a_display_number(uint8_t number);

/**
 * @brief   return the current value that is showing on the display
 * 
 * @return  uint16_t :  current display value
 */
uint16_t tca6416a_get_current_display(void);


#endif /* TCA6416A_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/