#include"linalg.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	double **M, **I, **T, **F, **V, *X, *Y, det;
	int i, diml, dimc, LA, CA, LB, CB, cont = 0;
	
	M = I = T = F = V = NULL;
        X = Y = NULL;
        
	M = ler(argv[1],&diml, &dimc);
	printf("\n==========LEITURA==========:\n");
	imprime(M,diml,dimc);
	
	F = copia(M,diml,dimc);
	
	M = triangula(M,diml,dimc,&cont);
	printf("\n==========ESCALONAMENTO==========:\n");
	imprime(M,diml,dimc);
	
        if((det = determinante(M,diml,cont))!=0)
        {	printf("\n==========DETERMINANTE DA MATRIZ M=========\nDet = %.3lf\n", det);
                
                printf("\n==========SOLUÇÃO PELO MÉTODO DA ELIMINAÇÃO DE GAUSS COM PIVOTAMENTO PARCIAL=========\n\n");
                
                X = (double*)malloc(diml*sizeof(double));
                *X = 0;
                substituicao(M,X,diml);

                if(diml==dimc)
                {   *X = 0;
                    T = inversa(F,X,diml,dimc);	
                    I = transposta(T,diml,dimc);
                    
                    printf("\n==========INVERSA=========\n\n");
                    imprime(I,diml,dimc);
                }
                    
                Y = (double*)malloc(diml*sizeof(double));
                printf("\n==========SOLUÇÃO PELO MÉTODO DE JACOBI=========\n\n");
                Y = jacobi(M,diml);
                
                for(i=0;i<diml;i++)
                        printf("\nx[%d] = %g\n", i, Y[i]);
        }
	
	LA = LB = diml;
	CA = CB = dimc;
	
	if(CA == LB)
	{	printf("\n=========MULTIPLICAÇÃO DA MATRIZ LIDA COM SUA INVERSA=========\n");
		V = multiplica(F,I,LA,CA,CB);
		imprime(V,LA,CB);
	} else	printf("\nNão é possível multiplicar.\n");
	
	if(I)
          free(I);
        if(T)
            free(T);
        if(V)
            free(V);
        
        free(M);
        free(F);
	free(X);
	free(Y);
	
	return 0;
}
