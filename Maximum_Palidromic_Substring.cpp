#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 1009
#define mp make_pair
int dp[mx][mx];
string str;
int foo(int start_index,int end_index)
{
    if(start_index>=end_index) /// start_index > end_index when substring size is even
        return 1;
    if(dp[start_index][end_index]!=-1)
        return dp[start_index][end_index];
    if(str[start_index]==str[end_index])
        return dp[start_index][end_index]=foo(start_index+1,end_index-1);
    else
        return dp[start_index][end_index]=0;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>str;
    int len = str.length();
    int mx_val = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(foo(i,j))
            {
                mx_val=max(mx_val,j-i+1);
            }
        }
    }
    cout<<mx_val<<endl;
}
