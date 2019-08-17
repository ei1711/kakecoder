#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]) {
    if(argc==1){
        printf("ERROR : Insufficient Arguments\n");
        return 0;
    }

    static char input[1000][1000], name[1000], problem_name[1000];
    int hrno, indent_n;
    int source_end;
    int start, end;
    int i, j, k;

    char userID[100];
    sprintf(userID,"%s",argv[1]);
    
    start = end = 0;

    FILE* fp;
    char make_file[1000];

    char sourcename[100];
    sprintf(sourcename,"%ssource.cpp",userID);
    fp = fopen(sourcename, "w+");
    if (fp == NULL) return 0;
    
    int brackets = 0, flg = 0;

    
    for (int i = 0; 1; i++) {
        scanf(" %[^\n\r]", input[i]);
        //printf("check\n");
        /*for (int j = 0; input[i][j] != '\0'; j++) {
            if (input[i][j] == '{') brackets++;        
            if (input[i][j] == '}') brackets--;          
        }*/
        if(!strcmp(input[i],"end")){
			source_end=i;
			break;
		}
    }
    //printf("check\n");

    indent_n = 3;
    char output[1000][1000];
    int line = 0;
    int string_n;
    int flag = 0;
    for (i = 0; i < source_end; i++) {
        j = 0;
        string_n = strlen(input[i]);
        for (j = 0; j < indent_n * line; j++) output[i][j] = ' ';           
        if (input[i][string_n - 1] == '{') line++;           
        if (input[i + 1][0] == '}') line--;          
        for (k = 0; input[i][k] != '\0'; k++, j++) output[i][j] = input[i][k];
        output[i][j] = '\0';
    }

    for (i = 0; i < source_end; i++) fprintf(fp, "%s\n", output[i]);
    fclose(fp);

    return 0;
}