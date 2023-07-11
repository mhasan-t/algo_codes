#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int nodes=10;
int weight_value[10];
int parent[10];
int visited[10]={0};
int adjMat[10][10];
int MST[10][10];

bool compare(int n1, int n2){
    return weight_value[n1] > weight_value[n2];
}

void prims(){
    weight_value[0]=0;
    parent[0] = 0;
    for(int i=1;i<nodes;i++){
        weight_value[i]=9999;
    }
    priority_queue<int, vector<int>, function<bool(int, int)>> Q(compare);
    Q.push(0);
    while(!Q.empty()){
        int u = Q.top();
        Q.pop();
        MST[u][parent[u]]= adjMat[u][parent[u]];
        MST[parent[u]][u]= adjMat[parent[u]][u];
        visited[u]=1;
        for(auto v=0; v<nodes; v++){
            if(adjMat[u][v]==0) continue;
            if(visited[v]==1) continue;
            if( adjMat[u][v]<weight_value[v] ){
                weight_value[v] = adjMat[u][v];
                parent[v]=u;
                Q.push(v);
            }
        }
    }
}

int main(){

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            adjMat[i][j]=0;
        }
    }

    adjMat[0][1]=3;
    adjMat[0][3]=4;
    adjMat[0][4]=10;
    adjMat[0][5]=8;
    adjMat[1][0]=3;
    adjMat[1][2]=7;
    adjMat[1][3]=2;
    adjMat[2][1]=7;
    adjMat[2][3]=6;
    adjMat[3][0]=4;
    adjMat[3][1]=2;
    adjMat[3][2]=6;
    adjMat[3][4]=1;
    adjMat[4][0]=10;
    adjMat[4][3]=1;
    adjMat[4][5]=3;
    adjMat[4][6]=5;
    adjMat[5][0]=8;
    adjMat[5][4]=3;
    adjMat[5][6]=6;
    adjMat[5][9]=4;
    adjMat[6][3]=8;
    adjMat[6][4]=5;
    adjMat[6][5]=6;
    adjMat[6][7]=8;
    adjMat[6][8]=10;
    adjMat[6][9]=7;
    adjMat[7][3]=11;
    adjMat[7][6]=8;
    adjMat[7][8]=9;
    adjMat[8][6]=10;
    adjMat[8][7]=9;
    adjMat[8][9]=2;
    adjMat[9][5]=4;
    adjMat[9][6]=7;
    adjMat[9][8]=2;

    prims();
    cout <<"\nVERTICE-";
    for(int i='a';(i-'a')<nodes;i++){
        cout<< ((char)i)<<" ";
    }
    cout <<"\nPARENTS-";
    for(int i=0;i<nodes;i++){
        cout<< ((char)(parent[i]+'a'))<<" ";
    }
    cout <<"\nWEIGHTS-";
    for(int i=0;i<nodes;i++){
        cout<< weight_value[i]<<" ";
    }
    return 0;
}
