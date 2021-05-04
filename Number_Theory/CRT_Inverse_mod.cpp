ll BigMod(ll base,ll power,ll mod)
{
    if(power==0)
        return 1;
    if(power%2==1)
        return (base%mod)*(BigMod(base,power-1,mod)%mod)%mod;
    else
    {
        ll res = (BigMod(base,power/2,mod)%mod);
        return (res*res)%mod;
    }
}
ll CRT(ll div[],ll rem[],ll n,ll P)
{
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll val=P/div[i];
        ll inv=BigMod(val,div[i]-2,div[i]);
        ans+=(rem[i]*val*inv)%P;
        ans%=P;
    }
    return ans;
}
