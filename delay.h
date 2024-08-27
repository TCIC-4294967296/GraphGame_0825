#ifndef DELAY_H_114514
#define DELAY_H_114514

#ifdef __WIN32__
#include<windows.h>
void delay(int ms){
	Sleep(ms);
}
#else
#include<unistd.h>
void delay(int ms){
	sleep(ms*0.001);
}
#endif

#endif
