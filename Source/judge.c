/*-------------------------------------------------
date:2019/08/11


-------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include <sys/time.h>
#include<signal.h>


#define MICRO 1000000

typedef long long int ll;
typedef struct{
    time_t now_time;
    char ID[100];
    char contest_name[100];
    char problem;
    char lang[100];

    char source_code[1000][1000];
    int source_end;

    int testcase_result[100];
    int testcase_flg;

    time_t start_time;
    time_t end_time;
}user_t;//ユーザのもつ情報

//made by watanabe
void init(user_t*);
void login(user_t*);
void input_source(user_t*);
int compile(user_t*);
void try_testcase(user_t*);
void output_result_log(user_t,int*);
void make_scoretable(int*,user_t);
void make_continfo(user_t*);
void clean_up(user_t);
//test
int mysystem(char*);
void kill_proc(char*);
//reference
void sigcatch(int);


char userid[100];

int main(){
    int score_table[100]={};
    char cmd[100];
    user_t ur;

    init(&ur);
    
    //printf("command?\n");
    scanf("%s",cmd);
    login(&ur);

    make_scoretable(score_table,ur);
    make_continfo(&ur);

    input_source(&ur);
    
    int ret_code=compile(&ur);
    if(!ret_code){
        try_testcase(&ur);
    }else{
        //printf("CE\n");
        ur.testcase_flg=3;
    }
    output_result_log(ur,score_table);
    char command[1000];
    sprintf(command,"cp %s%ldtext.txt ./Problems/%s/ReJudge",ur.ID,ur.now_time,ur.contest_name);
    system(command);

    clean_up(ur);
    return 0;
}

void init(user_t *ur){
    for(int i=0;i<100;i++){
        ur->testcase_result[i]=0;
    }
    ur->testcase_flg=0;
}


void login(user_t *ur) {
    //printf("now time?\n");
    scanf("%ld",&ur->now_time);
    //printf("ID?\n");
    scanf(" %[^\n\r]", ur->ID);
    //printf("contest_name?\n");
    scanf(" %s",ur->contest_name);
    //printf("problem?\n");
    scanf(" %c",&ur->problem);
    //printf("programming_language?\n");
    scanf(" %s",ur->lang);

    strcpy(userid,ur->ID);
}

void input_source(user_t *ur) {
    //printf("source?[end]\n");
    for(int i=0;1;i++){
        scanf(" %[^\n\r]",ur->source_code[i]);
        if(!strcmp(ur->source_code[i],"END")||!strcmp(ur->source_code[i],"end")){
            ur->source_end=i+1;
            break;
        }
    }

    char copy_source_name[10000], make_file_command[10000],source_name[10000],zisage_command[10000];

    sprintf(source_name,"%ssource.txt",ur->ID);
    if(!strcmp(ur->lang,"C(gnu11)")){
        //printf("gnu\n");
        sprintf(copy_source_name, "./Problems/%s/User_Source/#%ld_%s_%s_%c.c", ur->contest_name,(long int)ur->now_time,ur->contest_name, ur->ID, ur->problem);
        sprintf(zisage_command,"./zisage_c.out < %s %s",source_name,ur->ID);
        sprintf(make_file_command, "cp %ssource.c %s", ur->ID,copy_source_name);
    }else if(!strcmp(ur->lang,"C++(c++11)")){
        sprintf(copy_source_name, "./Problems/%s/User_Source/#%ld_%s_%s_%c.cpp", ur->contest_name,(long int)ur->now_time,ur->contest_name, ur->ID, ur->problem);
        sprintf(zisage_command,"./zisage_cpp.out < %s %s",source_name,ur->ID);
        sprintf(make_file_command, "cp %ssource.cpp %s", ur->ID,copy_source_name);
    }
    //printf("check\n");
   
    
    FILE *copy_source_fp = fopen(source_name, "w+");
    FILE *save_path_fp = fopen(copy_source_name, "w+");

    for (int i = 0; i < ur->source_end; i++) {
        fprintf(copy_source_fp, "%s\n", ur->source_code[i]);
    }

    fclose(copy_source_fp);
    fclose(save_path_fp);

    system(zisage_command);
    system(make_file_command);
}


int compile(user_t *ur) {
    char gcc_command[10000];
    char gpp_command[10000];
    char py2_command[10000];
    char py3_command[10000];

    int system_return;

    if(!strcmp(ur->lang,"C(gnu11)")){
        sprintf(gcc_command,"gcc %ssource.c -o %s.out -std=gnu11 2> %serr.txt",ur->ID,ur->ID,ur->ID);
        system_return = system(gcc_command);
    }else if(!strcmp(ur->lang,"C++(c++11)")){
        sprintf(gpp_command,"g++ %ssource.cpp -o %s.out -std=c++11 2> %serr.txt",ur->ID,ur->ID,ur->ID);
        system_return = system(gpp_command);
    }
    /*else if(!strcmp(ur->lang,"Python2(ver2.7.5)")){
        sprintf(py2_command,"python2 %ssource.py 2> %serr.txt",ur->ID,ur->ID,ur->ID);
        system_return = system(py2_command);
    }else if(!strcmp(ur->lang,"Python3(ver3.6.8)")){
        sprintf(py3_command,"python3 %ssource.py 2> %serr.txt",ur->ID,ur->ID,ur->ID);
        system_return = system(py3_command);
    }*/

    sleep(2);

    return system_return;
}

