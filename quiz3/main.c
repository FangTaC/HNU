#include"beep.H"
#include"sys.H"
#include"STC15F2K60S2.H"

code unsigned long SysClock=11059200;         //必须。定义系统工作时钟频率(Hz)，用户必须修改成与实际工作频率（下载时选择的）一致


void main(){
	BeepInit();
	SetBeep(1200,180);//发出的声音是1.2kHz，长度为1.8s
	MySTC_Init();
	while(1){
		MySTC_OS();
}
}