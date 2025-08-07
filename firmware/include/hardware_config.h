#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

// Electrical Connection

#define I2C_SDA_PIN                     41
#define I2C_SCL_PIN                     42

#define SPI_MOSI_PIN                    11
#define SPI_SCK_PIN                     12
#define SPI_MISO_PIN                    13

#define TFT_HOR_RES                     130
#define TFT_VER_RES                     160

#define TFT_CLK_PIN                     SPI_SCK_PIN
#define TFT_SDA_PIN                     SPI_MOSI_PIN
#define TFT_RES_PIN                     17
#define TFT_DC_PIN                      18
#define TFT_CS_PIN                      19
#define TFT_BL_PIN                      20

#define NRF24_MOSI_PIN                  SPI_MOSI_PIN
#define NRF24_MISO_PIN                  SPI_MISO_PIN
#define NRF24_SCK_PIN                   SPI_SCK_PIN
#define NRF24_CSN_PIN                   14
#define NRF24_CE_PIN                    21

#define BUZZER_PIN                      47
#define VIBRATION_MOTOR_PIN             48

//

#define I2C_TRANSMISSION_FREQUENCY      100000

#endif
