/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;    

int n;

void solve(string res,int w,int l)
{
    if(w==n || l==n)
    {
        cout << res << endll;
        return ;
    }
    else 
    {
        if(w+1<=n) 
            res+="W ";
        solve(res,w+1,l);
        res.erase(res.length()-2,2);
        if(l+1<=n) 
            res+="L ";
        solve(res,w,l+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int w,l;
    cin >> n >> w >> l;

    string res;
    solve(res,w,l);

    return 0;

}