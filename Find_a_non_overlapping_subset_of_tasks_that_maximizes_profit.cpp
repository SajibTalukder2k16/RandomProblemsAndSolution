#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mx 100009
#define mp make_pair
vector<pair<pair<int,int>,int> >vec;
pair<pair<int,int>,int>pr;
int no_of_tasks;
int dp[mx];
int foo(int pos)
{
    if(pos>=no_of_tasks)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    pr = mp(mp(vec[pos].first.second,vec[pos].first.second),vec[pos].second);
    ///Here upper bound is used for finding the next task position that is posible after current positions ending time
    int next = upper_bound(vec.begin(),vec.end(),pr)-vec.begin();
    dp[pos] = max(foo(pos+1),foo(next)+vec[pos].second);
    return dp[pos];
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>no_of_tasks;
    pair<pair<int,int>,int>pr;
    int start_time,end_time,profit;
    for(int i=0;i<no_of_tasks;i++)
    {
        cin>>start_time>>end_time>>profit;
        pr = make_pair(make_pair(start_time,end_time),profit);
        vec.push_back(pr);
    }
    sort(vec.begin(),vec.end());
    cout<<foo(0)<<endl;
}
