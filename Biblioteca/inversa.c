#include<linalg.h>

double **inversa(double **M, double *X, int diml, int dimc)
{	double **T, **H, **B;
	int i, j, k, cont;
	
	T = (double**)malloc(diml*sizeof(double*));
	H = (double**)malloc(diml*sizeof(double*)); //alocando matrizes e ponteiros auxiliares
	B = (double**)malloc(diml*sizeof(double*));

	for(i=0;i<diml;i++)
	{	T[i] = (double*)malloc((2*diml)*sizeof(double));
		H[i] = (double*)malloc((diml+1)*sizeof(double));
		B[i] = (double*)malloc((diml)*sizeof(double));
	}		
	
	for(i=0;i<diml;i++)
		for(j=0;j<diml;j++)
		{	T[i][j] = M[i][j];
			B[i][j] = 0;
			X[i] = 0; //inicializando valores do vetor
		}
	
	for(i=0;i<diml;i++)
		for(j=diml;j<2*diml;j++)
			T[i][j] = (j-i==4) ? 1 : 0; //criando a identidade, pra triangularizar

	imprime(T,diml,2*diml);
	
	T = triangula(T,diml,2*diml,&cont);
	
	for(k=diml;k<2*diml;k++)
	{	for(i=0;i<diml;i++)
		{	H[i][diml] = T[i][k]; //colocando apenas os valores da coluna desejada
			
			for(j=0;j<diml;j++)				
			{	H[i][j] = T[i][j]; //copiando a matriz, da forma convencional
				X[j] = 0; //renovando valores, pro programa não calcular usando valores antigos
			}
		}
		
		printf("Matriz %d:\n", k-diml+1); //esses dois prints são para verificação do processo
		imprime(H,diml,diml+1);
		
		printf("Matriz %d dos coeficientes:\n", k-diml+1);
		imprime(B,diml,diml);
		
		substituicao(H, X, diml);
		
		for(j=0;j<diml;j++)
			B[k-diml][j] = X[j]; //preenche colunas, linha a linha
	}
	
	return B;
}
