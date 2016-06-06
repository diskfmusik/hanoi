#include <stdio.h>

const int poleSize = 5;

int a[poleSize];
int b[poleSize];
int c[poleSize];

const int GetSizeInPole(const int _ary[])
{
	int num = 0;

	for (int i = 0; i < poleSize; i++)
	{
		if (_ary[i] > 0) ++num;
	}
	return num;
}

void Draw()
{
	for (int y = poleSize - 1; y >= 0; y--)
	{
		printf("%d  %d  %d\n", a[y], b[y], c[y]);
	}
	printf("\n");
}

void Swap(int _from[], int _to[])
{
	int fromSize = GetSizeInPole(_from);
	--fromSize;

	int toSize = GetSizeInPole(_to);

	int temp = _from[fromSize];
	_from[fromSize] = _to[toSize];
	_to[toSize] = temp;
}

void Move(int _from[], int _to[], int _work[], int _n)
{
	if (_n < 1)
	{
		return;
	}
	else if (_n == 1)
	{
		Swap(_from, _to);
		Draw();
	}
	else
	{
		Move(_from, _work, _to, _n - 1);
		Swap(_from, _to);
		Draw();
		Move(_work, _to, _from, _n - 1);
	}
}

void main()
{
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = poleSize - i;
	}
	Draw();
	getchar();

	Move(a, c, b, poleSize);
	getchar();
}