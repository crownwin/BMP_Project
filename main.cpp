// ham main dung de demo cat K lat cat theo chieu doc trong mang 2 chieu
// mang hai chieu duoc su dung trong ham main co vai tro thay the cho mang nang luong diem anh


#include <stdio.h>
#include "timLatCat.h"


int main ()
{
	int **a, m, n;
	
	nhapDuLieu(a, m, n);
	
	timLatCat(a, m, n, 2); // cat 2 lat cat
	
	
	// xuat mang sau khi cat de kiem tra
	
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	xoaDuLieu(a, m);
	return 0;
}