void try_testcase(user_t *ur) {
    FILE* fp_list;
    char filename[100][100];

    char tmp[10000];
    sprintf(tmp,"ls ./Problems/%s/testcase/%s_%c_testcase/in > testcase_list.txt",ur->contest_name,ur->contest_name,ur->problem);
    system(tmp);
    fp_list=fopen("testcase_list.txt","r");
    if(fp_list==NULL){
        printf("not found\n");
        exit(1);
    }

    int i,list_end;
    for(i=0;fscanf(fp_list,"%s",filename[i++])!=EOF;);
    fclose(fp_list);

    list_end=i-1;
    //printf("list_end:%d\n",list_end);
    for(i=0;i<list_end;i++){
        //printf("%d:%s\n",i+1,filename[i]);
    }

    int cnt;
    for (cnt = 1; cnt <= list_end; cnt++) {
        char user_output1[10000];
        sprintf(user_output1,"%sUser_Output.txt",ur->ID);
        remove(user_output1);

        char input[10000], output[10000];
        int ac_count = 0;
        sprintf(input, "./Problems/%s/testcase/%s_%c_testcase/in/%s",ur->contest_name,ur->contest_name, ur->problem, filename[cnt-1]);
        sprintf(output, "./Problems/%s/testcase/%s_%c_testcase/out/%s",ur->contest_name,ur->contest_name, ur->problem, filename[cnt-1]);

        char user_output2[10000];
        sprintf(user_output2,"%sUser_Output.txt",ur->ID);
        char test_command[10000];
        sprintf(test_command, "./%s.out < %s >> %s" ,ur->ID,input,user_output2);

        struct timeval s,t;
        gettimeofday(&s,NULL); 
        
        if(SIG_ERR==signal(SIGALRM,sigcatch)){
            printf("failed to set signal handler.\n");
        }
        
        
        //int system_return = system(test_command);
        int system_return =mysystem(test_command);
        //printf("system_return >>%d\n",system_return);
        gettimeofday(&t,NULL);
        int time=(t.tv_sec-s.tv_sec)*1000+(t.tv_usec-s.tv_usec)/1000; 

        if (!system_return) {//AC or WA or TLE
            if (time <= 1000) {//AC or WA
                static char compare1[100000], compare2[100000];
               
                FILE *User_Output_fp = fopen(user_output2, "r");
                FILE *test_out_fp = fopen(output, "r");
                //printf("check\n");
                ur->testcase_result[cnt - 1]=1;
                while (fscanf(User_Output_fp, "%s", compare1) != EOF &&fscanf(test_out_fp, "%s", compare2) != EOF) {
                    ur->testcase_result[cnt - 1]=0;
                    if (strcmp(compare1, compare2)) {
                        ur->testcase_result[cnt - 1] = 1;//WA
                        break;
                    }
                }

                fclose(User_Output_fp);
                fclose(test_out_fp);
            } else {//TLE
                ur->testcase_result[cnt - 1] = 2;
            }      
        } else {
            ur->testcase_result[cnt - 1] = 3;//CE
        }

        char tcfile_name[10000];
        sprintf(tcfile_name,"%stestcase.txt",ur->ID);

        FILE *fp=fopen(tcfile_name,"a+");
        fprintf(fp,"【%s】", filename[cnt-1]);

        if (!system_return) {
            fprintf(fp,"  process time : %d[ms]\n", time);
        }else if(system_return==2) {
            fprintf(fp,"  process time : %d[ms]\n",time);
        }

        fprintf(fp,"  result : ");
        switch (ur->testcase_result[cnt - 1]) {
        case 0:
            fprintf(fp,"AC\n");
            break;
        case 1:
            fprintf(fp,"WA\n");
            ur->testcase_flg = 1;
            break;
        case 2:
            fprintf(fp,"TLE\n");
            ur->testcase_flg=2;
            break;
        case 3:
            fprintf(fp,"CE\n");
            ur->testcase_flg = 3;
            break;
        default:
            fprintf(fp,"Error\n");
        }
        fclose(fp);
        remove(user_output2);
    }
}

