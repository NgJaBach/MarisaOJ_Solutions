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
		for(int i = 1; i < n; ++i)
			if(s[i] == s[i - 1])
				return;
		for(int i = 0; i < n; ++i)
			printf("%c", s[i]);
		printf("\n");
		return;
	}
	s[x] = 'A'; back(s, x + 1, n);
	s[x] = 'B'; back(s, x + 1, n);
	s[x] = 'C'; back(s, x + 1, n);
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