// Dreaming the Impossible

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

struct SparseTable{
    int n;
    vector<vector<int>>table;
    
    int lg(const unsigned long long &i) { // log2_floor
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    
    SparseTable(const vector<int>&arr){
        n = (int)arr.size();

        table.resize(lg(n) + 1, vector<int>(n));
        for(int i = 0; i < n; ++i)
            table[0][i] = arr[i];
        for(int i = 1; i <= lg(n); ++i)
            for(int j = 0; j + (1 << i) <= n; ++j)
                table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }

    int RMQ(const int &L, const int &R){ // 0-based indexing (no need for this problem)
        int i = lg(R - L + 1);
        return max(table[i][L], table[i][R - (1 << i) + 1]);
    }
};

void solve(){
    int n, q, L;
    cin >> n >> q >> L;
    vector<int>peak(L + 1, 0);
    for(int i = 0; i < n; ++i){
    	int x, y;
    	cin >> x >> y;
        peak[x] = max(peak[x], y);
    }
    SparseTable sp(peak);
    const int lim = 25;
    vector<vector<int>>binlift(L + 1, vector<int>(lim, -1));
    for(int i = 0; i < L; ++i){
        int jump = sp.RMQ(1, i + (i < L));
        if(jump > i)
            binlift[i][0] = jump;
    }

    for(int i = 1; i < lim; ++i){
        for(int j = 0; j < L; ++j){
            if(binlift[j][i-1] == -1)
                continue;
            int jump = binlift[binlift[j][i-1]][i-1];
            if(jump > j)
                binlift[j][i] = jump;
        }
    }
    while(q--){
    	int x, y, ans = 0;
    	cin >> x >> y;
        --x;
        for(int i = lim - 1; i >= 0; --i){
            if(binlift[x][i] == -1) continue;
            if(binlift[x][i] < y){
                x = binlift[x][i];
                ans += (1 << i);
            }
        }

        if(binlift[x][0] >= y)
            ++ans;
        else
            ans = -1;
        cout << ans << endl;
    }
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