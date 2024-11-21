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
const int N=305,M=1000000007;
const ll INF=1e18+7;

string str;
int n;

int matching(const string &s){
    int m=(int)s.size();
    int j=0;
    for(int i=0;i<m and j<n;++i) if(s[i]==str[j]) ++j;
    return j;
}

string append(string a,string b){
    a.pob();
    return a+b;
}

struct node{
    string s;
    int match;
    pair<string,int>get() const {
        return {s,match};
    }
    bool operator < (const node &other) const {
        return (int)s.size() > (int)other.s.size();
    }
};

vector<string>gay[26];
int mincost[N][26];

void solve(){
    string s;
    int cost,ending,match;
    cin>>n;
    while(n--){
        cin>>s;
        gay[s.front()-'a'].pb(s);
    }
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<=n;++i) for(int j=0;j<26;++j) mincost[i][j]=M;
    priority_queue<node>que;
    for(int i=0;i<26;++i){
        for(auto tmp:gay[i]){
            cost=(int)tmp.size();
            ending=tmp.back()-'a';
            match=matching(tmp);
            
            if(cost<mincost[match][ending]){
                mincost[match][ending]=cost;
                que.push({tmp,match});
            }
        }
    }
    while(!que.empty()){
        tie(s,match)=que.top().get();
        que.pop();
        cost=(int)s.size();
        ending=s.back()-'a';
        if(cost!=mincost[match][ending]) continue;
        
        for(auto tmp:gay[ending]){
            string ns=append(s,tmp);
            int nending=tmp.back()-'a';
            int ncost=cost+(int)tmp.size()-1;
            int nmatch=matching(ns);
            if(ncost<mincost[nmatch][nending]){
                mincost[nmatch][nending]=ncost;
                que.push({ns,nmatch});
            }
        }
    }
    int ans=M;
    for(int i=0;i<26;++i) ans=min(ans,mincost[n][i]);
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
