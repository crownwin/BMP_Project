#include <stdio.h>

void	capPhatVungNho(int **&a, int m, int n);

void 	nhapDuLieu(int **&a, int &m, int &n);
void	xoaDuLieu(int **&a, int m);

void	Init(int **a, int m, int n, int **&T, int **&track);

void 	loTrinh(int **track, int i, int j, int m, int n, int *&way);
void 	partTimDuong(int **a, int m, int n, int **T, int **track, int &k);

void 	timDuong(int **a, int m, int n, int *&way);


void	catAnh(int **&a, int &m, int &n, int *T);
void	timLatCat(int **&a, int &m, int &n, int k);
