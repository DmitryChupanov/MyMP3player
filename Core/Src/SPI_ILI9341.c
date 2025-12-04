#include "SPI_ILI9341.h"
#include "main.h"
#include "cmsis_os.h"
#include <cstdlib>
//#include "font24.c"
//#include "font20.c"
//#include "font16.c"
#include "font12.c"
#include "font8.c"
#include "font18.c"
#include "MySPI.h"
//#include "ff.h"
//-------------------------------------------------------------------

//extern RNG_HandleTypeDef hrng;
//-------------------------------------------------------------------
uint16_t TFT9341_WIDTH;
uint16_t TFT9341_HEIGHT;

// Иконка музыкального файла 18 х 18 пикселей
const uint8_t MusicIcon[] = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x8e,0x11,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x50,0x53,0xd8,0x00,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4b,0x12,0x6c,0xdb,0x4b,0xb7,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5b,0xb4,0x01,0x32,0x09,0xd4,0x22,0x95,0x08,0xc8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0xb3,0x01,0x0f,0x01,0x0c,0x01,0xf2,0x0a,0xd7,0x09,0xcf,0x00,0x21,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0xb4,0x01,0x6f,0x00,0x00,0x00,0x00,0x00,0x64,0x02,0x52,0x0b,0x58,0x00,0x85,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0xb4,0x02,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x29,0x03,0x7a,0x00,0x43,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0xb4,0x02,0xb2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x8c,0x01,0xf0,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4b,0x53,0x03,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x02,0x74,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x91,0x03,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x01,0xaf,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0xcf,0x03,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0b,0x00,0x44,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0xed,0x02,0x51,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0xca,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0xa5,0x21,0xaa,0x19,0xcc,0x01,0x2a,0x00,0xee,0x01,0x2e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x67,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x11,0x4c,0x85,0x1a,0xa6,0x5e,0x6d,0x9d,0x3c,0x7c,0x0b,0xda,0x04,0x1a,0x02,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x01,0xcf,0x23,0xba,0x54,0xfc,0x34,0x5c,0x13,0x7a,0x02,0xf9,0x03,0x59,0x05,0x3c,0x02,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x02,0xf3,0x0c,0xbb,0x0b,0xfa,0x0b,0xba,0x0b,0xda,0x0c,0x9b,0x0d,0x5b,0x03,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x01,0xaa,0x02,0xf0,0x03,0x31,0x02,0xcf,0x01,0xc9,0x00,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
// Иконка папки 18 х 18 пикселей
const uint8_t FolderIcon[] = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x09,0x48,0x12,0x90,0x1b,0xd9,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x3a,0x24,0x5c,0x24,0x5c,0x24,0x5c,0x09,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x3a,0x24,0x5c,0x24,0x5c,0x24,0x5c,0x12,0xb1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0x12,0x0d,0x24,0x3b,0x2c,0x7c,0x6d,0x7c,0xa6,0x7d,0x6c,0xd7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0x09,0xcc,0x1b,0x55,0x2c,0x7b,0x6d,0x7c,0xb6,0xbd,0xf7,0xbf,0xff,0xff,0xff,0xff,0xd7,0x1e,0x00,0xa4,0x12,0x4e,0x2c,0x3a,0x12,0x4e,0x00,0x00
,0x00,0x00,0x00,0xc5,0x1b,0x34,0x2c,0x7b,0x6d,0x9c,0xb6,0xbd,0xf7,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xb6,0xff,0x65,0xbf,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x08,0xe6,0x00,0x00
,0x00,0x00,0x09,0x27,0x85,0xdc,0xef,0x9e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd7,0x5f,0x86,0x3f,0x3d,0x3f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0x9c,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x42,0x7d,0x9c,0xf7,0xbe,0xff,0xff,0xff,0xff,0xa6,0xbf,0x55,0x7f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x1b,0x34,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x4c,0x98,0xf7,0x9e,0xff,0xff,0xc7,0x3f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x11,0xcb,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x23,0x12,0xef,0x7d,0xff,0xff,0x8e,0x5f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x00,0x83,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x0a,0x0d,0xd6,0xfc,0xff,0xff,0x55,0x7f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x24,0x19,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x09,0x27,0xae,0x5c,0xe7,0x7f,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x1a,0xb1,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x41,0x85,0xbb,0xae,0x9e,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xde,0x23,0x75,0x09,0x8a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x5c,0x97,0x6d,0xbe,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x2c,0xff,0x24,0x3a,0x12,0x4e,0x00,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x32,0x3d,0x1e,0x2c,0xff,0x2c,0xbd,0x1a,0xf2,0x09,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x0d,0x23,0xb7,0x11,0xcb,0x00,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


typedef struct
{
	uint16_t TextColor;
	uint16_t BackColor;
	sFONT *pFont;
}LCD_DrawPropTypeDef;
LCD_DrawPropTypeDef lcdprop;

//-------------------------------------------------------------------
void TFT9341_SendCommand(uint8_t cmd)
{
  DC_COMMAND();
	while(SPI2_TransferInProcess) {__NOP();}
	SPI2_DMA_TransmitIT(&cmd, 1);
	while(SPI2_TransferInProcess) {__NOP();}
}
//-------------------------------------------------------------------
void TFT9341_SendData(uint8_t dt)
{
	DC_DATA();
	while(SPI2_TransferInProcess) {__NOP();}
	SPI2_DMA_TransmitIT(&dt, 1);
	while(SPI2_TransferInProcess) {__NOP();}
}
//-------------------------------------------------------------------
static void TFT9341_WriteData(uint8_t* buff, size_t buff_size) 
{
	DC_DATA();
	while(buff_size > 0) {
		uint16_t chunk_size = buff_size > 32768 ? 32768 : buff_size;
		while(SPI2_TransferInProcess) {__NOP();}
		SPI2_DMA_TransmitIT(buff, chunk_size);
		while(SPI2_TransferInProcess) {__NOP();}
		buff += chunk_size;
		buff_size -= chunk_size;
	}
}
//-------------------------------------------------------------------

void TFT9341_reset(void)
{
	RESET_ACTIVE();
	HAL_Delay(5);
	RESET_IDLE();
}

