#include <cstdio>
#include <cstdlib>

class graph
{
private:
    struct node
    {
        int vertex;
        struct node *next;
    };
    struct node **adj;
    int vertices;

public:
    graph(int v)
    {
        vertices = v;
        adj = (struct node **)malloc(vertices * sizeof(struct node *));
        for (int i = 0; i < vertices; i++)
        {
            adj[i] = NULL;
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

    // Insert at beginning for src
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = dest;
    newnode->next = adj[src];
    adj[src] = newnode;

    // Insert at beginning for dest (since undirected)
    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode2->vertex = src;
    newnode2->next = adj[dest];
    adj[dest] = newnode2;

    printf("Edge inserted between %d and %d\n", src, dest);
}

void graph::delete_edge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        printf("Invalid vertices!\n");
        return;
    }

    struct node *temp = adj[src];
    struct node *prev = NULL;

    while (temp != NULL && temp->vertex != dest)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Edge does not exist!\n");
    }
    else
    {
        if (prev == NULL)
            adj[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    // Also remove the reverse edge
    temp = adj[dest];
    prev = NULL;

    while (temp != NULL && temp->vertex != src)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL)
    {
        if (prev == NULL)
            adj[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    printf("Edge deleted between %d and %d\n", src, dest);
}

int graph::search_edge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        printf("Invalid vertices!\n");
        return -1;
    }

    struct node *temp = adj[src];
    while (temp != NULL)
    {
        if (temp->vertex == dest)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void graph::display()
{
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d: ", i);
        struct node *temp = adj[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void graph::free_memory()
{
    for (int i = 0; i < vertices; i++)
    {
        struct node *temp = adj[i];
        while (temp != NULL)
        {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
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