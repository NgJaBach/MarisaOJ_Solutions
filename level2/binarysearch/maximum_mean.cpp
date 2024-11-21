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
const ll INF=1e12+7;
vector<long double>gay,spoon;
const long double eps=0.00000001;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,k;
    ll a;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a;
        gay.pb(a);
    }
    long double L,R,mid,ans=0,minis,two=2;
    bool ok;
    L=0; R=M;
    while(!(R-L<eps)){
        mid=(L+R)/two;
//        cout<<L<<" "<<R<<" "<<mid<<endl;
        spoon=gay;
        for(int i=0;i<n;++i) spoon[i]-=mid;
        for(int i=1;i<n;++i) spoon[i]+=spoon[i-1];
        if(spoon[k-1]>=0){
            L=mid;
            ans=max(ans,mid);
            continue;
        }
        minis=spoon[0];
        ok=false;
        for(int i=k;i<n;++i){
            if((spoon[i]-minis)>=0){
                ok=true;
                break;
            }
            minis=min(minis,spoon[i-k+1]);
        }
        if(ok){
            L=mid;
            ans=max(ans,mid);
        }
        else{
            R=mid;
        }
    }
    cout<<setpre(3)<<ans;
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