//-------------------------------------------------------------------
static void TFT9341_SetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  // column address set
  TFT9341_SendCommand(0x2A); // CASET
  {
    uint8_t data[] = { (x0 >> 8) & 0xFF, x0 & 0xFF, (x1 >> 8) & 0xFF, x1 & 0xFF };
    TFT9341_WriteData(data, sizeof(data));
  }
 
  // row address set
  TFT9341_SendCommand(0x2B); // RASET
  {
    uint8_t data[] = { (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF };
    TFT9341_WriteData(data, sizeof(data));
  }
 
  // write to RAM
  TFT9341_SendCommand(0x2C); // RAMWR
}
//-------------------------------------------------------------------
void TFT9341_FillRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
  if((x1 >= TFT9341_WIDTH) || (y1 >= TFT9341_HEIGHT) || (x2 >= TFT9341_WIDTH) || (y2 >= TFT9341_HEIGHT)) return;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
  TFT9341_SetAddrWindow(x1, y1, x2, y2);
  uint8_t data[] = { color >> 8, color & 0xFF };
  DC_DATA();
  for(uint32_t i = 0; i < (x2-x1+1)*(y2-y1+1); i++)
  {
		while(SPI2_TransferInProcess) {__NOP();}
		SPI2_DMA_TransmitIT(data, 2);
		while(SPI2_TransferInProcess) {__NOP();}
  }
}
//-------------------------------------------------------------------
void TFT9341_FillScreen(uint16_t color)
{
  TFT9341_FillRect(0, 0, TFT9341_WIDTH-1, TFT9341_HEIGHT-1, color);
}
//-------------------------------------------------------------------
uint16_t TFT9341_RandColor(void)
{
	uint32_t RandomNumber = 0;
	//HAL_RNG_GenerateRandomNumber(&hrng, &RandomNumber);
	return RandomNumber & 0x0000FFFF;
}
//-------------------------------------------------------------------
uint32_t TFT9341_RandColor32(void)
{
	uint32_t RandomNumber = 0;
	//HAL_RNG_GenerateRandomNumber(&hrng, &RandomNumber);
	return RandomNumber;
}
//-------------------------------------------------------------------
void TFT9341_DrawPixel(int x, int y, uint16_t color)
{
	if((x<0)||(y<0)||(x>=TFT9341_WIDTH)||(y>=TFT9341_HEIGHT)) return;
	TFT9341_SetAddrWindow(x,y,x,y);
	TFT9341_SendCommand(0x2C);
	TFT9341_SendData(color>>8);
	TFT9341_SendData(color & 0xFF);
}
//-------------------------------------------------------------------
void TFT9341_DrawLine(uint16_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
  int steep = abs(y2-y1)>abs(x2-x1);
  if(steep)
  {
    swap(x1,y1);
    swap(x2,y2);
  }
  if(x1>x2)
  {
    swap(x1,x2);
    swap(y1,y2);
  }
  int dx,dy;
  dx=x2-x1;
  dy=abs(y2-y1);
  int err=dx/2;
  int ystep;
  if(y1<y2) ystep=1;
  else ystep=-1;
  for(;x1<=x2;x1++)
  {
    if(steep) TFT9341_DrawPixel(y1,x1,color);
    else TFT9341_DrawPixel(x1,y1,color);
    err-=dy;
    if(err<0)
    {
      y1 += ystep;
      err+=dx;
    }
  }
}
//-------------------------------------------------------------------
void TFT9341_DrawRect(uint16_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	TFT9341_DrawLine(color,x1,y1,x2,y1);
	TFT9341_DrawLine(color,x2,y1,x2,y2);
	TFT9341_DrawLine(color,x1,y1,x1,y2);
	TFT9341_DrawLine(color,x1,y2,x2,y2);
}
//-------------------------------------------------------------------
void TFT9341_DrawCircle(uint16_t x0, uint16_t y0, int r, uint16_t color)
{
	int f = 1-r;
	int ddF_x=1;
	int ddF_y=-2*r;
	int x = 0;
	int y = r;
	TFT9341_DrawPixel(x0,y0+r,color);
	TFT9341_DrawPixel(x0,y0-r,color);
	TFT9341_DrawPixel(x0+r,y0,color);
	TFT9341_DrawPixel(x0-r,y0,color);
	while (x<y)
	{
		if (f>=0)
		{
			y--;
			ddF_y+=2;
			f+=ddF_y;
		}
		x++;
		ddF_x+=2;
		f+=ddF_x;
		TFT9341_DrawPixel(x0+x,y0+y,color);
		TFT9341_DrawPixel(x0-x,y0+y,color);
		TFT9341_DrawPixel(x0+x,y0-y,color);
		TFT9341_DrawPixel(x0-x,y0-y,color);
		TFT9341_DrawPixel(x0+y,y0+x,color);
		TFT9341_DrawPixel(x0-y,y0+x,color);
		TFT9341_DrawPixel(x0+y,y0-x,color);
		TFT9341_DrawPixel(x0-y,y0-x,color);
	}
}
//-------------------------------------------------------------------
void TFT9341_FontsIni(void)
{
  Font8.Height = 8;
  Font8.Width = 5;
  Font12.Height = 12;
  Font12.Width = 7;
//  Font16.Height = 16;
//  Font16.Width = 11;
	Font18.Height = 18;
  Font18.Width = 14;
//  Font20.Height = 20;
//  Font20.Width = 14;
//  Font24.Height = 24;
//  Font24.Width = 17;
  lcdprop.BackColor=TFT9341_BLACK;
  lcdprop.TextColor=TFT9341_GREEN;
//  lcdprop.pFont=&Font16;
}
//-------------------------------------------------------------------
void TFT9341_SetTextColor(uint16_t color)
{
  lcdprop.TextColor=color;
}
//------------------------------------
void TFT9341_SetBackColor(uint16_t color)
{
  lcdprop.BackColor=color;
}
//------------------------------------
void TFT9341_SetFont(sFONT *pFonts)
{
  lcdprop.pFont=pFonts;
}
//-------------------------------------------------------------------
void TFT9341_DrawChar(uint16_t x, uint16_t y, uint8_t c)
{
  uint32_t i = 0, j = 0;
  uint16_t height, width;
  uint8_t offset;
  uint8_t *c_t;
  uint8_t *pchar;
  uint32_t line=0;
  height = lcdprop.pFont->Height; // Высота символа в пикселах
  width  = lcdprop.pFont->Width;	// Ширина символа в пикселах
  offset = 8 *((width + 7)/8) -  width ; // Ширина непечатаемого остатка в битах от ширины в байтах
  c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' ') * lcdprop.pFont->Height * ((lcdprop.pFont->Width + 7) / 8)]); // Указатель на начальный байт начертания символа
  for(i = 0; i < height; i++) // Пробегает по высоте символа сверху вниз
  {
    pchar = ((uint8_t *)c_t + (width + 7)/8 * i);
    switch(((width + 7)/8))		// Ширина символа в байтах
    {
      case 1:									// Если ширина символа 1 байт
          line =  pchar[0];   // Заполнение 32-битной переменной линиями символа   
          break;
      case 2:									// Если ширина символа 2 байта
          line =  (pchar[0]<< 8) | pchar[1]; // Заполнение 32-битной переменной линиями символа
          break;
      case 3:									// Если ширина символа 3 байта
      default:
        line =  (pchar[0]<< 16) | (pchar[1]<< 8) | pchar[2];  // Заполнение 32-битной переменной линиями символа    
        break;
    }
    for (j = 0; j < width; j++) // Пробегает по одной линии пикселов символова слева направо
    {
      if(line & (1 << (width- j + offset- 1))) 
      {
        TFT9341_DrawPixel((x + j), y, lcdprop.TextColor);
      }
      else
      {
        TFT9341_DrawPixel((x + j), y, lcdprop.BackColor);
      } 
    }
    y++;      
  }
}
//-------------------------------------------------------------------
void TFT9341_String(uint16_t x,uint16_t y, char *str)
{
  while(*str)
  {
    TFT9341_DrawChar(x,y,str[0]);
    x+=lcdprop.pFont->Width;
    (void)*str++;
  }
}
//-------------------------------------------------------------------
void TFT9341_SetRotation(uint8_t r)
{
  TFT9341_SendCommand(0x36);
  switch(r)
  {
    case 0:
      TFT9341_SendData(0x48);
      TFT9341_WIDTH = 240;
      TFT9341_HEIGHT = 320;
      break;
    case 1:
      TFT9341_SendData(0x28);
      TFT9341_WIDTH = 320;
      TFT9341_HEIGHT = 240;
      break;
    case 2:
      TFT9341_SendData(0x88);
      TFT9341_WIDTH = 240;
      TFT9341_HEIGHT = 320;
      break;
    case 3:
      TFT9341_SendData(0xE8);
      TFT9341_WIDTH = 320;
      TFT9341_HEIGHT = 240;
      break;
  }
}
//-------------------------------------------------------------------





