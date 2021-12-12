#include "my.h"
#include "std_lib_facilities.h"



void print_foo()
{
	cout << foo << '\n';
}

void print(int i)
{
	cout << i << '\n';
}

void swap_v(int a, int b)
{
	int temp;
	temp = a, a = b;
	b = temp;
	std::cout << "Swapped using swap_v()\n";
	std::cout << "a:" << a << " b:" << b << '\n';
}

int swap_r(int& a, int& b)
{
	int temp;
	temp = a, a = b;
	b = temp;
	return a, b;
}

//void swap_cr(const int& a, const int& b)
//{
//	int temp;
//	temp = a, a = b;
//	b = temp;
//}