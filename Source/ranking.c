#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int asc(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int desc(const void *a, const void *b) { return *(int *)b - *(int *)a; }

typedef struct {
    int score_flg[100];
    char userid[1000];
    int score[100];
    int time[100];
    int pena[100];
    int pena_sum;
    double sum;
    int max_time;
    int flg;
} user_t;

int asc_t(const void *a, const void *b) {
    return ((user_t *)a)->score - ((user_t *)b)->score;
}
// int desc_t(const void *a,const void *b){return ((user_t*)b)->score -
// ((user_t*)a)->score;}
int desc_t(const void *a, const void *b) {
    return ((user_t *)b)->sum > ((user_t *)a)->sum ? 1 : -1;
}

void init(user_t *, int);
int search_id(FILE *, char *);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("(引数が足り)ないです\n");
        return 0;
    }

    // printf("check\n");

    char contest_name[100];
    int user_n, problem_n;
    long long int start_time, end_time, now_time;
    static user_t ur[10000];

    user_n = -1;
    problem_n = atoi(argv[1]);
    // printf("problem_n:%d\n",problem_n);
    strcpy(contest_name, argv[2]);
    // printf("contname:%s\n",contest_name);

    init(ur, 500);
    /*
    for(int i=0;i<user_n;i++){
        printf("i:%d sum:%lf\n",i,ur[i].sum);
    }
    */
    char ss[1000];
    sprintf(ss, "./Contests/%s/continfo.txt", contest_name);
    FILE *fp_info = fopen(ss, "r");
    int start, end;
    fscanf(fp_info, "%d", &start);
    fscanf(fp_info, "%d", &end);
    fclose(fp_info);
    end -= start;
    start = 0;

    char s1[1000];
    sprintf(s1, "./Contests/%s/userlist.txt", contest_name);
    FILE *fp_userlist = fopen(s1, "r+");
    if (fp_userlist == NULL) {
        printf("\"userlist.txt\" not found\n");
        return 0;
    }
    char s2[1000];
    sprintf(s2, "./Contests/%s/submitinfo.txt", contest_name);
    FILE *fp_subinfo = fopen(s2, "r+");
    if (fp_subinfo == NULL) {
        printf("\"submitinfo.txt\" not found\n");
        return 0;
    }

    int user_num, score_sum, pena_sum;
    char prob_alpha, status[10];
    int flg = 0, flg2 = 0;
    char tmp[100];

    for (int i = 0; 1; i++) {
        score_sum = 0;

        if (EOF == fscanf(fp_subinfo, "%s", tmp)) {
            break;
        }

        /*いじらない */
        char userid2[1000];
        flg = flg2 = 0;
        user_num = 0;

        FILE *fp_userlist = fopen(s1, "r+");

        if (fp_userlist == NULL) {
            printf("\"userlist.txt\" not found\n");
            return 0;
        }
        while (fscanf(fp_userlist, "%s %d", userid2, &user_num) != EOF) {
            if (!strcmp(tmp, userid2)) {
                flg = 1;
                break;
            }
        }
        if (!flg) {
            user_num++;
            fprintf(fp_userlist, "%s %d\n", tmp, user_num);
        }
        fclose(fp_userlist);
        /*---------- */

        if (user_num > user_n) {
            user_n = user_num;
        }

        strcpy(ur[user_num - 1].userid, tmp);
        // printf("i:%d userid:%s user_num:%d\n",i,tmp,user_num);
        fscanf(fp_subinfo, " %c", &prob_alpha);
        int temp1, temp2;
        fscanf(fp_subinfo, "%d", &temp1);
        fscanf(fp_subinfo, "%d", &temp2);
        if (ur[user_num - 1].score_flg[prob_alpha - 'A'] == 0) {
            ur[user_num - 1].score[prob_alpha - 'A'] = temp1;
            ur[user_num - 1].time[prob_alpha - 'A'] = temp2;
            if (temp1 > 0) {
                ur[user_num - 1].score_flg[prob_alpha - 'A'] = 1;
            }
        }
        // printf("prob:%c score:%d
        // time:%d\n",prob_alpha,ur[user_num-1].score[prob_alpha-'A'],ur[user_num-1].time[prob_alpha-'A']);
        fscanf(fp_subinfo, "%s", status);

        if (strcmp(status, "WA") == 0 || strcmp(status, "TLE") == 0) {
            if (ur[user_num - 1].time[prob_alpha - 'A'] <= end)
                ur[user_num - 1].pena[prob_alpha - 'A']++;
            // ur[user_num-1].pena_sum++;
        } else if (strcmp(status, "AC") == 0) {
            ur[user_num - 1].pena_sum +=
                ur[user_num - 1].pena[prob_alpha - 'A'];
            if (ur[user_num - 1].time[prob_alpha - 'A'] >
                ur[user_num - 1].max_time) {
                ur[user_num - 1].max_time =
                    ur[user_num - 1].time[prob_alpha - 'A'];
                // printf("max_time:%d\n",ur[user_num-1].max_time);
            }
        }

        for (int j = 0; j < problem_n; j++) {
            score_sum += ur[user_num - 1].score[j];
        }
        // printf("ur[%d].sum==%lf\n",user_num-1,ur[user_num-1].sum);
        if (score_sum != 0) {
            ur[user_num - 1].sum =
                (double)score_sum - sqrt((double)ur[user_num - 1].max_time) -
                sqrt((double)ur[user_num - 1].pena_sum * 180.0);
        } else {
            ur[user_num - 1].sum = 0.0;
        }
    }
    fclose(fp_subinfo);

    // printf("user_n:%d\n",user_n);
    qsort(ur, user_n, sizeof(user_t), desc_t);  //要

    char s3[1000];
    sprintf(s3, "./Contests/%s/x.html", contest_name);
    FILE *fp2 = fopen(s3, "w");
    fprintf(fp2, "<!DOCTYPE html>\n");
    fprintf(fp2, "<html lang=\"ja\">\n");
    fprintf(fp2, "<head>\n");
    fprintf(fp2, "	<meta charset=\"UTF-8\">\n");
    fprintf(fp2,
            "   <meta name=\"viewport\" content=\"width=device-width, "
            "initial-scale=1, shrink-to-fit=no\">\n");
    // fprintf(fp2,"	<link rel=\"stylesheet\"
    // href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\"
    // integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\"
    // crossorigin=\"anonymous\">");
    fprintf(fp2,
            "	<link rel=\"stylesheet\" "
            "href=\"https://cdn.datatables.net/t/bs-3.3.6/"
            "jqc-1.12.0,dt-1.10.11/datatables.min.css\"/> ");
    fprintf(fp2,
            "	<script "
            "src=\"https://cdn.datatables.net/t/bs-3.3.6/jqc-1.12.0,dt-1.10.11/"
            "datatables.min.js\"></script>\n");
    fprintf(fp2, "	<script>\n");
    fprintf(fp2, "       jQuery(function($){\n");
    fprintf(fp2, "       	$.extend( $.fn.dataTable.defaults, {\n");
    fprintf(fp2,
            "       		language: { url: "
            "\"http://cdn.datatables.net/plug-ins/9dcbecd42ad/i18n/"
            "Japanese.json\" }\n");
    fprintf(fp2, "			});\n");
    fprintf(fp2, "			$(\"#ranking-table\").DataTable({\n");
    fprintf(fp2, "				order:[[0,\"desc\"]]\n");
    fprintf(fp2, "			});\n");
    fprintf(fp2, "		});\n");
    fprintf(fp2, "	</script>\n");
    // fprintf(fp2,"	<script src=\"lib/codemirror.js\">\n");
    // fprintf(fp2,"	<link rel=\"stylesheet\"
    // href=\"lib/codemirror.css\">\n"); fprintf(fp2,"	<script
    // src=\"mode/javascript/javascript.js\"></script>\n");
    fprintf(fp2, "	<title></title>\n");
    fprintf(fp2, "</head>\n");
    fprintf(fp2, "<body>\n");

    fprintf(fp2,
            "	<table id=\"ranking-table\" class=\"table "
            "table-bordered\">\n");
    fprintf(fp2, "	<thead>\n");
    fprintf(fp2, "	<tr><th>RANK</th>\n");
    fprintf(fp2, "	<th>ID</th>\n");
    for (int i = 0; i < problem_n; i++) {
        fprintf(fp2, "       <th>%c </th>\n", 'A' + i);
    }

    fprintf(fp2, "       <th>SCORE </th>\n");
    fprintf(fp2, "	</tr>\n");
    fprintf(fp2, "	</thead>\n");

    fprintf(fp2, "	<tbody>\n");
    int zero_rank = -1;
    int time, min, sec;
    for (int i = 0; i < user_n; i++) {
        if (!(start <= ur[i].max_time && ur[i].max_time <= end)) continue;

        fprintf(fp2, "   <tr>\n");
        if (ur[i].sum != 0.0) {
            fprintf(fp2, "       <td>%d </td>\n", i + 1);
        } else {
            if (zero_rank == -1) {
                zero_rank = i + 1;
            }
            fprintf(fp2, "       <td>%d </td>\n", zero_rank);
        }
        fprintf(fp2, "       <td>%s </td>\n", ur[i].userid);
        for (int j = 0; j < problem_n; j++) {
            time = ur[i].time[j];
            if (ur[i].time[j] > end) {
                time = 0;
            }
            min = time / 60;
            time %= 60;
            sec = time;

            fprintf(fp2, "       <td>%d<br>", ur[i].score[j]);
            fprintf(fp2, "       %02d:%02d<br>", min, sec);
            fprintf(fp2, "       (%d) </td>\n", ur[i].pena[j]);
        }
        fprintf(fp2, "       <td>%.2lf </td>\n", ur[i].sum);
        fprintf(fp2, "   </tr>\n");
    }
    fprintf(fp2, "	</tbody>\n");
    fprintf(fp2, "</table>\n");

    fclose(fp2);

    return 0;
}

void init(user_t *ur, int n) {
    for (int i = 0; i < n; i++) {
        ur->sum = 0.0;
        ur->max_time = -1;
        ur->pena_sum = 0;
        for (int j = 0; j < 100; j++) {
            ur->pena[j] = 0;
            ur->score_flg[j] = 0;
        }
        ur->flg = 0;
        ur++;
    }
}
