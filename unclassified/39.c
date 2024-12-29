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

int main(){
	int n, m, u, v;
	scanf("%d %d %d %d", &n, &m, &u, &v);
	int a[n + 1][m + 1];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	int x, y, sum = a[u][v];

	x = u; y = v;
	while(x > 1 && y > 1){
		--x; --y;
		sum += a[x][y];
	}
	x = u; y = v;
	while(x > 1 && y < m){
		--x; ++y;
		sum += a[x][y];
	}
	x = u; y = v;
	while(x < n && y > 1){
		++x; --y;
		sum += a[x][y];
	}
	x = u; y = v;
	while(x < n && y < m){
		++x; ++y;
		sum += a[x][y];
	}
	printf("%d", sum);
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