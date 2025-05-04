#include <cstdio>
#include <cstdlib>
#define INF 999999

class graph
{
private:
    int vertices;
    int **adj;

public:
    graph(int v)
    {
        vertices = v;
        adj = (int **)malloc(vertices * sizeof(int *));
        for (int i = 0; i < vertices; i++)
        {
            adj[i] = (int *)malloc(vertices * sizeof(int));
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
        }
    }

    void insert_edge(int src, int dest, int weight)
    {
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        {
            printf("Invalid vertices!\n");
            return;
        }
        adj[src][dest] = weight;
        adj[dest][src] = weight; // Undirected graph
        printf("Edge inserted between %d and %d with weight %d\n", src, dest, weight);
    }

    void display()
    {
        printf("Adjacency Matrix:\n");
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }
    }

    void prims()
    {
        int *key = (int *)malloc(vertices * sizeof(int));
        int *parent = (int *)malloc(vertices * sizeof(int));
        int *mstSet = (int *)malloc(vertices * sizeof(int));

        for (int i = 0; i < vertices; i++)
        {
            key[i] = INF;
            mstSet[i] = 0;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++)
        {
            int min = INF, u = -1;

            for (int v = 0; v < vertices; v++)
            {
                if (mstSet[v] == 0 && key[v] < min)
                {
                    min = key[v];
                    u = v;
                }
            }

            if (u == -1)
            {
                printf("Graph is disconnected!\n");
                return;
            }

            mstSet[u] = 1;

            for (int v = 0; v < vertices; v++)
            {
                if (adj[u][v] && mstSet[v] == 0 && adj[u][v] < key[v])
                {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        printf("Prim's MST:\n");
        int total = 0;
        for (int i = 1; i < vertices; i++)
        {
            printf("%d - %d : %d\n", parent[i], i, adj[i][parent[i]]);
            total += adj[i][parent[i]];
        }
        printf("Total weight: %d\n", total);

        free(key);
        free(parent);
        free(mstSet);
    }

    struct edge
    {
        int src, dest, weight;
    };

    int find_parent(int *parent, int i)
    {
        if (parent[i] == i)
            return i;
        return find_parent(parent, parent[i]);
    }

    void union_set(int *parent, int x, int y)
    {
        int xset = find_parent(parent, x);
        int yset = find_parent(parent, y);
        parent[xset] = yset;
    }

    void kruskal()
    {
        struct edge *edges = (struct edge *)malloc(vertices * vertices * sizeof(struct edge));
        int e = 0;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = i + 1; j < vertices; j++)
            {
                if (adj[i][j] != 0)
                {
                    edges[e].src = i;
                    edges[e].dest = j;
                    edges[e].weight = adj[i][j];
                    e++;
                }
            }
        }

        for (int i = 0; i < e - 1; i++)
        {
            for (int j = 0; j < e - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    struct edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        int *parent = (int *)malloc(vertices * sizeof(int));
        for (int i = 0; i < vertices; i++)
            parent[i] = i;

        printf("Kruskal's MST:\n");
        int total = 0, count = 0;

        for (int i = 0; i < e; i++)
        {
            int u = edges[i].src;
            int v = edges[i].dest;
            int u_set = find_parent(parent, u);
            int v_set = find_parent(parent, v);

            if (u_set != v_set)
            {
                printf("%d - %d : %d\n", u, v, edges[i].weight);
                total += edges[i].weight;
                union_set(parent, u_set, v_set);
                count++;
                if (count == vertices - 1)
                    break;
            }
        }
        printf("Total weight: %d\n", total);

        free(edges);
        free(parent);
    }

    void dijkstra(int src)
    {
        int *dist = (int *)malloc(vertices * sizeof(int));
        int *visited = (int *)malloc(vertices * sizeof(int));

        for (int i = 0; i < vertices; i++)
        {
            dist[i] = INF;
            visited[i] = 0;
        }

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++)
        {
            int min = INF, u = -1;
            for (int v = 0; v < vertices; v++)
            {
                if (!visited[v] && dist[v] <= min)
                {
                    min = dist[v];
                    u = v;
                }
            }

            if (u == -1)
            {
                printf("Graph is disconnected!\n");
                return;
            }

            visited[u] = 1;

            for (int v = 0; v < vertices; v++)
            {
                if (!visited[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        printf("Dijkstra's shortest paths from source %d:\n", src);
        for (int i = 0; i < vertices; i++)
        {
            printf("To %d: %d\n", i, dist[i]);
        }

        free(dist);
        free(visited);
    }

    void free_memory()
    {
        for (int i = 0; i < vertices; i++)
            free(adj[i]);
        free(adj);
    }
};

int main()
{
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    if (v <= 0)
    {
        printf("Invalid number of vertices!\n");
        return 0;
    }

    graph g(v);

    int choice;

    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Insert Edge\n2. Display\n3. Prim's Algorithm\n4. Kruskal's Algorithm\n5. Dijkstra's Algorithm\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int src, dest, weight;
            printf("Enter source, destination, and weight: ");
            scanf("%d %d %d", &src, &dest, &weight);
            g.insert_edge(src, dest, weight);
            break;
        }
        case 2:
        {
            g.display();
            break;
        }
        case 3:
        {
            g.prims();
            break;
        }
        case 4:
        {
            g.kruskal();
            break;
        }
        case 5:
        {
            int src;
            printf("Enter source vertex: ");
            scanf("%d", &src);
            g.dijkstra(src);
            break;
        }
        case 6:
        {
            printf("Exiting...\n");
            g.free_memory();
            return 0;
        }
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
}