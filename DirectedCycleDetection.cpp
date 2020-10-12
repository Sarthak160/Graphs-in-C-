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
    void addEdge(int x, int y, bool directed = true)
    {
        l[x].push_back(y);
        if (!directed)
        {
            l[y].push_back(x);
        }
    }
    bool cycle_detect_helper(int node, bool *visited, vector<bool> &stackjesa)
    {
        visited[node] = true;
        stackjesa[node] = true;
        for (auto nbr : l[node])
        {
            if (stackjesa[nbr] == true)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool cycle_mila = cycle_detect_helper(nbr, visited, stackjesa);
                if (cycle_mila == true)
                {
                    return true;
                }
            }
        }
        stackjesa[node] = false;
        return false;
    }
    bool cycle_detect()
    {
        bool *visited = new bool[V];
        vector<bool> stackjesa(V);
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            stackjesa[i] = false;
        }
        return cycle_detect_helper(0, visited, stackjesa);
    }
};

int main(int argc, char const *argv[])
{
    Graph<int> g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);  // backedge
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
