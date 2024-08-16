#include "STC15F2K60S2.H"        //���롣
#include "sys.H"                 //���롣
#include "displayer.H" 


code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          //��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x77,0x7c,0x39,0x5e,0x79,0x71,0x3d,0x76,0x0f,0x0e,0x75,0x38,0x37,0x54,0x5c,0x73,0x67,0x31,0x49,0x78,0x3e,0x1c,0x7e,0x64,0x6e,0x59, 
	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 	10	  11		12   13   14   15   16  17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33    34  35   36*/
                /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  	(��)  A  		b 		C 	d  		E   F   G     H   I    J    K    L    M     n   o    P    Q    r    S    t    U     v    W    X   Y     Z*/  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* ��С����     0         1         2         3         4         5         6         7         8         9        */
#endif

long ms=0,sec=0,min=0;
long temp;
char oput[8] = {0};

void func(){
	temp ++;
	if(temp==60*60*1000+60*1000+1000) temp=0;//������ʱ����������
	ms = temp%1000;//���ٺ���
	sec = (temp/1000)%60;//������
	min = (temp/60000)%60;//���ٷ���
	oput[7] = ms%10;
	oput[6] =(ms/10)%10;
	oput[5] = ms/100;
	oput[4] = sec%10;
	oput[3] = sec/10;
	oput[2] = min%10;
	oput[1] = min/10;
	oput[0] = 10;
	Seg7Print(oput[0],oput[1],oput[2],oput[3],oput[4],oput[5],oput[6],oput[7]);
}

void main(){
	
	DisplayerInit();
	SetDisplayerArea(0,7);
	Seg7Print(1,1,1,1,1,1,1,1);
	LedPrint(0);
	SetEventCallBack(enumEventSys1mS,func);
	MySTC_Init();
	while(1){
		MySTC_OS();
}
	
	


}