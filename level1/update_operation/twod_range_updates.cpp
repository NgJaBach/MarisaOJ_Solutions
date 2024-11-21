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
const int N=1050,M=1000000007;
const ll INF=1e18+7;
int table[N][N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m,q,a,b,c,d;
    cin>>n>>m>>q;
    while(q--){
        cin>>a>>b>>c>>d;
        ++table[a][b];
        --table[a][d+1];
        --table[c+1][b];
        ++table[c+1][d+1];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            table[i][j]+=table[i-1][j]+table[i][j-1]-table[i-1][j-1];
            cout<<table[i][j]<<" ";
        }
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