//-------------------------------------------------------------------
void TFT9341_ini(uint16_t w_size, uint16_t h_size)
{
  uint8_t data[15];
	CS_ACTIVE();
	TFT9341_reset();
	//Software Reset
  TFT9341_SendCommand(0x01);
  HAL_Delay(1000);
	//Power Control A  
  data[0] = 0x39;
  data[1] = 0x2C;
  data[2] = 0x00;
  data[3] = 0x34;
  data[4] = 0x02;
  TFT9341_SendCommand(0xCB);
  TFT9341_WriteData(data, 5);
  //Power Control B
  data[0] = 0x00;
  data[1] = 0xC1;
  data[2] = 0x30;
  TFT9341_SendCommand(0xCF);
  TFT9341_WriteData(data, 3);
  //Driver timing control A
  data[0] = 0x85;
  data[1] = 0x00;
  data[2] = 0x78;
  TFT9341_SendCommand(0xE8);
  TFT9341_WriteData(data, 3);
  //Driver timing control B
  data[0] = 0x00;
  data[1] = 0x00;
  TFT9341_SendCommand(0xEA);
  TFT9341_WriteData(data, 2);
  //Power on Sequence control
  data[0] = 0x64;
  data[1] = 0x03;
  data[2] = 0x12;
  data[3] = 0x81;
  TFT9341_SendCommand(0xED);
  TFT9341_WriteData(data, 4);
  //Pump ratio control
  data[0] = 0x20;
  TFT9341_SendCommand(0xF7);
  TFT9341_WriteData(data, 1);
  //Power Control,VRH[5:0]
  data[0] = 0x10;
  TFT9341_SendCommand(0xC0);
  TFT9341_WriteData(data, 1);
  //Power Control,SAP[2:0];BT[3:0]
  data[0] = 0x10;
  TFT9341_SendCommand(0xC1);
  TFT9341_WriteData(data, 1);
  //VCOM Control 1
  data[0] = 0x3E;
  data[1] = 0x28;
  TFT9341_SendCommand(0xC5);
  TFT9341_WriteData(data, 2);
  //VCOM Control 2
  data[0] = 0x86;
  TFT9341_SendCommand(0xC7);
  TFT9341_WriteData(data, 1);
  //Memory Acsess Control
  data[0] = 0x48;
  TFT9341_SendCommand(0x36);
  TFT9341_WriteData(data, 1);
  //Pixel Format Set
  data[0] = 0x55;//16bit
  TFT9341_SendCommand(0x3A);
  TFT9341_WriteData(data, 1);
  //Frame Rratio Control, Standard RGB Color
  data[0] = 0x00;
  data[1] = 0x18;
  TFT9341_SendCommand(0xB1);
  TFT9341_WriteData(data, 2);
  //Display Function Control
  data[0] = 0x08;
  data[1] = 0x82;
  data[2] = 0x27;//320 строк
  TFT9341_SendCommand(0xB6);
  TFT9341_WriteData(data, 3);
  //Enable 3G (пока не знаю что это за режим)
  data[0] = 0x00;//не включаем
  TFT9341_SendCommand(0xF2);
  TFT9341_WriteData(data, 1);
  //Gamma set
  data[0] = 0x01;//Gamma Curve (G2.2) (Кривая цветовой гаммы)
  TFT9341_SendCommand(0x26);
  TFT9341_WriteData(data, 1);
  //Positive Gamma  Correction
  data[0] = 0x0F;
  data[1] = 0x31;
  data[2] = 0x2B;
  data[3] = 0x0C;
  data[4] = 0x0E;
  data[5] = 0x08;
  data[6] = 0x4E;
  data[7] = 0xF1;
  data[8] = 0x37;
  data[9] = 0x07;
  data[10] = 0x10;
  data[11] = 0x03;
  data[12] = 0x0E;
  data[13] = 0x09;
  data[14] = 0x00;
  TFT9341_SendCommand(0xE0);
  TFT9341_WriteData(data, 15);
  //Negative Gamma  Correction
  data[0] = 0x00;
  data[1] = 0x0E;
  data[2] = 0x14;
  data[3] = 0x03;
  data[4] = 0x11;
  data[5] = 0x07;
  data[6] = 0x31;
  data[7] = 0xC1;
  data[8] = 0x48;
  data[9] = 0x08;
  data[10] = 0x0F;
  data[11] = 0x0C;
  data[12] = 0x31;
  data[13] = 0x36;
  data[14] = 0x0F;
  TFT9341_SendCommand(0xE1);
  TFT9341_WriteData(data, 15);
  TFT9341_SendCommand(0x11);//Выйдем из спящего режима
	osDelay(120);
	//Display ON
  data[0] = TFT9341_ROTATION;
  TFT9341_SendCommand(0x29);
  TFT9341_WriteData(data, 1);
	TFT9341_WIDTH = w_size;
  TFT9341_HEIGHT = h_size;
	TFT9341_FontsIni();
	
	
	
}
//-------------------------------------------------------------------
//------------------------------------------------------------ Отправка кадрового буфера на дисплей --------------------------------------
// Нумерация пикселов столбцов и колонок начинается с нуля, поэтому максимальные значения Х и У = TFT9341_WIDTH-1 и TFT9341_HEIGHT-1
void TFT9341_SendFrameBuf(uint8_t *FrBuf, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	if((x1 >= TFT9341_WIDTH) || (y1 >= TFT9341_HEIGHT) || (x2 >= TFT9341_WIDTH) || (y2 >= TFT9341_HEIGHT)) return;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
  TFT9341_SetAddrWindow(x1, y1, x2, y2);
  DC_DATA();
  SPI2_DMA_TransmitIT(FrBuf, MyDisplWidth * MyDisplHeight * 2);
}
//-------------------------------------------------------------------
uint8_t TFT9341_DrawCharToBuf(uint8_t *Buf, uint16_t x, uint16_t y, uint8_t c)
{
	uint32_t i = 0, j = 0;
  uint16_t height, width;
  uint8_t offset;
  uint8_t *c_t;
  uint8_t *pchar;
  uint32_t line=0;
  height = lcdprop.pFont->Height; // Высота символа в пикселах
  width  = lcdprop.pFont->Width;	// Ширина символа в пикселах
  offset = 8 *((width + 7)/8) -  width ; // Ширина непечатаемого остатка в битах от ширины в байтах
  c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' ') * (lcdprop.pFont->Height+1) * ((lcdprop.pFont->Width + 7) / 8)]); // Указатель на начальный байт начертания символа
  //ThisSumbolWidth = *c_t;
	for(i = 1; i < height+1; i++) // Пробегает по высоте символа сверху вниз
  {
    pchar = ((uint8_t *)c_t + (width + 7)/8 * i); // Указатель на строку
    switch(((width + 7)/8))		// Ширина символа в байтах
    {
      case 1:									// Если ширина символа 1 байт
          line =  pchar[0];   // Заполнение 32-битной переменной линиями символа   
          break;
      case 2:									// Если ширина символа 2 байта
          line =  (pchar[0]<< 8) | pchar[1]; // Заполнение 32-битной переменной линиями символа
          break;
      case 3:									// Если ширина символа 3 байта
      default:
        line =  (pchar[0]<< 16) | (pchar[1]<< 8) | pchar[2];  // Заполнение 32-битной переменной линиями символа    
        break;
    }
    for (j = 0; j < width; j++) // Пробегает по одной линии пикселов символова слева направо
    {
      if(line & (1 << (width- j + offset- 1))) 
      {
				Buf[(x*2)+(MyDisplWidth*2*y) + (j*2)] = (lcdprop.TextColor >> 8);
				Buf[(x*2)+(MyDisplWidth*2*y) + ((j*2)+1)] = (lcdprop.TextColor);
        //TFT9341_DrawPixel((x + j), y, lcdprop.TextColor);
      }
      else
      {
				Buf[(x*2)+(MyDisplWidth*2*y) + (j*2)] = (lcdprop.BackColor >> 8);
				Buf[(x*2)+(MyDisplWidth*2*y) + ((j*2)+1)] = (lcdprop.BackColor);
        //TFT9341_DrawPixel((x + j), y, lcdprop.BackColor);
      } 
    }
    y++;      
  }
	return *c_t;
}
//-------------------------------------------------------------------
uint8_t TFT9341_DrawCharToBufFM(uint8_t *Buf, uint16_t x, uint16_t y, uint8_t c)
{
	uint32_t i = 0, j = 0;
  uint16_t height, width;
  uint8_t offset;
  uint8_t *c_t;
  uint8_t *pchar;
  uint32_t line=0;
  height = lcdprop.pFont->Height; // Высота символа в пикселах
  width  = lcdprop.pFont->Width;	// Ширина символа в пикселах
  offset = 8 *((width + 7)/8) -  width ; // Ширина непечатаемого остатка в битах от ширины в байтах
	if(c>=0x80 && c <= 0xAF)
		c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' '+64) * (lcdprop.pFont->Height+1) * ((lcdprop.pFont->Width + 7) / 8)]); // Указатель на начальный байт начертания символа
	else if(c>=0xE0 && c <= 0xEF)
		c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' '+16) * (lcdprop.pFont->Height+1) * ((lcdprop.pFont->Width + 7) / 8)]); // Указатель на начальный байт начертания символа
	else
		c_t = (uint8_t*) &(lcdprop.pFont->table[(c-' ') * (lcdprop.pFont->Height+1) * ((lcdprop.pFont->Width + 7) / 8)]); // Указатель на начальный байт начертания символа
  //ThisSumbolWidth = *c_t;
	for(i = 1; i < height+1; i++) // Пробегает по высоте символа сверху вниз
  {
    pchar = ((uint8_t *)c_t + (width + 7)/8 * i); // Указатель на строку
    switch(((width + 7)/8))		// Ширина символа в байтах
    {
      case 1:									// Если ширина символа 1 байт
          line =  pchar[0];   // Заполнение 32-битной переменной линиями символа   
          break;
      case 2:									// Если ширина символа 2 байта
          line =  (pchar[0]<< 8) | pchar[1]; // Заполнение 32-битной переменной линиями символа
          break;
      case 3:									// Если ширина символа 3 байта
      default:
        line =  (pchar[0]<< 16) | (pchar[1]<< 8) | pchar[2];  // Заполнение 32-битной переменной линиями символа    
        break;
    }
    for (j = 0; j < width; j++) // Пробегает по одной линии пикселов символова слева направо
    {
      if(line & (1 << (width- j + offset- 1))) 
      {
				Buf[(x*2)+(MyDisplWidth*2*y) + (j*2)] = (lcdprop.TextColor >> 8);
				Buf[(x*2)+(MyDisplWidth*2*y) + ((j*2)+1)] = (lcdprop.TextColor);
        //TFT9341_DrawPixel((x + j), y, lcdprop.TextColor);
      }
      else
      {
				Buf[(x*2)+(MyDisplWidth*2*y) + (j*2)] = (lcdprop.BackColor >> 8);
				Buf[(x*2)+(MyDisplWidth*2*y) + ((j*2)+1)] = (lcdprop.BackColor);
        //TFT9341_DrawPixel((x + j), y, lcdprop.BackColor);
      } 
    }
    y++;      
  }
	return *c_t;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void TFT9341_StringToBuf(uint8_t *Buf, uint16_t x,uint16_t y, char *str)
{
  while(*str)
  {
		if((x + lcdprop.pFont->Width) < MyDisplWidth)
		{
			x += TFT9341_DrawCharToBuf(Buf, x, y, str[0]);
			x++;
		}
    (void)*str++;
  }
}
/********************************************************************************************************************/
void TFT9341_StringToBufFM(uint8_t *Buf, uint16_t x,uint16_t y, char *str)
{
	while((x + lcdprop.pFont->Width) < MyDisplWidth-18)
  {
		if(*str)
		{
			x += TFT9341_DrawCharToBufFM(Buf, x, y, str[0]);
			x++;
			(void)*str++;
		}
		else
		{
			x += TFT9341_DrawCharToBuf(Buf, x, y,' ');
		}
  }
	
	while(x < MyDisplWidth-16)	// Заполнение фоном до полосы прокрутки
	{
		for(uint16_t i = y;i<y+lcdprop.pFont->Height;i++)
		{
			Buf[i*MyDisplWidth*2 + x*2] = lcdprop.BackColor >> 8;
			Buf[i*MyDisplWidth*2 + x*2 + 1] = lcdprop.BackColor;
		}
		x++;
	}
}
/********************************************************************************************************************/

