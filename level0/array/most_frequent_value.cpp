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
map<int,int>gay;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,a,maxis=-1,ans;
    cin>>n;
    while(n--){
        cin>>a;
        ++gay[a];
    }
    for(auto tmp:gay){
        if(tmp.se==maxis) ans=max(ans,tmp.fi);
        else if(tmp.se>maxis){
            maxis=tmp.se;
            ans=tmp.fi;
        }
    }
    cout<<ans;
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8
-1 2 3 2 2 3 -1 -1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

