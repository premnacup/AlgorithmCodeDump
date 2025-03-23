#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
void BFS(int f, vector<vector<pair<int, int>>> graph, vector<int> &visited)
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
            if (visited[graph[current][i].first] == 0)
            {
                visited[graph[current][i].first] = visited[current] + 1;
                q.push(graph[current][i].first);
            }
        }
    }
}

int main()
{
    int i, n, k, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);

    for (i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;

        graph[src - 1].push_back({dest - 1, 1});
        graph[dest - 1].push_back({src - 1, 1});
    }
    int minDist = INT_MAX;
    int bestLocation = 1;
    for (int j = 0; j < n; j++)
    {
        vector<int> visited(n, 0);
        BFS(j, graph, visited);
        int maxUsed = 0;
        bool canReachAll = true;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                canReachAll = false;
                break;
            }
            else if (visited[i] > maxUsed)
            {
                maxUsed = visited[i];
            }
        }
        if (canReachAll && maxUsed < minDist || (maxUsed == minDist && j < bestLocation - 1))
        {
            minDist = maxUsed;
            bestLocation = j + 1;
        }
    }
    cout << bestLocation << endl;
    return 0;
}
