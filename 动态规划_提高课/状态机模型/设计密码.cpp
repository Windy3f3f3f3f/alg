#include <bits/stdc++.h>

using namespace std;
const int N = 55, mod = 1e9+7;
int n, m;
char t[N];
int ne[N];
int f[N][N];
int main(){
    cin >> n >>t+1; // t[1]开始
    m = strlen(t+1); // 这是真len
    // s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
    // 求模式串的Next数组：
    for (int i = 2, j = 0; i <= m; i ++ )
    {
        while (j && t[i] != t[j + 1]) j = ne[j];
        if (t[i] == t[j + 1]) j ++ ;
        ne[i] = j;
    }
    f[0][0] = 1;
    // 匹配
    for (int i = 0; i < n; i ++ ){//每一个n
        for(int j = 0; j < m ; j ++){//每一个m
            //每一个m其实有a-z个可能的输入
            for(char k='a';k<='z';k++){
                int u = j;
                while(u && k!=t[u+1]) u=ne[u];
                if(k==t[u+1]) f[i+1][u+1] = (f[i+1][u+1]+f[i][j]) % mod; //如果还能接着匹配，则匹配，这里u要+1
                else if(u==0){
                    f[i+1][u] = (f[i+1][u]+f[i][j]) % mod; //如果失配，则这个失配状态可以转移过去了
                }
            }
        }
    }
    int res = 0;
    for(int i=0; i<m;i++) res=(res+f[n][i])%mod;
    cout<<res<<endl;
    return 0;
}
