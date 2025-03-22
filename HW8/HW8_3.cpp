#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

int DFS(int i, int parentNode, vector<pair<int, int>> graph[], vector<int> &visited)
{
    visited[i] = 1;
    for (int j = 0; j < graph[i].size(); j++)
    {
        int next = graph[i][j].first;

        if (!visited[next])
        {
            int find = DFS(next, i, graph, visited);
            if (find == 1)
            {
                return 1;
            }
        }
        else if (next != parentNode)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i, j, k, f, n;
    cin >> n;
    vector<pair<int, int>> graph[n];
    vector<int> visited(n, 0);
    for (i = 0; i < n; i++)
    {
        int src, dest;
        cin >> src;
        while (1)
        {
            cin >> dest;
            if (dest == 0)
            {
                break;
            }
            graph[src - 1].push_back({dest - 1, 1});
        }
    }

    int is_cycle = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int find = DFS(i, -1, graph, visited);
            if (find == 1)
            {
                is_cycle = 1;
                break;
            }
        }
    }
    if (is_cycle == 1)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}
