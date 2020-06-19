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
class Graph {
    map<T ,vector< pair<T,int> > > l;
    map<T,int> visited;
    public:
    void addEdge(T x,T y,int wt){
        l[x].pb(mp(y,wt));
        l[y].pb(mp(x,wt));
    }
    void printAdjList(){
        for(auto it : l){
            cout<<it.ff<<" -> ";
            for(auto it2:it.ss)cout<<it2.ff<<" "<<it2.ss<<", ";
            cout<<endl;
        }
    }
    // void dfs_helper(T src,list<T> &ordering){
    //     visited[src]=1;
    //     for(auto nbr : l[src]){
    //         if(!visited[nbr])dfs_helper(nbr,ordering);
    //     }
    //     ordering.push_front(src);
    //     return;
    // }
    // void dfs(){
    //     list<T> ordering; 
    //     for(auto it:l) {
    //         T node = it.ff;
    //         if(!visited[node])dfs_helper(node,ordering);
    //     }
    //     for(auto it:ordering)cout<<it<<"\n";
    // }
    // void dijkstra(T src,int n){
    //     map<T,int> distance;
    //     for(int i=0;i<n+1;i++){
    //         distance[i]=inf;
    //     }
    //     set<pair<int,T>> s;
    //     distance[src]=0;
    //     s.insert(mp(0,src));
        
    //     while(!s.empty()){
    //         auto p = *(s.begin());
    //         T node = p.ss;
    //         int node_distance = p.ff;
    //         s.erase(s.begin());
    //         for(auto childpair:l[node]){
    //             T des = childpair.ff;
    //             int dis = childpair.ss;
    //             if(node_distance+dis<distance[des]){
    //                 auto f = s.find(mp(distance[des],des));
    //                 if(f!=s.end()){
    //                     s.erase(f);
    //                 }
    //                 distance[des] = dis + node_distance;
    //                 s.insert(mp(distance[des],des));
    //             }
                
    //         }
    //     }
    //     for(auto it:distance){
    //         if(it.ff==0)continue;
    //         if(it.ff == src)continue;
    //         if(it.ss ==inf)it.ss=-1;
    //         cout<<it.ss<<" ";
    //         // cout<<it.ff<<" "<<it.ss<<"\n";
    //     }
    //     cout<<endl;
    // }
    // void_cycle(T src){
    //     map<T,visited>
    // }
    
    int find_min_vertex(map<T,int> &weight){
        int min_distance=inf;
        int min_node;
        for(auto it:l){
            int node = it.ff;
            if(visited[node])continue;
            if(weight[node]<min_distance){
                min_distance=weight[node];
                min_node=node;
            }
        }
        return min_node;
    }
    void Prims(T src,int n){
        map<T,int> parent;
        map<T,int> weight;
        for(auto it:l){
            T node =it.ff;
            weight[node] = inf;
        }
        parent[src]=-1;
        weight[src]=0;
        for(int i=0;i<n;i++){
            int min_vertex = find_min_vertex(weight);
            visited[min_vertex]=1;
            for(auto it:l[min_vertex]){
                int node = it.ff;
                int dis =it.ss;
                if(visited[node])continue;
                if(dis<weight[node]){
                    weight[node]=dis;
                    parent[node]=min_vertex;
                }
            }
        }
        for(auto it:parent){
            int s =it.ff;
            int des =it.ss;
            if(s==src)continue;
            else cout<<s<<" -- "<<des<<"  with weight  "<<weight[s]<<endl;
        }
    }
};

int32_t main()
{
    c_p_c();
    Graph<int> g;
    // g.printAdjList();
    int n ,e ,money;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g.addEdge(s,d,w);
    }
    g.Prims(0,n);
    // Kruskals(input,n,e);

    return 0;
}