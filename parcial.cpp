#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <math.h>


void Generar_Vector(int [],int );
void Metodos_Ordenamiento(int lon);
int Burbuja(int lon);
void Mostrar_Vector(int vector[],int lon);

void Binario(int lon);
void Busqueda(int lon);
void Secuencial(int lon);
void Mezclar(int vector1[],int n1,int vector2[],int n2,int vector3[]);
void Mezcla(int vector[],int n);
void Menu();

int vector[500000],lon;

int main(){
	Menu();
	return 0;
}



void Menu(){
	int opcion, lon;
	
	
	
	printf("1.Metodos de Ordenamiento\n");
	printf("2.Metodos de Busqueda\n");
	printf("0.Salir\n");
	scanf("%d",&opcion);
	while(opcion!=0)
	{
		switch(opcion)
		{
		case 0:		  
			exit(0);		  
		case 1:
			printf(" Generar Vector\n\n");
			printf("Ingrese Tamaño del Vector:\n");
			printf("\n100000\n");
			printf("\n200000\n");
			printf("\n300000\n");
			printf("\n500000\n");
			scanf("%d",&lon);
			Generar_Vector(vector,lon);
			break; 		  
		case 2:
			printf(" Generar Vector\n\n");
			printf("Ingrese Tamaño del Vector:\n");
			printf("\n100000\n");
			printf("\n200000\n");
			printf("\n300000\n");
			printf("\n500000\n");
			scanf("%d",&lon);
			printf(" ordenar Vector:\n\n");
			Generar_Vector(vector,lon);
			Busqueda(lon);
			break;
		}
	}
}

void Generar_Vector(int vector[],int lon){
	int tiempo;	
	
	srand(time(NULL));	
	for(int i=0;i<=lon;i++)
	{		
		vector[i]=(rand()%999999)-999998;			
	}
	tiempo=clock();
	printf("Mostrando Vector:\n");
	for(int i=0;i<lon;i++)
	{
		printf("%d ",vector[i]);
	}
	printf("\nTiempo Transcurrido Generando Vector: %f s\n\n",(clock()-tiempo)/(double)CLOCKS_PER_SEC);
	Metodos_Ordenamiento(lon);
}

void Metodos_Ordenamiento(int lon){
	int opcion, tiempo;
	printf("Metodos de ordenamiento\n");
	printf("Que Metodo desea utilizar:\n1.Eficiente\n2.No Eficiente\n");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		printf("Metodos Eficientes, escoja una opcion:\n1.Merge\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			printf("Metodo Merge\n");
			Mezcla(vector,lon);
			tiempo=clock();
			Mostrar_Vector(vector,lon);
			printf("\nTiempo desde que inicio Ordenamiento Merge: %f s\n",(clock()-tiempo)/(double)CLOCKS_PER_SEC);			
			break;
		}
		break;
	case 2:
		printf("Metodos No Eficientes:\n1.Burbuja\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:			
			printf("Metodo Burbuja:\n");				   
			int tiempo;				   
			Burbuja(lon);
			tiempo=clock();				   
			Mostrar_Vector(vector,lon);
			printf("\nTiempo desde que inicio Ordenamiento Burbuja: %f s\n",(clock()-tiempo)/(double)CLOCKS_PER_SEC);				   
		break;
	}	
}

}
void Busqueda(int lon){
	int opcion;
	printf("Metodos de Busqueda, escoja una opcion:\n1.Busqueda Binaria\n2.Busqueda Secuencial\n");
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		printf("Busqueda Binaria\n");
		int tiempo;
		Binario(lon);
		tiempo=clock();
		printf("\nTiempo desde que inicio Busqueda Binaria: %f s\n",(clock()-tiempo)/(double)CLOCKS_PER_SEC);
		break;
	case 2:
		printf("Busqueda Secuencial\n");
		Secuencial(lon);
		tiempo=clock();
		printf("\nTiempo desde que inicio Busqueda Secuencial: %f s\n",(clock()-tiempo)/(double)CLOCKS_PER_SEC);
		break;
	}
	Menu();
}

int Burbuja(int lon)
{
	int aux;
	printf("Vector Ordenado:\n");
	
	for (int i=0;i<lon;i++)
	{
		for (int j=0;j<lon;j++)
		{
			if (vector[j]>vector[j+1])
			{
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;				
			}
		}
	}
	return *vector;
}


	
void Mostrar_Vector(int vector[],int lon)
{
	printf("Mostrando Vector Ordenado:\n");
	for(int i=0;i<=lon;i++)
	{
		printf("%d\n",vector[i]);
	}
}


void Binario(int lon)
{	
	int inf,sup,dato,mitad;
	char band = 'F';	
	printf ("ingrese el dato a buscar;\n");
	scanf ("%d",&dato);	
	inf = 0;
	sup = lon;	
	while((inf <= sup) && (band == 'F')) {
		mitad =((inf+sup)/2);
		if(vector[mitad]==dato){
			band = 'V';
		}
		else {
		   if(vector[mitad]>dato){
			sup = mitad - 1;
		} else{
			   inf = mitad + 1;
		   }
		} 
	}	
	if(band == 'F'){
		printf("Elemento no encontrado ");
	} 
	else{
	   if(band=='V'){
		printf("Elemento encontrado, en la pos: %i",mitad);
	}
	}
}

void Secuencial(int lon)
{
	int num;
	int encontrado=0;
	printf("Ingrese Numero a Buscar:\n");
	scanf("%d",&num);
	for(int i=0;i<lon;i++)
	{
		if(vector[i]==num)
		{
			encontrado=1;
		}
	}
	if(encontrado==1)
	{
		printf("Numero Encontrado\n");
	}else{
		printf("Numero NO Encontrado en la Lista\n");
	}
}

void Mezclar(int vector1[],int n1,int vector2[],int n2,int vector3[])
{
	int x1=0;
	int x2=0;
	int x3=0;
	
	while(x1<n1 && x2<n2)
	{
		if(vector1[x1]<vector2[x2])
		{
			vector3[x3]=vector1[x1];
			x1++;
		}else{
			vector3[x3]=vector2[x2];
			x2++;
		}
		x3++;
	}
	while(x1<n1)
	{
		vector3[x3]=vector1[x1];
		x1++;
		x3++;
	}
	while(x2<n2)
	{
		vector3[x3]=vector2[x2];
		x2++;
		x3++;
	}	
}

void Mezcla(int vector[],int n)
{
	int *vector1,*vector2,n1,n2,x,y;
	if(n>1)
	{
		if(n%2==0)
		{
			n1=n2=(int)n/2;
		}else{
			n1=(int)n/2;
			n2=n1+1;
		}
		vector1=(int*)malloc(sizeof(int)*n1);
		vector2=(int*)malloc(sizeof(int)*n2);
		for(x=0;x<n1;x++)
		{
			vector1[x]=vector[x];
		}
		for(y=0;y<n2;y++)
		{
			vector2[y]=vector[x];
		}		
		Mezcla(vector1,n1);
		Mezcla(vector2,n2);
		Mezclar(vector1,n1,vector2,n2,vector);
		free(vector1);
		free(vector2);
	}
}

