#include<iostream>
using namespace std;


int knapsack_01_dp(char names[], int weights[], int values[], int n, int W){
    int dp[n+1][W+1];
    for(int i=0,j=0; i<=n||j<=W; i++,j++){
        if(i<=n) dp[i][0]=0;
        if(j<=W) dp[0][j]=0;
    }

    for( int i=1; i<=n; i++){
        for( int j=1; j<=W; j++){
            if(j< weights[i-1]){
                dp[i][j]=dp[i-1][j];
                continue;
            }

            int valueIncludingi = dp[i-1][j-weights[i-1]] + values[i-1];
            int valueExcludingi = dp[i-1][j];
            int ans = max(valueExcludingi, valueIncludingi);
            dp[i][j]=ans;
        }
    }
    cout << dp[n][W] << endl;

    int val = dp[n][W];
    int x=n, y=W;
    while(val>0){
        if(val == dp[x-1][y]){
            x--;
        }
        else {
            val -= values[x-1];
            cout << names[x-1]<<endl;
            for(int j=0;j<W;j++){
                if(dp[x-1][j]==val){
                    x--;
                    y=j;
                }
            }
        }
    }
}


int main(){
    int c,n;
    cin>> c>>n;
    int payment[n], hours[n];
    char names[n];
    for(int i=0;i<n;i++){
        int x, y; char z;
        cin >> z >> x >> y;
        names[i]=z;
        hours[i]=x;
        payment[i]=y;
    }
    knapsack_01_dp(names, hours, payment, n, c);
}
/*

INPUTS
------
5
4
B 2 1000
C 1 1200
D 2 2000
E 1 3000


5
5
A 2 6000
B 2 1000
C 1 1200
D 2 2000
E 1 3000



*/