#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

void BFS(int f, vector<vector<int>> &graph, vector<int> &visited)
{
    queue<int> q;
    q.push(f);
    visited[f] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            int neighbor = graph[current][i];
            if (visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
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
            graph[src - 1].push_back(dest - 1);
        }
    }
    int k;
    cin >> k;
    vector<int> startVertex(k);
    for (int i = 0; i < k; i++)
    {
        cin >> startVertex[i];
    }

    for (int i = 0; i < k; i++)
    {
        int found = 0;
        fill(visited.begin(), visited.end(), 0);
        BFS(startVertex[i] - 1, graph, visited);
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                cout << j + 1 << " ";
                found = 1;
            }
        }
        if (!found)
        {
            cout << "0";
        }
        cout << endl;
    }
}
