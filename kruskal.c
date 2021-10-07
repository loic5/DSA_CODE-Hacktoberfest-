#include <stdio.h>
#include <stdlib.h>

int **input(int n, int *len)
{
    int **a = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = (int *)calloc(n, sizeof(int));
    int ch = 0;
    while (ch != -1)
    {
        int m, w;
        scanf("%d%d%d", &ch, &m, &w);
        if (ch != -1)
        {
            (*len)++;
            a[ch][m] = w;
            a[m][ch] = w;
        }
    }
    return a;
}

void kruskal(int *v[2], int *a[3], int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = a[i][0];
        printf("start->%d\n", start);
        int end = a[i][1];
        printf("end->%d\n", end);
        int count = 0, count2 = 0;
        while (v[start][1] != -1)
        {
            start = v[start][1];
            count++;
        }
        while (v[end][1] != -1)
        {
            end = v[end][1];
            count2++;
        }
        if (start != end || (start == -1 && end == -1))
        {
            //if you want you can make as a tree of subtree size but i chose to ignore it
            /*if (count >= count2)
            {
                v[a[i][1]][0] = a[i][2];
                v[a[i][1]][1] = a[i][0];
            }
            else
            {
                v[a[i][0]][0] = a[i][2];
                v[a[i][0]][1] = a[i][1];
            }*/
            v[a[i][1]][0] = a[i][2];
            v[a[i][1]][1] = a[i][0];
        }
    }
}

int **sort(int *a[3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][2] < a[j][2])
            {
                int temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;
                temp = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] = temp;
                temp = a[i][2];
                a[i][2] = a[j][2];
                a[j][2] = temp;
            }
    }
    return a;
}

int main()
{
    int n, m = 0;
    printf("Enter the range:");
    scanf("%d", &n);
    int **adj = input(n, &m);
    int **v = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        v[i] = (int *)malloc(2 * sizeof(int));
        v[i][0] = 0;
        v[i][1] = -1;
    }
    int **adjs = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        adjs[i] = (int *)malloc(3 * sizeof(int));
    int l = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (adj[i][j] != 0)
            {
                adjs[l][0] = i;
                adjs[l][1] = j;
                adjs[l++][2] = adj[i][j];
            }
        }
    adjs = sort(adjs, m);
    printf("After sorting\n");
    for (int i = 0; i < m; i++)
        printf("%d,%d->%d\n", adjs[i][0], adjs[i][1], adjs[i][2]);
    kruskal(v, adjs, m);
    printf("after kruskal\n");
    for (int i = 0; i < n; i++)
        printf("%d->%d\n", i, v[i][1]);
    return 0;
}
