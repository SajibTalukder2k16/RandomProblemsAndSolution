#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
int foo(int ara[],int n)
{
    for(int i=n;i>=1;i--)
        ara[i]=ara[i-1];
    ara[0]=INT_MIN;
    ara[n+1]=INT_MIN;
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
    int ans = 1,val;
    for(int i=1;i<=n;i++)
    {
        val=left[i-1]+right[i-1]-1;
        val*=ara[i];
        if(val>ans)
            ans=val;
    }
    return ans;
}
int main()
{
    int row,col;
    cin>>row>>col;
    char ara[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>ara[i][j];
        }
    }
    int val[row][col+2];
    for(int i=0;i<col;i++)
        val[0][i]=1-(ara[0][i]-48);
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(ara[i][j]=='0')
                val[i][j]=val[i-1][j]+1;
            else
                val[i][j]=0;
        }
    }
    int ans=-1;
    for(int i=0;i<row;i++)
    {
        ans=max(ans,foo(val[i],col));
    }
    cout<<ans<<endl;
}
