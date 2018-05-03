#include<linalg.h>

double **ler(char *arquivo, int *linha, int *coluna)
{	double **R, a, l;
	int i, j, diml, dimc;
	FILE *p;
	
	fflush(stdin);
	
	if(!(p = fopen(arquivo, "r")))
		return NULL;
	
	i = fscanf(p,"%d%d",&diml, &dimc);

	R = (double**)malloc(diml*sizeof(double*));

	for(i=0;i<diml;i++)
		R[i] = (double*)malloc((dimc)*sizeof(double));
	
	for(i=0;i<diml;i++)
	{	for(j=0;j<dimc;j++)
		{	l = fscanf(p,"%lf",&a);
			R[i][j] = a;
		}
	}	
	*linha = diml;
	*coluna = dimc;
	
	fclose(p);
	
	return R;
}
