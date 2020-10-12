// prob name -
//author - COOL
#include <bits/stdc++.h>
#define f(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define int long long int
#define endl "\n"
#define mii map<int, int>
#define vi vector<int>
#define fi(i, a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define fo(i, a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << a[i] << " ";    \
    }
#define pb push_back
#define MP make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define mk(arr, n, type) type *arr = new type[n];
#define pw(b, p) pow(b, p) + 0.1
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define Pi 3.14159265358979
using namespace std;
/*                                   ____
  ||     //\\    ||\  /||   || / || ||   ||   //\\       
  ||    //  \\   || \/ ||   ||/  || ||___||  //  \\       
  ||   //____\\  ||    ||   ||\  || ||\\    //____\\  
  ||  //      \\ ||    ||   || \ || || \\  //      \\
*/
const int N = 100005;
int M = 22;
int visited[N];
vi gr[N];
bool odd_cycle = 0;
void dfs(int curr, int par, int col)
{
    visited[curr] = col;
    for (auto child : gr[curr])
    {
        if (visited[child] == 0)
        {
            dfs(child, curr, 3 - col);
        }
        else if (child != par and visited[child] == col)
        {
            odd_cycle = 1;
            break;
        }
    }
    return;
}
void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1, 0, 1);
    if (odd_cycle)
    {
        cout << "NOT BIPARTITE" << endl;
    }
    else
    {
        cout << "BIPARTITE" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
