#include <stdio.h>
#include <string.h>

#define M   6
#define N   20000

int m[M + 1];
int sum;

static int dfs(void);

static int input(void)
{
    int i;

    sum = 0;
    for (i = 1; i <= M; ++i) {
        scanf("%d", &m[i]);
        sum += i * m[i];
    }

    return sum;
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
    int i, j, k;

    if (sum & 1) {
        return 0;
    }

    memset(dp, 0, sizeof (dp));
    dp[0] = 1;
    sum /= 2;
    v = 0;

    for (i = 1; i <= M; ++i) {
        if (m[i] > 0 && !dp[i]) {
            for (j = v; j >= 0; --j) {
                if (!dp[j] || dp[sum])
                    continue;
                for (k = 1; k < m[i]; ++k) {
                    if (j + k * i == sum) {
                        dp[j + k * i] = 1;
                        break;
                    }
                    if (j + k * i > sum || dp[j + k * i])
                        break;
                    dp[j + k * i] = 1;
                }
            }
        }
        v += i * m[i];
        if (v > sum)
            v = sum;
    }

    return dp[v];
}
