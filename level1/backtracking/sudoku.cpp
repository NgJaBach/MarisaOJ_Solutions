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
//#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;
bool col[10][10],row[10][10],table[10][10];
int board[10][10];
int idx[10][10]={
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
};
void back(int x,int y){
    if(y==10){
        ++x;
        y=1;
    }
//    cout<<"--> "<<x<<" "<<y<<endl;
//    for(int i=1;i<=9;++i){
//        for(int j=1;j<=9;++j){
//            cout<<board[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    if(x==10){
        for(int i=1;i<=9;++i){
            for(int j=1;j<=9;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }
    if(board[x][y]){
        back(x,y+1);
        return;
    }
//    vector<int>available;
//    for(int i=1;i<=9;++i){
//        if(col[y][i] and row[x][i] and table[idx[x][y]][i]){
//            available.pb(i);
//        }
//    }
//    cout<<"available: ";
//    for(auto tmp:available) cout<<tmp<<" "; cout<<endl;
    
    for(int i=1;i<=9;++i){
        if(col[y][i] and row[x][i] and table[idx[x][y]][i]){
            col[y][i]=false;
            row[x][i]=false;
            table[idx[x][y]][i]=false;
            board[x][y]=i;
            back(x,y+1);
            board[x][y]=0;
            col[y][i]=true;
            row[x][i]=true;
            table[idx[x][y]][i]=true;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int a;
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            table[i][j]=true;
            row[i][j]=true;
            col[i][j]=true;
        }
    }
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            cin>>a;
            board[i][j]=a;
            row[i][a]=false;
            col[j][a]=false;
            table[idx[i][j]][a]=false;
        }
    }
    back(1,1);
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

