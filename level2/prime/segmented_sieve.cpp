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
const int N=1000050,M=1000000007;
const ll INF=1e18+7;
bool ok[N],ans[N];
vector<int>prime;

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    ll L,R,num;
    prime.pb(2);
    for(int i=3;i<N;i+=2) ok[i]=true;
    for(ll i=3;i<N;i+=2){
        if(ok[i]){
            prime.pb(i);
            for(ll j=i*i;j<N;j+=2*i){
                ok[j]=false;
            }
        }
    }
    cin>>L>>R;
    for(int i=0;i<=(R-L);++i) ans[i]=true;
    for(auto tmp:prime){
        num=L/tmp*tmp;
        if(num<L) num+=tmp;
        if(num==tmp) num+=tmp;
        for(ll i=num;i<=R;i+=tmp) ans[i-L]=false;
    }
    for(int i=0;i<=(R-L);++i) if(ans[i]) cout<<(i+L)<<" ";
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

