/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
#define mod 1000000007
#define st first
#define nd second
#define pr pair<int,int>
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
char g[2003][2003];
bool vis[2003][2003];
int n,m,co=0;
int dx[]={-1,0,1,0,1,1,-1,-1,};
int dy[]={0,1,0,-1,1,-1,-1,1};

bool isValid(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||g[i][j]=='0') 
        return 0;
    return !vis[i][j];
}

/*void DFS(int i,int j)
{
    
    vis[i][j]=1;
    for(int k=0;k<8;k++)
    {
        if(isValid(i+dx[k],j+dy[k]))
            DFS(i+dx[k],j+dy[k]);
    }
}*/
void DFS(int i,int j)
{
    stack<pr> s;
    s.push({i,j});
    vis[i][j] = 1;
    while(!s.empty())
    {
        int x = s.top().st;
        int y = s.top().nd;
        s.pop();

        for(int i=0;i<8;i++)
        {
            if(isValid(x+dx[i],y+dy[i]))
            {
                s.push({x+dx[i],y+dy[i]});
                vis[x+dx[i]][y+dy[i]] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> g[i][j];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='1' && !vis[i][j]){
                DFS(i,j); co++;}
        }
    }
    cout << co;

    return 0;

}
/*
4 4
1 0 0 0
0 0 0 1
0 0 1 1
1 0 0 1
*/