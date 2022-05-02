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
char g[1001][1001];
bool vis[1001][1001];
int n,m,lv=1;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
bool ch=0;

bool isValid(int x,int y,int px,int py)
{
    if(x<1||y<1||x>n||y>m||g[x][y]=='N') 
        return 0;
    if((px != x || py !=y) && vis[x][y]) return ch=1;
    return !vis[x][y];
}

void out (queue<pair<pr,pr>> q)
{
    while(!q.empty())
    {
        cout << q.front().st.st << " " << q.front().st.nd << " :" << q.front().nd.st << " " << q.front().nd.nd << endll;
        q.pop();
    }
}
void BFS(int srcx,int srcy)
{
    queue<pair<pr,pr>> q;
    q.push({{srcx,srcy},{0,0}});
    vis[srcx][srcy]=1;

    while(!q.empty())
    {
        int qs = q.size();
        lv++;
        while(qs--){
            int x = q.front().st.st;
            int y = q.front().st.nd;
            //cout << x << " " << y << " :" << q.front().nd.st << " " << q.front().nd.nd << endll;
            int px = q.front().nd.st;
            int py = q.front().nd.nd;

            /*out (q);
            cout << endll;*/
            q.pop();
            
            if(g[x][y]=='B')
            {
                for(int i=0;i<4;i++)
                { 
                    if(isValid(x+dx[i],y+dy[i],px,py))
                    {
                        if(ch)
                        {
                            cout << lv << endll << x+dx[i] << " " << y+dy[i];
                            return;
                        }
                        q.push({{x+dx[i],y+dy[i]},{x,y}});
                        vis[x+dx[i]][y+dy[i]] =1;
                        //cout << x+dx[i] << " " << y+dy[i] << endll;
                    }
                }
            } else if(g[x][y]=='R')
            {
                if(isValid(x,y+1,px,py))
                {
                    if(ch)
                    {
                        cout << lv << endll << x << " " << y+1;
                        return;
                    }
                    q.push({{x,y+1},{x,y}});
                    vis[x][y+1] =1;
                    //cout << x << " " << y+1 << endll;
                }
            } else if(g[x][y]=='D')
            {
                if(isValid(x+1,y,px,py))
                {
                    if(ch)
                    {
                        cout << lv << endll << x+1 << " " << y;
                        return;
                    }
                    q.push({{x+1,y},{x,y}});
                    vis[x+1][y] =1;
                    //cout << x+1 << " " << y << endll;
                }
            }
            g[x][y]='*';
            //cout << endll;
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << g[i][j] << " ";
            }
            cout << endll;
        }
        cout << endll;*/

    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> g[i][j];
    memset(vis,0,sizeof(vis));
    BFS(1,1);

    return 0;

}