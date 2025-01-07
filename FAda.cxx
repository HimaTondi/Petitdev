#include<stdio.h>
#define k 10
typedef 
struct Fada{
	int numero;
	float taille;
	float poids;
}Fada;
void elements( int n,struct Fada element[]){
	int i;
	printf("entrez l'effectif:");
	scanf("%d",&n);
	for(i=0;i< n;i++){
		printf("entrez le numero de %d eme element:",i+1);
		scanf("%d",&element[i].numero);
		printf("entrez la taille de %d eme  element:", i+1);
		scanf("%f",&element[i].taille);
		printf("entrez le poids de %d eme  element:",i+1);
		scanf("%f",&element[i].poids);
	}
	printf("---------------------------------------------------------\n");
printf("|\t....la liste des elements de la FADA   .....|\n");
printf("---------------------------------------------------------\n");
		printf("| le numero\t |\tla taille\t| le poids\t| ");
		printf("\n---------------------------------------------------------\n");
	for(i=0;i<n;i++){	
	printf("|%d. %d\t|\t%.0f\t\t |\t%.0f\t\t|",(i+1),element[i].numero,element[i].taille,element[i].poids);
	if(i<n){
			printf("\n---------------------------------------------------------\n");
	}
	}
}
int main(){
	struct Fada element[k];
	int n;
	elements(n,element);
	return(0);
}