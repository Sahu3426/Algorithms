/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;

vector< pair <int, int> > adjW[100005];
bool vis[100005];
int dist[10000000];

void Dijkstra(int src,int V){
    
    for(int i=1;i<=V;i++){
        
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    
    multiset<pair<int, int>> mul;
    
    dist[src] = 0;
    
    mul.insert({0,src});
    
    while( !mul.empty()){
        
        pair<int,int> frnt = *mul.begin();
        
        int u = frnt.second;
        
        mul.erase(mul.begin());
        
        if( !vis[u]){
            
            vis[u]=1;
            
            for(auto i:adjW[u]){
                
              int v = i.first;
              
              int w = i.second;
              
              if(dist[u]+w<dist[v]){
                  
                  dist[v]=dist[u]+w;
                  mul.insert({dist[v],v});
              }
            
            
            }
        
        }
        
        
    }
    
    for(int i=2;i<=V;i++) {
        
         cout<<dist[i]<<" ";
    }
}

int main(){
    
    int vertex,edges,u,v,w;
    
    cin>>vertex>>edges;
    
    for(int i=0;i<edges;i++){
        
        cin>>u>>v>>w;
        adjW[u].push_back({v,w});
       // adjW[v].push_back({u,w});
    }
    
    Dijkstra(1,vertex);
}
