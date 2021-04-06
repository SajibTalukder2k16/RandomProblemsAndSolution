#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 100001
ll p_power[mx];
ll prefix_hash[mx];
int pre_compute_power(int p,int mod)
{
    p_power[0]=1;
    for(int i=1;i<=mx;i++)
        p_power[i]=(p_power[i-1]*p)%mod;
}
int compute_hash(string str,int p,int mod)
{
    ll hash_value = 0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value+(str[i]-'a'+1)*p_power[i])%mod;
        prefix_hash[i]=hash_value;
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
int main()
{
    ll p1=29;
    ll mod1=1e9+7;
    pre_compute_power(p1,mod1);
    string a;
    cin>>a;
    ll h1=compute_hash(a,p1,mod1);
    ///substring hash
    int pos_from,pos_to;///1 indexing
    cin>>pos_from>>pos_to;;
    int dif=pos_to-pos_from+1;
    pos_to--;
    pos_from-=2;
    ll to_hash=prefix_hash[pos_to];
    //cout<<to_hash<<" "<<prefix_hash[pos_from]<<" "<<BigMod(p1,dif,mod1)<<endl;
    ll from_hash=prefix_hash[pos_from];//*BigMod(p1,dif,mod1))%mod1;
    //cout<<from_hash<<endl;
    pos_from++;
    ll substring_hash_value=(((to_hash-from_hash)%mod1)*(BigMod(p1,mod1-1-pos_from,mod1)%mod1))%mod1;;
    cout<<substring_hash_value<<endl;
}
