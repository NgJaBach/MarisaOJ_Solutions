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
//#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;
ull cnt[20],ten[20];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    ll n;
    cin>>n;
    cnt[0]=0; ten[0]=1; cnt[1]=9; ten[1]=10;
    for(ll i=2;i<=18;++i){
        ten[i]=ten[i-1]*10;
        cnt[i]=(ten[i]-ten[i-1])*i;
        cnt[i]+=cnt[i-1];
    }
//    for(int i=0;i<6;++i) cout<<cnt[i]<<" ";
    ll L,R,mid,num,maxis=1;
    L=1; R=INF;
    while(L<=R){
        mid=(L+R)/2;
        num=INF;
        for(ll i=1;i<=18;++i){
            if(mid<ten[i]){
                num=cnt[i-1]+(mid-ten[i-1]+1)*i;
                break;
            }
        }
//        if(num==INF){
//            cout<<"GAY";
//            return 0;
//        }
//        cout<<L<<" "<<R<<" : "<<mid<<" : "<<num<<endl;
        if(num>n) R=mid-1;
        else{
            maxis=max(maxis,mid);
            L=mid+1;
        }
    }
//    cout<<maxis;
    for(ll i=1;i<=18;++i){
        if(maxis<ten[i]){
            num=cnt[i-1]+(maxis-ten[i-1]+1)*i;
            break;
        }
    }
//    cout<<maxis<<" "<<num<<endl;
    if(num==n){
        cout<<maxis%10;
    }
    else{
        ++maxis;
        n=n-num-1;
//        cout<<n<<endl;
        cout<<to_string(maxis)[n];
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
Nam gay
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

