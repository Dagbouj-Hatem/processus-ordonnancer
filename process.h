#ifndef PROCESS_H
#define PROCESS_H

struct processus
{
	char proc_name[30]; // nom  de processus
	int DAhh ; // l'heure d'arriv�e de processus
	int DAmm; // le minute d'arriv�e de processus
	int duree;  // le temps n�cessaire d'execution 
};
typedef  struct processus Process;




#endif
