// prob name -
//author - COOL
#include <iostream>
#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define int long long int
#define endl "\n"
#define mii map<int, int>
#define umii unordered_map<int, int>
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
#define minall(a) *min_element(a, a + n)
#define maxall(a) *max_element(a, a + n)
#define ld long double
#define I_WANT_SPEED              \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

/*                                   ____
  ||     //\\    ||\  /||   || / || ||   ||   //\\
  ||    //  \\   || \/ ||   ||/  || ||___||  //  \\
  ||   //____\\  ||    ||   ||\  || ||\\    //____\\
  ||  //      \\ ||    ||   || \ || || \\  //      \\
*/

void lets_do_it()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// DSU datastructure
// Path compression + Union by rank

class DSU
{
private:
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        // parent = -1, rank = 1;
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // find function
    int find(int i)
    {
        //base case
        if (parent[i] == -1)
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    // union by rank optimization
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            // dono me se chota part hoga use bde wale part se attach kardo easy rhega kyoki chote ko dhoondhna
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
private:
    int V;
    vector<vector<int>> edgelist;

public:
    Graph(int V)
    {

        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y}); // w ko phle isly lelia taaki hum sort function use kare to weight ke acc sort ho jaye
    }

    int kruskal_mst()
    {
        // Main Logic = Easy !!!
        // 1) sort all edges acc to weight
        sort(edgelist.rbegin(), edgelist.rend());

        // init a DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            // Take that edge in MST if it doesn't form cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int32_t main()
{
    I_WANT_SPEED

    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

   // lets_do_it();
    // w(t)
    // {
    //     int n, m;
    //     cin >> n >> m;
    //     Graph(n);
    //     for (int i = 0; i < m; i++)
    //     {
    //         int x, y, w;
    //         cin >> x >> y >> w;
    //         g.addEdge(x - 1, y - 1, w);
    //     }

    cout << g.kruskal_mst() << endl;
    // }
    return 0;
}
