#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
int compute_hash(string str,int p,int mod)
{
    ll hash_value = 0;
    int p_power = 1;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        hash_value=(hash_value+(str[i]-'a'+1)*p_power)%mod;
        p_power=p;
    }
    return hash_value;
}
int main()
{
    ll p1=29;
    ll mod1=1e9+7;
    ll p2=31;
    ll mod2=1e9+9;
    string a,b;
    cin>>a>>b;
    ll h1=compute_hash(a,p1,mod1);
    ll h2=compute_hash(b,p1,mod1);
    ll h3=compute_hash(a,p2,mod2);
    ll h4=compute_hash(b,p2,mod2);
    if(h1==h2 && h3==h4)
    {
        int n=a.length();
        int m=b.length();
        if(n!=m)
            cout<<"NO"<<endl;
        else
        {
            bool chk = true;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=b[i])
                    chk=false;
            }
            if(chk==false)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
}
