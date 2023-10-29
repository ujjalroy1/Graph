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
ll N=(ll)1e16;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
      ll n,m,i,j;
      cin>>n>>m;
      vector<vector<ll>>grp;
      ll parent[n+2]={0};
      ll dis[n+2];
      for(i=0;i<=n;i++)dis[i]=N;
      while(m--)
      {
          ll u,v,w;
          cin>>u>>v>>w;
          grp.push_back({u,v,w});
      }
      ll check=0;
      ll last=0;
      for(i=1;i<=n;i++)
      {
        check=0;
        for(j=0;j<grp.size();j++)
        {
            ll u,v,w;
            u=grp[j][0];
            v=grp[j][1];
            w=grp[j][2];
            if(dis[u]+w<dis[v])
            {
                  check=1;
                  dis[v]=dis[u]+w;
                  parent[v]=u;
                  last=v;
            }

        }
      }
      if(check==0)
      {
          cout<<"NO\n";
          return 0;
      }
      cout<<"YES\n";
      for(i=1;i<=n-1;i++)
      {
        last=parent[last];
      }
      vector<ll>v;
      v.push_back(last);
      ll y;
      y=last;
      while(y!=parent[last])
      {
           v.push_back(parent[last]);
           last=parent[last];
      }
     v.push_back(y);
     reverse(v.begin(),v.end());
     for(auto u:v)cout<<u<<" ";
     cout<<endl;

    return 0;
}
