#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define K 100
#define T 30000

struct gangster {
    int t;  /* moments of time when gangsters come */
    int p;  /* prosperity of gangsters */
    int s;  /* stoutness of gangsters */
};

struct gangster g[1 + N];
int n;  /* number of gangsters ranges [1..N] */
int k;  /* state of openness ranges [1..K] */
int t;  /* interval of time ranges [0..T] */

int gangster_cmp(const void *p1, const void *p2)
{
    const struct gangster *g1 = (const struct gangster *)p1;
    const struct gangster *g2 = (const struct gangster *)p2;
    return g1->t > g2->t;
}

static int dfs(void);

int main(void)
{
    int i;
    
    scanf("%d%d%d", &n, &k, &t);
    for (i = 1; i <= n; ++i)
        scanf("%d", &g[i].t);
    for (i = 1; i <= n; ++i)
        scanf("%d", &g[i].p);
    for (i = 1; i <= n; ++i)
        scanf("%d", &g[i].s);
    qsort(&g[1], n, sizeof(g[0]), gangster_cmp);
    printf("%d\n", dfs());
    
    return 0;
}

static inline int ABS(int x)
{
    return x < 0 ? -x : x;
}

int dp[1 + N];
int dfs(void)
{
    int ans = 0;
    int i, j;
    int v;
    
    memset(dp, 0, sizeof (dp));
    for (i = 1; i <= n; ++i) {
        if (g[i].t >= g[i].s)
            dp[i] = g[i].p;
        for (j = i - 1; j >= 0; --j) {
            if (0 == dp[j])
                continue;
            if (ABS(g[i].s - g[j].s) > g[i].t - g[j].t)
                continue;
            v = dp[j] + g[i].p;
            if (dp[i] < v)
                dp[i] = v;
        }
        if (ans < dp[i])
            ans = dp[i];
    }

    return ans;
}
