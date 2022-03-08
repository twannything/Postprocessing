#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "interval.h"

void PP_interval_bin(FILE* fp1, FILE* fp2);

void PP_interval_bin(FILE* fp1, FILE* fp2)  {

    unsigned int xtmp = 0;
    unsigned int tmp = 0;
    unsigned char buf[1] = {0x00, };
    unsigned char str[4096] = {0x00,};

    if(fgets(str,sizeof(str),fp1)==NULL){
        printf("fgets error!\n");
        return;
    };
    xtmp = (unsigned int)atoi(str);
    
    while(1){

        if(fgets(str,sizeof(str),fp1)==NULL) break;

        tmp = (unsigned int)atoi(str);

        if((tmp-xtmp)<0){

            buf[0] = (unsigned char)(((tmp-xtmp)+__UINT32_MAX__+1)%0xff);
            fwrite(buf, sizeof(unsigned char), 1, fp2);

        }

        else {

            buf[0] = (unsigned char)((tmp-xtmp)%0xff);
            fwrite(buf, sizeof(unsigned char), 1, fp2);
        }
         
        if(fgets(str,sizeof(str),fp1)==NULL) break;
  
        xtmp = (unsigned int)atoi(str);

        if((xtmp-tmp)<0){

            buf[0] = (unsigned char)(((xtmp-tmp)+__UINT32_MAX__+1)%0xff);
            fwrite(buf, sizeof(unsigned char), 1, fp2);

        }

        else {

            buf[0] = (unsigned char)((xtmp-tmp)%0xff);
            fwrite(buf, sizeof(unsigned char), 1, fp2);
        }

    };
}


