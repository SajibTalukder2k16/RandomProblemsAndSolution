#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000005
ll ext_gcd(ll a,ll b,ll *val_x,ll *val_y)
{
    bool a_sign=true,b_sign=true;
    if(a<0)
    {
        a=-a;
        a_sign=false;
    }
    if(b<0)
    {
        b=-b;
        b_sign=false;
    }
    bool s=false;
    if(b>a)
    {
        swap(a,b);
        s=true;
    }
    ll x1=1,y1=0;
    ll x2=0,y2=1;
    ll r1=a;
    ll r2=b;
    ll xi,yi,ri,qi;
    while(r1%r2!=0)
    {
        ri=r1%r2;
        qi=r1/r2;
        xi=x1-qi*x2;
        yi=y1-qi*y2;
        r1=r2;r2=ri;
        x1=x2;x2=xi;
        y1=y2;y2=yi;
    }
    *val_x=x2;
    *val_y=y2;
    if(a_sign==false)
        *val_x=-*val_x;
    if(b_sign==false)
        *val_y=-*val_y;
    if(s==true)
        swap(*val_x,*val_y);
    return r2;
}
int main()
{
    int n;
    cin>>n;
    ll rem[n],mod[n];
    for(int i=0;i<n;i++)
        cin>>mod[i]>>rem[i];
    ll a1 = rem[0];
    ll m1 = mod[0];
    ll p, q;
    for(int i=1;i<n;i++)
    {
        ll a2 = rem[i];
        ll m2 = mod[i];
        ext_gcd(m1, m2, &p, &q);
        ll val=m1*m2;
        ll x = ((((a1%val)*(m2%val))%val*q%val)%val + (((a2%val)*(m1%val))%val*p%val)%val) % (val);
        a1 = x;
        m1 = m1 * m2;
    }
    if (a1 < 0) a1 += m1;
    cout<<a1<<endl;
}
