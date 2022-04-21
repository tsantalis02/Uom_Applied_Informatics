#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HMax 9
#define VMax 10
#define EndOfList -1

typedef struct{
   char phone[10];
   int code;
} ListElementType;

typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];
    int Size;
	int SubListPtr;
    int StackPtr;
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
int findAverage(KeyType s);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList,int code);
void PrintPinakes(HashListType HList);

int main(){
HashListType HList;
ListElm AnItem;
KeyType AKey;
int Loc,Pred,code;
char surname[20],ch;
  printf("1.Create HashList\n");
  BuildHashList(&HList);
  PrintPinakes(HList);
  printf("2.Insert new teacher\n");
  do{
    printf("Enter teacher's name:");
    scanf("%s",AnItem.RecKey);
    printf("Enter teacher's surname:");
    scanf("%s",surname);
    strcat(AnItem.RecKey," ");
    strcat(AnItem.RecKey,surname);
    printf("Enter teacher's phone:");
    scanf("%s",AnItem.Data.phone);
    printf("Enter teacher's code:");
    scanf("%d",&AnItem.Data.code);
    AddRec(&HList,AnItem);
    printf("\nContinue Y/N:");
    do{
        scanf("%c",&ch);
    }while(toupper(ch)!='N' && toupper(ch)!='Y');
  }while(toupper(ch)!='N');
  PrintPinakes(HList);
  printf("3.Delete a teacher\n");
  printf("Enter teacher's name:");
  scanf("%s",AnItem.RecKey);
  printf("Enter teacher's surname:");
  scanf("%s",surname);
  strcat(AnItem.RecKey," ");
  strcpy(AKey,strcat(AnItem.RecKey,surname));
  DeleteRec(&HList,AKey);
  PrintPinakes(HList);
  printf("4.Search for a teacher\n");
  printf("Enter teacher's name:");
  scanf("%s",AnItem.RecKey);
  printf("Enter teacher's surname:");
  scanf("%s",surname);
  strcat(AnItem.RecKey," ");
  strcpy(AKey,strcat(AnItem.RecKey,surname));
  SearchHashList(HList,AKey,&Loc,&Pred);
  if(Loc==-1 && Pred==-1){
    printf("DEN YPARXEI EGGRAFH ME KLEIDI %s",AKey);
  }else{
    printf("[%s,%s,%d]\n",AnItem.RecKey,HList.List[Loc].Data.phone,HList.List[Loc].Data.code);
  }
  printf("\n5.Search by subject\n");
  printf("Enter code:");
  scanf("%d",&code);
  printf("List of teachers with subject code %d:\n",code);
  Search_HashList_By_Subject(HList,code);
return 0;
}

int HashKey(KeyType Key)
{
    int avg;
    avg=findAverage(Key);

	return avg%HMax;
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void CreateHashList(HashListType *HList)
{
	int index;

	HList->Size=0;
	HList->StackPtr=0;
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}

void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
{
	int Loc, Pred, New, HVal;


	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

int findAverage(KeyType s){
char first,last;
first=toupper(s[0]);
last=toupper(s[strlen(s)-1]);
return ((first-64)+(last-64))/2;
}

void BuildHashList(HashListType *HList){
ListElm AnItem;
FILE* fp;
char surname[20],termch;
CreateHashList(HList);
fp=fopen("i4f6.txt","r");
if(fp==NULL){
      printf("Cannot open input file i4f6.txt\n");
   }else{
    while(TRUE){
       fscanf(fp,"%10[^,],%20[^,],%10[^,],%d%c",AnItem.RecKey,surname,AnItem.Data.phone,&AnItem.Data.code,&termch);
        if(feof(fp)){
            break;
        }
        if(termch!='\n'){
            printf("Error\n");
        }else{
          strcat(AnItem.RecKey," ");
          strcat(AnItem.RecKey,surname);
          AddRec(HList,AnItem);
        }
    }
}
fclose(fp);
}

void Search_HashList_By_Subject(HashListType HList,int code){
int i,SubIndex;
for(i=0;i<HMax;i++){
    SubIndex=HList.HashTable[i];
    while(SubIndex!=EndOfList){
        if(HList.List[SubIndex].Data.code==code){
            printf("%d: [%s, %s, %d]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.phone,HList.List[SubIndex].Data.code);
        }
   SubIndex=HList.List[SubIndex].Link;
    }
}
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d,",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}
