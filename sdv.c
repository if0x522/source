
#include "sdv.h"

FILE * ff = NULL;

void sdv_init(void){
    uint8_t * buf;
    int i;
    if(ff != NULL){
        fclose(ff);
    }
    ff = fopen(RDRI,"rb+");  // 检查文件是否存在
}

uint8_t SDV_read(uint8_t * buf,uint16_t sector,uint32_t count){
    uint32_t addr;
    addr = sector << 9;
    fseek(ff,addr,SEEK_SET);
    if(fread(buf,512,count,ff)>0){
        return 0;
    }
    return 1;
}

uint8_t SDV_write(uint8_t * buf,uint16_t sector,uint32_t count){
    uint32_t addr;
    addr = sector << 9;
    fseek(ff,addr,SEEK_SET);
    if(fwrite(buf,512,count,ff)>0){
        return 0;
    }
    return 1;
}
