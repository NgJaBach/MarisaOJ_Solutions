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
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int cnt = 0, role = M, mostcnt = 0, mostrole = 0;
    for(int i = 0; i < n; ++i){
    	if(role != a[i]){
    		role = a[i];
    		cnt = 0;
    	}
    	++cnt;
		if(cnt > mostcnt){
			mostcnt = cnt;
			mostrole = role;
		}
		else if(cnt == mostcnt && role > mostrole)
			mostrole = role;
    }
    printf("%d", mostrole);
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