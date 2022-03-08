#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

clock_t char2dec(unsigned char* in);

int main(int argc, char* argv[]){
    unsigned char buf[1] = {0x00,};
    unsigned int tmp[8] = {0x00,};
    unsigned char str[4096] = {0x00,};
    int flag = 0;
    FILE* fp_1 = NULL;
    FILE* fp_2 = NULL;
    int ret = 0;
    if(argc != 3) {
        printf("./bin [input.txt] [output.bin]\n");
        return 0;
    }

    fp_1 = fopen(argv[1],"r");
    if(fp_1 == NULL){
        printf("fopen error!\n");
        return 1;
    }
    fp_2 = fopen(argv[2],"wb");
    if(fp_2 == NULL){
        printf("fopen error!\n");
        return 1;
    }


    while(1){

        for(int i = 0;i<8;i++){
            if(fgets(str,sizeof(str),fp_1)==NULL){
                printf("fgets error!\n");
                flag =1;
                break;
            }
        
            tmp[i] = char2dec(str);
            //printf("%d\n",tmp[i]);
        }
        if(flag==1) break;
        
        buf[0] = (unsigned char)((tmp[0]&0x01)^((tmp[1]&0x01)<<1)^((tmp[2]&0x01)<<2)^((tmp[3]&0x01)<<3)^
        ((tmp[4]&0x01)<<4)^((tmp[5]&0x01)<<5)^((tmp[6]&0x01)<<6)^((tmp[7]&0x01)<<7));

        fwrite(buf,sizeof(unsigned char),1,fp_2);
    }


    fclose(fp_1);
    fclose(fp_2);

    return 0;
}

clock_t char2dec(unsigned char* in){
    clock_t out=0;

    out += (in[0]-48)*100000000;
    out += (in[1]-48)*10000000;
    out += (in[2]-48)*1000000;
    out += (in[3]-48)*100000;
    out += (in[4]-48)*10000;
    out += (in[5]-48)*1000;
    out += (in[6]-48)*100;
    out += (in[7]-48)*10;
    out += (in[8]-48)*1;

    return out;
}
