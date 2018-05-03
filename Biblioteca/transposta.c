#include<linalg.h>

double **transposta(double **M, int diml, int dimc)
{	double **S;
	int i, j;
	
	S = (double**)malloc(diml*sizeof(double*));
	for(i=0;i<diml;i++)
		S[i] = (double*)malloc((dimc)*sizeof(double));
	
	for(i=0;i<diml;i++)
		for(j=0;j<dimc;j++)
			S[i][j] = M[j][i]; //troca linhas por colunas
	
	return S;
}
