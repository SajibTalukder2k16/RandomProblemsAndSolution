#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 300002
struct NODE
{
    ll val;
    vector<int>adj;
};
ll x;
int mod = 1000000007;
typedef struct NODE node;
vector<node>vec(mx);
ll dfsVisit(int cur)
{
    int sz=vec[cur].adj.size();
    if(sz==0)
        return 1;
    ll sum=0;
    vector<pair<ll,ll> >vec_pair;
    for(int i=0;i<sz;i++)
    {
        int v = vec[cur].adj[i];
        ll ans=dfsVisit(v);
        sum+=ans;
        vec_pair.push_back(mp(-ans,v));
    }
    sort(vec_pair.begin(),vec_pair.end());
    vec[cur].adj.clear();
    ll new_sum=x;
    //cout<<"Cur: "<<cur<<" "<<new_sum<<" "<<endl;
    for(int i=0;i<sz;i++)
    {
        ll v=vec_pair[i].second;
        new_sum+=(((-1)*vec_pair[i].first)%mod*(i+1))%mod;
        new_sum=new_sum%mod;
        //cout<<vec_pair[i].first*(-1)<<" ";
        vec[cur].adj.push_back(v);
    }
    //cout<<endl;
    //cout<<"Cur: "<<cur<<" out  "<<new_sum<<endl;
    return new_sum%mod;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n>>x;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].adj.push_back(v);
        }
        ll root=1;
        ll ans=dfsVisit(root)%mod;
        cout<<ans<<endl;
        /*
        int cur=root;
        vec[root].val=x;
        queue<int>bfs_queue;
        bfs_queue.push(root);
        ll sum=x;
        while(!bfs_queue.empty())
        {
            cur=bfs_queue.front();
            bfs_queue.pop();
            int sz=vec[cur].adj.size();
            ll value=vec[cur].val;
            for(int i=0;i<sz;i++)
            {
                bfs_queue.push(vec[cur].adj[i]);
                int pos=vec[cur].adj[i];
                vec[pos].val=((value)%mod*(i+1)%mod)%mod;
                sum+=(vec[pos].val)%mod;
                sum%=mod;
            }
            //cout<<cur<<" "<<sum<<endl;
        }
        cout<<sum<<endl;
        */
        for(int i=0;i<n;i++)
            vec[i].adj.clear();
        //vec.clear();
    }
}
