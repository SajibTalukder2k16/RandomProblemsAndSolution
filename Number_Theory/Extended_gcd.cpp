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
    return r2;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int g=ext_gcd(a,b);
    cout<<val_x<<" "<<val_y<<" "<<g<<endl;
}
