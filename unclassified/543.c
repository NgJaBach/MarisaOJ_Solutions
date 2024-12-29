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

void back(char s[11], int x, int n){
	if(x == n){
		for(int i = 0; i < n; ++i)
			printf("%c", s[i]);
		printf("\n");
		return;
	}
	s[x] = '0'; back(s, x + 1, n);
	s[x] = '1'; back(s, x + 1, n);
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	char s[11];
	back(s, 0, n);
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