#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);
    }

    void help_dfs(T src, map<T, bool> &visited, list<T> &ordering)
    {
        //   cout << src << " ";
        visited[src] = true;
        // go to all the neighbour of the node which is not visited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                help_dfs(nbr, visited, ordering); // yh isko baar baar call karega aur jo neighbour visited nhi hoga usko source bna diya jaega aur yh jab tak chalega tab tak neighbouring nodes is ki visited rhengi
            }
        }
        // wapsi m hmne queue ki front m add kardiaya
        ordering.push_front(src);
        return;
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        for (auto p : l)
        {
            T node = p.first;
            // jab recursive function value return aega tab loop m dubara enter karega aur check karega ki aur konsi node unvisited padi h
            if (!visited[node])
                help_dfs(node, visited, ordering);
        }
        for (auto node : ordering)
        {
            cout << node << " ";
        }
        cout << endl;
    }
};
int main(int argc, char const *argv[])
{
    Graph<string> g;
    g.addEdge("Python", "Datapreprocessing");
    g.addEdge("Python", "Pytoch");
    g.addEdge("Python", "ML");
    g.addEdge("Datapreprocessing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("DL", "Facerecogn");
    g.addEdge("Dataset", "Facerecogn");

    g.dfs();

    return 0;
}
