//          Dephth First Search (DFS)

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



class Edge{
  public:
  int src;
  int dest;
  int weight;
  void print(){
      cout<<src<<" "<<dest<<" "<<weight<<endl;
  }
};
bool compare(Edge a,Edge b){
    return a.weight<b.weight;
}
int find(vector<int> &v,int i){
    if(v[i]!=i){
        v[i] = find(v,v[i]);
    }
    return v[i];
}
// template<typename T>
// class Graph {
//     map<T ,vector< pair<T,int> > > l;
//     map<T,int> visited;
//     public:
//     void addEdge(T x,T y,int wt){
//         l[x].pb(mp(y,wt));
//         l[y].pb(mp(x,wt));
//     }
//     void printAdjList(){
//         for(auto it : l){
//             cout<<it.ff<<" -> ";
//             for(auto it2:it.ss)cout<<it2.ff<<" "<<it2.ss<<", ";
//             cout<<endl;
//         }
//     }
//     // void dfs_helper(T src,list<T> &ordering){
//     //     visited[src]=1;
//     //     for(auto nbr : l[src]){
//     //         if(!visited[nbr])dfs_helper(nbr,ordering);
//     //     }
//     //     ordering.push_front(src);
//     //     return;
//     // }
//     // void dfs(){
//     //     list<T> ordering; 
//     //     for(auto it:l) {
//     //         T node = it.ff;
//     //         if(!visited[node])dfs_helper(node,ordering);
//     //     }
//     //     for(auto it:ordering)cout<<it<<"\n";
//     // }
//     // void dijkstra(T src,int n){
//     //     map<T,int> distance;
//     //     for(int i=0;i<n+1;i++){
//     //         distance[i]=inf;
//     //     }
//     //     set<pair<int,T>> s;
//     //     distance[src]=0;
//     //     s.insert(mp(0,src));
        
//     //     while(!s.empty()){
//     //         auto p = *(s.begin());
//     //         T node = p.ss;
//     //         int node_distance = p.ff;
//     //         s.erase(s.begin());
//     //         for(auto childpair:l[node]){
//     //             T des = childpair.ff;
//     //             int dis = childpair.ss;
//     //             if(node_distance+dis<distance[des]){
//     //                 auto f = s.find(mp(distance[des],des));
//     //                 if(f!=s.end()){
//     //                     s.erase(f);
//     //                 }
//     //                 distance[des] = dis + node_distance;
//     //                 s.insert(mp(distance[des],des));
//     //             }
                
//     //         }
//     //     }
//     //     for(auto it:distance){
//     //         if(it.ff==0)continue;
//     //         if(it.ff == src)continue;
//     //         if(it.ss ==inf)it.ss=-1;
//     //         cout<<it.ss<<" ";
//     //         // cout<<it.ff<<" "<<it.ss<<"\n";
//     //     }
//     //     cout<<endl;
//     // }
//     // void_cycle(T src){
//     //     map<T,visited>
//     // }
// };

void Kruskals(Edge *input,int n,int e){
    sort(input,input+e,compare);
    // for(int i=0;i<e;i++)cout<<input[i].src<<" "<<input[i].dest<<" "<<input[i].weight<<endl;
    Edge output[n-1];
    vector<int> v(n+1);
    for(int i=0;i<=n;i++)v[i]=i;
    int no_of_edges=0; int index=0;
    while((no_of_edges<n-1)&&(index<e)){
        Edge temp = input[index];
        index++;
        int parent_1 = find(v,temp.src);
        int parent_2 = find(v,temp.dest);
        if(parent_1==parent_2)continue;
        v[parent_1]=parent_2;
        output[no_of_edges++]=input[index-1];
    }
    // cout<<"Output\n";
    for(int i=0;i<n-1;i++)output[i].print();
    return;
}

int32_t main()
{
    c_p_c();
    // Graph<int> g;
    // g.printAdjList();
    int n ,e ,money;
    cin>>n>>e>>money;
    Edge input[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].src=s;
        input[i].dest=d;
        input[i].weight=w;
        // input[i].print();
    }
    Kruskals(input,n,e);

    return 0;
}