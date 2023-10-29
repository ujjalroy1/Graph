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
vector<vector<ll>>grp;
ll dis[1000+123];
const ll mx=10000000000000000;
bool bell(ll n,ll m)
{
     for(ll i=0;i<n;i++)
     {
           dis[i]=mx;
     }
     dis[0]=0;
     for(ll i=1;i<n;i++)
     {
          for(ll j=0;j<grp.size();j++)
          {
              ll u,v,w;
              u=grp[j][0];
              v=grp[j][1];
              w=grp[j][2];
              if(dis[u]<mx)
              {
                 if((w+dis[u])<dis[v])
                 {
                       dis[v]=w+dis[u];
                 }


              }
          }
     }

               for(ll j=0;j<grp.size();j++)
          {
              ll u,v,w;
              u=grp[j][0];
              v=grp[j][1];
              w=grp[j][2];
              if(dis[u]<mx)
              {
                 if((w+dis[u])<dis[v])
                 {
                       dis[v]=w+dis[u];
                       return true;
                 }


              }
          }


   return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
     ll t;
     cin>>t;

     while(t--)
     {
          grp.clear();
         ll n,m;
         cin>>n>>m;
         ll x;
         x=m;
         while(m--)
         {
             ll u,v,w;
             cin>>u>>v>>w;
             grp.push_back({u,v,w});
         }
         if(bell(n,x))cout<<"possible\n";
         else cout<<"not possible\n";

     }

    return 0;
}