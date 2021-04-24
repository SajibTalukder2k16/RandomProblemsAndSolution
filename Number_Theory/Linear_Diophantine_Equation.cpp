#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mx 1000005
int val_x,val_y;
int ext_gcd(int a,int b)
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
bool LinearDiophantineEquation(int a,int b,int c)
{
    int g=__gcd(a,b);
    if(c%g)
        return false;
    a/=g;
    b/=g;
    c/=g;
    ext_gcd(a,b);
    if(g<0)
        val_x*=-1,val_y*=-1,c*=-1;
    val_x*=c,val_y*=c;
    return true;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    LinearDiophantineEquation(a,b,c);
    cout<<val_x<<" "<<val_y<<endl;
}
