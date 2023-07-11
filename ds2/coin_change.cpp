#include<iostream>
using namespace std;

int coin_dp(int coins[], int m, int n){
    int answer=0, dp[m+1];
    dp[0]=0;
    for( int i=1; i<=m; i++ ){
        answer = 9999999;
        for( int j=0; j<n; j++ ){
            if(i >= coins[j]){
                if( (dp[i-coins[j]])+1 <  answer){
                    answer = (dp[i-coins[j]])+1;
                }
            }
        }
        dp[i] = answer;
    }

    for( int i=1; i<=m; i++ ){
        cout << dp[i] << " ";
    }
    cout<<endl;
    return dp[m];
}

int main(){
    int coins[] = {1,2,5,7}, n=4, m = 10;
    cout << coin_dp(coins, m, n);
}

