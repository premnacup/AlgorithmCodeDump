#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
void BFS(int f, vector<vector<pair<int, int>>> &graph, vector<int> &visited)
{
    queue<int> queues;
    queues.push(f);
    visited[f] = 1;

    while (!queues.empty())
    {
        int current = queues.front();
        queues.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            if (visited[graph[current][i].first] == 0)
            {
                visited[graph[current][i].first] = visited[current] + 1;
                queues.push(graph[current][i].first);
            }
        }
    }
}
int main()
{
    int i, n, k, m;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> visited(n, 0);

    while (1)
    {
        int src, dest;
        cin >> src >> dest;
        if (src == 0 && dest == 0)
        {
            break;
        }
        graph[src - 1].push_back({dest - 1, 1});
    }
    cin >> k >> m;
    BFS(k - 1, graph, visited);
    int count_cantreach = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 || visited[i] > m + 1)
        {
            count_cantreach++;
        }
    }
    cout << count_cantreach << endl;
    return 0;
}
