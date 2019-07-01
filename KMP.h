//
// Created by Gyy on 2019/5/7.
//
#include "string.h"
#ifndef KCSJ3_KMP_H
#define KCSJ3_KMP_H
void GetNext(char* p, int next[]){
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1){
        if (k == -1 || p[j] == p[k]){
            ++j;
            ++k;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];}
        else
        {
            k = next[k];
        }}}
int KmpSearch(char *s, char* p,int next[]){
    int count=0;
    //int flag=0;
    int i = 0;
    int j = -1;
    int sLen = strlen(s);
    int pLen = strlen(p);
    int hangnum =1;
    while (i < sLen){
        if (j == -1 || s[i] == p[j]){
            i++;
            j++;
            if(*(s+i) == '\n')
                hangnum++;
        }
        else{
            j = next[j];
        }
        if (j == pLen) {
            count++;
            printf("count:%d  ",count);
            printf("Column : %d",i-j);
            printf("  ");
            printf("Row : %d",hangnum);
            printf("\n");
            j = 0;
        }
    }
    return count;
}
#endif //KCSJ3_KMP_H
