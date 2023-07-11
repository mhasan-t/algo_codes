#include<iostream>
using namespace std;

int knapsack_01_dp(int weights[], int values[], int n, int W){
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

//    for(int i=0; i<=n; i++){
//        for(int j=0; j<=W; j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[n][W];
}

int fractional_knapsack_greedy(int weights[], int values[], int n, int W){
    float* valuesPerUnit = (float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++){
        valuesPerUnit[i] = (float)values[i]/weights[i];
    }

    int takenWeights = 0, takenValues = 0;
    for(int i=0;i<n;i++){

        int maxValuedItem = 0;
        int temp = 0;
        for(int j=0;j<n;j++){
            if(valuesPerUnit[j] > temp) {
                temp = valuesPerUnit[j];
                maxValuedItem = j;
            }
        }

        if(takenWeights >= W){
            return takenValues;
        }
        if(weights[maxValuedItem]<=(W-takenWeights)){
            takenValues+= values[maxValuedItem];
            takenWeights+= weights[maxValuedItem];
        }
        else {
            takenValues+= valuesPerUnit[maxValuedItem]*(W-takenWeights);
            break;
        }
        valuesPerUnit[maxValuedItem] = -1;
    }


    return takenValues;
}

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct Task{
    int no, weight, value;
};

bool comparison(Task t1, Task t2){
    return t1.value*1.0/t1.weight > t2.value*1.0/t2.weight;
    //return t1.start < t2.start;
    //return t1.finish > t2.finish;
//    if (t1.finish < t2.finish) return true;
//    else if (t1.finish == t2.finish){
//        return t1.start < t2.start;
//    } else return false;
}

int gred_frac(int W,Task items[], int n){
    sort(items,items+n, comparison);
    int w = W;
    int i = 0;
    int profit = 0;
    while(w>0 && i<n){
        float xi = w/items[i].weight>=1 ? 1 : w/items[i].weight;
        w = w - xi*items[i].value;
        profit+=xi*items[i].value;
        i++;
    }
    return profit;
}

int main(){
    int prices[]= {30, 20, 40};
    int weights[]={2, 1, 1};
    int capacity=4, n=3;
    knapsack_01_dp(weights, prices, n, capacity);
    cout << fractional_knapsack_greedy(weights, prices, n, capacity);
    return 0;
}
