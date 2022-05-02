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
string t;

void solve(int d)
{
    if(d==n)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(t[i] == '0'){
                cout << t << ' ';
                t[i] = '1' ;
                cout << t << endll;
                t[i] = '0' ;
            }
        } return;
    }
    t+='0';
    solve(d+1);
    t.pop_back();
    t+='1';
    solve(d+1);
    t.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    solve(0);
    
    return 0 ;
}