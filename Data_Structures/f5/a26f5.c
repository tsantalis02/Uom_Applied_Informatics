#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
 int code;
 int recNo;
}BinTreeElementType;

typedef struct{
int code;
char name[20];
char surname[20];
char sex;
int year;
float grade;
}StudentT;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade(float theGrade);
void writeNewstudents(BinTreePointer *Root,int *size);

int main(){
BinTreeElementType indexRec;
BinTreePointer ARoot,LocPtr;
int size;
boolean found;
float theGrade;
 printf("Q1.Build BST from  a file\n");
 size=BuildBST(&ARoot);
 printf("Q2.Print size and BST\n");
 printf("Size=%d\n",size);
 printf("Nodes of BST\n");
 RecBSTInorder(ARoot);
 printf("Q3.Write new students,update file and BST\n");
 writeNewstudents(&ARoot,&size);
 printf("Q4.Print size and BST\n");
 printf("Size=%d\n",size);
 RecBSTInorder(ARoot);
 printf("Q5.Search for a student\n");
 printf("Give student's code?");
 scanf("%d",&indexRec.code);
 RecBSTSearch(ARoot,indexRec,&found,&LocPtr);
 if(found==TRUE){
    PrintStudent(LocPtr->Data.code);
 }else{
    printf("Student with code %d hasn't found \n",indexRec.code);
 }
 printf("Q6.print size and BST\n");
 printf("Size=%d\n",size);
 RecBSTInorder(ARoot);
 printf("Q7.Print students with grades >= given grade\n");
 printf("Give the grade:");
 scanf("%f",&theGrade);
 printStudentsWithGrade(theGrade);
return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data.code = Item.code;
        (*Root)->Data.recNo=Item.recNo;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else{
        if(Item.code < (*Root) ->Data.code){
            RecBSTInsert(&(*Root) ->LChild,Item);
        }else if (Item.code > (*Root) ->Data.code){
            RecBSTInsert(&(*Root) ->RChild,Item);
        }else{
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
    }
}
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else{
                    *Found = TRUE;
                    *LocPtr=Root;
            }
}

 void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%d,%d),",Root->Data.code,Root->Data.recNo);
        RecBSTInorder(Root->RChild);
    }
}

int BuildBST(BinTreePointer *Root){
FILE* fp;
int nscan,size,line;
char termch;
StudentT student;
BinTreeElementType indexRec;
 CreateBST(Root);
 fp=fopen("foitites.dat","r");
 size=0;
 line=0;
 if(fp!=NULL){
    while(TRUE){
        nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch);
        if(nscan==EOF){
           break;
           }
         line++;
        if(nscan!=6 || termch!='\n'){
            printf("Error in the line%d.Programm termination \n",line);
        }else{
          indexRec.code=student.code;
          indexRec.recNo=size;
          RecBSTInsert(&(*Root),indexRec);
          size++;
        }
    }
 }
fclose(fp);
return size;
}

void writeNewstudents(BinTreePointer *Root,int *size){
FILE* fp;
StudentT student;
BinTreeElementType indexRec;
boolean found;
BinTreePointer LocPtr;
char ch;
fp=fopen("foitites.dat","a");

if(fp!=NULL){
    while(TRUE){
       printf("Give student's AM?");
       scanf("%d",&indexRec.code);
       RecBSTSearch(*Root,indexRec,&found,&LocPtr);
       if(found==FALSE){
        student.code=indexRec.code;
        printf("Give student's surname?");
        scanf("%s",student.surname);getchar();
        printf("Give student's name?");
        scanf("%s",student.name);getchar();
        printf("Give student's sexF/M?");
        scanf("%c",&student.sex);getchar();
        printf("Give student's registration year?");
        scanf("%d",&student.year);
        printf("Give student's grade?");
        scanf("%f",&student.grade);
        indexRec.recNo=*size;
        RecBSTInsert(&(*Root),indexRec);
        fprintf(fp,"\n");
        (*size)++;
       }else{
         printf("%d exists in file already\n",indexRec.code);
          printf("Continue Y/N:");
           do{
              scanf("%c", &ch);
             } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        }while (toupper(ch)!='N');
       }
      fclose(fp);
}
}

void PrintStudent(int recNum){
FILE* fp;
int nscan,lines;
char termch;
StudentT student;
fp=fopen("foitites.dat","r");
lines=0;
if(fp!=NULL){
    while(lines!=recNum){
       nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch);
         if(nscan == EOF) break;
         lines++;
        if(nscan != 6 || termch != '\n'){
            printf("Error in line %d.Program termination\n",lines);
            exit(1);
   }
   if(lines==recNum+1){
    printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade);
   }
}
}
fclose(fp);
}

void printStudentsWithGrade(float theGrade){
FILE* fp;
int nscan,line=0;
char termch;
StudentT student;
fp=fopen("foitites.dat","r");
if(fp!=NULL){
    while(TRUE){
         nscan=fscanf(fp,"%d,%s,%s,%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch);
         if(nscan == EOF) break;
         line++;
        if(nscan != 6 || termch != '\n'){
            printf("Error in line %d.Program termination \n",line);
    }else{
       if(student.grade>=theGrade){
        printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade);
       }
     }
}
fclose(fp);
}
}
