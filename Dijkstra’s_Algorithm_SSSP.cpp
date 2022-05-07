#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    int *cost;
    int *parent;
    list<pair<int, int>> *adj;
    list<pair<int, int>>::iterator it;

    Graph(int node)
    {
        this->node = node;
        adj = new list<pair<int, int>>[node + 1]; // O-based indexing
        cost = new int[node + 1];
        parent = new int[node + 1];
    }

    void addEdge(int source, int destination, int weight)
    {
        adj[source].push_back(make_pair(destination, weight));
    }

    void pre_assign()
    {
        for (int i = 1; i <= node; i++)
        {
            cost[i] = INT_MAX;
            parent[i] = INT_MAX;
        }
    }

    void dijskstra(int source)
    {
        pre_assign();
        cost[source] = 0;
        parent[source] = source;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.push(make_pair(cost[source], source));

        while (!PQ.empty())
        {
            int parent_node = PQ.top().second;
            PQ.pop();
            for (it = adj[parent_node].begin(); it != adj[parent_node].end(); it++)
            {
                int current_node = it->first;
                int current_cost = it->second;

                if (cost[parent_node] + current_cost < cost[current_node])
                {
                    parent[current_node] = parent_node;
                    cost[current_node] = cost[parent_node] + current_cost;
                    PQ.push(make_pair(cost[current_node], current_node));
                }
            }
        }
    }
    void print_SSSP(int LastN)
    {
        int C=1;
        for (int i = 1; i <= node; i++)
        {

            cout<<i;
            LastN = i;
            while(LastN !=1)
            {
                cout<< " -> "<<parent[LastN];
                LastN = parent[LastN];
            }
            cout<<endl;
        }

    }
};

int main()
{
    int node, edge;
    cin >> node >> edge;

    int source, destination, weight,LastN;
    Graph graph(node);

    for (int i = 1; i <= edge; i++)
    {
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    cin >> source;
    //cout<<endl<<"Last node: ";
    //cin>>LastN;
    graph.dijskstra(source);
    graph.print_SSSP(LastN);
}

/* Sample Input
5 10
1 2 10
1 3 5
2 3 2
2 4 1
3 2 3
3 4 9
3 5 2
4 5 4
5 1 7
5 4 6
1
*/
