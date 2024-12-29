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
	int n, a, b, ans = 0;
	scanf("%d %d", &n, &a);
	--n;
	while(n--){
		scanf("%d", &b);
		if(a > b && ans < (a - b))
			ans = (a - b);
		else if(a < b && ans < (b - a))
			ans = (b - a);
		a = b;
	}
	printf("%d", ans);
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