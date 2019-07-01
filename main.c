#include "QueueAL.h"
#include "KMP.h"
#define Maxsize 1000
int Filelength(filename){//读取文件长度
    int length = 0;
    FILE *f1;
    f1 = fopen(filename,"r");
    while(fgetc(f1)!=EOF)
        length++;
    fclose(f1);
    return  length;
}
void Start(){
    FILE *fp;
    LinkQueue Q;
    int size = sizeof(char);//fread参数size
    printf("enter file name:\n");
    char filename [50],content[Maxsize][Maxsize];//存文件名、读取的文件内容
    char  *outchar[50];
    gets(filename);//输入文件名
    if ((fp=fopen(filename,"r"))==NULL){
        printf("ERROR FILENAME !\nPRESS ANY KEY TO EXIT\n");
        getchar();
        exit(-1);
    } else {
        fread(content,2,Filelength(filename),fp);//读取文件内容放入content数组
        fclose(fp);//关闭
        int timeout,time,count;
        printf("%s\n",content);
        printf("how many words you want to search?\n");
        scanf("%d", &count);
        if(count < 0){
            printf("ERROR INPUT ! \nPRESS ANY KEY TO EXIT");
            getchar();
            exit(-1);
        } else {
            int next[count];//next数组
            printf("enter these words:\n");
            InitQueue(&Q);
            for (time = 0; time < count; time++) {
                char *str = (char *) malloc(sizeof(char) * 20*count);
                scanf("%s", str);
                EnterQueue(&Q, str);}
            for (timeout = 0; timeout < count; timeout++) {
                outchar[timeout] = DeleteQueue(&Q);//出队且存于字符数组中
                GetNext(outchar[timeout], next);
                printf("\n");
                printf("%s:total:%d\n",outchar[timeout],KmpSearch(content, outchar[timeout], next));
            }}}}
int main(){
    Start();
    return 0;}