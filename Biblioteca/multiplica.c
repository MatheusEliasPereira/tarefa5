#include<linalg.h>

double **multiplica(double **A, double **B, int LA, int CA, int CB)
{	double **C, aux = 0;
	int i, j, k;
	
	C = (double**)malloc(LA*sizeof(double*));
	for(i=0;i<LA;i++)
		C[i] = (double*)malloc(CB*sizeof(double));
		
	for(k=0;k<CB;k++)
	{	for(i=0;i<LA;i++)
		{	for(j=0;j<CA;j++)
				aux = aux + A[i][j]*B[j][k];
			
			C[i][k] = aux;
			aux = 0;
		}
	}
	return C;
}
