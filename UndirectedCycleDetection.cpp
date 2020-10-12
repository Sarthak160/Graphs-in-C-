#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    list<int> *l; // yeh bani h lists of lists
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycle_detect_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                bool cycle_mila = cycle_detect_helper(nbr, visited, node);
                if (cycle_mila)
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool cycle_detect()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        return cycle_detect_helper(0, visited, -1);
    }
};

int main(int argc, char const *argv[])
{
    Graph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 0);
    if (g.cycle_detect())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
