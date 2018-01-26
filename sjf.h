#ifndef SJF_H
#define SJF_H
#include "process.h"
#include<stdio.h>

int position_shirt(Process *t,int  size)
{	int i ;
	int pos = 0 ; 
	
	for(i=1;i<size;i++)
	{
		if(&t[i]!=NULL)
		{
				if(t[i].duree<t[pos].duree)
				{
					pos =i ; 
				}
		}
	}
	
	return pos ; 
}

void change_hh_mm( int *hh , int *mm , int duree)
{
	     	// test  sur les munite
			mm += duree;  
			if (mm>=60)
			{
				mm -=60;
				hh+=1;
			}
			// test sur les heure 
			if(hh>=24)
			{
				hh-=24;
			}
			 
}
void sjf(Process *t,int  size)  
{ int j ;
  Process p;
  int  pos ; 
   int  hh , mm ;
	
	
	printf("-------------    FJF Strategy    --------------\n");
	for(j=0 ; j<size; j++)
	{
		// position  de shirt job 
		pos =  position_shirt(t,size);
		// determiner le heure de fin  de job 
		if(j==0)
		{
			hh= t[pos].DAhh; 
			mm = t[pos].DAmm; 
		}  
		// affichage 
		printf(" Processus : %s Date Arr: %d:%d  Duree : %d Date Servis : %d:%d",t[pos].proc_name, t[pos].DAhh,t[pos].DAmm,t[pos].duree, hh, mm);
	 	printf("\n");
	 	// change heure 
	 	change_hh_mm(&hh,&mm,t[pos].duree);
		// supprimer le processus 
		t[pos]=p; 
		
		
	}
	
	printf("\n\n");
	
}

#endif
