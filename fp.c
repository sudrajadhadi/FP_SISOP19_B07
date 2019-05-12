#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

void *activated(void *sentence){
    while(1){
        //read file
        FILE *dir;
        dir = fopen("crontab.data","r");
        
        if(fp=NULL){
            peror("FILE NOT FOUND!! :(");
            exit(EXIT_FAILURE);
        }

        char time_crontab[10][100];
        char bash[10][100];
        int baris=0;
        int kolom=0;
        int loop_time_crontab=0;

        char character;
        while((character=fgetc(dir))!=EOF){
            if(loop_time_crontab<10){
                if(loop_time_crontab%2==0) time_crontab[baris][kolom]=character;
                kolom++;
                loop_time_crontab++;
                if(loop_time_crontab==9) time_crontab[baris][kolom]='\0';
            }
            else{
                if(character=='\n'){
                    bash[baris][kolom]=character='\0';
                    kolom=0;
                    baris++;
                    loop_time_crontab=0;
                }
                else{
                    bash[baris][kolom]=character;
                    kolom++;
                }
            }
        }
        bash[baris][kolom]='\0';
        fclose(dir);
        //end read file

        for(int i=0; i<baris; i++){
            time_t now;
            time(&now);

            struct tm *info;
            info=localtime(&now);
            char string_now[100];
            strftime(string_now,100,"%w%m%d%M%H",info);

            char minggu[2];
            minggu[0]=string_now[0];
            minggu[1]='\0';

            char bulan[3];
            bulan[0]=string_now[1];
            bulan[1]=string_now[2];
            bulan[2]='\0';

            char hari[3];
            hari[0]=string_now[3];
            hari[1]=string_now[4];
            hari[2]='\0';

            char menit[3];
            menit[0]=string_now[5];
            menit[1]=string_now[6];
            meint[2]='\0';

            char jam[3];
            jam[0]=string_now[7];
            jam[1]=string_now[8];
            jam[2]='\0';

        }
    }

}
