#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PP_time_diff(FILE* fp1, FILE* fp2);

// int main(int argc, char* argv[]){
    
//     FILE* fp1 = NULL;
//     FILE* fp2 = NULL;

//     char* filename1 = "temp.txt";
//     char* filename2 = "test.bin";

//     fp1 = fopen(filename1, "r");
//     if(fp1 == NULL){
//         printf("fopen error!\n");
//         return 1;
//     }
//     fp2 = fopen(filename2, "wb");
//     if(fp2 == NULL){
//         printf("fopen error!\n");
//         return 1;
//     }

//     PP_time_diff(fp1, fp2);
    

//     fclose(fp1);
//     fclose(fp2);

//     return 0;
// }

void PP_time_diff(FILE* fp1, FILE* fp2){

    unsigned char buf[1] = {0x00,};
    unsigned int tmp[8] = {0x00,};
    unsigned int xtmp = 0;
    unsigned char str[4096] = {0x00,};
    
    if(fgets(str,sizeof(str),fp1)==NULL){
                printf("fgets error!\n");
    }

    int flag = 0;

    if(fgets(str,sizeof(str),fp1)==NULL){
        printf("fgets error!\n");
    }
    xtmp = atoi(str);

    while(1){
        
        for(int i = 0;i<8;i++){
            if(fgets(str,sizeof(str),fp1)==NULL){
                printf("fgets error!\n");
                flag =1;
                break;
            }
        
            tmp[i] = atoi(str);
            //printf("%d\n",tmp[i]);
        }
        if(flag==1) break;
        
        buf[0] = (unsigned char)((xtmp>tmp[0])^((tmp[0]>tmp[1])<<1)^((tmp[1]>tmp[2])<<2)^((tmp[2]>tmp[3])<<3)^
        ((tmp[3]>tmp[4])<<4)^((tmp[4]>tmp[5])<<5)^((tmp[5]>tmp[6])<<6)^((tmp[6]&tmp[7])<<7));
        xtmp = tmp[7];

        fwrite(buf,sizeof(unsigned char),1,fp2);
    }
}