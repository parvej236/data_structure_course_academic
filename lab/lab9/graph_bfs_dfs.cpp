#include <bits/stdc++.h>
using namespace std;

#define MAX 10

int V;
int adj[MAX][MAX];

void initGraph(int vertices)
{
    V = vertices;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void displayAdjMatrix()
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int src)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[src] = 1;
    queue[rear++] = src;

    cout << "BFS Traversal: ";

    while (front < rear)
    {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    cout << endl;
}

void dfs(int u, int visited[])
{
    visited[u] = 1;
    cout << u << " ";

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v] == 1 && visited[v] == 0)
        {
            dfs(v, visited);
        }
    }
}

int main()
{
    initGraph(5);

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    displayAdjMatrix();
    cout << "\n";

    bfs(0);

    int visited[MAX] = {0};
    cout << "DFS Traversal: ";
    dfs(0, visited);
    cout << endl;

    return 0;
}
