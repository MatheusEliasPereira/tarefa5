#include<linalg.h>

double **triangula(double **M, int diml, int dimc, int *cont)
{
 	int i, j, k, h, p = -1;
 	double aux;
 	
 	for(k=0;k<diml;k++) // função que faz triangular superior
 	{	for(h=k;h<diml;h++)
 			if(M[k][k]<fabs(M[h][k]))
				p = h;
 		
 		if(p!=-1)
		{	troca(M[k],M[p],dimc);
 			puts("Matriz trocada");
 			imprime(M,diml,dimc);
 			*cont++;
		}
	 	
	 	p = -1;
 		
 		for(i=k+1;i<diml;i++)
 		{	
 			aux = (M[i][k]/M[k][k]);
 
 			for(j=k;j<=dimc;j++)
 				M[i][j] = M[i][j] - aux*M[k][j];
 		}
 		
 		printf("\nPasso %d\n", k+1);
 		imprime(M,diml,dimc);	
 	}
		
	return M;
}
