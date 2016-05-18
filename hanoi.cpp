#include <stdio.h>

const int poleSize = 3; // 円盤の数

int a[poleSize];
int b[poleSize];
int c[poleSize];


// 現在、棒に何枚の円盤があるか？
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
	for (int y = 0; y < poleSize; y++)
	{
		printf("%d  %d  %d\n", a[y], b[y], c[y]);
	}
}


void Sort(int _from[], int _to[])
{
	int temp = *_from;
	*_from = *_to;
	*_to = temp;
}


void Move(int _from[], int _to[], int _other[], int _num)
{

	if (_num < 1)
	{
		return;
	}
	else if (_num == 1)
	{
		/* 真ん中に持っていくやつ */
		Sort(&_from[poleSize - 2], &_to[poleSize - 1]);

		/* other に避けていた円盤を to に戻す */
		for (int i = 0; i < poleSize - 2; i++)
		{
			Sort(&_other[2 + i], &_to[(poleSize - 2) - i]);
		}
	}
	else
	{
		int fromSize = GetSizeInPole(_from);
		//printf("%d\n", fromSize);

		// 0 は あり得ない（渡せるものが無いから）
		int fromIndex = poleSize - fromSize;


		int otherSize = GetSizeInPole(_other);
		//printf("%d\n", toSize);

		int otherIndex = poleSize - otherSize;
		--otherIndex; // 要素数として扱う為


		Sort(&_from[fromIndex], &_other[otherIndex]);


		Move(_from, _to, _other, _num - 1);
	}

} // void Move(int _from[], int _to[], int _other[], int _num)


void main()
{
	// 円盤の初期座標
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = i + 1;
	}


	Draw();
	getchar();


	Move(a, b, c, poleSize - 1);
	Draw();
	getchar();

	/* 一番下の円盤 */
	Sort(&a[poleSize - 1], &c[poleSize - 1]);
	Draw();
	getchar();


	//Move(b, a, c, poleSize - 2);
	//Draw();
	//getchar();



	getchar();
}