#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long int 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define from(i,n)       for(int i=0;i<(int)n;i++)
#define from_j(i,j,n)   for(int i=j;i<(int)n;i++)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Graph{
    map<string , list< pair<string,int> > > l;
    public:
    void addEdge(string x,string y,bool bidir,int wt){
        l[x].pb(mp(y,wt));
        if(bidir) l[y].pb(mp(x,wt));
    }
    
    void printAdList(){
        for(auto p : l){
            string city = p.ff;
            list< pair<string,int> > nbrs =p.ss;
            cout<<city<<"->";
            for(auto nbr:nbrs){
                string dest = nbr.ff;
                int dis = nbr.ss;
                cout<<dest<<" "<<dis<<", ";
            }
            cout<<endl;
            
        }
    } 
    
};
 
int32_t main()
{
    c_p_c();
    Graph g;
    g.addEdge("A","D",false,50);
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,30);
    
    g.printAdList();
    // g.addEdge("B","D");
    return 0;
}