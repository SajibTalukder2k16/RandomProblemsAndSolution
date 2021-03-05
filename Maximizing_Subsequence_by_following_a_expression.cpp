#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 1009
int dp[mx][mx];
int n;
int ara[mx];
int foo(int pos,int idx)
{
    if(pos>=n)
        return 0;
    if(dp[pos][idx]!=-1)
        return dp[pos][idx];
    return dp[pos][idx]=max(ara[pos]*idx+foo(pos+1,idx+1),foo(pos+1,idx));
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    cout<<foo(0,1)<<endl;;
}
