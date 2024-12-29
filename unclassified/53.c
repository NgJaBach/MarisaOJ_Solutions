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

char table[11][11];
int n, cnt;

bool check(int u, int v){
	int x, y;
	x = u; y = v;
	while(x > 1 && y > 1){
		--x; --y;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(x > 1 && y < n){
		--x; ++y;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(x < n && y > 1){
		++x; --y;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(x < n && y < n){
		++x; ++y;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(x > 1){
		--x;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(y > 1){
		--y;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(x < n){
		++x;
		if(table[x][y] == 'X')
			return false;
	}
	x = u; y = v;
	while(y < n){
		++y;
		if(table[x][y] == 'X')
			return false;
	}
	return true;
}

void back(int x){
	if(x > n){
		++cnt;
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(check(i, x)){
			table[i][x] = 'X';
			back(x + 1);
			table[i][x] = '.';
		}
	}
	return;
}

int main(){
	cnt = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			table[i][j] = '.';
	back(1);
	printf("%d", cnt);
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