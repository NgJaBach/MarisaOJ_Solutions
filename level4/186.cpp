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

vector<int>gay[N];
int maxlight[N];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) maxlight[i]=-1;
    while(m--){
        int x,y;
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    priority_queue<pair<int,int> >que;
    while(k--){
        int x,y;
        cin>>x>>y;
        que.push({y,x});
        maxlight[x]=max(maxlight[x],y);
    }
    while(!que.empty()){
        int light,x;
        tie(light,x)=que.top();
        que.pop();
//        cout<<"--> "<<light<<" "<<x<<endl;
        if(light<maxlight[x]) continue;
        if(!light) continue;
        --light;
        for(const int &y:gay[x]){
//            cout<<maxlight[y]<<" "<<light<<endl;
            if(maxlight[y]<light){
                maxlight[y]=light;
                que.push({light,y});
            }
        }
    }
//    for(int i=1;i<=n;++i) cout<<maxlight[i]<<" "; cout<<endl;
    int ans=0;
    for(int i=1;i<=n;++i) ans+=(maxlight[i]!=-1);
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

