#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 100009
int dp[mx];
int n;
int ara[mx];
int foo(int pos)
{
    if(pos>=n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    return dp[pos]=max(ara[pos]+foo(pos+2),foo(pos+1));
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    cout<<foo(0)<<endl;;
}
