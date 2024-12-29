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
	int n;
	scanf("%d", &n);
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = (n - 1) / 2 * 2 + 1; i >= 1; i -= 2)
		printf("%d ", a[i]);
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