/********************************************************************************************************************/
void DrawPictureToBuf(uint8_t *Buf, uint16_t x,uint16_t y, const uint8_t *Picture, uint16_t PicWidth, uint16_t PicHeight)
{
	if((x+PicWidth)>MyDisplWidth){return;}
	if((y+PicHeight)>MyDisplHeight){return;}
	uint32_t StartPosition = (MyDisplWidth*2*y)+(x*2);
	for(uint8_t P_String = 0;P_String < PicHeight; P_String++)
	{
		for(uint8_t P_Column = 0;P_Column < PicWidth; P_Column++)
		{
			Buf[(StartPosition+(P_Column*2)+(P_String*MyDisplWidth*2))] = Picture[((P_Column*2)+(PicWidth*2*P_String))]; 
			Buf[(StartPosition+(P_Column*2)+(P_String*MyDisplWidth*2)+1)] = Picture[((P_Column*2)+(PicWidth*2*P_String)+1)];
		}
	}
}

/********************************************************************************************************************/
void DrawVolToFrameBuf(uint8_t *Buf, uint16_t x, uint16_t y, uint16_t FillingColor, uint16_t BackgroundColor, float Vol)
{ 
	#define X_column_Max 60
	if(Vol > 150){Vol = 150;}
	uint32_t fillingBorder = (uint32_t)(X_column_Max - (Vol /(float)2.5));
	uint32_t y_offset;
	for(uint32_t x_column = 0; x_column < X_column_Max; x_column++)
	{
		y_offset = x_column / 4;
		Buf[(y*MyDisplWidth*2)+(x*2) + (x_column*2)] = FillingColor >> 8;
		Buf[(y*MyDisplWidth*2)+(x*2) + (x_column*2) + 1] = FillingColor;
		Buf[((y-y_offset)*MyDisplWidth*2)+(x*2) + (x_column*2)] = FillingColor >> 8;
		Buf[((y-y_offset)*MyDisplWidth*2)+(x*2) + (x_column*2)+1] = FillingColor;
	}
	for(uint8_t i = y_offset; i > 0; i--)
	{
		Buf[((y-i)*MyDisplWidth*2)+(x*2-2)+(X_column_Max*2)] = FillingColor >> 8;
		Buf[((y-i)*MyDisplWidth*2)+(x*2-2)+(X_column_Max*2)+1] = FillingColor;
	}
	for(uint32_t x_column = 0; x_column< X_column_Max-1; x_column++)
	{
		y_offset = x_column / 4;
		for(uint8_t y_row = 1; y_row < y_offset; y_row++)
		{
			if(x_column>6 && x_column <= fillingBorder)
			{
				Buf[((y-y_row)*MyDisplWidth*2)+(x*2) + (x_column*2)] = FillingColor >> 8;
				Buf[((y-y_row)*MyDisplWidth*2)+(x*2) + (x_column*2)+1] = FillingColor;
			}
			else if(x_column > 6 && x_column > fillingBorder)
			{
				Buf[((y-y_row)*MyDisplWidth*2)+(x*2) + (x_column*2)] = BackgroundColor >> 8;
				Buf[((y-y_row)*MyDisplWidth*2)+(x*2) + (x_column*2)+1] = BackgroundColor;
			}
			
		}
	}
}

