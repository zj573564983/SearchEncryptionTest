#include"RSA.h"

int candp(int a, int b, int c)        //���ݴ�������ʵ���ݵ�ȡ������
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
int fun(int x, int y)               //��Կe��t�Ļ����ж�
{
	int t;
	while (y)
	{
		t = x;
		x = y;
		y = t % y;
	}
	if (x == 1)
		return 0;                          //x��y����ʱ����0
	else
		return 1;                          //x��y������ʱ����1
}