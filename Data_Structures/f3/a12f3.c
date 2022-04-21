#include <stdio.h>

#define QueueLimit 4

typedef struct {
    int arrival,stay,start,end;
}QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void ReadData(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void PrintData(QueueType *Queue);
void TraverseQ(boolean flag,QueueType Queue);

int main(){
  QueueType QW,QS;
  int i;
  CreateQ(&QW);
  for(i=0;i<QueueLimit-1;i++){
    printf("Give: arrival time,stay time for client %d: ",i+1);
    ReadData(&QW);
  }
  TraverseQ(TRUE,QW);
  QS=TimesInQueue(&QW);
  TraverseQ(TRUE,QW);
  TraverseQ(FALSE,QS);
return 0;}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{


	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}

void ReadData(QueueType *Queue)
{
  QueueElementType Queuetmp;
   scanf("%d,%d",&Queuetmp.arrival,&Queuetmp.stay);
   Queuetmp.start=-1;
   Queuetmp.end=-1;
   AddQ(&(*Queue),Queuetmp);
}

QueueType TimesInQueue(QueueType *Queue){
 int earliestStart=0,currentStart=0,currentEnd=0;
 QueueType QueueServiced;
 QueueElementType CurrentQueue;
  CreateQ(&QueueServiced);
   while(!EmptyQ(*Queue)){
     RemoveQ(&(*Queue),&CurrentQueue);
    if(CurrentQueue.arrival>earliestStart){
        currentStart=CurrentQueue.arrival;
    }else{
       currentStart=earliestStart;
    }
    currentEnd=currentStart+CurrentQueue.stay;
    earliestStart=currentEnd;
    CurrentQueue.start=currentStart;
    CurrentQueue.end=currentEnd;
    AddQ(&QueueServiced,CurrentQueue);
}
 return QueueServiced;
}

 void TraverseQ(boolean flag,QueueType Queue) {
	int current;
	int i=0;
	if(!EmptyQ(Queue)){
	  if(flag){
        printf("\n Waiting Queue \n");
	  }else{
	    printf("\n Service Queue \n");
	  }
	  current = Queue.Front;
	  printf("Client   \t\tStart\tEnd\tArrival\tStay\n");
	while (current != Queue.Rear) {
        printf("Client %d\t\t%d\t%d\t%d\t%d\n ",i+1,Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].arrival,Queue.Element[current].stay);
		current = (current + 1) % QueueLimit;
		i+=1;
	}
	}else{
	    if(flag){
           printf("Waiting Queue is empty\n");
	    }else{
	      printf("Service Queue is empty\n");
	    }
	}
}


