#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
string str;
int d;
int dp[(1<<10)+2][1005];
int foo(int mask,int mod)
{
    int cnt=__builtin_popcount(mask);
    if(cnt==str.size())
    {
        return mod==0;
    }
    if(dp[mask][mod]!=-1)
        return dp[mask][mod];
    int res = 0;
    for(int i=0;i<str.size();i++)
    {
        if((1<<i)&mask)
            continue;
        int val = foo((mask|(1<<i)),(mod*10+(str[i]-'0'))%d);
        res+=val;
    }
    return dp[mask][mod]=res;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>str>>d;
    cout<<foo(0,0)<<endl;;
}
