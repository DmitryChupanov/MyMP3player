#ifndef __SPI_ILI9341_H
#define __SPI_ILI9341_H

//#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "fonts.h"
#include "ff.h"

#define MyDisplWidth 240
#define MyDisplHeight 320
#define DisplPrintRows 12	// Количество элементов печатаемых на экран

#define RESET_ACTIVE() HAL_GPIO_WritePin(TFT_RST_GPIO_Port,TFT_RST_Pin,GPIO_PIN_RESET)
#define RESET_IDLE() HAL_GPIO_WritePin(TFT_RST_GPIO_Port,TFT_RST_Pin,GPIO_PIN_SET)
#define CS_ACTIVE() HAL_GPIO_WritePin(TFT_CS_GPIO_Port,TFT_CS_Pin,GPIO_PIN_RESET)
#define CS_IDLE() HAL_GPIO_WritePin(TFT_CS_GPIO_Port,TFT_CS_Pin,GPIO_PIN_SET)
#define DC_COMMAND() HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_RESET)
#define DC_DATA() HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_SET)
//-------------------------------------------------------------------
#define TFT9341_MADCTL_MY  0x80
#define TFT9341_MADCTL_MX  0x40
#define TFT9341_MADCTL_MV  0x20
#define TFT9341_MADCTL_ML  0x10
#define TFT9341_MADCTL_RGB 0x00
#define TFT9341_MADCTL_BGR 0x08
#define TFT9341_MADCTL_MH  0x04
#define TFT9341_ROTATION (TFT9341_MADCTL_MX | TFT9341_MADCTL_BGR)
#define	TFT9341_BLACK   0x0000
#define	TFT9341_BLUE    0x001F
#define	TFT9341_RED     0xF800
#define	TFT9341_GREEN   0x07E0
#define TFT9341_CYAN    0x07FF
#define TFT9341_MAGENTA 0xF81F
#define TFT9341_YELLOW  0xFFE0
#define TFT9341_WHITE   0xFFFF
//-------------------------------------------------------------------
#define swap(a,b) {int16_t t=a;a=b;b=t;}
//-------------------------------------------------------------------

