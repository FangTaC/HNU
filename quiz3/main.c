#include"beep.H"
#include"sys.H"
#include"STC15F2K60S2.H"

code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��


void main(){
	BeepInit();
	SetBeep(1200,180);//������������1.2kHz������Ϊ1.8s
	MySTC_Init();
	while(1){
		MySTC_OS();
}
}