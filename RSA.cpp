#include"RSA.h"

int candp(int a, int b, int c)        //数据处理函数，实现幂的取余运算
{
	int r = 1;
	b = b + 1;
	while (b != 1)
	{
		r = r * a;
		r = r % c;
		b--;
	}
	return r;
}
int fun(int x, int y)               //公钥e与t的互素判断
{
	int t;
	while (y)
	{
		t = x;
		x = y;
		y = t % y;
	}
	if (x == 1)
		return 0;                          //x与y互素时返回0
	else
		return 1;                          //x与y不互素时返回1
}