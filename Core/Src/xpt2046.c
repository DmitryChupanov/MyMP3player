#include "main.h"
#include "xpt2046.h"
// "ILI9341_GFX.h"

#define TOUCH_SCALE_X 240
#define TOUCH_SCALE_Y 320

#define TOUCH_MIN_RAW_X 34200//1500
#define TOUCH_MAX_RAW_X 63500//30000
#define TOUCH_MIN_RAW_Y 35600//2500
#define TOUCH_MAX_RAW_Y 64100//30000

extern SPI_HandleTypeDef hspi4;
#define TOUCH_SPI_PTR 		 &hspi4




// калибровка
/*#include "string.h"
#include "stdio.h"
extern UART_HandleTypeDef huart1;*/


uint8_t ILI9341_TouchGetCoordinates(uint16_t *x, uint16_t *y)
{
	static const uint8_t cmd_read_x = 0x90;
	static const uint8_t cmd_read_y = 0xD0;
	static const uint8_t zeroes_tx[] = {0x00, 0x00};
	
	if(HAL_GPIO_ReadPin(T_IRQ_GPIO_Port, T_IRQ_Pin) != GPIO_PIN_RESET) return 0;

    TOUCH_CS_SELECT;

    uint32_t avg_x = 0;
    uint32_t avg_y = 0;

	HAL_SPI_Transmit(TOUCH_SPI_PTR, (uint8_t*)&cmd_read_y, 1, 1000);

	uint8_t x_raw[2] = {0,};
	HAL_SPI_TransmitReceive(TOUCH_SPI_PTR, (uint8_t*)zeroes_tx, x_raw, 2, 1000);

	HAL_SPI_Transmit(TOUCH_SPI_PTR, (uint8_t*)&cmd_read_x, 1, 1000);

	uint8_t y_raw[2] = {0,};
	HAL_SPI_TransmitReceive(TOUCH_SPI_PTR, (uint8_t*)zeroes_tx, y_raw, 2, 1000);

	avg_x = (((uint16_t)x_raw[0]) << 8) | ((uint16_t)x_raw[1]);
	avg_y = (((uint16_t)y_raw[0]) << 8) | ((uint16_t)y_raw[1]);

    TOUCH_CS_UNSELECT;

    if(avg_x < TOUCH_MIN_RAW_X) avg_x = TOUCH_MIN_RAW_X;
    if(avg_x > TOUCH_MAX_RAW_X) avg_x = TOUCH_MAX_RAW_X;

    if(avg_y < TOUCH_MIN_RAW_X) avg_y = TOUCH_MIN_RAW_Y;
    if(avg_y > TOUCH_MAX_RAW_Y) avg_y = TOUCH_MAX_RAW_Y;

    *x = (avg_x - TOUCH_MIN_RAW_X) * TOUCH_SCALE_X / (TOUCH_MAX_RAW_X - TOUCH_MIN_RAW_X);
    *y = TOUCH_SCALE_Y - ((avg_y - TOUCH_MIN_RAW_Y) * TOUCH_SCALE_Y / (TOUCH_MAX_RAW_Y - TOUCH_MIN_RAW_Y));
	
// калибровка
//		*x = avg_x;
//		*y = avg_y;
    return 1;
}

/**/

