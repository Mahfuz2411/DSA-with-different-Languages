#include <stdio.h>

int main() {
    int n;  
    printf("Enter the number nodes: ");
    scanf ("%d", &n);

    int graph[n][n];

    int i;
    for(i=0; i<n; i++) {
        int j;
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }

    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int a, b; 

        scanf("%d %d", &a, &b);

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    
    for(i=0; i<n; i++) {
        int j;
        for(j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}