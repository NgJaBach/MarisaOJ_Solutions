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
	int n, m;
	scanf("%d %d", &n, &m);
	int sum[m + 1];
	for(int i = 1; i <= m; ++i)
		sum[i] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			int x;
			scanf("%d", &x);
			sum[j] += x;
		}
	for(int i = 1; i <= m; ++i)
		printf("%d ", sum[i]);
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