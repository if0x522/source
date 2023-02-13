#ifndef SDV_H
#define SDV_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SDV_SIZE    (16*1024*1024)      // 虚拟磁盘文件大小
#define RDRI    "../xi.bin"              // 虚拟磁盘文件

void sdv_init(void);

uint8_t SDV_read(uint8_t * buf,uint16_t sector,uint32_t count);
uint8_t SDV_write(uint8_t * buf,uint16_t sector,uint32_t count);

#endif