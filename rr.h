#ifndef RR_H
#define RR_H
#include "process.h"
#include<stdio.h>
void rr(Process *t,int  size)  
{ int j ;
 int  hh , mm ;
	
	
	printf("-------------    RR Strategy    --------------\n");
	for(j=0 ; j<size; j++)
	{
		if(j==0)
		{
			hh= t[j].DAhh; 
			mm = t[j].DAmm; 
		}  
			
		 
		
		printf(" Processus : %s Date Arr: %d:%d  Time : %d Date Servis : %d:%d",t[j].proc_name, t[j].DAhh,t[j].DAmm,t[j].duree, hh, mm);
	 	printf("\n");
	 	
	 	// test  sur les munite
			mm += t[j].duree; 
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
	
	printf("\n\n");
	
}

#endif
