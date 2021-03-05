#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 100009
int dp[mx][2];
int n;
int ara[mx];
int foo(int pos,bool flag)
{
    if(pos>=n)
        return 0;
    if(dp[pos][flag]!=-1)
        return dp[pos][flag];
    if(flag==0)
    {
        dp[pos][flag]=max(ara[pos]+foo(pos+1,!flag),foo(pos+1,flag));
    }
    else
    {
        dp[pos][flag]=max(-ara[pos]+foo(pos+1,!flag),foo(pos+1,flag));
    }
    return dp[pos][flag];
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    cout<<foo(0,1)<<endl;;
}
