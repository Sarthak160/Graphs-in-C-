#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
int v;
// Array of list
list<int> *l;
public:
Graph(int v){
this->v = v;
l = new list<int>[v];
}
void AddEdge(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
}
void print(){
    // itetrate over all vertices
    for (int  i = 0; i < v; i++)
    {
        cout<< "vertex" << i << "-->";
        for(auto nbr : l[i]){
            cout<<nbr << ',';
        }
        cout << endl;
    }
}
};

int main(int argc, char const *argv[])
{
    Graph g(4);
    g.AddEdge(0,2);
    g.AddEdge(0,1);
    g.AddEdge(2,3);
    g.AddEdge(1,2);
    g.print();
    return 0;
}
