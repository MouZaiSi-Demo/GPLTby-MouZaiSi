/*****************************
L1-006 连续因子 (20分)
一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2
​31
​​ ）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630
输出样例：
3
5*6*7


*******************************/


#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main() {
    cin >> num;
    int first = 0, len = 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
        int j; temp = 1;
        for (j = i; j <= sqrt(num); j++)//找那可爱的长串串因子
        {
            temp *= j;
            if (num % temp != 0) break;//不是因子就退出这无尽硝烟
        }
        if (j - i > len) //看看这个串串是不是最长的
        {
            len = j - i;
            first = i;
        }
    }
    if (first == 0) cout << 1 << endl << num;//如果是素数就 啪得一下输出
    else //否则按照题意老实点咯
    {
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}