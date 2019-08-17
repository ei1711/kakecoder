/*-------------------------------------------------
date:2019/08/13


-------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include <sys/time.h>
#include<signal.h>


int main(){
    char contest_name[100];
    printf("contest_name?>>");
    scanf("%s",contest_name);

    char filename[100];
    sprintf(filename,"%srejudge.txt",contest_name);
    char command[1000];
    sprintf(command,"ls ./Problems/%s/ReJudge > %srejudge.txt",contest_name,contest_name);
    system(command);

    FILE *fp=fopen(filename,"r");
    char submit_list[1000][100];
    char command2[1000],command3[1000];
    char command4[1000];
    int list_i=0;
    while(fscanf(fp,"%s",submit_list[list_i])!=EOF){
        sprintf(command4,"cp ./Problems/%s/ReJudge/%s .",contest_name,submit_list[list_i]);
        system(command4);

        printf("ReJudgging 「%s」...\n",submit_list[list_i]);

        sprintf(command2,"./JUDGE.out < ./Problems/%s/ReJudge/%s",contest_name,submit_list[list_i]);
        int ret_code=system(command2);
        //printf("ret>>%d\n",ret_code);

        sprintf(command3,"./ranking.out 6 %s",contest_name);
        system(command3);

        list_i++;
    }

    return 0;
}