#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flag_clock/flag_clock.h"
#include "time_difference/time_diff.h"
#include "slow_clock/slow_clock.h"
#include "sample/interval/interval.h"
#include "fast_clock/fast_clock.h"
#include "clock/clock.h"

void print_menu(void);

unsigned int case0(void);
unsigned int case1(void);
unsigned int case2(void);
unsigned int case3(void);
unsigned int case4(void);
unsigned int case5(void);
unsigned int case6(void);

unsigned int case20(void);
unsigned int case21(void);

int main(){
    unsigned char* file1 = NULL;
    unsigned char* file2 = NULL;

    file1 = (unsigned char*)malloc(10);
    file2 = (unsigned char*)malloc(10);

    printf("\n");
	printf("========================================\n");
	printf("   Post-processing noise source v1.0    \n");
	printf("----------------------------------------\n");
	printf("   Copyright 2022 CISI, Kookmin Univ.   \n");
	printf("========================================\n");
    printf("\n");

    print_menu();

    printf("Select API : ");

    int select = 0;
    int api = 0;
    api = scanf("%d", &select);
    
    while(api == 1){
        if(select == 0){
            printf("# [All_Method]\n");
            FILE* fp0 = NULL;
            FILE* fp1 = NULL;
            FILE* fp2 = NULL;
            FILE* fp3 = NULL;
            FILE* fp4 = NULL;
            FILE* fp5 = NULL;
            FILE* fp6 = NULL;
            FILE* fp7 = NULL; // clock_8bit
            FILE* fp_temp = NULL;

            int i = 0;
            int length = 0;
            int flag_len = 0;
            int flag = 0;
            char num[10] = {0,};
            char filename[20] = {0,};
            char* filename0 = NULL;
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename3 = NULL;
            char* filename4 = NULL;
            char* filename5 = NULL;
            char* filename6 = NULL;
            char* filename7 = NULL; // clock_8bit
            char* txt_exten = ".txt";
            char* filename_temp = "temp.txt";
            char* bin_exten1 = "_fast_clock.bin";
            char* bin_exten2 = "_flag_clock.bin";
            char* bin_exten3 = "_interval.bin";
            char* bin_exten4 = "_clock.bin";
            char* bin_exten5 = "_slow_clock.bin";
            char* bin_exten6 = "_time_diff.bin";
            char* bin_exten7 = "_clock_8bit.bin";  // clock_8bit

            printf("input filename(.txt) : ");
            scanf("%s", filename);
            printf("Input flag(dec): ");
            scanf("%s", num);
            flag = atoi(num);

            for(i = 0; num[i] != '\0'; i++)
                flag_len++;
            for(i = 0; filename[i] != '\0'; i++)
                length++;

            filename0 = (char *)malloc(length + 4);
            filename1 = (char *)malloc(length + 15);
            filename2 = (char *)malloc(length + flag_len + 1 + 15);
            filename3 = (char *)malloc(length + 19);
            filename4 = (char *)malloc(length + 10);
            filename5 = (char *)malloc(length + flag_len + 1 + 15);
            filename6 = (char *)malloc(length + 14);
            filename7 = (char *)malloc(length + 19);  // clock_8bit

            length = 0;

            strcpy(filename0, filename);
            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcpy(filename3, filename);
            strcpy(filename4, filename);
            strcpy(filename5, filename);
            strcpy(filename6, filename);
            strcpy(filename7, filename);
            strcat(filename0, txt_exten);
            strcat(filename1, bin_exten1);
            strcat(filename2, "_");
            strcat(filename2, num);
            strcat(filename2, bin_exten2);
            strcat(filename3, bin_exten3);
            strcat(filename4, bin_exten4);
            strcat(filename5, "_");
            strcat(filename5, num);
            strcat(filename5, bin_exten5);
            strcat(filename6, bin_exten6);
            strcpy(filename7, bin_exten7);


            fp0 = fopen(filename0, "r");
            fp4 = fopen(filename4, "wb");
            
            PP_clock(fp0, fp4);

            fclose(fp0);
            fclose(fp4);

            fp0 = fopen(filename0, "r");
            fp4 = fopen(filename7, "wb");
            
            PP_clock_8bit(fp0, fp4);

            fclose(fp0);
            fclose(fp4);

            printf("PP Clock..done\n");

            fp0 = fopen(filename0, "r");
            fp_temp = fopen(filename_temp, "w");

            PP_interval(fp0, fp_temp);

            fclose(fp0);
            fclose(fp_temp);

            printf("Interval file.. done\n");

            fp0 = fopen(filename_temp, "r");
            fp1 = fopen(filename1, "wb");
            
            PP_fast_clock(fp0, fp1);

            fclose(fp0);
            fclose(fp1);
            printf("PP Fast Clock..done\n");
            
            fp_temp = fopen(filename_temp, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_flag_clock(fp_temp, fp2, flag);
            
            fclose(fp2);
            fclose(fp_temp);
            printf("PP Flag Clock..done\n");
            
            fp0 = fopen(filename0, "r");
            fp3 = fopen(filename3, "wb");
            
            PP_interval_bin(fp0, fp3); //&256?

            fclose(fp0);
            fclose(fp3);
            printf("PP Interval..done\n");

            fp0 = fopen(filename0, "r");
            fp5 = fopen(filename5, "wb");
            
            PP_slow_clock(fp0, fp5, flag);

            fclose(fp0);
            fclose(fp5);

            printf("PP Slow Clock..done\n");
            
            fp_temp = fopen(filename_temp, "r");
            fp6 = fopen(filename6, "wb");
            
            PP_time_diff(fp_temp, fp6);

            fclose(fp6);
            fclose(fp_temp);

            printf("PP Time diff method..done\n");

            printf("[PP all method done] Make [%s] [%s] [%s] [%s] [%s] [%s]\n", filename1, filename2, filename3, filename4, filename5, filename6);
            //return 0;
        }
        else if(select == 1){
            printf("# [Fast_Clock_Method]\n");
            //case1();
            FILE* fp1 = NULL;
            FILE* fp2 = NULL;

            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* txt_exten = ".txt";
            char* bin_exten = "_fast_clock.bin";
            char bin_exten2[30] = "test_txt";

            printf("input filename(.txt) : ");
            scanf("%s", filename);
            
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + 15);
            length = 0;

            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);

            fp1 = fopen(filename1, "r");
            fp2 = fopen(filename2, "wb");

            PP_fast_clock(fp1, fp2);

            fclose(fp1);
            fclose(fp2);

            printf("[PP Fast Clock method done] Make [%s]\n", filename2);
        }
        else if(select == 2){
            printf("# [Flag_Clock_Method]\n");
            //case2();
            FILE* fp1 = NULL;
            FILE* fp2 = NULL;
            FILE* fp_temp = NULL;

            int i = 0;
            int length = 0;
            int flag_len = 0;
            int flag = 0;
            char num[10] = {0,};
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename_temp = "temp.txt";
            char* txt_exten = ".txt";
            char* bin_exten = "_flag_clock.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            printf("Input flag(dec): ");
            scanf("%s", num);
            flag = atoi(num);
            for(i = 0; num[i] != '\0'; i++)
                flag_len++;
            
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + flag_len + 1 + 15);
            length = 0;

            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcat(filename2, "_");
            strcat(filename2, num);
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);

            fp1 = fopen(filename1, "r");
            fp_temp = fopen(filename_temp, "w");

            PP_interval(fp1, fp_temp);

            fclose(fp1);
            fclose(fp_temp);

            fp_temp = fopen(filename_temp, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_flag_clock(fp_temp, fp2, flag);

            free(filename1);
            free(filename2);
            fclose(fp2);
            fclose(fp_temp);

            printf("[PP Flag Clock method done] Make [%s]\n", filename2);
        }
        else if(select == 3){
            printf("# [Interval_Method]\n");
            //case3();
            FILE* fp1;
            FILE* fp2;

            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename_temp = "temp.txt";
            char* txt_exten = ".txt";
            char* bin_exten = "_interval.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
                        
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + 13);
            length = 0;
            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);

            fp1 = fopen(filename1, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_interval_bin(fp1, fp2);

            printf("[PP Interval method done] Make [%s]\n", filename2);

            fclose(fp1);
            fclose(fp2);
        }
        else if(select == 4){
            printf("# [Clock_Method]\n");
            //case4();
            FILE* fp1;
            FILE* fp2;
            
            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename3 = NULL;
            char* txt_exten = ".txt";
            char* bin_exten = "_clock.bin";
            char* bin_exten_8 = "_clock_8bit.bin";  // 8-bit clock
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + 10);
            filename3 = (char *)malloc(length + 15);  // 8-bit clock
            length = 0;

            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcpy(filename3, filename);  // 8-bit clock
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);
            strcat(filename3, bin_exten_8); // 8-bit clock

            fp1 = fopen(filename1, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_clock(fp1, fp2);

            printf("[PP Clock method done] Make [%s]\n", filename2);

            fclose(fp1);
            fclose(fp2);

            fp1 = fopen(filename1, "r");
            fp2 = fopen(filename3, "wb");
            
            PP_clock_8bit(fp1, fp2);

            printf("[PP Clock method done] Make [%s]\n", filename3);

            fclose(fp1);
            fclose(fp2);
        }
        else if(select == 5){
            printf("# [Slow_Clock_Method]\n");
            //case5();
            FILE* fp1;
            FILE* fp2;
            
            int flag_len = 0;
            int flag = 0;
            char num[10] = {0,};
            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* txt_exten = ".txt";
            char* bin_exten = "_slow_clock.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            printf("Input flag(dec) [no input 0]: ");
            scanf("%s", num);
            flag = atoi(num);
            for(i = 0; num[i] != '\0'; i++)
                flag_len++;
            
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + flag_len + 1 + 15);
            length = 0;

            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcat(filename2, "_");
            strcat(filename2, num);
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);

            fp1 = fopen(filename1, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_slow_clock(fp1, fp2, flag);

            fclose(fp1);
            fclose(fp2);

             printf("[PP Slow Clock method done] Make [%s]\n", filename2);
        }
        else if(select == 6){
            printf("# [Time_Difference_Method]\n");
            //case6();
            FILE* fp1 = NULL;
            FILE* fp_temp = NULL;
            FILE* fp2 = NULL;
            
            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename_temp = "temp.txt";
            char* txt_exten = ".txt";
            char* bin_exten = "_time_diff.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            filename2 = (char *)malloc(length + 14);
            length = 0;

            strcpy(filename1, filename);
            strcpy(filename2, filename);
            strcat(filename1, txt_exten);
            strcat(filename2, bin_exten);

            fp1 = fopen(filename1, "r");
            fp_temp = fopen(filename_temp, "w");

            PP_interval(fp1, fp_temp);

            fclose(fp1);
            fclose(fp_temp);

            fp_temp = fopen(filename_temp, "r");
            fp2 = fopen(filename2, "wb");
            
            PP_time_diff(fp_temp, fp2);

            fclose(fp2);
            fclose(fp_temp);

             printf("[PP Time Difference method done] Make [%s]\n", filename2);
        }
        else if(select == 10){
            printf("# [Set_A_Section_Flag_Clock_Method]\n");
            //case10();
            FILE* fp1 = NULL;
            FILE* fp2 = NULL;
            FILE* fp_temp = NULL;

            int i = 0;
            int length = 0;
            int flag_len = 0;
            int flag = 0;
            char num[10] = {0,};
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* filename_temp = "temp.txt";
            char* txt_exten = ".txt";
            char* bin_exten = "_flag_clock.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            
            unsigned int min = 0;
            unsigned int max = 0;

            printf("Input flag min(0 ~ 255): ");
            scanf("%d", &min);
            printf("Input flag Max(0 ~ 255): ");
            scanf("%d", &max);
            if(min > max){
                printf("\n#error# Input min, Max value wrong! (try max > min)\n");
                return 0;
            }
            if((min > 256) | (max > 256)){
                printf("\n#error# Input min, Max value wrong! (min, max : 0~255)\n");
                return 0;
            }
                
            filename1 = (char *)malloc(length + 4);
            strcpy(filename1, filename);
            strcat(filename1, txt_exten);
            

            printf("Loading");
            for(i = min; i < max + 1; i++)
            {
                if(0 <= i & i < 10)
                {
                    flag = i;
                    filename2 = (char *)malloc(sizeof(char) * (length + 17));
                    strcpy(filename2, filename);                    
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);                    
                    strcat(filename2, bin_exten);
                }
                else if (10 <= i & i < 100)
                {
                    flag = i;
                    filename2 = (char *)malloc(length + 18);
                    strcpy(filename2, filename);
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);
                    strcat(filename2, bin_exten);

                }
                else
                {
                    flag = i;
                    filename2 = (char *)malloc(length + 19);
                    strcpy(filename2, filename);
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);
                    strcat(filename2, bin_exten);

                }
                fp1 = fopen(filename1, "r");
                fp_temp = fopen(filename_temp, "w");

                PP_interval(fp1, fp_temp);

                fclose(fp1);
                fclose(fp_temp);

                fp_temp = fopen(filename_temp, "r");
                fp2 = fopen(filename2, "wb");
                
                PP_flag_clock(fp_temp, fp2, flag);

                free(filename2);
                fclose(fp2);
                fclose(fp_temp);
                if((i % 8) == 0)
                    printf(".");
            }
            free(filename1);
            printf("!\n[PP All of Flag(%d~%d) Flag Clock method done] Make [%s]\n", min, max, filename);
        }
        else if(select == 11){
            printf("# [Set_A_Section_Slow_Clock_Method]\n");
            //case5();
            FILE* fp1;
            FILE* fp2;
            
            int flag_len = 0;
            int flag = 0;
            char num[10] = {0,};
            int i = 0;
            int length = 0;
            char filename[20] = {0,};
            char* filename1 = NULL;
            char* filename2 = NULL;
            char* txt_exten = ".txt";
            char* bin_exten = "_slow_clock.bin";
            char bin_exten2[30] = "test_txt";

            printf("Input filename(.txt) : ");
            scanf("%s", filename);
            for(i = 0; filename[i] != '\0'; i++)
                length++;
            filename1 = (char *)malloc(length + 4);
            unsigned int min = 0;
            unsigned int max = 0;

            printf("Input flag min(1 ~ 255): ");
            scanf("%d", &min);
            printf("Input flag Max(1 ~ 255): ");
            scanf("%d", &max);
            if(min > max){
                printf("\n#error# Input min, Max value wrong! (try max > min)\n");
                return 0;
            }
            if((min > 256) | (max > 256)){
                printf("\n#error# Input min, Max value wrong! (min, max : 0~255)\n");
                return 0;
            }
            if((min == 0) | (max == 0)){
                printf("\n#error# No input 0.\n");
                return 0;
            }
                
            filename1 = (char *)malloc(length + 4);
            strcpy(filename1, filename);
            strcat(filename1, txt_exten);
            
            printf("Loading");
            for(i = min; i < max + 1; i++)
            {
                if(0 <= i & i < 10)
                {
                    flag = i;
                    filename2 = (char *)malloc(sizeof(char) * (length + 17));
                    strcpy(filename2, filename);                    
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);                    
                    strcat(filename2, bin_exten);
                }
                else if (10 <= i & i < 100)
                {
                    flag = i;
                    filename2 = (char *)malloc(length + 18);
                    strcpy(filename2, filename);
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);
                    strcat(filename2, bin_exten);

                }
                else
                {
                    flag = i;
                    filename2 = (char *)malloc(length + 19);
                    strcpy(filename2, filename);
                    strcat(filename2, "_");
                    sprintf(num, "%d", i);
                    strcat(filename2, num);
                    strcat(filename2, bin_exten);

                }
                fp1 = fopen(filename1, "r");
                fp2 = fopen(filename2, "wb");
                
                PP_slow_clock(fp1, fp2, flag);

                free(filename2);
                fclose(fp1);
                fclose(fp2);
                if((i % 8) == 0)
                    printf(".");
            }
            free(filename1);
            printf("!\n[PP All of Flag(%d~%d) Flag Clock method done] Make [%s]\n", min, max, filename);

        
             printf("[PP Slow Clock method done] Make [%s]\n", filename2);
        }
        else if(select == 90){
            printf("# Bye bye ~\n");
            return 0;
        }
        else if(select == 91){
            printf("# [Print Menu]\n");
            case21();
        }
        else {
            return 0;
        }
        printf("\n\n");
        print_menu();
        printf("Select API : ");
        scanf("%d", &select);
    }
    
}