int mysystem(char *test_command){
    alarm(4);
    //char tmp[1000];
    //sprintf(tmp,"./%s.out",test_command);
    system(test_command);

    char ret_check[1000],ret_code[1000];
    sprintf(ret_code,"%sret_code.txt",userid);
    sprintf(ret_check,"echo $? > %sret_code.txt",userid);
    system(ret_check);
    
    FILE *fp=fopen(ret_code,"r");
    int ret;
    fscanf(fp,"%d",&ret);
    fclose(fp);
    remove(ret_code);

    //printf("ret>>%d\n",ret);
    return 0;
}
void sigcatch(int sig){
    //printf("catch signal %d\n", sig);
    if (sig == SIGALRM) {
        kill_proc(userid);
    }
}

void kill_proc(char *str){
    //printf("str>%s\n",str);

    char procid_name[1000];
    sprintf(procid_name,"%sprocid.txt",str);
    char check_com[1000];
    sprintf(check_com,"pgrep %s.out > %sprocid.txt",str,str);
    system(check_com);

    int procid;
    FILE *fp0=fopen(procid_name,"r");
    fscanf(fp0,"%d",&procid);
    fclose(fp0);
    
    //printf(">%d\n",procid);

    char command[1000];
    sprintf(command,"kill %d",procid);
    system(command);

    //printf("check\n");
    remove(procid_name);
}

