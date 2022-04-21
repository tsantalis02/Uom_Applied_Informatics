#include <stdio.h>

#define QueueLimit 11

typedef int QueueElementType;

typedef struct {
	int Front, Rear,Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){
  QueueElementType i,n;
  QueueType Q;
  CreateQ(&Q);
  for(i=0;i<QueueLimit-1;i++){
    AddQ(&Q,i);
  }
  printf("---a---\n");
  printf("Queue: ");
  TraverseQ(Q);
  printf("Front=%d Rear=%d Count=%d \n",Q.Front,Q.Rear%10,Q.Count);
  printf("---b---\n");
  AddQ(&Q,5);
  printf("\n Queue: ");
  TraverseQ(Q);
  printf("Front=%d Rear=%d Count=%d \n",Q.Front,Q.Rear%10,Q.Count);
  printf("---c---\n");
  RemoveQ(&Q,&n);
  printf("Queue: ");
  TraverseQ(Q);
  printf("Removed item=%d Front=%d Rear=%d Count=%d \n",n,Q.Front,Q.Rear%10,Q.Count);
  printf("---d---\n");
  AddQ(&Q,25);
  printf("Queue: ");
  TraverseQ(Q);
  printf("Front=%d Rear=%d Count=%d \n",Q.Front,Q.Rear+1,Q.Count);
  printf("---e---\n");
  AddQ(&Q,6);
  printf("\nQueue: ");
  TraverseQ(Q);
  printf("Front=%d Rear=%d Count=%d \n",Q.Front,Q.Rear+1,Q.Count);
  printf("---f---\n");
  do{
    printf("Queue: ");
    RemoveQ(&Q,&n);
    TraverseQ(Q);
    if(EmptyQ(Q)){
      printf("Removed item=%d Front=%d Rear=%d Count=%d \n",n,(Q.Front%10)+1,Q.Rear+1,Q.Count);
    }else{
       printf("Removed item=%d Front=%d Rear=%d Count=%d \n",n,Q.Front%10,Q.Rear+1,Q.Count);
    }
  }while( Q.Count!=0);
return 0;}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
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
		Queue->Count--;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1)%QueueLimit;
		Queue->Count++;
	}
	else
		printf("Full Queue");
}


void TraverseQ(QueueType Queue) {
	int current,i;
	if(EmptyQ(Queue)) printf("Empty Queue \n");
	else{
	current = Queue.Front;
	//while (current != Queue.Rear) {
      for(i=1;i<=Queue.Count;i++){
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
}
