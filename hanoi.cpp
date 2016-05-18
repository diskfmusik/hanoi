#include <stdio.h>

const int poleSize = 7; // ‰~”Õ‚Ì”

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


void Sort(int _from[], int _to[])
{
	int temp = *_from;
	*_from = *_to;
	*_to = temp;
}


void Move(int _from[], int _to[], int _other[], int _moveNum, int _startNum)
{

	if (_moveNum < 1)
	{
		return;
	}
	else if (_moveNum == 1)
	{
		// to ‚Ìˆê”Ô‰º‚É’u‚­‰~”Õ
		Sort(&_from[poleSize - 2], &_to[poleSize - 1]);

		/* other ‚É”ğ‚¯‚Ä‚¢‚½‰~”Õ‚ğ to ‚É–ß‚· */
		for (int i = 0; i < _startNum - 1; i++)
		{
			Sort(&_other[2 + i], &_to[(poleSize - 2) - i]);
		}
	}
	else
	{
		int fromSize = GetSizeInPole(_from);
		//printf("%d\n", fromSize);

		// 0 ‚Í ‚ ‚è“¾‚È‚¢i“n‚¹‚é‚à‚Ì‚ª–³‚¢‚©‚çj
		int fromIndex = poleSize - fromSize;


		int otherSize = GetSizeInPole(_other);
		//printf("%d\n", toSize);

		int otherIndex = poleSize - otherSize;
		--otherIndex; // —v‘f”‚Æ‚µ‚Äˆµ‚¤ˆ×


		Sort(&_from[fromIndex], &_other[otherIndex]);


		Move(_from, _to, _other, _moveNum - 1, _startNum);
	}

} // void Move(int _from[], int _to[], int _other[], int _moveNum, int _startNum)


void main()
{
	// ‰~”Õ‚Ì‰ŠúÀ•W
	for (int i = 0; i < poleSize; i++)
	{
		a[i] = i + 1;
	}
	Draw();
	getchar();


	Move(a, b, c, poleSize - 1, poleSize - 1);
	Draw();
	getchar();

	Sort(&a[poleSize - 1], &c[poleSize - 1]);
	Draw();
	getchar();


	Move(b, a, c, poleSize - 2, poleSize - 2);
	Draw();
	getchar();

	Sort(&b[poleSize - 1], &c[poleSize - 2]);
	Draw();
	getchar();


	// ‚±‚ê‚Å‚¢‚¢‚Ì‚©H
#if 1
	for (int i = 0; i < poleSize - 2; i++)
	{
		Sort(&a[(poleSize - 1) - i], &c[(poleSize - 3) - i]);
	}
	Draw();
	getchar();
#endif

#if 0 // ????
	//Move(a, c, b, poleSize - 3, poleSize - 3);
	//Draw();
	//getchar();
#endif


	getchar();
}