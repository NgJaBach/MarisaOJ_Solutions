// NgJaBach: Forever Meadow <3

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=2000050,M=1000000007;
const ll INF=1e18+7;
bool ok[N];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n;
    cin>>n;
    if(n<2){
        return 0;
    }
    for(int i=2;i<=n;++i) ok[i]=true;
    cout<<2<<" ";
    for(int i=2;i<=n;i+=2) ok[i]=false;
    for(ll i=3;i<=n;i+=2){
        if(ok[i]){
            cout<<i<<" ";
            for(ll j=i*i;j<=n;j+=2*i) ok[j]=false;
        }
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

