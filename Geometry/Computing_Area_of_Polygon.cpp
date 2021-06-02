#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
struct point
{
    int x,y;
};
double areaOfPolygon(point ara[],int n)
{
    double area=0;
    for(int i=1;i<n-1;i++)
    {
        int x1=ara[i].x-ara[0].x;
        int y1=ara[i].y-ara[0].y;
        int x2=ara[i+1].x-ara[0].x;
        int y2=ara[i+1].y-ara[0].y;
        area+=x1*y2-x2*y1;
    }
    return abs(area)/2;
}
int main()
{
    int no_of_points;
    cin>>no_of_points;
    point ara[no_of_points];
    for(int i=0;i<no_of_points;i++)
    {
        cin>>ara[i].x>>ara[i].y;
    }
    cout<<areaOfPolygon(ara,no_of_points)<<endl;
}
