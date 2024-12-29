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
	int n, a = -M, b = -M;
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		if(x > a){
			b = a;
			a = x;
		}
		else if(x > b)
			b = x;
	}
	printf("%d", b);
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