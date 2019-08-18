#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("引数が足りません\n");
        return 0;
    }
    char contest_name[100];
    strcpy(contest_name,argv[1]);

    char path_of_source[1000];
    sprintf(path_of_source,"./Problems/%s/User_Source",contest_name);
    char path_of_out[1000];
    sprintf(path_of_out,"./Contests/%s/source_list.txt",contest_name);

    char command1[1000];
    sprintf(command1,"ls %s > %s",path_of_source,path_of_out);
    system(command1);

    FILE *fp_source_list=fopen(path_of_out,"r");
    char source_list[1000][1000];
    int list_i=0;
    while(fscanf(fp_source_list,"%s",source_list[list_i++])!=EOF);
    int list_n=list_i-1;

    //printf(":%d\n",list_n);
	char path_of_html[1000];
    sprintf(path_of_html,"./Contests/%s/source_list.html",contest_name);
    FILE *fp_html=fopen(path_of_html,"w");
    

	int flg=0;
    for(int i=0;i<list_n;i++){
		char tmp[1000]="";
        char submit_id[1000]="";
        char contest_id[1000]="";
        char user_id[1000]="";
        char problem[1000]="";
        int ii=0,next;
        for(int j=0;source_list[i][j]!='\0';j++){
            if(source_list[i][j]=='_'){
                next=j+1;
                break;
            }
            submit_id[ii++]=source_list[i][j];
        }
        for(int j=next,ii=0;source_list[i][j]!='\0';j++){
            if(source_list[i][j]=='_'){
                next=j+1;
                break;
            }
            contest_id[ii++]=source_list[i][j];
        }
        for(int j=next,ii=0;source_list[i][j]!='\0';j++){
            if(source_list[i][j]=='_'){
                next=j+1;
                break;
            }
            user_id[ii++]=source_list[i][j];
        }
        for(int j=next,ii=0;source_list[i][j]!='\0';j++){
            if(source_list[i][j]=='_'){
                next=j+1;
                break;
            }
            problem[ii++]=source_list[i][j];
        }
        //printf("%s>%s>%s>%s\n",submit_id,contest_id,user_id,problem);
		if(!flg){
			


			fprintf(fp_html,"<!DOCTYPE html>\n");
			fprintf(fp_html,"<html lang=\"ja\">\n");
    		fprintf(fp_html,"<head>\n");
    		fprintf(fp_html,"	<meta charset=\"UTF-8\">\n");
			fprintf(fp_html,"   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n");
   			//fprintf(fp_html,"	<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\" integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\" crossorigin=\"anonymous\">");
			fprintf(fp_html,"	<link rel=\"stylesheet\" href=\"https://cdn.datatables.net/t/bs-3.3.6/jqc-1.12.0,dt-1.10.11/datatables.min.css\"/> ");
    		fprintf(fp_html,"	<script src=\"https://cdn.datatables.net/t/bs-3.3.6/jqc-1.12.0,dt-1.10.11/datatables.min.js\"></script>\n");
    		fprintf(fp_html,"	<script>\n");
    		fprintf(fp_html,"       jQuery(function($){\n");
			fprintf(fp_html,"       	$.extend( $.fn.dataTable.defaults, {\n");
			fprintf(fp_html,"       		language: { url: \"http://cdn.datatables.net/plug-ins/9dcbecd42ad/i18n/Japanese.json\" }\n");
			fprintf(fp_html,"			});\n");
   			fprintf(fp_html,"			$(\"#source_list-table\").DataTable({\n");
			fprintf(fp_html,"				order:[[0,\"desc\"]]\n");
    		fprintf(fp_html,"			});\n");
			fprintf(fp_html,"		});\n");
    		fprintf(fp_html,"	</script>\n");
			//fprintf(fp_html,"	<script src=\"lib/codemirror.js\">\n");
			//fprintf(fp_html,"	<link rel=\"stylesheet\" href=\"lib/codemirror.css\">\n");
			//fprintf(fp_html,"	<script src=\"mode/javascript/javascript.js\"></script>\n");
    		fprintf(fp_html,"	<title></title>\n");
    		fprintf(fp_html,"</head>\n");
			fprintf(fp_html,"    <body>\n");
    		//fprintf(fp_html,"        <nav class=\"navbar navbar-expand-sm navbar-dark bg-dark mt-3 mb-3\">\n");
   		 	//fprintf(fp_html,"        <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarNav4\"\n");
    		//fprintf(fp_html,"            aria-controls=\"navbarNav4\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n");
    		//fprintf(fp_html,"            <span class=\"navbar-toggler-icon\"></span>\n");
    		//fprintf(fp_html,"        </button>\n");
    		//fprintf(fp_html,"        <a class=\"navbar-brand\" href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/index.html\">KakeCoder</a>\"\n");
    		//fprintf(fp_html,"        <div class=\"collapse navbar-collapse\">\n");
			/*
    		fprintf(fp_html,"            <ul class=\"navbar-nav\">\n");
    		fprintf(fp_html,"                <li class=\"nav-item active\">\n");
    		fprintf(fp_html,"                    <a class=\"nav-link\" href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/index.html\">ホーム</a>\n");
    		fprintf(fp_html,"                </li>\n");
    		fprintf(fp_html,"                <li class=\"nav-item\">\n");
    		fprintf(fp_html,"                    <a class=\"nav-link\"\n");
    		fprintf(fp_html,"                        href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contest.html\">コンテスト</a>\n");
    		fprintf(fp_html,"                </li>\n");
    		fprintf(fp_html,"            </ul>\n");
    		fprintf(fp_html,"        </div>\n");
    		fprintf(fp_html,"        </nav>\n");
    		fprintf(fp_html,"        <!-- Optional JavaScript -->\n");
    		fprintf(fp_html,"        <!-- jQuery first, then Popper.js, then Bootstrap JS -->\n");
    		fprintf(fp_html,"        <script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\"\n");
    		fprintf(fp_html,"        integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\"\n");
    		fprintf(fp_html,"        crossorigin=\"anonymous\"></script>\n");
    		fprintf(fp_html,"        <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js\"\n");
    		fprintf(fp_html,"        integrity=\"sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49\"\n");
    		fprintf(fp_html,"        crossorigin=\"anonymous\"></script>\n");
    		fprintf(fp_html,"        <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js\"\n");
    		fprintf(fp_html,"        integrity=\"sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy\"\n");
    		fprintf(fp_html,"        crossorigin=\"anonymous\"></script>\n");

   			 fprintf(fp_html,"    </body>\n");
				*/
			fprintf(fp_html,"<body>\n");
			//fprintf(fp_html,"<div class=\"container\">");
    		//fprintf(fp_html,"        <div class=\"card\" style=\"width: 1000px;\">");
    	//	fprintf(fp_html,"            <div class=\"card-body\">");
    		//fprintf(fp_html,"                <nav class=\"navbar navbar-expand-sm navbar-light bg-light mt-3 mb-3\">");
   		 	//fprintf(fp_html,"                    <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarNav4\"");
    		//fprintf(fp_html,"                        aria-controls=\"navbarNav4\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">");
    		//fprintf(fp_html,"                        <span class=\"navbar-toggler-icon\"></span>");
    		//fprintf(fp_html,"                    </button>");
    		//fprintf(fp_html,"                    <div class=\"collapse navbar-collapse\">");
    	//	fprintf(fp_html,"                        <ul class=\"navbar-nav\">");
    	/*
			fprintf(fp_html,"                            <li class=\"nav-item active\">");
    		fprintf(fp_html,"                                <a class=\"nav-link\"");
    		fprintf(fp_html,"                                    href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/%s/index.html\">コンテストTOP</a>",contest_id);
    		fprintf(fp_html,"                            </li>");
    		fprintf(fp_html,"                            <li class=\"nav-item\">");
    		fprintf(fp_html,"                                <a class=\"nav-link\"");
    		fprintf(fp_html,"                                    href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/%s/problems.html\">問題一覧</a>",contest_id);
    		fprintf(fp_html,"                            </li>");
    		fprintf(fp_html,"                            <li class=\"nav-item\">");
    		fprintf(fp_html,"                                <a class=\"nav-link\"");
    		fprintf(fp_html,"                                    href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/%s/submit.html\">提出する</a>",contest_id);
    		fprintf(fp_html,"                            </li>");
    		fprintf(fp_html,"                           <li class=\"nav-item\">");
    		fprintf(fp_html,"                                <a class=\"nav-link\"");
    		fprintf(fp_html,"                                    href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/%s/ranking.html\">順位</a>",contest_id);
    		fprintf(fp_html,"                            </li>");
    		fprintf(fp_html,"                        </ul>");
    		fprintf(fp_html,"                    </div>");
    		fprintf(fp_html,"                </nav>");
			*/

			fprintf(fp_html,"	<table id=\"source_list-table\" class=\"table table-bordered\">\n");
			fprintf(fp_html,"		<thead>\n");
			fprintf(fp_html,"			<tr><th>提出番号</th><th>コンテストID</th><th>ユーザID</th><th>問題</th><th>リンク</th></tr>\n");
			fprintf(fp_html,"		</thead>\n");
			fprintf(fp_html,"		<tbody>\n");

			flg=1;
		}


		sprintf(tmp,"<tr><td>%s</td><td>%s</td><td>%s</td><td>%c</td><td><a href=\"https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/%s/User_Info/%s_%s_%s_%c.html\">link</a></td></tr>",
							submit_id,contest_id,user_id,problem[0],contest_id,submit_id,contest_id,user_id,problem[0]);
		fprintf(fp_html,"			%s\n",tmp);
    }
//	fprintf(fp_html,"			<div>\n");
	fprintf(fp_html,"		</tbody>\n");
	fprintf(fp_html,"	</table>\n");
	fprintf(fp_html,"</body>\n");
	fprintf(fp_html,"</html>\n");
    return 0;
}
