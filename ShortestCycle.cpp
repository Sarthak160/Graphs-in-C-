#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int M = 22;
vector<int> gr[N];
void bfs(int src, int n, int &ans)
{
    vector<int> dis(n + 1, INT_MAX);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nbr : gr[src])
        {
            if (dis[nbr] == INT_MAX)
            {
                dis[nbr] = dis[cur] + 1;
                q.push(nbr);
            }
            else if (dis[nbr] >= dis[cur])
            {
                // back edge is encountered
             //   cout << ans << " ";
                ans = min(ans, dis[nbr] + dis[cur] + 1);
                // cout << dis[cur] << " ";
                // cout << dis[nbr] << endl;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++)
    {
        bfs(i, n, ans);
    }
    if (ans == n + 1)
    {
        cout << "No cycle is present in the graph" << endl;
    }
    else
    {
        cout << "shortest cycle detected is of length " << ans << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
