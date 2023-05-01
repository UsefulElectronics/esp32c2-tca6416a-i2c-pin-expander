/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  i2c_config..h
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Apr 28, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/

#ifndef I2C_H_
#define I2C_H_


/* INCLUDES ------------------------------------------------------------------*/

#include <system_common.h>
/* MACROS --------------------------------------------------------------------*/
#define I2C_MASTER_SCL_IO           CONFIG_I2C_MASTER_SCL      /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           CONFIG_I2C_MASTER_SDA      /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0                          /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          100000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/
/**
 * @brief i2c master initialization
 */
esp_err_t i2c_master_init(void);
/**
 * @brief   Read data with len length over I2C bus
 * 
 * @param   i2c_address :   I2C slave address
 * 
 * @param   reg_addr    :   address to write data to
 * 
 * @param   data        :   Data to write 
 * 
 * @return  esp_err_t   :   Error status
 */
esp_err_t i2c_register_read(uint8_t i2c_address, uint8_t reg_addr, uint8_t *data, size_t len);
/**
 * @brief   Write 2 bytes over I2C bus
 * 
 * @param   i2c_address :   I2C slave address
 * 
 * @param   reg_addr    :   address to write data to
 * 
 * @param   data        :   Data to write 
 * 
 * @return  esp_err_t   :   Error status
 */
esp_err_t i2c_register_write_byte(uint8_t i2c_address, uint8_t reg_addr, uint16_t data);

#endif /* I2C_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/