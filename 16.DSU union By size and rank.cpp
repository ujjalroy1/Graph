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
#define mod 1000000007
class DSU
{
    vector<ll>rank,parent,Size;
    public:
    DSU(ll n)
    {
         rank.resize(n+1,0);
         parent.resize(n+1);
         Size.resize(n+1);
         for(ll i=0;i<=n;i++)
         {
             parent[i]=i;
             Size[i]=1;

         }
    }
    ll findPar(ll node)
    {
          if(node==parent[node])
          {
             return parent[node]=node;
          }

          return parent[node]=findPar(parent[node]);
    }
    void unionByrank(ll u,ll v)
    {
          ll a=findPar(u);
          ll b=findPar(v);
          if(a==b)
          {
             return;
          }
          if(rank[a]<rank[b])
          {
              parent[a]=b;
          }
          else if(rank[a]>rank[b])
          {
               parent[b]=a;
          }
          else
          {
               parent[b]=a;
               rank[a]+=1;
          }
    }
    void unionBySize(ll u,ll v)
    {
          ll a=findPar(u);
          ll b=findPar(v);
          if(a==b)return;
          if(Size[a]<Size[b])
          {
               parent[a]=b;
               Size[b]+=Size[a];
          }
          else
          {
                    parent[b]=a;
                  Size[a]+=Size[b];
          }
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    DSU ds(n);
    for(ll i=0;i<n-1;i++)
    {
         ll a,b;
         cin>>a>>b;
         ds.unionBySize(a,b);
    }
    if(ds.findPar(4)==ds.findPar(1))cout<<"YES\n";
    else cout<<"NO\n";
     

    return 0;
}
