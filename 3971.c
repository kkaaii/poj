#include <stdio.h>
#include <string.h>

#define N   1000000

char w[N + 1];
int n;  /* the number of weights */
int d;  /* the modulus */

int dfs(void);

int main(void)
{
    int cases;
    int b;  /* the length of the binary representation of number W */
    
    scanf("%d", &cases);
    while (cases--) {
        memset(w, '0', sizeof (w));
        scanf("%d%d%d\n", &n, &b, &d);
        scanf("%s", &w[n - b]);
        printf("%d\n", dfs());
    }

    return 0;
}

int dp[2];

int dfs(void)
{
    int i;
    int j;
    
    dp[0] = 1;
    dp[1] = 0;
    
    for (i = 1; i <= n; ++i) {
        j = w[n - i] - '0';
        dp[j] = (dp[0] + dp[1]) % d;
    }
    
    return dp[0];
}
