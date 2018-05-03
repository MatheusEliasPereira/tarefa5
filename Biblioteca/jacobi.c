#include<linalg.h>

double *jacobi(double **M, int dim)
{	double *x, *aux, soma, prec = 1e-5;
	int i, j;
	
	x = (double*)malloc(dim*sizeof(double));
	aux = (double*)malloc(dim*sizeof(double));
	
	memset(x,0,dim*sizeof(0));
	memset(aux,0,dim*sizeof(0));
	
	do
	{	for(i=0;i<dim;i++)
		{	soma = 0;
			aux[i] = x[i];
			
			for(j=0;j<dim+1;j++)
				if(i!=j)
					soma += M[i][j]*x[j];
			
			x[i] = (M[i][dim] - soma)/M[i][i];
		}
	}while(precisao(x,aux,dim)>prec);
	
	return x;
}
