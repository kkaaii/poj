#include <stdio.h>
#include <string.h>

#define M   6
#define N   20000

int m[M + 1];

static int dfs(void);

static int input(void)
{
    int total = 0;
    int i;

    for (i = 1; i <= M; ++i) {
        scanf("%d", &m[i]);
        total += m[i];
    }

    return total;
}

int main(void)
{
    int i;
    
    for (i = 1; input(); ++i) {
        printf("Collection #%d:\n", i);
        puts(dfs() ? "Can be divided.\n" : "Can't be divided.\n");
    }

    return 0;
}

int v;
int dp[N * M + 1];

int dfs(void)
{
    int c;
    int sum;
    
    sum = 0;
    for (c = 1; c <= M; ++c) {
        sum += c * m[c];
    }

    if (sum & 1) {
        return 0;
    }

    memset(dp, 0x80, sizeof (dp));
    dp[0] = 0;

    v = sum / 2;
    for (c = 1; c <= M; ++c) {
        /* TODO */
    }

    return dp[v] >= 0;
}
