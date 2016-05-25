#include <stdio.h>

const int poleSize = 3; // �~�Ղ̐�

int a[poleSize];
int b[poleSize];
int c[poleSize];


// ���݁A�_�ɉ����̉~�Ղ����邩�H
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
	int temp = *_from;
	*_from = *_to;
	*_to = temp;
}


void Move(int _from[], int _to[], int _work[], int _n)
{

	if (_n < 1)
	{
		return;
	}
	else if (_n == 1)
	{
		int fromSize = GetSizeInPole(_from);
		--fromSize;
		//printf("%d\n", fromSize);

		int toSize = GetSizeInPole(_to);

		Swap(&_from[fromSize], &_to[toSize]);

		Draw();
	}
	else
	{
		Move(_from, _work, _to, _n - 1);


		int fromSize = GetSizeInPole(_from);
		--fromSize;
		//printf("%d\n", fromSize);


		int toSize = GetSizeInPole(_to);


		Swap(&_from[fromSize], &_to[toSize]);


		Draw();


		Move(_work, _to, _from, _n - 1);
	}

} // void Move(int _from[], int _to[], int _work[], int _n)


void main()
{
	// �~�Ղ̏������W
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = poleSize - i;
	}
	Draw();
	getchar();


	Move(a, c, b, poleSize);
	getchar();


	getchar();
}