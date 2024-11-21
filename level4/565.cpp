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
#define mt make_tuple
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

ll dp[N][3],a[N];
vector<pii>gay[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        for(int j=0;j<3;++j) dp[i][j]=INF;
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    priority_queue<tuple<ll,int,int> >que;
    que.push(mt(0,1,0));
    que.push(mt(-a[1],1,1));
    dp[1][0]=0;
    dp[1][1]=a[1];
    while(!que.empty()){
        ll sum;
        int x,id;
        tie(sum,x,id)=que.top();
        que.pop();
        sum=-sum;
        if(sum!=dp[x][id]) continue;
        for(auto tmp:gay[x]){
            int y,z;
            tie(y,z)=tmp;
            ll nsum=sum+z;
            if(nsum<dp[y][id]){
                dp[y][id]=nsum;
                que.push(mt(-nsum,y,id));
            }
            if(id==0){
                nsum+=a[y];
                if(nsum<dp[y][1]){
                    dp[y][1]=nsum;
                    que.push(mt(-nsum,y,1));
                }
            }
            else if(id==1){
                nsum-=a[y];
                if(nsum<dp[y][2]){
                    dp[y][2]=nsum;
                    que.push(mt(-nsum,y,2));
                }
            }
        }
    }
    ll ans=min({dp[n][0],dp[n][1],dp[n][2]});
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    while(t--){
        solve();
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


