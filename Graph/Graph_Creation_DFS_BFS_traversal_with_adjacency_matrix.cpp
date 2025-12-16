#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedges(vector<vector<int>> &adj,int u,int v,bool directed = false){
    adj[u].push_back(v);  // u=source and v=destination
    if(!directed) {adj[v].push_back(u);}
} 

void display(vector<vector<int>> adj,int v){
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int node : adj[i]){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}

void bfs(vector<vector<int>> adj,int v,int start){
    vector<bool> visited(v,false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout<<"BFS traversal from node: "<<start<<" : ";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
            for(int neighbour : adj[node]){
                if(visited[neighbour] == false){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;
}

void dfshelper(vector<vector<int>> adj,vector<bool> &visited,int node){
    visited[node] = true;
    cout<<node<<" ";
    for(int neighbour : adj[node]){
        if(visited[neighbour] == false){
        dfshelper(adj,visited,neighbour);
        }
    }
}

void dfs(vector<vector<int>> adj,int v,int start){
    vector<bool>visited(v,false);
    cout<<"DFS from "<<start<<" : ";
    dfshelper(adj,visited,start);
}

int main(){
    int v = 7;
    vector<vector<int>> adj(v);
    addedges(adj,0,1);
    addedges(adj,0,2);
    addedges(adj,0,3);

    addedges(adj,1,2);

    addedges(adj,2,3);
    addedges(adj,2,4);

    addedges(adj,3,4);

    addedges(adj,4,5);
    addedges(adj,4,6);

   // display(adj,v);

   //bfs(adj,v,0);
    dfs(adj,v,0);
    return 0;
}