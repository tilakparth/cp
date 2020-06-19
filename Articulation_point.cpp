#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


template<typename T>
class Graph{
    map<T,vector<T>> l;
    map<int,int> disc;
    map<int,int> lowest;
    vi articulation_points;
    int tim =1;
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
    
    void dfs(int curr,int par){
        if(disc[curr])return;
        disc[curr]=tim;
        lowest[curr]=tim;
        tim++;
        int temp=0;
        int no_of_childs=0;
        for(auto it:l[curr]){
            if(!disc[it]){
                dfs(it,curr);
                no_of_childs++;
                lowest[curr] = min(lowest[curr],lowest[it]);
                temp = max(temp,lowest[it]);
            }
            else if(it!=par){
                lowest[curr] = min(lowest[curr],disc[it]); 
            }
        }
        if(par==0){
            if(no_of_childs>1)articulation_points.pb(curr);
        }
        else if(temp>=disc[curr])articulation_points.pb(curr);
    }
    
    void solve(){
        dfs(1,0);
        for(auto it:disc)cout<<it.ff<<" "<<it.ss<<endl;   cout<<endl<<endl;
        for(auto it:lowest)cout<<it.ff<<" "<<it.ss<<endl; cout<<endl;
        for(auto it:articulation_points)cout<<it<<" ";
        
    }
    
    
};

 
int32_t main()
{
    c_p_c();
    int n,m;  cin>>n>>m;
    Graph<int> g;
    from(i,m){
        int a,b; cin>>a>>b;
        g.addEdge(a,b);
    }
    g.solve();
    
    return 0;
}