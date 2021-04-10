#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000001
ll p_power[mx];
ll prefix_hash1[mx];
ll prefix_hash2[mx];
int pre_compute_power(int p,int mod)
{
    p_power[0]=1;
    for(int i=1;i<=mx;i++)
    {
        p_power[i]=((p_power[i-1]%mod)*(p%mod))%mod;
        //cout<<p_power[i]<<endl;
    }
}
int compute_hash1(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)%mod*(p_power[i]%mod))%mod)%mod;
        prefix_hash1[i]=hash_value%mod;
        //cout<<prefix_hash1[i]<<endl;
    }
    return hash_value;
}
int compute_hash2(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)%mod*(p_power[i]%mod))%mod)%mod;
        prefix_hash2[i]=hash_value%mod;
        //cout<<prefix_hash2[i]<<endl;
    }
    return hash_value;
}
int single_hash_compute(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    bool chk = false;
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)*p_power[i]%mod)%mod)%mod;
    }
    return hash_value;
}
int reverse_hash_comput(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=len-1,j=0;i>=0;i--,j++)
    {
        hash_value=(hash_value%mod+((str[i]-'a'+1)*p_power[j]%mod)%mod)%mod;
        //cout<<hash_value<<endl;
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
int foo(string a,string b)
{
    ll p1=29;
    ll mod1=1e9+7;
    int l=1;
    int h=b.length();
    compute_hash1(b,p1,mod1);
    compute_hash2(a,p1,mod1);
    int best=0;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        ll dif=mid;
        ll len=b.length();
        unordered_map<ll,bool>mp_ib;
        for(ll i=dif-1,j=-1;i<len;i++,j++)
        {
            ll to_hash=prefix_hash1[i]%mod1;
            ll from_hash;
            if(i==dif-1)
                from_hash=0;
            else
                from_hash=prefix_hash1[j]%mod1;
            ll val1 = (to_hash-from_hash)%mod1;
            if(val1<0)
            {
                val1+=mod1;
                val1%=mod1;
            }
            ll val2 = BigMod(p1,mod1-1-(j+1),mod1)%mod1;
            ll substring_hash_value=((val1)%mod1*(val2)%mod1)%mod1;;
            mp_ib[substring_hash_value]=true;
        }
        len=a.length();
        bool chk=false;
        for(ll i=dif-1,j=-1;i<len;i++,j++)
        {
            ll to_hash=prefix_hash2[i];
            ll from_hash;
            if(i==dif-1)
                from_hash=0;
            else
                from_hash=prefix_hash2[j];
            ll val1 = (to_hash-from_hash)%mod1;
            if(val1<0)
            {
                val1+=mod1;
                val1%=mod1;
            }
            ll val2 = BigMod(p1,mod1-1-(j+1),mod1)%mod1;
            ll substring_hash_value=((val1)%mod1*(val2)%mod1)%mod1;;
            if(mp_ib[substring_hash_value])
            {
                chk=true;
                break;
            }
        }
        if(chk)
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return best;

}
int main()
{
    ll p1=29;
    ll mod1=1e9+7;
    pre_compute_power(p1,mod1);
    string first,second;
    cin>>first>>second;
    int l1=first.length();
    int l2=second.length();
    if(l2>l1)
    {
        swap(first,second);
        swap(l1,l2);
    }
    int res = foo(first,second);
    cout<<res<<endl;
}
