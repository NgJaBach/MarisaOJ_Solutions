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
vector<int>smallPrime;
bool checkprime(int n){
    if(n<2) return false;
    if(n<4) return true;
    if(n%2==0 or n%3==0) return false;
    for(int i=5;i<=sqrt(n);i+=6) if(n%i==0 or n%(i+2)==0) return false;
    return true;
}
int divcnt(ll n){
    int ans=1,cnt;
    for(auto tmp:smallPrime){
        if(tmp*tmp*tmp>n) break;
        cnt=1;
        while(n%tmp==0){
            n/=tmp;
            ++cnt;
        }
        ans*=cnt;
    }
    if(n==1) return ans;
    if(checkprime(n)) return ans*2;
    int sq=sqrt(n);
    if(sq*sq==n) return ans*3;
    return ans*4;
}
bool ok[1005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    smallPrime.pb(2);
    for(int i=3;i<=1000;i+=2) ok[i]=true;
    for(int i=3;i<=1000;i+=2){
        if(ok[i]){
            smallPrime.pb(i);
            for(int j=i*i;j<=1000;j+=2*i) ok[j]=false;
        }
    }
    
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<divcnt(n)<<endl;
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5
464199374
669584822
736171974
828649263
365820829
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

