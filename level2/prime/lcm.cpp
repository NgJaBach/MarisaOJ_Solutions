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
const int N=100050,M=1000000007;
const ll INF=1e18+7;
int divi[N];
void decomposing(ll n){
    int cnt;
    for(ll i=2;i*i<=n;++i){
        cnt=0;
        while(n%i==0){
            n/=i;
            ++cnt;
        }
        divi[i]=max(divi[i],cnt);
    }
    if(n>1){
        divi[n]=max(divi[n],1);
    }
    return;
}
ll binpow(ll a,int b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,a;
    ll ans=1;
    cin>>n;
    while(n--){
        cin>>a;
        decomposing(a);
    }
//    for(int i=2;i<=10;++i) cout<<divi[i]<<" "; cout<<endl;
    for(int i=2;i<N;++i) ans=(ans*binpow(i,divi[i]))%M;
    cout<<ans;
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
1 3 4 5
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

