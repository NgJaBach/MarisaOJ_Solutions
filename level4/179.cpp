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
const int N=100050,M=1000000007;
const ll INF=1e18+7;

int sum_digit(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int mincost[N];

void solve(){
    int n;
    cin>>n;
    string s=to_string(n);
    int m=(int)s.size();
    s="$"+s;
    for(int i=0;i<n;++i) mincost[i]=M;
    priority_queue<pii>que;
    for(int i=n;i<N;++i){
        int sum=sum_digit(i);
        int du=sum%n;
        if(sum<mincost[du]){
            mincost[du]=sum;
            que.push({-sum,du});
        }
    }
    while(!que.empty()){
        int sum,du;
        tie(sum,du)=que.top();
        que.pop();
        sum=-sum;
        if(sum!=mincost[du]) continue;
        for(int i=0;i<10;++i){
            int nsum,ndu;
            nsum=sum+i;
            ndu=(du*10+i)%n;
            if(nsum<mincost[ndu]){
                mincost[ndu]=nsum;
                que.push({-nsum,ndu});
            }
        }
    }
    cout<<mincost[0];
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


