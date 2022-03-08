#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../sample/interval/interval.h"

int PP_flag_clock(FILE* fp1, FILE* fp2, int flag);

void PP_interval(FILE* fp1, FILE* fp2);

void PP_interval(FILE* fp1, FILE* fp2)  {

    unsigned int xtmp = 0;
    unsigned int tmp = 0;
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

            fprintf(fp2,"%u\n",(unsigned int)(tmp-xtmp+__UINT32_MAX__+1));

        }

        else {

            fprintf(fp2,"%u\n",(unsigned int)(tmp-xtmp));
        }
         
        if(fgets(str,sizeof(str),fp1)==NULL) break;
  
        xtmp = (unsigned int)atoi(str);

        if((xtmp-tmp)<0){

            fprintf(fp2,"%u\n",(unsigned int)((xtmp-tmp)+__UINT32_MAX__+1));

        }

        else {

            fprintf(fp2,"%u\n",(unsigned int)(xtmp-tmp));
        }

    };
}

int PP_flag_clock(FILE* fp1, FILE* fp2, int flag) {
        unsigned char buf[11];
        unsigned char prin[1] = {0x00,};
        unsigned int count = 0;
        unsigned int temp[1] = {0,};
        unsigned int tick[1] = { 0,};
        unsigned int write[2] = {0x00, };
        unsigned char str[1] = {0x00,};
        unsigned int b, c= 0;
        int cnt = 0;
        int i = 0;

        
        while(fread(buf, sizeof(char), 10, fp1)!=0){
                for(i = 0; i < 9; i++){
                        tick[0] += (buf[i] - 48);
                        if(i != 8)
                                tick[0] = tick[0] * 10;
                }
                //printf("%d\n", tick[0]);
                if(tick[0] > flag)
                        prin[0] = prin[0] ^ 0x01;
                else
                        prin[0] = prin[0] ^ 0x00;
                cnt++;
                if(cnt == 8){
                        fwrite(prin, sizeof(char), 1, fp2);
                        cnt = 0;
                        prin[0] = 0;
                }
                else
                        prin[0] = prin[0] << 1;
                        tick[0] = 0;      
        }
        if(cnt != 0)
                fwrite(prin, sizeof(char), 1, fp2);
        
}