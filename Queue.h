//
// Created by Gyy on 2019/5/7.
//

#ifndef KCSJ3_QUEUE_H
#define KCSJ3_QUEUE_H
#define TRUE 0
#define FALSE 1
#include "stdio.h"
#include "stdlib.h"
typedef char* QueueElementType;
typedef struct Node{
    QueueElementType data;
    struct Node *next;
}LinkQueueNode;
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;
#endif //KCSJ3_QUEUE_H
