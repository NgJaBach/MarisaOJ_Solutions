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

vector<int>dolls,escapes,gay[N];
int mindoll[N],minmar[N];

void solve(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    while(k--){
        int x;
        cin>>x;
        dolls.pb(x);
    }
    while(p--){
        int x;
        cin>>x;
        escapes.pb(x);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        mindoll[i]=M;
        minmar[i]=M;
    }
    {
        queue<pair<int,int> >que;
        for(const int &x:dolls){
            que.push({0,x});
            mindoll[x]=0;
        }
        while(!que.empty()){
            int cost,x;
            tie(cost,x)=que.front();
            que.pop();
            if(cost!=mindoll[x]) continue;
            for(const int &y:gay[x]){
                if(mindoll[y]>(cost+1)){
                    mindoll[y]=cost+1;
                    que.push({mindoll[y],y});
                }
            }
        }
    }
    if(!mindoll[1]){
        cout<<"NO";
        return;
    }
    {
        queue<pair<int,int> >que;
        que.push({0,1});
        minmar[1]=0;
        while(!que.empty()){
            int cost,x;
            tie(cost,x)=que.front();
            que.pop();
            if(cost!=minmar[x]) continue;
            for(const int &y:gay[x]){
                int ncost=cost+1;
                if(ncost>=mindoll[y]) continue;
                if(minmar[y]>ncost){
                    minmar[y]=ncost;
                    que.push({ncost,y});
                }
            }
        }
    }
//    for(int i=1;i<=n;++i) cout<<mindoll[i]<<" "; cout<<endl;
//    for(int i=1;i<=n;++i) cout<<minmar[i]<<" "; cout<<endl;
    
    for(const int &x:escapes) if(minmar[x]!=M){
        cout<<"YES";
        return;
    }
    cout<<"NO";
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

