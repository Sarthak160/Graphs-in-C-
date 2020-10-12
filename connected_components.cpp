#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
  unordered_map<T, list<T>> l;

public:
  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }
  void bfs(T src)
  {
    map<T, bool> visited;
    queue<T> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
      T node = q.front();
      cout << q.front() << " ";
      q.pop();
      for (auto nbr : l[node])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }
  // .. We can also use stack for dfs
  void help_dfs(T src, map<T, bool> &visited)
  {
    cout << src << " ";
    visited[src] = true;
    // go to all the neighbour of the node which is not visited
    for (auto nbr : l[src])
    {
      if (!visited[nbr])
      {
        help_dfs(nbr, visited); // yh isko baar baar call karega aur jo neighbour visited nhi hoga usko source bna diya jaega
      }
    }
    return;
  }
  void dfs()
  {
    map<T, bool> visited;
    for (auto p : l)
    {
      T node = p.first;
      visited[node] = false;
    }
    int cnt = 0;
    for (auto p : l)
    {

      T node = p.first;
      if (!visited[node])
      {
        cout << " Components " << cnt << " --> ";
        help_dfs(node, visited);
        cnt++;
        cout << endl;
      }
    }
  }

  //   void ShortestPath(T src){
  //    map<T,int> dist;
  //    queue<T> q;
  //    // All the other nodes will have distances equal to infinity or INT_MAX
  //    for (auto node_pair:l)
  //    {
  //      T node = node_pair.first;
  //      dist[node] = INT_MAX;
  //    }
  //    q.push(src);
  //    dist[src] = 0;
  //    while (!q.empty())
  //    {
  //        T node = q.front();
  //        cout<<q.front()<< " ";
  //        q.pop();
  //        for (auto nbr : l[node])
  //        {
  //          if (dist[nbr] == INT_MAX)
  //          {
  //              q.push(nbr);
  //              // mark the NBR as visited
  //              dist[nbr] = dist[node]+1;
  //           //  child node  = parent node +1
  //          }
  //        }
  //    }
  //    cout<<endl;
  //    for(auto node_pair : l){
  //   T node = node_pair.first;
  //   int d= dist[node];
  //   cout<<" NODE "<<node<<"has a distance of "<<d<<"from the source "<<endl;
  //    }
  //  }
};

int main(int argc, char const *argv[])
{
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(0, 3);
  g.addEdge(0, 4);

  g.addEdge(5, 6);
  g.addEdge(6, 7);
  g.addEdge(8, 8);
  g.dfs();
  //g.bfs(0);
  //g.dfs(0);
  //  g.ShortestPath(0);
  return 0;
}
