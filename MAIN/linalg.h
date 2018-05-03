/*
 * linalg.h
 * 
 * Copyright 2018 Aluno <uff@LabUFFVR>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#ifndef linalg_h__
#define linalg_h__

extern double **ler(char *arquivo, int *linha, int *coluna);

extern void imprime(double **A, int diml, int dimc);

extern void troca(double *a, double *b, int dimc);

extern double **triangula(double **M, int diml, int dimc, int *cont);

extern void substituicao(double **M, double *raizes, int diml);

extern double determinante(double **A, int dim, int q);

extern double **inversa(double **M, double *X, int diml, int dimc);

extern double **transposta(double **M, int diml, int dimc);

extern double **copia(double **M, int diml, int dimc);

extern double **multiplica(double **A, double **B, int LA, int CA, int CB);

extern double precisao(double *u, double *v, int dim);

extern double *jacobi(double **M, int dim);

#endif //linalg_h__

