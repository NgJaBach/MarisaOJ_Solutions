// Dreaming the Impossible

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define pii pair<int,int>
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
const int M = -1;

int full(const int &n, const int &m, const int &a, const int &b, const int &c, const int &d, const vector<vector<int>>&table){
    vector<vector<int>> minis(n + 2, vector<int>(m + 2, M));
    vector<int>compress;
    compress.emplace_back(0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            compress.emplace_back(table[i][j]);
        }
    }
    sort(bend(compress));
    auto it=unique(compress.begin(), compress.end());
    compress.resize(it - compress.begin());

    vector<bool>virgin((int)compress.size(), true);
    vector<vector<pii>>teleport((int)compress.size()); // co so 0 nen khong can +1
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int idx = lwb(bend(compress), table[i][j]) - compress.begin();
            teleport[idx].emplace_back(i, j);
        }
    }
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    deque<pii> master, que;
    
    master.push_back({a, b});
    minis[a][b] = 0;
    
    while(!master.empty()){
        swap(master, que);
        while(!que.empty()){
            int x, y;
            tie(x, y) = que.front();
            // cout << x << " " << y << " : " << table[x][y] << endl;
            que.pop_front();
            int idx = lwb(bend(compress), table[x][y]) - compress.begin();
            if(virgin[idx]){
                virgin[idx] = false;
                for(const pii &tmp: teleport[idx]){
                    int i, j;
                    tie(i, j) = tmp;
                    if(minis[i][j] != M)
                        continue;
                    master.push_back({i, j});
                    minis[i][j] = minis[x][y] + 1;
                }
            }
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!table[nx][ny])
                    continue;
                if(minis[nx][ny] != M)
                    continue;
                minis[nx][ny] = minis[x][y] + 1;

                idx = lwb(bend(compress), table[nx][ny]) - compress.begin();
                if(virgin[idx])
                    master.push_front({nx, ny});
                else
                    master.push_front({nx, ny});
            }
        }        
    }


    return minis[c][d];
}

int brute(const int &n, const int &m, const int &a, const int &b, const int &c, const int &d, const vector<vector<int>>&table){
    vector<vector<int>> minis(n + 2, vector<int>(m + 2, M));
    vector<vector<pii>> teleport(105);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            teleport[table[i][j]].emplace_back(i, j);
        }
    }
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    queue<pii>que;
    que.push({a, b});
    minis[a][b] = 0;
    while(!que.empty()){
        int x, y;
        tie(x, y) = que.front();
        // cout << x << " " << y << " : " << table[x][y] << endl;
        que.pop();
        for(const pii &tmp: teleport[table[x][y]]){
            int i, j;
            tie(i, j) = tmp;
            if(minis[i][j] != M)
                continue;
            que.push({i, j});
            minis[i][j] = minis[x][y] + 1;
        }
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!table[nx][ny])
                continue;
            if(minis[nx][ny] != M)
                continue;
            minis[nx][ny] = minis[x][y] + 1;
            que.push({nx, ny});
        }
    }
    return minis[c][d];
}

int gen(int n, int buff){
    return rng() % n + buff;
}

void checker(){
    int n, m, a, b, c, d;
    int A, B;
    n = 10, m = 10;
    vector<vector<int>> table(n + 2, vector<int>(m + 2, 0));
    while(true){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                table[i][j] = gen(3, 0);
            }
        }
        while(true){
            a = gen(n, 1);
            b = gen(m, 1);
            if(!table[a][b])
                continue;
            c = gen(n, 1);
            d = gen(m, 1);
            if(!table[c][d])
                continue;
            break;
        }
        A = full(n, m, a, b, c, d, table);
        B = brute(n, m, a, b, c, d, table);
        if(A != B){
            cout << "WA!" << endl;
            cout << "--> " << A << " " << B << endl;
            cout << n << " " << m << endl;
            cout << a << " " << b << " " << c << " " << d << endl;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    cout << table[i][j] << " ";
                }
                cout << endl;
            }
            return;
        }
        cout << "AC" << endl;
    }
    return;
}

int solve(){
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    vector<vector<int>> table(n + 2, vector<int>(m + 2, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> table[i][j];
        }
    }
    return full(n, m, a, b, c, d, table);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("BAI4.inp","r",stdin);
    // freopen("BAI4.out","w",stdout);
    
    // checker(); return 0;

    cout << solve();
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
