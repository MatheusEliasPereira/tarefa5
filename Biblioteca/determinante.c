#include<linalg.h>

double determinante(double **A, int dim, int q)
{	int i;
	double x = 1;
	
	for(i=0;i<dim;i++)
		x *= A[i][i];
	
	if(q%2!=0)
		x = -1*x;
	
	return x;
}
