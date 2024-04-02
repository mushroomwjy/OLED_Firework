//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : OLED 4�ӿ���ʾ����(51ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              SCL  P17��SCL��
//              SDA  P16��SDA��
//              RES  P15
//              DC   P14
//              CS   P13 
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//******************************************************************************/
//#include "REG51.h"
#include "oled.h"
#include "OLED12864.h"
#include "bmp.h"
#define SIZES 896
#define T1MS (65536-32768)
int count,second;
void tm0_isr() interrupt 1 using 1 //1ms
{
	TL0 = T1MS; //reload timer0 low byte
	TH0 = T1MS >> 8; //reload timer0 high byte
	count++;
	if (count==3000)
	{
		count = 0; //reset counter
		//second+=3;
	}
}
void yanhua(int x,int y)
{
	int xx=x+24,yy=y+3,yn=6,i;
	unsigned char st=0x80,ed=0xff;
	for(i=0;i<8;i++)
	{
		OLED_Set_Pos(xx,7);
		OLED_WR_Byte(st,OLED_DATA);
		st=(st>>1)|0x80;
		Delay(10);
	}
	for(yn=6;yn>yy;yn--)
	{
		st=0x80;
		ed=0x7f;
		for(i=0;i<8;i++)
		{
			OLED_Set_Pos(xx,yn);
			OLED_WR_Byte(st,OLED_DATA);
			OLED_Set_Pos(xx,yn+1);
			OLED_WR_Byte(ed,OLED_DATA);
			st=(st>>1)|0x80;
			ed=ed>>1;
			Delay(40-yn*5);
		}
	}
	st=0x80;
	ed=0x3f;
	for(i=0;i<8;i++)
	{
		OLED_Set_Pos(xx,yy);
		OLED_WR_Byte(st,OLED_DATA);
		OLED_Set_Pos(xx,yy+1);
		OLED_WR_Byte(ed,OLED_DATA);
		st=(st>>1)|0x80;
		ed=ed>>2;
		Delay(40-yy*5);
	}
	for(i=0;i<7;i++)
	{
		OLED_DrawBMP(x,y,48,48,&fireworkdata[i*288]);
		Delay(80);
	}
	OLED_Clear();
	
}
int main(void)
{	
	//u8 t=' ',dela=0;
	u16 i,x,y;
	count=0;
	second=0;
	P1M1 = 0x03;
	P1M0 = 0x00; 
	AUXR = 0x80;
	TMOD = 0x01; 
	TL0 = T1MS; 
	TH0 = T1MS >> 8; 
	OLED_Init();//��ʼ��OLED
	P1ASF=0x01;
	ADC_RES=0;
	ADC_CONTR=0xe0;//11100000
	TR0 = 1;
	while(1)
	{
		x=TL0%80;
		y=3000;
		while(y--);
		y=TL0%3;
		yanhua(x,y);
		Delay(300);
	}
}

	