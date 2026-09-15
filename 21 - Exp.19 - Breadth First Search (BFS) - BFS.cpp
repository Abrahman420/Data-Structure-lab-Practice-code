#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int queue[10];

int n;

void BFS(int start)
{
    int front = 0;
    int rear = 0;

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while (front < rear)
    {
        int v = queue[front];
        front++;

        cout << v << " ";

        for (int i = 1; i <= n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges;
    int u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;

        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges:" << endl;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";

    BFS(start);

    cout << endl;

    return 0;
}
