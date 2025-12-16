#include<iostream>
#include <vector>
using namespace std;

void buildmat(vector<vector<int>> &adj,int u,int v,bool directed = false){
    adj[u][v] = 1; // u=source and v=destination
    if(!directed){adj[v][u] = 1;}
}

void display(vector<vector<int>> adj,int v){
    for(int i=0;i<v;i++){
        cout<<i<<" : ";
        for(int j=0;j<v;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfsHelper(vector<vector<int>> &adj,vector<bool> &visited,int node){
    visited[node] = true;
    cout<<node<<" ";

    for(int i=0;i<adj.size();i++){
        if(adj[node][i]==1 && visited[i] != 1){
            dfsHelper(adj,visited,i);
        }
    }
}

void dfs(vector<vector<int>> &adj,int v,int start){
    vector<bool> visited(v,false);
    cout<<"DFS begun from "<<start<<" : ";
    dfsHelper(adj,visited,start);
    
}


int main(){
     int v = 7;
    vector<vector<int>> adj(v,vector<int>(v,0));
    buildmat(adj,0,1);
    buildmat(adj,0,2);
    buildmat(adj,0,3);

    buildmat(adj,1,3);
    buildmat(adj,2,3);
    buildmat(adj,2,4);

    buildmat(adj,4,3);

    buildmat(adj,4,5);
    buildmat(adj,4,6);

   //display(adj,v);
   dfs(adj,v,0);
    return 0;
}