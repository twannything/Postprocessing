#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char* argv[]){
    FILE* fp1;
    FILE* fp2;
    int cnt = 0;
    unsigned char buf[11];
    unsigned char prin[1] = {0x00,};
    unsigned int count = 0;
    unsigned int temp[1] = {0,};
    unsigned int tick[1] = { 0,};
    unsigned int write[2] = {0x00, };
    unsigned char str[1] = {0x00,};
    unsigned int b, c= 0;
    struct timeval starTime;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "wb");
    int num1 = atoi(argv[3]);
    int i = 0;
    gettimeofday(&starTime, NULL);
    while(fread(buf, sizeof(char), 10, fp1)!=0){
       for(i = 0; i < 9; i++){
      tick[0] += (buf[i] - 48);
      if(i != 8)
         tick[0] = tick[0] * 10;
   }
   if(tick[0] > num1)
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
    fclose(fp1);
    fclose(fp2);

    return 0;
}