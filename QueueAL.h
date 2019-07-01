//
// Created by Gyy on 2019/5/7.
//
#ifndef KCSJ3_QUEUEAL_H
#define KCSJ3_QUEUEAL_H
#include "Queue.h"
int InitQueue(LinkQueue *Q)//初始化队列
{
    Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return(TRUE);
    }
    else
    {
        return FALSE;
    }}
int EnterQueue(LinkQueue *Q,QueueElementType x){
    LinkQueueNode *NewNode;
    NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear=NewNode;
        return (TRUE);
    }
    else
        return FALSE;
}//入队
char* DeleteQueue(LinkQueue *Q)
{
    char *str="-1";
    QueueElementType *x;
    LinkQueueNode *p;
    if(Q->front==Q->rear)
        return str;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    x = &(p->data);
    return *x;
}
#endif //KCSJ3_QUEUEAL_H
