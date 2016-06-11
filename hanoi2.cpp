#include <stdio.h>
#include <string>

void swap(std::string _from, std::string _to)
{
	printf("%s ‚©‚ç %s ‚Ö\n", _from.c_str(), _to.c_str());
	std::string temp = _from;
	_from = _to;
	_to = temp;
}

void move(std::string _from, std::string _work, std::string _to, int _n)
{
	if (_n > 1) move(_from, _to, _work, _n - 1);

	swap(_from, _to);

	if (_n > 1) move(_work, _from, _to, _n - 1);
}

void main()
{
	move("a", "b", "c", 3);
	getchar();
}