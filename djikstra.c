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

void heapify(int *ht, int *v[3], int i, int n)
{
    int lc = 2 * i + 1, rc = lc + 1, smal = i;
    if (lc < n && v[ht[lc]][0] < v[ht[smal]][0])
        smal = lc;
    if (rc < n && v[ht[rc]][0] < v[ht[smal]][0])
        smal = rc;
    if (smal != i)
    {
        int temp = ht[smal];
        ht[smal] = ht[i];
        ht[i] = temp;
        heapify(ht, v, smal, n);
    }
}

void build_heap(int *ht, int *v[3], int n)
{
    int start = n / 2;
    while (start != -1)
    {
        heapify(ht, v, start, n);
        start--;
    }
}

/*void heap_sort(int *ht, int *v[3], int n)
{
    build_heap(ht, v, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = ht[0];
        ht[0] = ht[i];
        ht[i] = temp;
        heapify(ht, v, 0, i);
    }
}*/

void djikstra(int *ht, int *v[3], int **a, int n)
{
    //heap_sort(ht, v, n);
    build_heap(ht, v, n);
    int m = n;
    while (m != 0)
    {
        int min = ht[0];
        for (int i = 0; i < n; i++)
        {
            if (v[i][2] != 1 && a[min][i] != 0 && a[min][i] + v[min][0] < v[i][0])
            {
                v[i][0] = a[min][i] + v[min][0];
                v[i][1] = min;
            }
        }
        v[min][2] = 1;
        int temp = ht[0];
        ht[0] = ht[m - 1];
        ht[m - 1] = temp;
        heapify(ht, v, 0, --m);
    }
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
        v[i] = (int *)malloc(3 * sizeof(int));
        v[i][2] = 0;
        v[i][0] = 999;
        v[i][1] = -1;
    }
    int *ht = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        ht[i] = i;
    v[3][0] = 0;
    djikstra(ht, v, adj, n);
    //build_heap(ht, v, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d->w=%d,l=%d,c=%d\n", i, v[i][0], v[i][1], v[i][2]);
        //printf("%d\t", ht[i]);
    }
    return 0;
}
