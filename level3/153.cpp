// The Shadow Monarch

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
const int N=2005,M=1000000007;
const ll INF=1e18+7;

bool dp[N][N];

void solve(){
    string s;
    int n,x,y,t;
    cin>>s; n=(int)s.size();
    s="$"+s;
    for(int i=1;i<=n;++i) dp[i][i]=true;
    for(int i=2;i<=n;++i) dp[i-1][i]=(s[i-1]==s[i]);
    for(int k=3;k<=n;++k)
        for(int i=k;i<=n;++i)
            dp[i-k+1][i]=(s[i-k+1]==s[i] and dp[i-k+2][i-1]);
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(dp[x][y]) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
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

