#include <bits/stdc++.h>
using namespace std;

#define nn   "\n"
#define ll   long long
#define ull  unsigned long long
#define yes  cout<<"YES\n"
#define no   cout<<"NO\n"
#define mod  1000000007

ll dp[101][100001];
//memoisation
ll knapsnack(ll* w,ll* v,ll n,ll mw)
{
    if(dp[n][mw]>-1) return dp[n][mw];
    if(n==0) return 0;//no item left
    if(mw==0) return 0;//no more capacity
    ll op1 = knapsnack(w,v,n-1,mw);
    ll op2 = LLONG_MIN;
    if(w[n-1]<=mw) op2 = v[n-1]+knapsnack(w,v,n-1,mw-w[n-1]);
    return dp[n][mw]=max(op1,op2);
}
//tabulation
ll knapsnacki(ll* w,ll* v,ll n,ll mw)
{
    ll i,j;
    for(i=0; i<=mw; i++) dp[0][i]=0;
    for(i=0; i<=n; i++) dp[i][0]=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=mw; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(w[i-1]<=j) dp[i][j] = max(dp[i][j],v[i-1]+dp[i-1][j-w[i-1]]);
        }
    }
    return dp[n][mw];
}
//tabulation memory optimised
ll knapsnacki2(ll &w,ll &v,ll n,ll mw)
{
    ll i,j;
    ll dp2[2][mw+1];
    for(i=0; i<=mw; i++) dp2[0][i]=0;
    dp2[1][0]=0;
    ll idx=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=mw; j++)
        {
            dp2[idx][j] = dp2[idx^1][j];
            if(w[i-1]<=j) dp2[idx][j] = max(dp2[idx][j],v[i-1]+dp2[idx^1][j-w[i-1]]);
        }
        idx^=1;
    }
    return dp2[idx^1][mw];
}
//for large weights
ll dpi3[100001][101];
ll knapsnacki3(ll &w,ll &v,ll n,ll mw)
{
    ll i,j;
    for(i=0; i<=n; i++) dpi3[0][i]=0;
    for(i=1; i<=100000; i++) dpi3[i][n]=mw+1;
    for(i=1; i<=100000; i++)
    {
        for(j=n-1; j>=0; j--)
        {
            dpi3[i][j] = dpi3[i][j+1];
            if(i-v[j]>=0) dpi3[i][j] = min(dpi3[i][j],w[j]+dpi3[i-v[j]][j+1]);
        }
    }
    ll ans = 0;
    for(i=0; i<=100000; i++) if(dpi3[i][0]>0&&dpi3[i][0]<=mw) ans = max(ans,i);
    return ans;
}
void solve()
{
    ll i,j,n,mw;
    cin>>n>>mw;
    ll w[n];
    ll v[n];
    for(i=0; i<=n-1; i++)
    {
        cin>>w[i]>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsnacki3(w,v,n,mw)<<endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	ll t;
	t=1;//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


