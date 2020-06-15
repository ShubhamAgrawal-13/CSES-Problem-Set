sum=int(input())
dp=[0 for i in range(sum+1)]
dp[0]=1
for i in range(1,sum+1):
    for j in range(1,7):
        if(i-j>=0):
            dp[i]=(dp[i]+dp[i-j])%1000000007
print(dp[sum])