void print_menu(void)   {
    printf("****************************************\n");
	printf("******* KMU Post-Processing v1.0 *******\n");
	printf("****************************************\n");
	printf("# Post-Processing Method\n");
	printf(" < 0> All_Method\n");
	printf(" < 1> Fast_Clock_Method\n");
	printf(" < 2> Flag_Clock_Method\n");
	printf(" < 3> Interval_Method\n");
	printf(" < 4> Clock_Method\n");
    printf(" < 5> Slow_Clock_Method\n");
    printf(" < 6> Time_Difference_Method\n");
    printf("# Post-Processing Method [set a section of flag(0~255)]\n");
    printf(" <10> Flag_Clock_Method\n");
    printf(" <11> Slow_Clock_Method\n");
    printf("# Testing Module Management\n");
	printf(" <90> Testing Module exit\n");
	printf(" <91> Print Menu\n");
	printf("----------------------------------------\n");

}

unsigned int case0(void){
    //all
}

unsigned int case1(void){
    //fast
}

unsigned int case2(void){
    //flag
}

unsigned int case3(void){
    //interval
}

unsigned int case4(void){
    //clock
}

unsigned int case5(void){
    //slock_clock
}

unsigned int case6(void){
    //time_diff
}

unsigned int case20(void){
    //all
}

unsigned int case21(void){
    //fast
}