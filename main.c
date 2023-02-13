#include <stdio.h>
#include "sdv.h"
#include"ff.h"

uint8_t txt1[] = "第一帧用于数据长度大于7字节的诊断数据,它和一个或多个连续帧并用,其中FF_DL表示这套多帧的数据长度,12 位 FF_DL 理论上支持发送多达 4096 个数据字节。";
uint8_t txt2[] = "如果是多帧数据,先发第一帧,然后是连续帧,其中SN是帧计数,初始为1[因为有第一帧]累加达到15后,置0.";
uint8_t txt3[] = "主要参考ISO 15765-2,定义了CAN总线传输的数据结构,以及多帧传输的方法,并对帧传输规约了时间参数。";
uint8_t txt[204];
int main(void){
    uint8_t * buf;
    FATFS QFATFS;   // 文件系统句柄
    FIL app;
    DIR dir;
    UINT s;
    int  i;
    FILINFO fno;
    printf("f_mount%d\n",f_mount(&QFATFS,"",1));      // 挂载SD卡文件系统
    printf("Failed SD successful\r\n");
    // 创建文件夹
    f_mkdir("/LIN/");
    // 检测是否有升级文件
    // 创建3个文件，
     f_opendir(&dir,"/LIN/");
    f_open(&app,"/LIN/1.txt",FA_WRITE|FA_OPEN_ALWAYS);
    f_write(&app,txt1,sizeof(txt1),&s);
    f_close(&app);
    printf("1.txt create init\n");
    f_open(&app,"/LIN/2.txt",FA_WRITE|FA_OPEN_ALWAYS);
    f_write(&app,txt2,sizeof(txt2),&s);
    f_close(&app);
    printf("2.txt create init\n");
    f_open(&app,"/LIN/3.txt",FA_WRITE|FA_OPEN_ALWAYS);
    f_write(&app,txt3,sizeof(txt3),&s);
    f_close(&app);
    printf("3.txt create init\n");
    //f_readdir(&dir,&fno);
    //if(fno.fname[0] == 0)   printf("%s/%s\n","/LIN/",fno.fname);
    for(;;){
        f_readdir(&dir,&fno);
        if(fno.fname[0] == 0)   break;
        printf("%s/%s\n","/LIN",fno.fname);
    }
     f_closedir(&dir);
    for(;;){
         scanf("%d",&i);
         printf("\n%d\n",i);
         switch(i){
             case 1:{
                 f_open(&app,"/LIN/1.txt",FA_READ);
                 f_read(&app,txt,204,&s);
                 f_close(&app);
                 printf("1.txt = %s\n",txt);
                 break;
             }
             case 2:{
                 f_open(&app,"/LIN/2.txt",FA_READ);
                 f_read(&app,txt,204,&s);
                 f_close(&app);
                 printf("2.txt = %s\n",txt);
                 break;
             }
             case 3:{
                 f_open(&app,"/LIN/3.txt",FA_READ);
                 f_read(&app,txt,204,&s);
                 f_close(&app);
                 printf("3.txt = %s\n",txt);
                 break;
             }
             case 4:{
                 return 0;
             }
         }
     }
    return 0;
}