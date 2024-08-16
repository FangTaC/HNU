#include"STC15F2K60S2.H"
#include"sys.H"
#include"displayer.H"
#include"Key.H"
code unsigned long SysClock=11059200;         //必须。定义系统工作时钟频率(Hz)，用户必须修改成与实际工作频率（下载时选择的）一致
#ifdef _displayer_H_                          //显示模块选用时必须。（数码管显示译码表，用戶可修改、增加等） 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x77,0x7c,0x39,0x5e,0x79,0x71,0x3d,0x76,0x0f,0x0e,0x75,0x38,0x37,0x54,0x5c,0x73,0x67,0x31,0x49,0x78,0x3e,0x1c,0x7e,0x64,0x6e,0x59, 
	              /* 序号:   0   1    2	   3    4	    5    6	  7   8	   9	 	10	  11		12   13   14   15   16  17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33    34  35   36*/
                /* 显示:   0   1    2    3    4     5    6    7   8    9  	(无)  A  		b 		C 	d  		E   F   G     H   I    J    K    L    M     n   o    P    Q    r    S    t    U     v    W    X   Y     Z*/  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* 带小数点     0         1         2         3         4         5         6         7         8         9        */
#endif

char a=10;//设置初值

void my_key_callback(){
	char k = GetKeyAct(enumKey1);//监测K1按键的状态
	if(k == enumKeyPress)	a = 18;//按下K1按键的时候	//输出'H'
		else a=10;//因为这里的函数是要调用多次（试想之前验证的时候，一旦按下就显示，一旦不按暇突岵幌允韭）
}

void my_callback(){
	my_key_callback();
	Seg7Print(10,10,10,10,10,10,10,a);//对应输出
}

void main(){//主函数
	DisplayerInit();
	KeyInit();
	SetDisplayerArea(0,7);
	LedPrint(0);
	SetEventCallBack(enumEventKey, my_callback);
	MySTC_Init();
	while(1)
		MySTC_OS();
}