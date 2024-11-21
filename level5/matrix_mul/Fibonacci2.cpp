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
vector<vector<ll> >matmul(vector<vector<ll> >A,vector<vector<ll> >B){
    int n=A.size(),m=A[0].size();
    int nn=B.size(),mm=B[0].size();
    vector<vector<ll> >C;
    vector<ll>vec;
    ll sum;
    for(int x=0;x<n;++x){
        vec.clear();
        for(int i=0;i<mm;++i){
            sum=0;
            for(int j=0;j<nn;++j){
                sum=(sum+(A[x][j]*B[j][i])%M)%M;
            }
            vec.pb(sum);
        }
        C.pb(vec);
    }
    return C;
}
vector<vector<ll> >DnC(vector<vector<ll> >A,ull k){
    if(k==1) return A;
    vector<vector<ll> >B=DnC(A,k/2);
    B=matmul(B,B);
    if(k&1) B=matmul(B,A);
    return B;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    vector<vector<ll> >fibo={{0,1}};
    vector<vector<ll> >base={
    {0,1},
    {1,1}
    };
    ull n;
    cin>>n;
    if(n<2){
        if(n==0) cout<<0;
        else cout<<1;
        return 0;
    }
    fibo=matmul(fibo,DnC(base,n-1));
    cout<<fibo[0].back();
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
