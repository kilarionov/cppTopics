// B-JA-2009-3.MONETI_ver3.cpp
// https://arena.maycamp.com/practice/get_problem_description?contest_id=28&problem_id=54
#include <cstdio>  // smaller exe
using namespace std;

const short fake [2] = {-1, 1} ;
short gr11[4], gr12[4],
	  gr21[4], gr22[4],
	  gr31[4], gr32[4] ;
char r2, op[3] ;
bool r[3] ;
short	sum11,	sum12, 
		sum21,	sum22,
		sum31,	sum32 ;

int main ()
{
	short i, resCounter, r1 ;
// input
	for (short k=0; k<4; k++) scanf(" %hd ", &gr11[k]);
	scanf(" %c", &op[0]);
	for (short k=0; k<4; k++) scanf(" %hd ", &gr12[k]);
	
	for (short k=0; k<4; k++) scanf(" %hd ", &gr21[k]);
	scanf(" %c", &op[1]);
	for (short k=0; k<4; k++) scanf(" %hd ", &gr22[k]);

	for (short k=0; k<4; k++) scanf(" %hd ", &gr31[k]);
	scanf(" %c", &op[2]);
	for (short k=0; k<4; k++) scanf(" %hd", &gr32[k]);
  for (resCounter=i=0; i<2; i++)	
	for (short k=1; resCounter<2 && k<13; k++)
	{
		sum11=sum12=sum21=sum22=sum31=sum32 = 0;
		for (short t= 0; t<4; t++)
		{
			if (gr11[t] == k)
			{
				sum11=fake[i];
			}
			if (gr12[t] == k)
			{
				sum12=fake[i];
			}
			switch (op[0])
			{
				case '<':  r[0] = (sum11<sum12) ; break ;
				case '>':  r[0] = (sum11>sum12) ; break ;
				case '=':  r[0] = (sum11 == sum12) ; break ;
			}
			
			if (gr21[t] == k)
			{
				sum21=fake[i];
			}
			if (gr22[t] == k)
			{
				sum22=fake[i];
			}
			switch (op[1])
			{
				case '<':  r[1] = (sum21<sum22) ; break ;
				case '>':  r[1] = (sum21>sum22) ; break ;
				case '=':  r[1] = (sum21 == sum22) ; break ;
			}
			
			if (gr31[t] == k)
			{
				sum31=fake[i];
			}
			if (gr32[t] == k)
			{
				sum32=fake[i];
			}
			switch (op[2])
			{
				case '<':  r[2] = (sum31<sum32) ; break ;
				case '>':  r[2] = (sum31>sum32) ; break ;
				case '=':  r[2] = (sum31 == sum32) ; break ;
			}
		} ;
//		cout <<"\nk="<<k<<"\ti="<<i<<"===\t"<<r[0]<<'\t'<<r[1]<<'\t'<<r[2]<<endl ;
		if (r[0]&&r[1]&&r[2])
		{
//			if (0==resCounter)
//			{
				r1=k ;
				if (fake[i]==1)
					r2='+' ;
				else
					r2='-' ;
//			} ;
			resCounter++ ;
		}
	}
	if (0 == resCounter)
		printf("%s","impossible");
	else if (resCounter>1)
		printf("%s","indefinite");
	else
		printf("%d%c",r1, r2);
	printf ("\n") ;  // arena is OK ?s po 1 MemLimit no na razli4ni testove
	return 0 ;
}
