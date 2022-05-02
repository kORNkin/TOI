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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long m , n , l = 1 , r = 1e12 ; cin >> m >> n ;
    ll arr[m];
    for(int i = 0 ; i < m ; i ++ )cin >> arr[i] ;
    while(l < r){
        
        long long sum = 0 ;
        long long mid = (l + r) >> 1 ;
        for(int i = 0 ; i < m ; i ++ )sum += mid / arr[i] ;
        if(sum >= n)r = mid ;
        else l = mid + 1 ;

        cout << sum << " " << l << " " << mid << " " << r << endll;
    }
    cout << l ;   

    return 0;

}