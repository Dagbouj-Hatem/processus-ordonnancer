#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"
#include "sjf.h"
#include "rr.h"
#include "process.h"

int menu()
{  int choix ; 

	printf("+---------------------------------------------------------------+\n");
	printf("|                 Politique d'ordonnancement v1.0               |\n");
	printf("+---------------------------------------------------------------+\n");
	
	do {
	printf("\n\t Choisir un politique parmi la liste suivante : \n\n");
	printf("1--> FIFO ( First In First Out ) \n");
	printf("2--> SJF  ( Shirt Job First    ) \n");
	printf("3--> RR   ( Round Robin        ) \n");
	printf("4--> Quitter\n");

	scanf("%d",&choix);
	}while(choix<1 || choix >4);

	return choix; 
}


void charger_file( char * file_name , Process * t , int *size)
{
	
	/* cette fonction permet  de charger les processus contenu 
	/* dans un fichier dans un tableau de Processus
	*/
  FILE *fp ; 
  char line[60];
  Process p ; 
  
   
  int j, i=0 ; 
  
  fp = fopen(file_name,"r"); 
  while(fgets(line, 60, fp)!=NULL)
  {
  	    // if is commentaire
  	    if(line[0]=='#')
  	    {    //  on  va supposer que toutes les commentaires contenue
		     //  dans le fichier "process.txt" --> commance par le caréctére "#"
		     
  	    	// printf("commentaire\n");	
		}
		// if line blanc (vide) 
		else if (line[0]=='\n' || line[1]=='\n')
		{	// on va supposer que toutes les ligne vide commence par "\n" 
			// dans le 1ere ou le 2eme caréctére
			
			//printf("ligne vide \n");
		}
		else
		{
			// sinon line == processname-hh:mm-durée  
			
			// 1.0 Allocc memory 
			//p= (Process) malloc(sizeof(Process));
			
			//2.0 red data from line
		    sscanf( line, "%9s %*c %2d %*c %2d %*c  %2d", p.proc_name, &p.DAhh, &p.DAmm,&p.duree );
		    //printf("%s ** %d **  %d ** %d **\n",p.proc_name, p.DAhh , p.DAmm , p.duree);
			
			// 3.0 add Process in table t 
			t[i]= p;
			i++;
			
		 
		}
  }
	fclose(fp); // fermeture de fichier process
	
	*size =i;
	
}
int main(int argc, char const *argv[])
{ 
	// déclaration 
	int choix ; 
	
	Process t[100];
	int size =0 ; 

	//charger les processus 
	charger_file(argv[1], &t , &size);  
	while(1)
	{
		choix = menu();
		switch(choix)
		{
			case 1 : fifo(t,size); break; 
			case 2 : sjf(t,size);  break; 
			case 3 : rr(t,size);   break; 
			case 4 :
		   {	
		   		printf("Merci Pour Votre Attention \n"); 
			      exit(0);
				break;
			} 
		}
	}
	return 0;
}
