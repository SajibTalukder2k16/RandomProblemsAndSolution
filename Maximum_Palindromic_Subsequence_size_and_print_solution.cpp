#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 1009
#define mp make_pair
int dp[mx][mx];
pair<int,int> next[mx][mx];
string str;
int foo(int start_index,int end_index)
{
    if(start_index==end_index)
        return 1;
    if(start_index>end_index) ///start_index > end_index when substring size is even but it is not valid
        return 0;
    if(dp[start_index][end_index]!=-1)
        return dp[start_index][end_index];
    if(str[start_index]==str[end_index])
    {
        next[start_index][end_index]={start_index+1,end_index-1};
        return dp[start_index][end_index]=foo(start_index+1,end_index-1)+2;
    }
    else
    {
        int val1 = foo(start_index,end_index-1);
        int val2 = foo(start_index+1,end_index);
        int mx_value = max(val1,val2);
        if(mx_value==val1)
            next[start_index][end_index]={start_index,end_index-1};
        else
            next[start_index][end_index]={start_index+1,end_index};
        return dp[start_index][end_index]=mx_value;
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    memset(next,-1,sizeof next);
    cin>>str;
    int len = str.length();
    int mx_val = foo(0,len-1);
    cout<<mx_val<<endl;
    string fr="",ba="";
    int b = 0;
    int e = len-1;
    while(true)
    {
        if(str[b]==str[e])
        {
            if(b==e)
            {
                fr+=str[b];
                break;
            }
            else
            {
                fr+=str[b];
                ba=str[e]+ba;
            }
        }
        int newb=next[b][e].first;
        int newe=next[b][e].second;
        b=newb,e=newe;
        if(b>e)
            break;
    }
    cout<<fr<<ba<<endl;
}
