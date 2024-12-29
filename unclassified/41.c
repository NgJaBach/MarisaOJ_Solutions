// Dreaming the Impossible

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>

typedef long long int ll;
#define gcd __gcd

const int N=200050,M=1000000007;
const ll INF=1e18+7;

void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
	return;
}

int main(){
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int a[n + 1][m + 1];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	while(q--){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t == 1)
			for(int i = 1; i <= m; ++i)
				swap(a[x][i], a[y][i]);
		else
			for(int i = 1; i <= n; ++i)
				swap(a[i][x], a[i][y]);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/