#include <stdio.h>
#include <string.h>

#define C 20  /* number of hooks ranges [2..C] */
#define G 20  /* number of weights ranges [2..G] */
#define X 15  /* position of hooks ranges [-X..X] */
#define W 25  /* value of weights ranges [1..W] */

#define Z (G*X*W) /* torque ranges [-Z..Z] */

int c;
int g;
int t[G + 1][C + 1];  /* torque */

static int dfs(void);

int main(void)
{
    int i, j;
    int x[C + 1];
    int w;
    
    while(~scanf("%d%d", &c, &g)) {
        for (j = 1; j <= c; ++j)
            scanf("%d", &x[j]);
        for (i = 1; i <= g; ++i) {
            scanf("%d", &w);
            for (j = 1; j <= c; ++j)
                t[i][j] = w * x[j];
        }
        printf("%d\n", dfs());
    }
    
    return 0;
}

int dp[G + 1][Z + 1 + Z];

int dfs(void)
{
    int i, j, k;
    
    memset(dp, 0, sizeof (dp));
    for (i = 1; i <= c; ++i)
        dp[1][Z + t[1][i]] = 1;
        
    for (i = 2; i <= g; ++i) {
        for (j = Z; j >= -Z; --j) {
            for (k = 1; k <= c; ++k) {
                dp[i][Z + j] += dp[i - 1][Z + j - t[i][k]];
            }
        }
    }
    
    return dp[g][Z];
}
