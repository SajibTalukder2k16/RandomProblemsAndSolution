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
#define m 3001
int dp[m][m];
pair<int,int>parent[m][m];
int lcs(int i,int j)
{
    if(i==a.length()||j==b.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
    {
        parent[i][j]=mp(i+1,j+1);
        return dp[i][j]=1+lcs(i+1,j+1);
    }
    else
    {
        int x=lcs(i,j+1);
        int y=lcs(i+1,j);
        if(x>y)
        {
            parent[i][j]=mp(i,j+1);
        }
        else
        {
            parent[i][j]=mp(i+1,j);
        }
        return dp[i][j]=max(x,y);
    }
}
void path(int i,int j)
{

    if(parent[i][j].first==-1 && parent[i][j].second==-1)
        return;
    if(a[i]==b[j])
        cout<<a[i];
    path(parent[i][j].first,parent[i][j].second);
}
int main()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1;
            parent[i][j]=mp(-1,-1);
        }
    }
    cin>>a>>b;
    lcs(0,0);
    path(0,0);
    cout<<endl;
}
