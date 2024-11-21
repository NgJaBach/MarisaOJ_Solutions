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
int trace[N];
bool ok[N];
set<int>ex;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    trace[1]=1;
    for(int i=2;i<N;i+=2) trace[i]=2;
    for(int i=3;i<N;i+=2) ok[i]=true;
    for(ll i=3;i<N;i+=2){
        if(ok[i]){
            trace[i]=i;
            for(ll j=i*i;j<N;j+=2*i){
                ok[j]=false;
                trace[j]=i;
            }
        }
    }
//    for(int i=2;i<=10;++i) cout<<trace[i]<<" "; cout<<endl;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ex.clear();
        while(n>1){
            ex.insert(trace[n]);
            n/=trace[n];
        }
        for(auto tmp:ex) cout<<tmp<<" ";
        cout<<endl;
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2
9
24
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