void TFT9341_ini(uint16_t w_size, uint16_t h_size);
void TFT9341_FillRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void TFT9341_FillScreen(uint16_t color);
uint16_t TFT9341_RandColor(void);
uint32_t TFT9341_RandColor32(void);
void TFT9341_DrawPixel(int x, int y, uint16_t color);
void TFT9341_DrawLine(uint16_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void TFT9341_DrawRect(uint16_t color, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void TFT9341_DrawCircle(uint16_t x0, uint16_t y0, int r, uint16_t color);
void TFT9341_DrawChar(uint16_t x, uint16_t y, uint8_t c);
void TFT9341_String(uint16_t x,uint16_t y, char *str);
void TFT9341_SetRotation(uint8_t r);
void TFT9341_SetTextColor(uint16_t color);
void TFT9341_SetBackColor(uint16_t color);
void TFT9341_SetFont(sFONT *pFonts);
void TFT9341_SendFrameBuf(uint8_t *FrBuf, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
uint8_t TFT9341_DrawCharToBuf(uint8_t *Buf, uint16_t x, uint16_t y, uint8_t c);
void TFT9341_StringToBuf(uint8_t *Buf, uint16_t x,uint16_t y, char *str);
void TFT9341_StringToBufFM(uint8_t *Buf, uint16_t x,uint16_t y, char *str);
void DrawPictureToBuf(uint8_t *Buf, uint16_t x,uint16_t y, const uint8_t *Picture, uint16_t PicWidth, uint16_t PicHeight);
void DrawVolToFrameBuf(uint8_t *Buf, uint16_t x, uint16_t y, uint16_t FillingColor, uint16_t BackgroundColor, float Vol);


typedef enum{
	CardIsUnmounted,
	CardIsMounted,
}MountCardStateTypedef;

typedef enum{
	DirClosed,
	DirOpend,
}OpenDirStateTupedef;

typedef enum{
	DirNotRread,
	DirRread,
}RreadDirStateTupedef;

typedef enum{
	FileNotOpened,
	FileOpened,
}FileOpenStateTupedef;

typedef enum{
	NoReq,
	ThereIsReq,
}RequestsTypedef;

typedef enum{
	MainScreen,
	EqualizerScreen,
}ScreenTypedef;

typedef struct{
	
	MountCardStateTypedef MountState;
	uint32_t DirItemsNumber; 							// Общее количество файлов и папок в директории за исключением системных
	uint8_t *FrBuf;
	uint32_t FirstPrintedItem; 						// Текущий первый напечатанный элемент
	uint32_t HighlightedItemNumber;				// Номер выделенного цветом элемента
	OpenDirStateTupedef OpenDirState;			// Состояние открытости директории
	RreadDirStateTupedef RreadDirState;		// Состояние прочитанности очередного элемента открытой директории
	FileOpenStateTupedef FileOpenState;		// Состояние открытости файла
	uint32_t FileSize;										// Размер файла
	uint32_t FileSizeRead;								// Размер считанной части файла
	uint32_t PlaybackBufBytesFilled;			// Сколько байт сейчас записано в PlaybackBuf
	UINT BytesRead;												// Прочитано байт при последнем вызове функции f_read(&SDFile, PlaybackBuf, SDFatFS.ssize, &BytesRead);
	uint32_t PlaybackBufTxIndex;					// Индекс для передачи данных из буфера на кодэк
	ScreenTypedef Screen;									// Активнфй экран
	RequestsTypedef DrawHF_GainBarReq; 		// Флаг запроса печати бара усиления высоких частот
	RequestsTypedef DrawHF_BorderBarReq; 	// Флаг запроса печати бара границы высоких частот
	RequestsTypedef DrawLF_GainBarReq; 		// Флаг запроса печати бара усиления низких частот
	RequestsTypedef DrawLF_BorderBarReq; 	// Флаг запроса печати бара границы низких частот
	RequestsTypedef ProgressDrawReq; 			// Флаг запроса отрисовки полосы воспроизведения файла
	
	char FilesArray[DisplPrintRows][_MAX_LFN + 1];
	DIR dir;                    		// Directory
	DIR dir2;                    		// Directory
	FILINFO FileInfo;               // File Info
	FILINFO FileInfo2;              // File Info
}FilManParamTypedef;


void PrintScrolLine(FilManParamTypedef *FMP_, uint16_t x_start, uint16_t y_start, uint16_t LenghtPixel, uint16_t FillingColor, uint16_t BackgroundColor); // Печатает линию прокрутки
uint32_t GetItemNumberInThisDir(FilManParamTypedef *FMP); // Получает кол-во элементов в данной директории за исключением системных
void FileManager(FilManParamTypedef *FMP); 
void Highlighting(FilManParamTypedef *FMP, uint32_t ActPlayFile);
void ReadFile(FilManParamTypedef *FMP, uint32_t *ActPlayFile);
void DrawBar(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t Length,uint16_t Height,uint8_t ValMin,uint8_t ValMax, uint8_t Val, uint16_t FillingColor, uint16_t BackgroundColor);
void DrawPlusBtn(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t FillingColor,uint16_t BackgroundColor);
void DrawMinusBtn(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t FillingColor,uint16_t BackgroundColor);
void DrawBar32(uint8_t *FrBuf,uint16_t x,uint16_t y,uint16_t Length,uint16_t Height,float ValMin,float ValMax, float Val, uint16_t FillingColor, uint16_t BackgroundColor);

#define ILI9341_SleepIn 0x10
#define ILI9341_SleepOut 0x11
void DisplOff(void);
void DisplOn(void);







#endif /*__SPI_ILI9341_H*/

/**/
