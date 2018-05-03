#include<linalg.h>

void substituicao(double **M, double *raizes, int diml)
{	int i, j;
	double b[diml], soma[diml], aux;
	
	for(i=diml-1;i>=0;i--)
	{	soma[i] = 0;
	
		for(j=i;j<=diml;j++)
		{	soma[i] = soma[i] + M[i][j-1]*raizes[j-1];
			printf("\nj = %d\tRaiz[%d] = %lf\n", j, j-1, raizes[j-1]);
		}
		
		aux = M[i][diml];
		b[i] = aux - soma[i];
		raizes[i] = (double)b[i]/M[i][i];
		
		printf("\nRaiz %d: %.3lf\n", i, raizes[i]);
	}
}
