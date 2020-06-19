#include <bits/stdc++.h>
using namespace std;

// vector <int> v;

template<typename T>
class Graph{
    map<T,list<T>> l;
    map<T,int> indegree;
    public:
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }   //Methord to add a edge
    void printAdjList(){
        for(auto p:l){
            cout<<p.first<<"->";
            for(int vertex: p.second){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }        //Methord to print AdjList
    void bfs(T src){
        queue<T> q;
        map<T,int> visited;
        
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                }
            }
        }
    }           //breath first search
    void topological_sort(){
        for(auto it:l){
            T x=it.first;
            for(auto it2:it.second){
                indegree[it2]++;
            }
        }
        queue<int> q;
        for(auto it:l){
            T x= it.first;
            if(indegree[x]==0)q.push(x);
        }
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
    }
    }     // to arrange the Graph in topological order
    bool is_tree(){
        map<T,int> visited;
        map<T,int> parent;
        for(auto it:l)parent[it.first]=it.first;
        queue<int> q;
        int src =0;
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(int nbr:l[node]){
                if(nbr==parent[node])continue;
                if(visited[nbr]==true)return false;
                else{
                    visited[nbr]==true;
                    q.push(nbr);
                    parent[nbr]=node;
                }
            }
        }
        return true;
    }          // to determine whether the graph is a tree or not
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
	
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(3,0);
	g.addEdge(1,2);
// 	g.addEdge(2,3);
// 	g.addEdge(3,5);
// 	g.addEdge(4,5);
// 	g.addEdge(2,5);
	
// 	g.printAdjList();
// 	g.bfs(0);
    // g.topological_sort();
    if(g.is_tree())cout<<"YES it is a tree\n";
    else cout<<"It is not a tree\n";
	return 0;
}
