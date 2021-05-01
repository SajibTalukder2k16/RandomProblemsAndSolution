#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000005
int ext_gcd(int a,int b,int &val_x,int &val_y)
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
    int x1=1,y1=0;
    int x2=0,y2=1;
    int r1=a;
    int r2=b;
    int xi,yi,ri,qi;
    while(r1%r2!=0)
    {
        ri=r1%r2;
        qi=r1/r2;
        xi=x1-qi*x2;
        yi=y1-qi*y2;
        r1=r2;r2=ri;
        x1=x2;x2=xi;
        y1=y2;y2=yi;
        //cout<<qi<<" "<<ri<<" "<<xi<<" "<<yi<<endl;
    }
    //cout<<x2<<" "<<y2<<" "<<r2<<endl;
    val_x=x2;
    val_y=y2;
    if(a_sign==false)
        val_x=-val_x;
    if(b_sign==false)
        val_y=-val_y;
    if(s==true)
        swap(val_x,val_y);
    return r2;
}
int main()
{
    int n;
    cin>>n;
    int rem[n],mod[n];
    for(int i=0;i<n;i++)
        cin>>mod[i]>>rem[i];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        ext_gcd(mod[i],mod[i+1],x,y);
        ll temp=mod[i]*x*rem[i+1]+mod[i+1]*y*rem[i];
        mod[i+1]=mod[i]*mod[i+1];
        temp%=mod[i+1];
        rem[i+1]=temp;
        //cout<<mod[i]<<" "<<mod[i+1]<<" "<<rem[i]<<" "<<rem[i+1]<<" "<<temp<<endl;
    }
    cout<<rem[n-1]<<endl;
}
