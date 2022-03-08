#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "slow_clock.h"

int PP_slow_clock(FILE* fp1, FILE* fp2, int flag);

// int main(int argc, char* argv[]){
//     FILE* fp1;
//     FILE* fp2;

//     char* filename1 = "interval0.txt";
//     char* filename2 = "test.bin";

//     fp1 = fopen(filename1, "r");
//     fp2 = fopen(filename2, "wb");

//     int flag = 128;

//     PP_slow_clock(fp1, fp2, flag);
    
//     return 0;
// }

int PP_slow_clock(FILE* fp1, FILE* fp2, int flag){

   unsigned char buf[11] = {0x00,};
   unsigned int temp = 0;
   unsigned char prin[1] = {0x00,};
   unsigned int count = 0;
   unsigned int tick[1] = { 0,};
   unsigned int write[2] = {0x00, };
   unsigned int str[1] = {0x00,};
   unsigned int b, c= 0;
   unsigned int ten = 1;
   int cnt = 0;
   int cnt2 = 0;
   int cnt3 = 0;
   int i = 0;

   while(fread(buf, sizeof(char), 10, fp1) != 0){
      for(i = 0; i < 9; i++){
         tick[0] += (buf[i] - 48);
      if(i != 8)
         tick[0] = tick[0] * 10;
      }
      if(cnt == 0){
         count = tick[0] / flag;
         count = count * flag;
      }   
      tick[0] = tick[0] - count;

      b = (tick[0] / flag);
      if(cnt == 0){
         temp = b;
         cnt++;
      }
      else{
         if(b == temp)
            cnt++;
         else{
            cnt2 = b - temp;
            prin[0] = (prin[0] << 1) ^ (cnt & 0x01);
            cnt3++;
            if(cnt3 == 8){
               fwrite(prin, sizeof(char), 1, fp2);
               prin[0] = 0;
               cnt3 = 0;
            }
            while(cnt2 > 1){
               
               prin[0] = (prin[0] << 1) ^ 0x00;
               cnt3++;
               if(cnt3 == 8){
                  fwrite(prin, sizeof(char), 1, fp2);
                  cnt3 = 0;
                  prin[0] = 0;
               }
               cnt2--;
                  
            }
         
            if(cnt3 == 8){
               fwrite(prin, sizeof(char), 1, fp2);
               cnt3 = 0;
               prin[0] = 0;
            }
            cnt = 1;
            temp = b;
         }
      }

      tick[0] = 0;   

   }
   if(cnt3 != 0)
      fwrite(prin, sizeof(char), 1, fp2);

   return 0;
}