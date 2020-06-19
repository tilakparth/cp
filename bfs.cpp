/**
 * @Date:   2020-04-18T19:30:06+05:30
 * @Last modified time: 2020-05-24T23:34:03+05:30
 */



// Breath First Search

#include <bits/stdc++.h>
using namespace std;

// vector <int> v;

template<typename T>

class Graph{

    map<T,list<T>> l;

    public:

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(auto p:l){
            cout<<p.first<<"->";
            for(int vertex: p.second){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }

    // void count_no_of_conections(int i,)
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
                // cout<<endl<<"Visited "<<visited[nbr]<<endl;
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                }

            }
        }
    }

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int a,b;
    cin>>a>>b;
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
// 	g.addEdge(3,4);
	g.addEdge(4,5);
// 	g.addEdge(2,3);

	g.printAdjList();
	g.bfs(0);

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
