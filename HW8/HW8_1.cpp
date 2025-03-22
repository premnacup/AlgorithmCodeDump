#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

void BFS(int start, vector<vector<pair<int, int>>> &graph, vector<int> &visited, int end)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            if (visited[graph[current][i].first] == -1)
            {
                visited[graph[current][i].first] = visited[current] + 1;
                q.push(graph[current][i].first);
            }
        }
    }
    cout << visited[end];
}

int main()
{
    int n, start, end;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++)
    {
        int src;
        cin >> src;
        while (1)
        {
            int dest;
            cin >> dest;
            if (dest == 0)
            {
                break;
            }
            graph[src - 1].push_back({dest - 1, 1});
        }
    }
    cin >> start >> end;
    BFS(start - 1, graph, visited, end - 1);
}