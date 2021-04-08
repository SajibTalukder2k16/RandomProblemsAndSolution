#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000001
ll p_power[mx];
ll prefix_hash[mx];
int pre_compute_power(int p,int mod)
{
    p_power[0]=1;
    for(int i=1;i<=mx;i++)
    {
        p_power[i]=((p_power[i-1]%mod)*(p%mod))%mod;
    }
}
int compute_hash(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)%mod*(p_power[i]%mod))%mod)%mod;
        prefix_hash[i]=hash_value%mod;
    }
    return hash_value;
}
int single_hash_compute(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)*p_power[i]%mod)%mod)%mod;
    }
    return hash_value;
}
ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    ll res=BigMod(base,power/2,mod);
    res=((res%mod)*(res%mod))%mod;
    if(power&1)
        res=(base*res)%mod;
    return res;
}
int BinarySearch(vector<int>vec,int val)
{
    int l=0;
    int h=vec.size()-1;//.size();
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(vec[mid]==val)
        {
            return mid;
        }
        else if(vec[mid]>val)
        {
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return -1;
}
int main()
{
    ll p1=29;
    ll mod1=1e9+7;
    pre_compute_power(p1,mod1);
    int no_of_strings;
    cin>>no_of_strings;
    string str;
    vector<int>vec;
    for(int i=0;i<no_of_strings;i++)
    {
        cin>>str;
        ll hash_value=single_hash_compute(str,p1,mod1);
        vec.push_back(hash_value);
    }
    sort(vec.begin(),vec.end());
    int no_of_query;
    cin>>no_of_query;
    for(int i=0;i<no_of_query;i++)
    {
        cin>>str;
        ll hash_value=single_hash_compute(str,p1,mod1);
        int val = BinarySearch(vec,hash_value);
        if(val==-1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
