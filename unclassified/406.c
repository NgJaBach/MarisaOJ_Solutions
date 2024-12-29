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
	int n, maxis = -M, pos;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(x > maxis){
			maxis = x;
			pos = i;
		}
	}
	printf("%d %d", maxis, pos);
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