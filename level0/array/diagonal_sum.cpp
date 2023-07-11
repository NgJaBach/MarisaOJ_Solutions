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
const int N=200050,M=1000000007;
const ll INF=1e18+7;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m,a[105][105],u,v,x,y,sum;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    sum=a[x][y];
    u=x-1; v=y-1;
    while(u>0 and v>0){
        sum+=a[u][v];
        --u; --v;
    }
    u=x-1; v=y+1;
    while(u>0 and v<=m){
        sum+=a[u][v];
        --u; ++v;
    }
    u=x+1; v=y-1;
    while(u<=n and v>0){
        sum+=a[u][v];
        ++u; --v;
    }
    u=x+1; v=y+1;
    while(u<=n and v<=m){
        sum+=a[u][v];
        ++u; ++v;
    }
    cout<<sum;
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

