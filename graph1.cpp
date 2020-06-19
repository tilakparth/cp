#include <bits/stdc++.h>
using namespace std;

vector <int> v;

class Graph{
    int Verices;
    list<int> *l;

    public:
    Graph(int v){
        Verices=v+1;
        l= new list<int>[v+1];
    }
    
    void addEdge(int u,int v,bool bider){
        l[u].push_back(v);
        if(bider)l[v].push_back(u);
    }
    
    void printAdjList(){
        for(int i=0;i<Verices;i++){
            cout<<i<<"->";
            for(int vertex: l[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
    
    // void count_no_of_conections(int i,)
    
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
	
	Graph g(5);
	g.addEdge(0,1,false);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	
	g.printAdjList();
	return 0;
}
