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
const int N=15,M=1000000007;
const ll INF=1e18+7;
int n,ans;
bool col[N],row[N],L[N][N],R[N][N];
void back(int a){
//    cout<<"--> "<<a<<endl;
    if(a==n){
        ++ans;
        return;
    }
    int x,y,z,u,v,p;
    for(int i=0;i<n;++i){
        if(!col[i]) continue;
        x=a; y=i;
        z=min(x,y);
        x-=z; y-=z;
        
        u=a; v=i;
        p=min(u,n-1-v);
        u-=p; v+=p;
        
        if(L[x][y] and R[u][v]){
            col[i]=false;
            L[x][y]=false;
            R[u][v]=false;
//            cout<<a+1<<" "<<i+1<<endl;
            back(a+1);
            
            
            col[i]=true;
            L[x][y]=true;
            R[u][v]=true;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        col[i]=true;
        row[i]=true;
        for(int j=0;j<n;++j){
            L[i][j]=true;
            R[i][j]=true;
        }
    }
    ans=0;
    back(0);
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

