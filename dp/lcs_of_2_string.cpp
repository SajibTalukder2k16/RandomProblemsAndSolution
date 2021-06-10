#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mod 1000000007
#define pi 3.141593
string a,b;
#define m 1000
int dp[m][m];
int lcs(int i,int j)
{
    if(i==a.length()||j==b.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j]=1+lcs(i+1,j+1);
    else
        return dp[i][j]=max(lcs(i,j+1),lcs(i+1,j));
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>a>>b;
    cout<<lcs(0,0)<<endl;
}
