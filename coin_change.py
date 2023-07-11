class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[0]*(amount+1) for _ in range(n) ]

        for i in range(n):
            for j in range(amount+1):
                if j==0:
                    dp[i][j] = 0
                    continue
                if j<coins[i]:
                    dp[i][j] = dp[i-1][j] if i>0 else -1
                    continue
                if j==coins[i]:
                    dp[i][j] = 1
                    continue
                
                if_not_taken = dp[i-1][j] if i>0 else -1
                if_taken = dp[i][j-coins[i]] + 1 if dp[i][j-coins[i]]!=-1 else -1
                
                if if_not_taken!=-1 and if_taken!=-1:
                    dp[i][j] = min(if_not_taken, if_taken)
                elif if_not_taken!=-1:
                    dp[i][j] = if_not_taken
                elif if_taken!=-1:
                    dp[i][j] = if_taken
                else:
                    dp[i][j] = -1
        return dp[n-1][amount]
