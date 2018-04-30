#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
struct _pair
{
    double x, y;
    _pair(double a = 0, double b = 0){ x = a, y = b; }
    bool operator < (const _pair c)const { return x < c.x; }
}que[1000 + 5];
int head = 0, tail = 0;
int n, R, T, ans;
bool flag;
inline void _push(_pair v){ que[tail] = v; tail++; }
inline void _pop(){ head++; }
bool judge(_pair &t, _pair v)   //�ж��Ƿ��н���������и��½���t
{
    if (!(t.x > v.y || t.y < v.x))
    {
        t.x = min(t.x, v.x);
        t.y = min(t.y, v.y);
        return true;
    }
    return false;
}
int main()
{
    while (scanf("%d%d", &n, &R))
    {
        if (!n&&!R) break;
        T++;
        ans = flag = head = tail = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (b > R) flag = 1;         //����޷��������������flag=1
            _push(_pair(a - sqrt((double)R*R - b*b), a + sqrt((double)R*R - b*b)));
        }
        if (flag) printf("Case %d: -1\n",T);
        else
        {
            sort(que, que + n);
            while (head != tail)
            {
                ans++;
                _pair t = que[head];    //������ʼ��Ϊ��һ������
                while (head != tail)
                {
                    _pair v = que[head];
                    if (judge(t, v)) _pop();   //�н����ͳ���
                    else break;
                }
            }
            printf("Case %d: %d\n", T, ans);
        }
    }
    return 0;
}
//
