#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
#define ll long long int
#define endl "\n"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
 //ordered_multiset <ll> kek;(declaration for multiorder set)
// ordered_set o_set;(declaration)
//kek.order_of_key(i);(strictly less then i for multi order set)
//o_set.order_of_key(5) ;(strictly less then i for multi order set)
#define yes cout << "YES\n"
#define no cout << "NO\n"
vector<ll>adj[10000];
ll vis[10000];
ll level[10000];
void bfs(ll node)
{
     vis[node]=1;
     queue<ll>q;
     q.push(node);
     while(!q.empty())
     {
         ll par=q.front();
         q.pop();
         cout<<par<<" ";
         for(auto child:adj[par])
         {
             if(vis[child]==0)
             {
                vis[child]=1;
                q.push(child);
                level[child]=level[par]+1;
             }
         }
     }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ll n,i;
    cin>>n;
    for(i=1;i<n;i++)
    {
         ll u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
         
    }
    bfs(1);
    cout<<endl;
   for(i=1;i<=n;i++)
   {
     cout<<i<<" "<<level[i]<<endl;
   }
   
    return 0;
}
