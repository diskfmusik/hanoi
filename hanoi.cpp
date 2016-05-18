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
	for (int y = 0; y < poleSize; y++)
	{
		printf("%d  %d  %d\n", a[y], b[y], c[y]);
	}
}


void Move(int _from[], int _to[], int _other[], int _num)
{

	if (_num < 1)
	{
		return;
	}
	else if (_num == 1)
	{
		/* �^�񒆂Ɏ����Ă������ */
		int temp = _from[poleSize - 2];
		_from[poleSize - 2] = _to[poleSize - 1]/* 0 */;
		_to[poleSize - 1] = temp;

		/* other �ɔ����Ă����~�Ղ� to �ɖ߂� */
		for (int i = 0; i < poleSize - 2; i++)
		{
			int temp = _other[2 + i];
			_other[2 + i] = _to[(poleSize - 2) - i];
			_to[(poleSize - 2) - i] = temp;
		}
	}
	else
	{
		int fromSize = GetSizeInPole(_from);
		//printf("%d\n", fromSize);

		// 0 �� ���蓾�Ȃ��i�n������̂���������j
		int fromIndex = poleSize - fromSize;


		int otherSize = GetSizeInPole(_other);
		//printf("%d\n", toSize);

		int otherIndex = poleSize - otherSize;
		--otherIndex; // �v�f���Ƃ��Ĉ�����


		int temp = _from[fromIndex];
		_from[fromIndex] = _other[otherIndex];
		_other[otherIndex] = temp;


		Move(_from, _to, _other, _num - 1);
	}

} // void move(int _from[], int _to[], int _num)


void main()
{
	// �~�Ղ̏������W
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = i + 1;
	}


	Draw();
	getchar();


	Move(a, b, c, poleSize - 1);
	Draw();
	getchar();


	getchar();
}