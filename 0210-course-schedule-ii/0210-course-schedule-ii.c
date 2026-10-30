/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    *returnSize = 0;

    int *indegree = (int*)calloc(numCourses, sizeof(int));
    int *queue = (int*)malloc(numCourses * sizeof(int));
    int *order = (int*)malloc(numCourses * sizeof(int));

    int **adj = (int**)malloc(numCourses * sizeof(int*));
    int *adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) 
    {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) 
    {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        adj[pre][adjSize[pre]++] = course;
        indegree[course]++;
    }

    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) 
    {
        if (indegree[i] == 0) 
        {
            queue[rear++] = i;
        }
    }

    while (front < rear) 
    {
        int course = queue[front++];
        order[(*returnSize)++] = course;

        for (int i = 0; i < adjSize[course]; i++) 
        {
            int next = adj[course][i];
            indegree[next]--;

            if (indegree[next] == 0) 
            {
                queue[rear++] = next;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) 
    {
        free(adj[i]);
    }

    free(adj);
    free(adjSize);
    free(indegree);
    free(queue);

    if (*returnSize != numCourses) 
    {
        free(order);
        *returnSize = 0;
        return NULL;
    }

    return order;
}