#include <stdio.h>

const int poleSize = 3; // ‰~”Õ‚Ì”

int a[poleSize];
int b[poleSize];
int c[poleSize];


// Œ»İA–_‚É‰½–‡‚Ì‰~”Õ‚ª‚ ‚é‚©H
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
	else
	{
		int fromSize = GetSizeInPole(_from);
		//printf("%d\n", fromSize);

		// 0 ‚Í ‚ ‚è“¾‚È‚¢i“n‚¹‚é‚à‚Ì‚ª–³‚¢‚©‚çj
		int fromIndex = poleSize - fromSize;


		int otherSize = GetSizeInPole(_other);
		//printf("%d\n", toSize);

		int toIndex = poleSize - otherSize;
		--toIndex; // —v‘f”‚Æ‚µ‚Äˆµ‚¤ˆ×


		int temp = _from[fromIndex];
		_from[fromIndex] = _other[toIndex];
		_other[toIndex] = temp;


		Move(_from, _to, _other, _num - 1);
	}

} // void move(int _from[], int _to[], int _num)


void main()
{
	// ‰~”Õ‚Ì‰ŠúÀ•W
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = i + 1;
	}


	Draw();
	getchar();


	Move(a, b, c, 2);
	Draw();
	getchar();


	getchar();
}