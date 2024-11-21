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
const int N=15,M=1000000007;
const ll INF=1e18+7;
ll cost[N][N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n;
    ll sum,minis=INF;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin>>cost[i][j];
    }
    vector<int>ords;
    for(int i=1;i<=n;++i) ords.pb(i);
    do{
        sum=cost[ords[n-1]][ords[0]];
        for(int i=1;i<n;++i) sum+=cost[ords[i-1]][ords[i]];
        minis=min(minis,sum);
    }while(next_permutation(bend(ords)));
    cout<<minis;
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