/********************************************************************************************************************/
/********************************************************************************************************************/
void PrintScrolLine(FilManParamTypedef *FMP_, uint16_t x_start, uint16_t y_start, uint16_t LenghtPixel, uint16_t FillingColor, uint16_t BackgroundColor)
{
	// Стрелка вверх
	uint16_t ArrowUp[16]=  {0xFFFF, 0x8001, 0x8001, 0x8001, 0x8001, 0x8181, 0x83C1, 0x87E1, 0x8FF1, 0x9FF9, 0xBFFD, 0x8001, 0x8001, 0x8001, 0x8001, 0xFFFF};
	// Стрелка вниз
	uint16_t ArrowDown[16]={0xFFFF, 0x8001, 0x8001, 0x8001, 0x8001, 0xBFFD, 0x9FF9, 0x8FF1, 0x87E1, 0x83C1, 0x8181, 0x8001, 0x8001, 0x8001, 0x8001, 0xFFFF};
	//uint32_t DisplQuantity = FMP_->DirItemsNumber/DisplPrintRows;
	// (LenghtPixel-32)/DisplQuantity
	uint32_t SquarePositionPixel = FMP_->FirstPrintedItem * (LenghtPixel-48)/(FMP_->DirItemsNumber - FMP_->DirItemsNumber%DisplPrintRows);
	//------------------------------------- Отрисовка стрелки вверх -----------------------------------
	for(uint8_t i = 0; i < 16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
			if(ArrowUp[i] & (0x8000 >> j))
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i] = FillingColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i + 1] = FillingColor;
			}
			else
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i] = BackgroundColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i + 1] = BackgroundColor;
			}
		}
	}
	//--------------------------------------- Отрисовка линии ----------------------------------------
	for(uint16_t i = y_start+15; i < y_start+LenghtPixel-16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
			if(j == 7 || j == 8)
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i] = FillingColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i + 1] = FillingColor;
			}
			else
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i] = BackgroundColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*i + 1] = BackgroundColor;
			}
		}
	}
	//------------------------------------ Отрисовка стрелки вниз -------------------------------------
	for(uint8_t i = 0; i < 16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
			if(ArrowDown[i] & (0x8000 >> j))
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*(i+y_start + LenghtPixel - 16)] = FillingColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*(i+y_start + LenghtPixel - 16) + 1] = FillingColor;
			}
			else
			{
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*(i+y_start + LenghtPixel - 16)] = BackgroundColor >> 8;
				FMP_->FrBuf[x_start*2 + j*2 + MyDisplWidth*2*(i+y_start + LenghtPixel - 16) + 1] = BackgroundColor;
			}
		}
	}
	//--------------------------- Отрисовка бегающего квадратика ---------------------------------
	for(uint8_t i = 0; i < 16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
				FMP_->FrBuf[x_start*2 + MyDisplWidth*2*(i+y_start+15+SquarePositionPixel)+ j*2] = FillingColor >> 8;
				FMP_->FrBuf[x_start*2 + MyDisplWidth*2*(i+y_start+15+SquarePositionPixel)+ j*2 + 1] = FillingColor;
		}
	}
	
	
	
}
/********************************************************************************************************************/
/******************** Получает кол-во элементов в данной директории за исключением системных ************************/
uint32_t GetItemNumberInThisDir(FilManParamTypedef *FMP)
{
	if(FMP->MountState == CardIsMounted)		// Проверка, смонтирована ли SD Карта
	{
		if(f_opendir(&FMP->dir2, "/") == FR_OK)   // Open Root
		{
			do
			{
				f_readdir(&FMP->dir2, &FMP->FileInfo2); // Читает какиие файлы есть в директории один за другим
				if(FMP->FileInfo2.fname[0] != 0)
				{ 
					if((FMP->FileInfo2.fattrib & AM_SYS)==0) // Если файл не системный
					{
						FMP->DirItemsNumber++;		// Количество файлов и папок находящихся в корневом каталоге за исключением системных
					}
				}
			} 
			while(FMP->FileInfo2.fname[0] != 0);
		}
		f_closedir(&FMP->dir2);
	}
	return FMP->DirItemsNumber;
}
/********************************************************************************************************************/
extern const uint8_t PropertiesBtn[];
extern const uint8_t ListBtn[];
/************************** Распечатывает страницу названий директорий на экран *************************************/
void FileManager(FilManParamTypedef *FMP)
{
	if(FMP->Screen == MainScreen)
	{
		uint32_t i = 0;
		uint16_t k = 0;
		uint32_t LastPrintedItem = FMP->FirstPrintedItem + DisplPrintRows;
		if(f_opendir(&FMP->dir2, "/") == FR_OK)   // Open Root
		{
			TFT9341_SetTextColor(TFT9341_BLUE);
			TFT9341_SetBackColor(TFT9341_BLACK);
			while(i < LastPrintedItem)
			{
				f_readdir(&FMP->dir2, &FMP->FileInfo2);
				if((FMP->FileInfo2.fattrib & AM_SYS)==0) // Если директория ни системная
				{
					if(i >= FMP->FirstPrintedItem && i < LastPrintedItem)
					{ 
						if(FMP->FileInfo2.fname[0] != 0) // Если файлы еще есть на диске
						{
							TFT9341_StringToBufFM(FMP->FrBuf,18,(i-FMP->FirstPrintedItem)*18 ,FMP->FileInfo2.fname); // Печатает имя файла
							k = 0;
							do{
								FMP->FilesArray[i-FMP->FirstPrintedItem][k] = FMP->FileInfo2.fname[k]; // Сохраняет имя файла в массив
							}while(FMP->FileInfo2.fname[k++] !=0);
							if( FMP->FileInfo2.altname[8] == '.' ) // Если это файл
							{
								DrawPictureToBuf(FMP->FrBuf, 0,(i-FMP->FirstPrintedItem)*18, MusicIcon, 18, 18); // Рисует иконку файла
							}
							else
							{
								DrawPictureToBuf(FMP->FrBuf, 0,(i-FMP->FirstPrintedItem)*18, FolderIcon, 18, 18); // Рисует иконку папки
							}
						}
						else
						{
							for(;i < LastPrintedItem; i++)
							{
								TFT9341_StringToBufFM(FMP->FrBuf,0,(i-FMP->FirstPrintedItem)*18 ," "); // Заполняет строку фоном
								FMP->FilesArray[i-FMP->FirstPrintedItem][0] = 0;	
							}
						}
					}
					i++;
				}
			}
		}
		f_closedir(&FMP->dir2);
		PrintScrolLine(FMP, 224, 1, 216, TFT9341_BLUE, TFT9341_BLACK);	// Отрисовка полосы прокрутки
		DrawPictureToBuf(FMP->FrBuf, 5,225, PropertiesBtn, 30, 30);
	}
	else if(FMP->Screen == EqualizerScreen)
	{
		for(uint32_t i =0; i < 104160; i++)
		{
			FMP->FrBuf[i] = 0;
		}
		DrawPictureToBuf(FMP->FrBuf, 5,225, ListBtn, 30, 30);
		//DrawBar(FMP->FrBuf,45,36,150,18,0,15, HF_Gain , TFT9341_GREEN, TFT9341_BLACK);
		TFT9341_SetTextColor(TFT9341_WHITE);
		TFT9341_SetBackColor(TFT9341_BLACK);
		TFT9341_StringToBuf(FMP->FrBuf,83,18,"Усиление ВЧ"); // Печатает Усиление ВЧ
		FMP->DrawHF_GainBarReq = ThereIsReq;
		DrawPlusBtn(FMP->FrBuf,205,37,TFT9341_BLUE,TFT9341_BLACK);
		DrawMinusBtn(FMP->FrBuf,20,37,TFT9341_BLUE,TFT9341_BLACK);
		
		TFT9341_StringToBuf(FMP->FrBuf,88,72,"Граница ВЧ"); // Печатает Граница ВЧ
		FMP->DrawHF_BorderBarReq = ThereIsReq;
		DrawPlusBtn(FMP->FrBuf,205,91,TFT9341_BLUE,TFT9341_BLACK);
		DrawMinusBtn(FMP->FrBuf,20,91,TFT9341_BLUE,TFT9341_BLACK);
		
		TFT9341_StringToBuf(FMP->FrBuf,83,126,"Усиление НЧ"); // Печатает Усиление НЧ
		FMP->DrawLF_GainBarReq = ThereIsReq;
		DrawPlusBtn(FMP->FrBuf,205,145,TFT9341_BLUE,TFT9341_BLACK);
		DrawMinusBtn(FMP->FrBuf,20,145,TFT9341_BLUE,TFT9341_BLACK);
		
		TFT9341_StringToBuf(FMP->FrBuf,88,179,"Граница НЧ"); // Печатает Граница НЧ
		FMP->DrawLF_BorderBarReq = ThereIsReq;
		DrawPlusBtn(FMP->FrBuf,205,198,TFT9341_BLUE,TFT9341_BLACK);
		DrawMinusBtn(FMP->FrBuf,20,198,TFT9341_BLUE,TFT9341_BLACK);
	}
}

