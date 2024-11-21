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
vector<ll>gay;
vector<ll>QuangBiu(int x,int y){
    vector<ll>vec,res;
    vec.clear(); res.clear();
    for(int i=x;i<y;++i) vec.pb(gay[i]);
    int n=vec.size();
    ll sum;
    for(int i=0;i<(1<<n);++i){
        sum=0;
        for(int j=0;j<n;++j){
            if((i>>j)&1) sum+=vec[j];
        }
        res.pb(sum);
    }
    sort(bend(res));
    return res;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m;
    ll sum=0,a;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        gay.pb(a);
        sum+=a;
    }
    if(n==1){
        cout<<gay.front();
        return 0;
    }
    vector<ll>A=QuangBiu(0,n/2);
    vector<ll>B=QuangBiu(n/2,n);
    n=(int)A.size(); m=(int)B.size();
    int L,R,mid,pick;
    ll ans=abs(sum);
    for(int i=0;i<n;++i){
        L=0; R=m-1; pick=0;
        while(L<=R){
            mid=(L+R)/2;
            if((A[i]+B[mid])>(sum/2)) R=mid-1;
            else{
                L=mid+1;
                pick=max(pick,mid);
            }
        }
//        cout<<(A[i]+B[pick])<<endl;
        ans=min(ans,abs(sum-2*(A[i]+B[pick])));
        if((mid+1)!=m){
            ++pick;
            ans=min(ans,abs(sum-2*(A[i]+B[pick])));
        }
    }
    cout<<ans;
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

