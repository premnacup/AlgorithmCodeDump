#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int vertex;
    int weight;
    Node(int v, int w)
    {
        vertex = v;
        weight = w;
    }
};

void addEdges(int v1, int v2, vector<vector<Node>> &graph)
{
    graph[v1 - 1].push_back(Node(v2, 1));
}

void dfs(int current, int target, vector<vector<Node>> &graph, vector<bool> &visited)
{
    if (visited[current])
        return;

    visited[current] = true;
    cout << (current + 1) << " ";

    for (const auto &neighbor : graph[current])
    {
        if (!visited[neighbor.vertex - 1])
        {
            dfs(neighbor.vertex - 1, target, graph, visited);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<Node>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int src, dest;
        cin >> src;
        while (true)
        {
            cin >> dest;
            if (dest == 0)
                break;
            addEdges(src, dest, graph);
        }
    }

    cout << "Graph adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ": ";
        for (const auto &node : graph[i])
        {
            cout << node.vertex << " ";
        }
        cout << endl;
    }

    int start, goal;
    cin >> start >> goal;

    vector<bool> visited(n, false);
    dfs(start - 1, goal - 1, graph, visited);
}
