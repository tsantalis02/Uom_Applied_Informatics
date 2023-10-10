	// -------------------------------------------------------------
//
// This program creates instances of the Boolean Satisfiability problem.
// Each instance has N propositions, M sentences and K propositions per sentence.
// The values for N, K and M are constants for the program.
// Instance might be unsolvable!

// Instances are named from <prefix><id1>.txt to <prefix><id2>.txt .
//
// Syntax:
// generator <prefix> <id1> <id2>
//
// Author: Ioannis Refanidis, April 2009
//
// --------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 6
#define M 40
#define K 3

int Problem[M][K];		// A problem

// Check whether a new random value for Problem[i][j]
// is a new value for the current clause.
int new_value(int r, int i, int j) {
	int jj;
	for(jj=0;jj<j;jj++)
		if (abs(Problem[i][jj])==r)
			return 0;
	return 1;
}

// This function creates radomly a new problem.
void new_problem()
{
	int i,j,r;
	for(i=0;i<M;i++)
		for(j=0;j<K;j++){
			do {
				r=rand()%N+1;
			} while (!new_value(r,i,j));
			Problem[i][j]=r;
			r=rand()%100;
			if (r<50)
				Problem[i][j]=-Problem[i][j];
		}
}

// Auxiliary function that displays a message in case of wrong input parameters.
void syntax_message()
{
	printf("Use syntax:\n\n");
	printf("\tbcsp_generator.exe <prefix> <id1> <id2>\n\n");
	printf("where:\n ");
	printf("\t<prefix> = the prefix of the filename of the instances to be generated\n");
	printf("\t<id1> = a number indicating the suffix of the first instance.\n");
	printf("\t<id2> = a number indicating the suffix of the last instance.\n\n");
	printf("e.g. the call \n\n\tgenerator test 1 10\n\ngenerates 10 instances with names ranging from test1.txt to test10.txt.\n");
	printf("Constraints: id1>0, id2>0, id1<=id2.");
	}

void number2string(int n,char* s)
{
	int i=0,j;
	while (n>0)
	{
		// shift one position to the right
		for(j=i-1;j>=0;j--)
			s[j+1]=s[j];
		s[0]=(char) (n % 10)+'0';
		n=n / 10;
		i++;
	}
	s[i]='\0';
}

// This function writes the puzzle to a file
void write_to_file(int id, char *filename)
{
	int i,j;
	char *temp=(char*) malloc(10*sizeof(char));
	FILE *fout;
	char s[255];
	strcpy(s,filename);
	strcat(s,"_");
	number2string(id,temp);
	strcat(s,temp);
	strcat(s,".txt");

	fout=fopen(s,"w");

	fprintf(fout,"%d %d %d\n",N,M,K);

	for(i=0;i<M;i++)
		for(j=0;j<K;j++)
			if (j<K-1)
				fprintf(fout,"%d ",Problem[i][j]);
			else
				fprintf(fout,"%d\n",Problem[i][j]);

	fclose(fout);
}

int main(int argc, char** argv)
{
	long id1,id2, i;
	char* endPtr;

	// Seed the random-number generator with current time so that
	// the numbers will be different every time we run.

	srand( (unsigned) time ( NULL ) );

	if (argc!=4)
	{
		printf("Wrong number of arguments. Use correct syntax:\n");
		syntax_message();
		return -1;
	}

	id1=strtol(argv[2],&endPtr,10);
	id2=strtol(argv[3],&endPtr,10);
	if (id1<=0 || id2<=0 || id1>id2)
	{
		syntax_message();
		return -1;
	}

	for(i=id1;i<=id2;i++){
		new_problem();
		write_to_file(i,argv[1]);
	}

	return 0;
}
