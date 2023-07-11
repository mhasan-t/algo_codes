#include<bits/stdc++.h>
using namespace std;

char vertices[10]={'a', 'b', 'c','d','e','f','g','h','i','j'};
int nodes=10;
int parent[10];
int visited[10]={0};
int adjMat[10][10];
int MST[10][10];

int parentOf(int n){
    int p = parent[n];
    while(p!=-1){
        p=parent[p];
        n=parent[n];
    }
    return n;
}

void kruskal(){
    for(int i=0;i<nodes;i++) parent[i]=-1;
    set<int> s;
    while(s.size()<nodes){
        int u,v, m=INT_MAX;
        for(int i=0;i<nodes;i++){ // minimum edge is [u][v]
            for(int j=0;j<nodes;j++){
                if( adjMat[i][j]!=0 && m>adjMat[i][j]){
                    m=adjMat[i][j];
                    u=i; v=j;
                }
            }
        }

        adjMat[u][v]=0;
        adjMat[v][u]=0;
        cout<<"\nCHECKING "<<vertices[u]<<"->"<<vertices[v]<<endl;
        if(parentOf(u)!=parentOf(v) ){
            parent[parentOf(u)]=parentOf(v);
            cout << "\nparent of "<< vertices[u]<<" is "<<vertices[v]<<endl;
            MST[u][v]=1;
            MST[v][u]=1;
            s.insert(u);
            s.insert(v);
        }
    }
}

int main(){

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            adjMat[i][j]=0;
            MST[i][j]=0;
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


    kruskal();

    cout <<"\nPARENTS-\n";
    for(int i=0;i<nodes;i++){
        cout<< vertices[i]<<" | ";
    }
    cout<<endl;
    for(int i=0;i<nodes;i++){
        cout<< vertices[parent[i]]<<" | ";
    }
    cout <<endl;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<MST[i][j]<<",";
        }
        cout<<endl;
    }

    return 0;
}
