#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 5010;
typedef struct tab_ele{
    //int start; //新添加的卡牌只会开销越来越大，不用考虑开头变了的情况
    int end;
    int value;
    int chosen_num;
}tab_ele;
tab_ele f[N][N];
typedef struct card{
    int cost;
    int value;
}card;
card cards[N];

bool cmp(card a,card b)
{
    return a.cost<b.cost;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>cards[i].value>>cards[i].cost;
    }
    sort(cards+1,cards+n+1,cmp);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<cards[i].cost<<" ";
    // }
    for(int i=1;i<=n;i++)
    {
        //f[i][1].start=cards[i].cost;
        f[i][1].end=cards[i].cost;
        f[i][1].value=cards[i].value;
        f[i][1].chosen_num=1;
    }
    for(int i=1;i<=k;i++)
    {
        //f[1][i].start=cards[i].cost;
        f[1][i].end=cards[i].cost;
        f[1][i].value=cards[i].value;
        f[1][i].chosen_num=1;   //已选一张卡牌
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i&&j<=k;j++)
        {
            if( (f[i-1][j-1].value-(cards[i].cost-f[i-1][j-1].end)+cards[i].value > f[i-1][j].value) ||  (f[i-1][j].chosen_num<j) )   //有利可图或者根本没填满
            {
                f[i][j].value=f[i-1][j-1].value-(cards[i].cost-f[i-1][j-1].end)+cards[i].value;
                f[i][j].end=cards[i].cost;
                f[i][j].chosen_num=f[i-1][j].chosen_num+1;  //直接加1，超了不用管
            }
            else    //继承上面的信息
            {
                f[i][j]=f[i-1][j];
            }
        }
    }
    // cout<<"\ntest\n";
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=k;j++)
    //     {
    //         cout<<f[i][j].chosen_num<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<f[n][k].value;
    return 0;
}
/*
5 5
1 5
2 4
3 3
4 2
5 1

5 2
1 5
2 4
3 3
4 2
5 1
*/
