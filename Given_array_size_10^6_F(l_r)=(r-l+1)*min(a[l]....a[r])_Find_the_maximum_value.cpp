#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
int main()
{
    int n;
    cin>>n;
    int ara[n+2];
    ara[0]=INT_MIN;
    ara[n+1]=INT_MIN;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    stack<pair<int,int> >stk;
    pair<int,int>pr;
    vector<int>left,right;
    stk.push(mp(ara[0],0));
    for(int i=1;i<=n;i++)
    {
        pr.first=ara[i];
        pr.second=i;
        int top_val=stk.top().first;
        int top_pos=stk.top().second;
        while(ara[i]<=top_val)
        {
            stk.pop();
            top_val=stk.top().first;
            top_pos=stk.top().second;
        }
        int l=i-stk.top().second;
        left.push_back(l);
        stk.push(pr);
    }
    while(!stk.empty())
        stk.pop();
    stk.push(mp(ara[n+1],n+1));
    for(int i=n;i>=1;i--)
    {
        pr.first=ara[i];
        pr.second=i;
        int top_val=stk.top().first;
        int top_pos=stk.top().second;
        while(ara[i]<=top_val)
        {
            stk.pop();
            top_val=stk.top().first;
            top_pos=stk.top().second;
        }
        int l=stk.top().second-i;
        right.push_back(l);
        stk.push(pr);
    }
    reverse(right.begin(),right.end());
    /**
    for(int i=0;i<left.size();i++)
        cout<<left[i]<<" ";
    cout<<endl;
    for(int i=0;i<right.size();i++)
        cout<<right[i]<<" ";
    cout<<endl;
    **/
    int ans = 1,val;
    for(int i=1;i<=n;i++)
    {
        val=left[i-1]+right[i-1]-1;
        val*=ara[i];
        if(val>ans)
            ans=val;
    }
    cout<<ans<<endl;
}
