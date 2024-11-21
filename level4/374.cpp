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
const int N=200050,M=1000000007;
const ll INF=1e18+7;

ll minis[N];

void solve(){
    ll n,A,B,C;
    cin>>n>>A>>B>>C;
    for(int i=0;i<A;++i) minis[i]=M;
    priority_queue<ll>que;
    que.push(-1);
    minis[1]=1;
    while(!que.empty()){
        ll cost=que.top();
        que.pop();
        cost=-cost;
        if(cost!=minis[cost%A]) continue;
        
        if((cost+B)<minis[(cost+B)%A]){
            minis[(cost+B)%A]=cost+B;
            que.push(-(cost+B));
        }
        if((cost+C)<minis[(cost+C)%A]){
            minis[(cost+C)%A]=cost+C;
            que.push(-(cost+C));
        }
    }
    ll sum=0;
    for(int i=0;i<A;++i){
        if(minis[i]==M) continue;
        ll cal=(ll)((n-minis[i])/A)+1;
//        cout<<i<<" : "<<minis[i]<<" -> "<<cal<<endl;
        sum+=cal;
    }
    cout<<sum;
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

