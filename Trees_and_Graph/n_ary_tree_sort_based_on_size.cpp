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
    ll val,sz;
    vector<int>adj;
};
typedef struct NODE node;
vector<node>vec(mx);
ll dfsVisit(int cur)
{
    int sz=vec[cur].adj.size();
    if(sz==0)
        return 1;
    int sum=1;
    vector<pair<int,int> >vec_pair;
    for(int i=0;i<sz;i++)
    {
        int v = vec[cur].adj[i];
        int ans=dfsVisit(v);
        sum+=ans;
        vec_pair.push_back(mp(-ans,v));
    }
    sort(vec_pair.begin(),vec_pair.end());
    vec[cur].adj.clear();
    for(int i=0;i<sz;i++)
    {
        int v=vec_pair[i].second;
        vec[cur].adj.push_back(v);
    }
    return sum;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].adj.push_back(v);
        }
        int mod = 1000000007;
        int root=1;
        dfsVisit(root);
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
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++)
            vec[i].adj.clear();
        //vec.clear();
    }
}