/********************************************************************************************************************/
/********************************************************************************************************************/
void Highlighting(FilManParamTypedef *FMP, uint32_t ActPlayFile)
{
	uint32_t LastPrintedItem = FMP->FirstPrintedItem + DisplPrintRows;
	if(FMP->HighlightedItemNumber >= FMP->FirstPrintedItem && FMP->HighlightedItemNumber < LastPrintedItem )	// Возврат цветов, которые были до выделения
	{
		TFT9341_SetTextColor(TFT9341_BLUE);
		TFT9341_SetBackColor(TFT9341_BLACK);
		TFT9341_StringToBufFM(FMP->FrBuf,18,((FMP->HighlightedItemNumber - FMP->FirstPrintedItem)*18), FMP->FilesArray[FMP->HighlightedItemNumber - FMP->FirstPrintedItem]); //
	}
	FMP->HighlightedItemNumber = ActPlayFile; // Запоминание номера выделяемой строки

	if(ActPlayFile >= FMP->FirstPrintedItem && ActPlayFile < (LastPrintedItem))
	{
		TFT9341_SetTextColor(TFT9341_WHITE);
		TFT9341_SetBackColor(TFT9341_BLUE);
		TFT9341_StringToBufFM(FMP->FrBuf,18,((ActPlayFile-FMP->FirstPrintedItem)*18), FMP->FilesArray[ActPlayFile - FMP->FirstPrintedItem]); // Выделение строки
	}
}
/********************************************************************************************************************/
/********************************************************************************************************************/
extern FIL SDFile;
extern uint8_t PlaybackBuf[_MAX_SS];
extern FATFS SDFatFS;    /* File system object for SD logical drive */
extern RequestsTypedef HighlightingReq;
extern RequestsTypedef PrintPageReq;
void ReadFile(FilManParamTypedef *FMP, uint32_t *ActPlayFile)
{
	static uint32_t CurrentFile = 0; 				// Воспроизыодимый сейчас файл
	uint32_t NumberOfRead = 0;
	if(FMP->MountState == CardIsMounted)		// Проверка, смонтирована ли SD Карта
	{
		if(*ActPlayFile != CurrentFile)		// Если номер файла, который нужно воспроизвести, на 1 больше воспроизводимого в данный момент файла
		{
			f_close(&SDFile); 									// Закрывает файл
			FMP->RreadDirState = DirNotRread;		// Директория не прочитана
			FMP->FileOpenState = FileNotOpened; // Файл не прочитан
			if(*ActPlayFile>=CurrentFile)
			{
				NumberOfRead = *ActPlayFile - CurrentFile;
			}
			else
			{
				f_closedir(&FMP->dir); // Закрывает корневой каталог
				FMP->OpenDirState = DirClosed;
				NumberOfRead = *ActPlayFile+1;
			}
		}
		
		
		//--------------------------------------- Открывает корневой каталог ---------------------------------------
		if(FMP->OpenDirState == DirClosed) 
		{
			if(f_opendir(&FMP->dir, "/") == FR_OK)   // Open Root
				FMP->OpenDirState = DirOpend;
		}
		
		//----------------------------------- Чтение элементов текущей дериктории ----------------------------------
		if(FMP->OpenDirState == DirOpend && FMP->RreadDirState == DirNotRread) // Если директория открыта но не прочитана
		{
								
			do
			{				
				if(f_readdir(&FMP->dir, &FMP->FileInfo) == FR_OK) // Читает свойства следующего Элемента директории (файла или папки)
				{
					if((FMP->FileInfo.fattrib & AM_SYS)==0)    // Если прочитанная директория ни системная
					{
						FMP->RreadDirState = DirRread;
						if(NumberOfRead>0){NumberOfRead--;}
					}					
				}
				if(FMP->FileInfo.fname[0]==0) // Если элементы в корневом каталоге закончились
				{
					f_closedir(&FMP->dir); // Закрывает корневой каталог
					FMP->OpenDirState = DirClosed;
					FMP->RreadDirState = DirNotRread;
					FMP->FileOpenState = FileNotOpened;
					*ActPlayFile = 0;
					FMP->FirstPrintedItem = 0;
					PrintPageReq = ThereIsReq;
					HighlightingReq = ThereIsReq;
					break;
				}
				//if(NumberOfRead>0){NumberOfRead--;}
			}while(NumberOfRead>0);
			CurrentFile = *ActPlayFile;
			
		}
		
		//-------------------------------------------------- Открытие файла -----------------------------------------------
		if(FMP->RreadDirState == DirRread)
		{
			if(FMP->FileInfo.altname[8] == '.' && FMP->FileInfo.altname[9] == 'M' && FMP->FileInfo.altname[10] == 'P' && FMP->FileInfo.altname[11] == '3')
			{
				if(FMP->FileOpenState == FileNotOpened)
				{
					if(f_open(&SDFile, FMP->FileInfo.fname,FA_READ) == FR_OK) // Открывает файл, прочитанный командой f_readdir(&dir, &FileInfo);
					{
						FMP->FileOpenState = FileOpened;
						FMP->FileSize = (uint32_t) f_size(&SDFile);
						FMP->FileSizeRead = 0;
					}
				}
			}
			else
			{
				FMP->RreadDirState = DirNotRread;
				*ActPlayFile +=1;
				HighlightingReq = ThereIsReq;
			}
		}
		
		//-------------------------------------------------- Чтение байтов файла -----------------------------------------------
		if(FMP->FileOpenState == FileOpened)
		{
			if(FMP->FileSizeRead < FMP->FileSize)
			{
				if(FMP->PlaybackBufBytesFilled == 0)
				{
					f_read(&SDFile, PlaybackBuf, SDFatFS.ssize, &FMP->BytesRead); // Чтение одного сектора файла в буфер
					FMP->FileSizeRead += FMP->BytesRead;													// Всего прочитано байт открытого файла
					FMP->PlaybackBufBytesFilled = FMP->BytesRead;	// Запоминание количества байт, записанных в буфер (это не индекс)
					FMP->PlaybackBufTxIndex = 0;									// Обнуление индекса передачи данных в кодек
					FMP->ProgressDrawReq = ThereIsReq;						// Флаг запроса отрисовки полосы воспроизведения файла
				}
			}
			else
			{
				f_close(&SDFile); // Закрывает файл
				FMP->FileOpenState = FileNotOpened;
				FMP->RreadDirState = DirNotRread;
				*ActPlayFile +=1;
				if(FMP->Screen == MainScreen) HighlightingReq = ThereIsReq;
			}
			
		}
	}

}
/********************************************************************************************************************/
void DrawBar(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t Length,uint16_t Height,uint8_t ValMin,uint8_t ValMax, uint8_t Val, uint16_t FillingColor, uint16_t BackgroundColor)
{
	for(uint16_t j = x*2; j <= (x+Length)*2; j +=2) // Отрисовка 2х горизонтальных полос
	{
		FrBuf[(y*MyDisplWidth*2)+ j] = FillingColor >> 8;
		FrBuf[(y*MyDisplWidth*2)+ j + 1] = FillingColor;
		FrBuf[((y+Height)*MyDisplWidth*2)+ j] = FillingColor >> 8;
		FrBuf[((y+Height)*MyDisplWidth*2)+ j + 1] = FillingColor;
	}
	for(uint16_t i = y; i < (y+Height); i++) // Отрисовка 2х вертикальных полос
	{
		FrBuf[(i*MyDisplWidth*2)+ x*2] = FillingColor >> 8;
		FrBuf[(i*MyDisplWidth*2)+ x*2 + 1] = FillingColor;
		FrBuf[(i*MyDisplWidth*2)+(x+Length)*2] = FillingColor >> 8;
		FrBuf[(i*MyDisplWidth*2)+(x+Length)*2 + 1] = FillingColor;
	}
	
	uint16_t FelingBorder =	x+(Length/(ValMax-ValMin))*Val;
	for(uint16_t i = y+1; i < (y+Height); i++) // Заливка
	{
		for(uint16_t j = (x+1); j < FelingBorder; j++)
		{
			FrBuf[(i*MyDisplWidth*2)+ j*2] = FillingColor >> 8;
			FrBuf[(i*MyDisplWidth*2)+ j*2 + 1] = FillingColor;
		}
		for(uint16_t j = FelingBorder+1; j < (x+Length); j++)
		{
			FrBuf[(i*MyDisplWidth*2)+ j*2] = BackgroundColor >> 8;
			FrBuf[(i*MyDisplWidth*2)+ j*2 + 1] = BackgroundColor;
		}
	}
}
/********************************************************************************************************************/
void DrawPlusBtn(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t FillingColor,uint16_t BackgroundColor)
{
	const uint16_t Btn[] = {0xFFFF, 0xFFFF, 0xC003, 0xC183, 0xC183, 0xC183, 0xC183, 0xDFFB, 0xDFFB, 0xC183, 0xC183, 0xC183, 0xC183, 0xC003, 0xFFFF, 0xFFFF};

	for(uint8_t i = 0; i < 16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
			if(Btn[i] & (0x8000 >> j))
			{
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y)] = FillingColor >> 8;
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y) + 1] = FillingColor;
			}
			else
			{
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y)] = BackgroundColor >> 8;
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y) + 1] = BackgroundColor;
			}
		}
	}
}
/********************************************************************************************************************/
void DrawMinusBtn(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t FillingColor,uint16_t BackgroundColor)
{
	const uint16_t Btn[] = {0xFFFF, 0xFFFF, 0xC003, 0xC003, 0xC003, 0xC003, 0xC003, 0xDFFB, 0xDFFB, 0xC003, 0xC003, 0xC003, 0xC003, 0xC003, 0xFFFF, 0xFFFF};

	for(uint8_t i = 0; i < 16; i++)
	{
		for(uint8_t j = 0; j < 16; j++)
		{
			if(Btn[i] & (0x8000 >> j))
			{
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y)] = FillingColor >> 8;
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y) + 1] = FillingColor;
			}
			else
			{
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y)] = BackgroundColor >> 8;
				FrBuf[x*2 + j*2 + MyDisplWidth*2*(i+y) + 1] = BackgroundColor;
			}
		}
	}
}
/********************************************************************************************************************/
/********************************************************************************************************************/
void DrawBar32(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t Length,uint16_t Height,float ValMin,float ValMax, float Val, uint16_t FillingColor, uint16_t BackgroundColor)
{
	for(uint16_t j = x*2; j <= (x+Length)*2; j +=2) // Отрисовка 2х горизонтальных полос
	{
		FrBuf[(y*MyDisplWidth*2)+ j] = FillingColor >> 8;
		FrBuf[(y*MyDisplWidth*2)+ j + 1] = FillingColor;
		FrBuf[((y+Height)*MyDisplWidth*2)+ j] = FillingColor >> 8;
		FrBuf[((y+Height)*MyDisplWidth*2)+ j + 1] = FillingColor;
	}
	for(uint16_t i = y; i < (y+Height); i++) // Отрисовка 2х вертикальных полос
	{
		FrBuf[(i*MyDisplWidth*2)+ x*2] = FillingColor >> 8;
		FrBuf[(i*MyDisplWidth*2)+ x*2 + 1] = FillingColor;
		FrBuf[(i*MyDisplWidth*2)+(x+Length)*2] = FillingColor >> 8;
		FrBuf[(i*MyDisplWidth*2)+(x+Length)*2 + 1] = FillingColor;
	}
	
	uint16_t FelingBorder =	x+ (uint16_t)(((float)Length/(ValMax-ValMin))*Val);
	for(uint16_t i = y+1; i < (y+Height); i++) // Заливка
	{
		for(uint16_t j = (x+1); j < FelingBorder; j++)
		{
			FrBuf[(i*MyDisplWidth*2)+ j*2] = FillingColor >> 8;
			FrBuf[(i*MyDisplWidth*2)+ j*2 + 1] = FillingColor;
		}
		for(uint16_t j = FelingBorder+1; j < (x+Length); j++)
		{
			FrBuf[(i*MyDisplWidth*2)+ j*2] = BackgroundColor >> 8;
			FrBuf[(i*MyDisplWidth*2)+ j*2 + 1] = BackgroundColor;
		}
	}
}
/********************************************************************************************************************/
/********************************************************************************************************************/
void DisplOff(void)
{
	TFT9341_SendCommand(ILI9341_SleepIn);
	HAL_GPIO_WritePin(TFT_Brightnes_GPIO_Port,TFT_Brightnes_Pin,GPIO_PIN_RESET);
}
/********************************************************************************************************************/
/********************************************************************************************************************/
void DisplOn(void)
{
	TFT9341_SendCommand(ILI9341_SleepOut);
	HAL_GPIO_WritePin(TFT_Brightnes_GPIO_Port,TFT_Brightnes_Pin,GPIO_PIN_SET);
}
/********************************************************************************************************************/
/********************************************************************************************************************/


/**/
