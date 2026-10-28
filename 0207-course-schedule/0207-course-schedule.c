bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int *indegree = calloc(numCourses, sizeof(int));
    int *queue = malloc(numCourses * sizeof(int));
    int **adj = malloc(numCourses * sizeof(int *));
    int *adjSize = calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        adj[pre][adjSize[pre]++] = course;
        indegree[course]++;
    }

    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int completed = 0;

    while (front < rear) {
        int course = queue[front++];
        completed++;

        for (int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        free(adj[i]);
    }

    free(adj);
    free(adjSize);
    free(indegree);
    free(queue);

    return completed == numCourses;
}