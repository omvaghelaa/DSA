#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedges(vector<int> adj[],int u,int v,bool undirected = true){
    adj[u].push_back(v);  // u=source and v=destination
    if(undirected) {adj[v].push_back(u);}
}

void display(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int temp : adj[i]){
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}

void bfs(vector<int> adj[],int v,int start){
    vector<bool> visited(v,false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout<<"BFS traversal from Node : "<<start<<" : ";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;
}


void dfsUtil(vector<int> adj[], vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(adj, visited, neighbor);
        }
    }
}

void dfs(vector<int> adj[], int v, int start) {
    vector<bool> visited(v, false);
    cout << "DFS Traversal starting from vertex " << start << ": ";
    dfsUtil(adj, visited, start);
    cout << endl;
}


int main(){
    int v = 7;
    vector<int> adj[v];

    addedges(adj,0,1);
    addedges(adj,0,2);
    addedges(adj,0,3);

    // addedges(adj,1,0);
    addedges(adj, 1, 2);

    // addedges(adj, 2, 0);
    // addedges(adj, 2, 1);
    addedges(adj, 2, 3);
    addedges(adj, 2, 4);

    // addedges(adj, 3, 0);
    // addedges(adj, 3, 2);
    addedges(adj,3,4);

    // addedges(adj,4,2);
    // addedges(adj,4,3);
    addedges(adj,4,5);
    addedges(adj,4,6);

    // addedges(adj,5,4);
    // addedges(adj,6,4);

    //bfs(adj,v,0);
    dfs(adj,v,0);
    // cout<<"Graph adj LIST : "<<endl;
   // display(adj,v);
    return 0;
}