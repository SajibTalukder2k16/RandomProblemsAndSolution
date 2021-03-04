#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 100009
int dp[mx];
int foo(int n)
{
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=foo(n-1)+foo(n-2)+2*foo(n-3);
}
int main()
{
    memset(dp,-1,sizeof dp);
    dp[1]=1;
    dp[2]=2;
    dp[3]=6;
    int sizeOfTiles;
    cin>>sizeOfTiles;
    cout<<foo(sizeOfTiles)<<endl;;
}
