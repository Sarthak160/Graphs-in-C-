#include <iostream>
#include<stack>
#include <vector>
using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}
void dfsIt(int s){
    stack<int> st;
    st.push(s);
    while (!st.empty())
    {
       int node =st.top();
      // visited[s] = true;
       st.pop();
       if(!visited[node]){
           cout << node << "->";
           visited[node] = true;
       }
      
       for (auto i = adj[node].begin(); i != adj[node].end(); ++i)
           if (!visited[*i])
               st.push(*i);
    }
}

void initialize()
{
    for (int i = 0; i < 10; ++i)
        visited[i] = false;
}

int main()
{
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes; //Number of nodes
    cin >> edges; //Number of edges
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        //Undirected Graph
        adj[x].push_back(y); //Edge from vertex x to vertex y
        adj[y].push_back(x); //Edge from vertex y to vertex x
    }

    initialize(); //Initialize all nodes as not visited

    for (int i = 1; i <= nodes; ++i)
    {
        if (visited[i] == false)
        {
            dfsIt(i);
            connectedComponents++;
        }
    }
   cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}