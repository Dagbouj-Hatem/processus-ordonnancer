#ifndef PROCESS_H
#define PROCESS_H

struct processus
{
	char proc_name[30]; // nom  de processus
	int DAhh ; // l'heure d'arrivée de processus
	int DAmm; // le minute d'arrivée de processus
	int duree;  // le temps nécessaire d'execution 
};
typedef  struct processus Process;




#endif
