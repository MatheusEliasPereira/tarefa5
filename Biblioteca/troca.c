#include<linalg.h>

void troca(double *a, double *b, int dimc)
{	double aux;
	int i;
	
	for(i=0;i<dimc;i++)
	{	aux = a[i];
		a[i] = b[i];
		b[i] = aux;
	}
}
