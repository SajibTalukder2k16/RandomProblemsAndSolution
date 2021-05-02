ll CRT(ll div[],ll rem[],int n)
{
    vector<pair<ll,ll> >vec(n);
    for(int i=0;i<n;i++)
    {
        vec.push_back(mp(-rem[i],div[i]));
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++)
    {
        vec[i].first=vec[i].first*(-1);
    }
    ll ans=vec[0].first;
    ll dv=vec[0].second;
    for(int i=1;i<n;i++)
    {
        ll limit=vec[i].second;
        ll remainder=vec[i].first;
        ll val=-1;
        for(int j=0;j<=limit;j++)
        {
            if(((j*dv+ans)%limit)==remainder)
            {
                val=j;
                break;
            }
        }
        ans=dv*val+ans;
        dv=dv*limit;
    }
    return ans;
}
