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
#define PB push_back
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
void lets_do_it()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
struct dsu
{
    int totcomponent;
    vector<int> par;
    vector<int> sz;
    // initialise
    void init(int n)
    {
        par.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++)
            par[i] = i;
        for (int i = 0; i < n; i++)
            sz[i] = 1;
        int totcomponent = n;
    }
    int get_superparent(int x)
    {
        if (x == par[x])
        {
            return x;
        }
        else
        {
            // path compression
            return par[x] = get_superparent(par[x]);
        }
    }
    void United(int x, int y)
    {
        int superparent_x = get_superparent(x);
        int superparent_y = get_superparent(y);
        if (superparent_x != superparent_y)
        {
            par[superparent_x] = superparent_y;
            sz[superparent_y] += sz[superparent_x];
            sz[superparent_x] = 0;
            totcomponent--;
        }
    }
} G;

int32_t main()
{
    // lets_do_it();

    // w(t)
    // {
    int n, m;
    cin >> n >> m;
    G.init(n);
    bool cycle = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (G.get_superparent(x) != G.get_superparent(y))
        {
            G.United(x, y);
        }
        else
        {
            // same component hence cycle exists
            cycle = 1;
        }
    }
    if (cycle)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    // // all elements are there in there connected components
    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     // i is considered as x
    //     int super_parent_i = G.get_superparent(i);
    //     ans += (n - G.sz[super_parent_i]);
    // }
    // cout << ans / 2 << endl; // y pairs naam ka ques hackerblocks ka uske liye kiya gya h
    return 0;
}
