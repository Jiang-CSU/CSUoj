#include <stdio.h>
#define V 4
#define INF 999

void dijkstra(int graph[V][V], int start);

int main(void)
{

    int graph[V][V] = 
    {
        {0, 7, 0, 2},
        {7, 0, 4, 8},
        {0, 4, 0, 1},
        {2, 8, 1, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

void dijkstra(int graph[V][V], int start)
{
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;
    
    for (int i = 0; i < V; i++)
    {
        int min = INF;
        int index = -1;

        for (int j = 0; j < V; j++)
        {
            if (dist[j] < min && !visited[j])
            {
                min = dist[j];
                index = j;
            }
        }

        if (index == -1)
        {
            break;
        }

        visited[index] = 1;

        for (int k = 0; k < V; k++)
        {
            if (graph[index][k] != 0 && !visited[k])
            {
                if (dist[index] + graph[index][k] < dist[k])
                {
                    dist[k] = dist[index] + graph[index][k];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d\n", dist[i]);
    }
}