void output_result_log(user_t ur, int *score_table) {
    char make_file[10000];

    sprintf(make_file, "./Problems/%s/User_Log/#%ld_%s_SubmitLog.txt",ur.contest_name,(long int)ur.now_time, ur.ID);

    FILE *log_fp = fopen(make_file, "w+");

    fprintf(log_fp, "【Submit#%ld】\n", ur.now_time);
    fprintf(log_fp, "<Submit Information>\n");
    fprintf(log_fp, "    Submit now_time and Time : %s", ctime(&ur.now_time));
    fprintf(log_fp, "    Problem : %c\n", ur.problem);
    fprintf(log_fp, "    Contestid：%s\n",ur.contest_name);
    fprintf(log_fp, "    User : %s\n", ur.ID);

    if (!ur.testcase_flg) {
        fprintf(log_fp, "    Score : %d\n", score_table[ur.problem - 'A']);
    }else {
        fprintf(log_fp, "    Score : 0\n");  
    }

    fprintf(log_fp, "    Result : ");
    switch (ur.testcase_flg) {
    case 0:
        fprintf(log_fp, "AC\n");
        break;
    case 1:
        fprintf(log_fp, "WA\n");
        break;
    case 2:
        fprintf(log_fp,"TLE\n");
        break;
    case 3:
        fprintf(log_fp, "CE\n");
        break;
    default:
        fprintf(log_fp, "Error\n");
    }
    fclose(log_fp);

    char logname[10000];
    sprintf(logname,"%slog.txt",ur.ID);
    FILE* log_fp2 = fopen(logname, "w+");

    fprintf(log_fp2, "\n【Submit#%ld】\n", (long int)ur.now_time);
    fprintf(log_fp2, "《Submit Information》\n");
    fprintf(log_fp2, "    Submit now_time and Time : %s", ctime(&ur.now_time));
    fprintf(log_fp2, "    Problem : %c\n", ur.problem);
    fprintf(log_fp2, "    Contest : %s\n",ur.contest_name);
    fprintf(log_fp2, "    User : %s\n", ur.ID);
    if (!ur.testcase_flg) fprintf(log_fp2, "    Score : %d\n", score_table[ur.problem - 'A']);
    else fprintf(log_fp2, "    Score : 0\n");  
    fprintf(log_fp2, "    Result : ");
    switch (ur.testcase_flg) {
    case 0:
        fprintf(log_fp2, "AC\n");
        break;
    case 1:
        fprintf(log_fp2, "WA\n");
        break;
    case 2:
        fprintf(log_fp2,"TLE\n");
        break;
    case 3:
        fprintf(log_fp2, "CE\n");
        break;
    default:
        fprintf(log_fp2, "Error\n");
    }
    fclose(log_fp2);


    char tmp[10000];
    sprintf(tmp,"./Contests/%s/submitinfo.txt",ur.contest_name);
    FILE *fp=fopen(tmp,"a+");
    fprintf(fp,"%s %c ",ur.ID,ur.problem);
    if(!ur.testcase_flg){
        fprintf(fp,"%d ",score_table[ur.problem-'A']);
    }else{
        fprintf(fp,"0 ");
    }  
    fprintf(fp,"%ld ",ur.now_time-ur.start_time);

    switch (ur.testcase_flg) {
    case 0:
        fprintf(fp, "AC\n");
        break;
    case 1:
        fprintf(fp, "WA\n");
        break;
    case 2:
        fprintf(fp,"TLE\n");
        break;
    case 3:
        fprintf(fp, "CE\n");
        break;
    default:
        fprintf(fp, "Error\n");
    }

    fclose(fp);
}

void clean_up(user_t ur) {
    char sourcec[1000],sourcetxt[1000];
    sprintf(sourcec,"%ssource.c",ur.ID);
    sprintf(sourcetxt,"%ssource.txt",ur.ID);
    remove(sourcec);
    remove(sourcetxt);
}

void make_scoretable(int* a,user_t ur){
    char scorefile[10000];
    sprintf(scorefile,"./Problems/%s/%s_score.txt",ur.contest_name,ur.contest_name);

    int i=0;
    FILE *fp=fopen(scorefile,"r");
    if(fp==NULL){
        printf("can't find scorefile\n");
    }
    while(fscanf(fp,"%d",&a[i++])!=EOF);
}

void make_continfo(user_t* ur){
    char filename[10000];
    sprintf(filename,"./Contests/%s/continfo.txt",ur->contest_name);

    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("can't find \"%s\"\n",filename);
    }else{
        fscanf(fp,"%ld\n",&ur->start_time);
        fscanf(fp,"%ld\n",&ur->end_time);
    }
}
