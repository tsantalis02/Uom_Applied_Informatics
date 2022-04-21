#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HMax 5
#define VMax 30
#define EndOfList -1

typedef struct{
  char name[20];
  int amount;
} ListElementType;

typedef int KeyType;

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


void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void PrintPinakes(HashListType HList);
void Print_HashList(HashListType HList);
void PrintListOfSynonyms(HashListType HList,KeyType key);

int main(){
char ch;
HashListType HList;
ListElm AnItem;
KeyType AKey;
int Loc,Pred;
printf("1.Create HashList\n");
CreateHashList(&HList);
Print_HashList(HList);
PrintPinakes(HList);
printf("2.Insert new member\n");
do{
    printf("Give code:");
    scanf("%d",&AnItem.RecKey);
    printf("Give name:");
    scanf("%s",AnItem.Data.name);
    printf("Give amount:");
    scanf("%d",&AnItem.Data.amount);
    AddRec(&HList,AnItem);
    printf("\nContinue Y/N:");
    do{
        scanf("%c",&ch);
    }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
}while (toupper(ch)!='N');
Print_HashList(HList);
PrintPinakes(HList);
printf("3.Search for a member\n");
do{
    printf("Give code:");
    scanf("%d",&AKey);
    SearchHashList(HList,AKey,&Loc,&Pred);
    if(Loc==-1 && Pred==-1){
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %d",AKey);
    }else{
       printf("[%d,%s,%d,%d]",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
    }
     printf("\nContinue Y/N:");
      do{
        scanf("%c",&ch);
      }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
}while(toupper(ch)!='N');
printf ("4.Update member amount\n");
do{
    printf("Give code:");
    scanf("%d",&AKey);
    SearchHashList(HList,AKey,&Loc,&Pred);
    if(Loc==-1 && Pred==-1){
      printf("DEN YPARXEI EGGRAFH ME KLEIDI %d",AKey);
    }else{
        printf("[%d,%s,%d,%d]",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
        printf("\nGive amount:");
        scanf("%d",&AnItem.Data.amount);
        if(HList.List[Loc].Data.amount>=AnItem.Data.amount){
            HList.List[Loc].Data.amount=HList.List[Loc].Data.amount-AnItem.Data.amount;
    }
    }
     printf("\nContinue Y/N:");
      do{
        scanf("%c",&ch);
      }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    }while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');
Print_HashList(HList);
PrintPinakes(HList);
printf("5.Delete a member\n");
do{
    printf("Give code:");
    scanf("%d",&AKey);
    SearchHashList(HList,AKey,&Loc,&Pred);
    if(Loc==-1 && Pred==-1){
       printf("DEN YPARXEI EGGRAFH ME KLEIDI %d",AKey);
    }else{
      if(HList.List[Loc].Data.amount==0){
            DeleteRec(&HList,AKey);
        }else{
         printf("Not deleted arrange amount\n");
        }
    }
    printf("\nContinue Y/N:");
      do{
        scanf("%c",&ch);
      }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    }while(toupper(ch)!= 'N');
    Print_HashList(HList);
    PrintPinakes(HList);
    printf("6.Print list of synonyms\n");
    do{
        printf("Give code:");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if(Loc==-1 && Pred==-1){
            printf("DEN YPARXEI EGGRAFH ME KLEIDI %d",AKey);
        }else{
          printf("[%d,%s,%d,%d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
             PrintListOfSynonyms(HList,AKey);
        }
        printf("\nContinue Y/N:");
        do{
        scanf("%c",&ch);
        }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        }while(toupper(ch)!= 'N');
return 0;
}

int HashKey(KeyType Key)
{
	return Key%HMax;
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

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
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

    New=0;
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

		/*else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}*/
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
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %d,%s,%d,%d\n",i,HList.List[i].RecKey,HList.List[i].Data.name,HList.List[i].Data.amount,HList.List[i].Link);
	printf("\n");
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %s, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name,HList.List[SubIndex].Data.amount,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

         /* printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");*/

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}


void PrintListOfSynonyms(HashListType HList, KeyType key)
{
     int Hval ,SubIndex;

   Hval=HashKey(key);
    SubIndex=HList.HashTable[Hval];
    while(SubIndex!=EndOfList)
    {
        printf("%d:[%d,%s, %d]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name,HList.List[SubIndex].Data.amount);
        SubIndex=HList.List[SubIndex].Link;
    }

}
