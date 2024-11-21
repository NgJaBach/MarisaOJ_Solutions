// Dreaming the Impossible

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define pb push_back
#define pob pop_back
#define emp emplace_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define rev reverse
#define fi first
#define se second
#define gcd __gcd
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define getl(s) getline(cin, s);
#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a))
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;

map<int,ll>rem;

ll back(int n){
	if(n==0)
		return 0;
	if(rem[n])
		return rem[n];

	int a = n/2;
	int b = n/3;
	int c = n/4;

	rem[n] = n;
	
	for(int i = 0; i < (1<<3); ++i){
		ll sum = 0;
		
		if(i&(1<<0))
			sum += back(a);
		else
			sum += a;

		if(i&(1<<1))
			sum += back(b);
		else
			sum += b;

		if(i&(1<<2))
			sum += back(c);
		else
			sum += c;

		rem[n] = max(rem[n], sum);
	}
	return rem[n];
}

void solve(){
    int t;
    cin >> t;
    while(t--){
    	int x;
    	cin >> x;
    	cout << back(x) << endl;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    while(t--){
        solve();
        cout<<endl;
    }
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