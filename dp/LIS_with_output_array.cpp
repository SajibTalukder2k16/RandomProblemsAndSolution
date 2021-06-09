#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define pi 3.141593
#define m 1000001
int n;
int dp[m];
int ara[m];
int next_pointer[m];
int foo(int pos)
{
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    int ans=1;
    int next=-1;
    for(int i=pos+1;i<n;i++)
    {
        if(ara[pos]<=ara[i])
        {
            if(1+foo(i)>ans)
            {
                ans=1+foo(i);
                next=i;
            }
        }
    }
    dp[pos]=ans;
    next_pointer[pos]=next;
    return ans;
}
void path(int i)
{
    cout<<ara[i]<<" ";
    if(next_pointer[i]==-1)
    {
        cout<<endl;
        return;
    }
    path(next_pointer[i]);
    return;
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof dp);
    memset(next_pointer,-1,sizeof next_pointer);
    for(int i=0;i<n;i++)
        cin>>ara[i];
    int ans=0;
    int base=-1;
    for(int i=0;i<n;i++)
    {
        int val = foo(i);
        //cout<<i<<" "<<val<<endl;
        if(ans<foo(i))
        {
            ans=foo(i);
            base=i;
        }
    }
    cout<<ans<<endl;
    path(base);
}
