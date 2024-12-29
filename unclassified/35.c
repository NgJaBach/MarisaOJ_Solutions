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

int cmp(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	qsort(a, n, sizeof(int), cmp);
	qsort(b, n, sizeof(int), cmp);
	for(int i = 0; i < n; ++i)
		if(a[i] != b[i]){
			printf("NO");
			return 0;
		}
	printf("YES");
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