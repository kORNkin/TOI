/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define mod 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
int n;
string s;
bool dp[256][256][3],vis[256][256][3];

bool solve(int l,int r,int x)
{
    if(vis[l][r][x])
        return 1;

    if(l==r)
    {
        if(s[l]==x+'0')
            dp[l][r][x] = 1;
        vis[l][r][x] = 1;
        return dp[l][r][x];
    }

    for(int k=l;k<r;k++)
    {
        
        if(x==0)
        {
            if(solve(l,k,0) && solve(k+1,r,2)) {dp[l][r][x] = 1;break;}
        }
        else if(x==1)
        {
            if(solve(l,k,0) && solve(k+1,r,1)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,1) && solve(k+1,r,1)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,1) && solve(k+1,r,2)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,2) && solve(k+1,r,0)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,2) && solve(k+1,r,2)) {dp[l][r][x] = 1;break;}
        }
        else if(x==2)
        {
            if(solve(l,k,0) && solve(k+1,r,0)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,1) && solve(k+1,r,0)) {dp[l][r][x] = 1;break;}
            if(solve(l,k,2) && solve(k+1,r,1)) {dp[l][r][x] = 1;break;}
        }
    }
    return dp[l][r][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=20;
    while(t--)
    {
        cin >> n >> s;

        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        if(solve(0,n-1,0) == true)
            cout << "yes\n";
        else cout << "no\n";
    }


    return 0;

}