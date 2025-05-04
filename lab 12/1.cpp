#include <cstdio>
#include <cstdlib>

class graph
{
private:
    int **adj;
    int vertices;

public:
    graph(int v)
    {
        vertices = v;
        adj = (int **)malloc(vertices * sizeof(int *));
        for (int i = 0; i < vertices; i++)
        {
            adj[i] = (int *)malloc(vertices * sizeof(int));
            for (int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void insert_edge(int src, int dest);
    void delete_edge(int src, int dest);
    int search_edge(int src, int dest);
    void display();
    void free_memory();
};

void graph::insert_edge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        printf("Invalid vertices!\n");
        return;
    }
    adj[src][dest] = 1;
    adj[dest][src] = 1; // For undirected graph
    printf("Edge inserted between %d and %d\n", src, dest);
}

void graph::delete_edge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        printf("Invalid vertices!\n");
        return;
    }
    if (adj[src][dest] == 0)
    {
        printf("Edge does not exist!\n");
        return;
    }
    adj[src][dest] = 0;
    adj[dest][src] = 0; // For undirected graph
    printf("Edge deleted between %d and %d\n", src, dest);
}

int graph::search_edge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        printf("Invalid vertices!\n");
        return -1;
    }
    if (adj[src][dest] == 1)
        return 1;
    else
        return 0;
}

void graph::display()
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

void graph::free_memory()
{
    for (int i = 0; i < vertices; i++)
    {
        free(adj[i]);
    }
    free(adj);
}

int main()
{
    int v;
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &v);

    if (v <= 0)
    {
        printf("Number of vertices must be positive!\n");
        return 0;
    }

    graph g(v);
    int choice;

    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Graph\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int src, dest;
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            g.insert_edge(src, dest);
            break;
        }
        case 2:
        {
            int src, dest;
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            g.delete_edge(src, dest);
            break;
        }
        case 3:
        {
            int src, dest;
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            int result = g.search_edge(src, dest);
            if (result == 1)
                printf("Edge exists between %d and %d\n", src, dest);
            else if (result == 0)
                printf("No edge exists between %d and %d\n", src, dest);
            break;
        }
        case 4:
        {
            g.display();
            break;
        }
        case 5:
        {
            printf("Exiting...\n");
            g.free_memory();
            return 0;
        }
        default:
            printf("Invalid choice, try again!\n");
        }
    } while (choice != 5);
}