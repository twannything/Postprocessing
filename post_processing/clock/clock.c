#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int PP_clock(FILE* fp1, FILE* fp2);
int PP_clock_8bit(FILE* fp1, FILE* fp2);

int PP_clock(FILE* fp1, FILE* fp2)
{
    unsigned char buf[1] = {0x00,};
    unsigned int tmp[8] = {0x00};
    unsigned char str[4096] = {0x00,};
    int flag = 0;

    while(1){
        
        if(fgets(str, sizeof(str),fp1)==NULL){
                printf("fgets error!\n");
                flag = 1;
                break;
        }

        tmp[0] = atoi(str);
        if(flag == 1)
            break;
        
        buf[0] = (unsigned char)(tmp[0] & 0xff);
        //printf("%c\n", buf[0]);

        fwrite(buf, sizeof(unsigned char), 1, fp2);
    }
}

int PP_clock_8bit(FILE* fp1, FILE* fp2)
{
    unsigned char buf[1] = {0x00,};
    unsigned int tmp[8] = {0x00};
    unsigned char str[4096] = {0x00,};
    int flag = 0;

    while(1){

        for(int i = 0;i<8;i++){
            if(fgets(str,sizeof(str),fp1)==NULL){
                //printf("fgets error!\n");
                flag =1;
                break;
            }
        
            tmp[i] = (unsigned int)atoi(str);
            //printf("%d\n",tmp[i]);
        }
        
        if(flag==1) break;
        
        buf[0] = (unsigned char)((tmp[0]&0x01)^((tmp[1]&0x01)<<1)^((tmp[2]&0x01)<<2)^((tmp[3]&0x01)<<3)^
        ((tmp[4]&0x01)<<4)^((tmp[5]&0x01)<<5)^((tmp[6]&0x01)<<6)^((tmp[7]&0x01)<<7));

        fwrite(buf,sizeof(unsigned char),1,fp2);
    }
}