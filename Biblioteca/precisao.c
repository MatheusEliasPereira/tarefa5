#include<linalg.h>

double precisao(double *u, double *v, int dim)
{	double soma = 0, mod = 0;
	
	for(;dim>0;dim--)
	{	soma += pow((u[dim-1] - v[dim-1]),2);
		mod += pow(v[dim-1],2);
	}
	
	return (double)soma/mod;
}
