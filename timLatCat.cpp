#include <stdio.h>
#include "timLatCat.h"


void	capPhatVungNho(int **&a, int m, int n)
{
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int [n];
	}
}


void 	nhapDuLieu(int **&a, int &m, int &n)
{
	scanf("%d%d", &m, &n);
	capPhatVungNho(a, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}


void	xoaDuLieu(int **&a, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}


void	Init(int **a, int m, int n, int **&T, int **&track)
{
	capPhatVungNho(T, m, n);
	capPhatVungNho(track, m, n);

	for (int i = 0; i < n; i++) 
	{
		T[m - 1][i] = a[m - 1][i];
		track[m - 1][i] = -2;
	}	
}


void 	loTrinh(int **track, int i, int j, int m, int n, int *&way)
{
	if (i == m)
		return;
	else 
	{
		loTrinh(track, i + 1, j + track[i][j], m, n, way);
		way[i] = j;
	}
}


void 	partTimDuong(int **a, int m, int n, int **T, int **track, int &k)
{
	int buocdi[] = { -1, 0, 1 };

	for (int i = m - 2; i >= 0; i--) 
	{
		for (int j = 0; j < n; j++) 
		{
			int min = 0;
			bool kt = false;
			for (int k = 0; k < 3; k++) 
			{
				if (j + buocdi[k] < 0 || j + buocdi[k] >= n)
					continue;
				int p = T[i + 1][j + buocdi[k]];
				if (kt == false || p < min) 
				{
					min = p;
					track[i][j] = buocdi[k];
					kt = true;
				}
			}
			T[i][j] = a[i][j] + min;
		}
	}

	int min = T[0][0];
	k = 0;
	for (int i = 1; i < n; i++) 
	{
		if (T[0][i] < min) 
		{
			min = T[0][i];
			k = i;
		}
	}


}

void 	timDuong(int **a, int m, int n, int *&way)
{
	int **T, **track;
	Init(a, m, n, T, track);

	int k;
	partTimDuong(a, m, n, T, track, k);

	loTrinh(track, 0, k, m, n, way);

	xoaDuLieu(T, m);
	xoaDuLieu(track, m);
}

void	catAnh(int **&a, int &m, int &n, int *T)
{
	for(int i = 0; i<m; i++)
	{
		for(int j = T[i]; j< n-1; j++)
		{
			a[i][j] = a[i][j+1];
		}
	}
	n--;
}


void	timLatCat(int **&a, int &m, int &n, int k)
{
	for(int i = 0; i< k; i++)
	{
		int *way = new int [m];
		timDuong(a,m,n, way);
		catAnh(a, m, n, way);
		delete []way;
	}
}
