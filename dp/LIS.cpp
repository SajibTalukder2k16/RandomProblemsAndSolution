#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define pi 3.141593
#define m 100001
int n;
int dp[m];
int foo(int pos,int ara[])
{
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    int ans=1;
    for(int i=pos+1;i<n;i++)
    {
        if(ara[pos]<ara[i])
        {
            ans=max(ans,1+foo(i,ara));
        }
    }
    dp[pos]=ans;
    return ans;
}
int main()
{
    cin>>n;
    int ara[n];
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        cin>>ara[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int val = foo(i,ara);
        //cout<<i<<" "<<val<<endl;
        ans=max(ans,foo(i,ara));
    }
    cout<<ans<<endl;
}
