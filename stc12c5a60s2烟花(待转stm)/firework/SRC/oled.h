#ifndef __OLED_H
#define __OLED_H

//#include "REG51.h"		
#include <stc12c5a60s2.h>  	 
 
#define  u8 unsigned char 
#define  u16 unsigned int
#define  u32 unsigned int
	
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

#define	SSIG		1	//1: ����SS�ţ���MSTRλ�����������Ǵӻ�		0: SS�����ھ������ӻ���
#define	SPEN		1	//1: ����SPI��								0����ֹSPI������SPI�ܽž�Ϊ��ͨIO
#define	DORD		0	//1��LSB�ȷ���								0��MSB�ȷ�
#define	MSTR		1	//1����Ϊ����								0����Ϊ�ӻ�
#define	CPOL		1	//1: ����ʱSCLKΪ�ߵ�ƽ��					0������ʱSCLKΪ�͵�ƽ
#define	CPHA		1	//
#define	SPR1		0	//SPR1,SPR0   00: fosc/4,     01: fosc/16
#define	SPR0		0	//            10: fosc/64,    11: fosc/128
#define	SPEED_4		0	// fosc/4
#define	SPEED_16	1	// fosc/16
#define	SPEED_64	2	// fosc/64
#define	SPEED_128	3	// fosc/128

//sfr SPSTAT  = 0xCD;	//SPI״̬�Ĵ���
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		//SPI������ɱ�־��д��1��0��
#define	WCOL	0x40		//SPIд��ͻ��־��д��1��0��

void	SPI_init(void);

sbit OLED_SCL=P1^7;//SCL
sbit OLED_SDA=P1^5;//SDA
sbit OLED_RES =P3^3;//RES
sbit OLED_DC =P1^3;//DC
sbit OLED_CS=P1^2; //CS

//-----------------OLED�˿ڶ���----------------

#define OLED_SCL_Clr() OLED_SCL=0
#define OLED_SCL_Set() OLED_SCL=1

#define OLED_SDA_Clr() OLED_SDA=0
#define OLED_SDA_Set() OLED_SDA=1

#define OLED_RES_Clr() OLED_RES=0
#define OLED_RES_Set() OLED_RES=1

#define OLED_DC_Clr() OLED_DC=0
#define OLED_DC_Set() OLED_DC=1

#define OLED_CS_Clr()  OLED_CS=0
#define OLED_CS_Set()  OLED_CS=1

//extern u16 loc;
//OLED�����ú���
void delay_ms(unsigned int ms);
void uDelay(unsigned int us);
void Delay(unsigned int ms);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 cmd);
void Write_Command(unsigned char Data);
void Write_Data(unsigned char Data);
void Vertical_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e);
void Horizontal_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);
void Continuous_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g, unsigned char h, unsigned char i, unsigned char j, unsigned char k);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 sizey);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 sizey);
void OLED_ShowChinese(u8 x,u8 y,u8 no,u8 sizey);
void OLED_DrawBMP(u8 x,u8 y,u8 sizex, u8 sizey,u8 BMP[]);
void OLED_Init(void);

#endif  
	 



