#include <iostream> 

using namespace std;

template <class T>
inline void myswap(T& a, T& b)
{
	T temp=a;
	a=b;
	b=temp;
}

int main()
{
	double a=5.1, b=8.7;
	bitset<sizeof(double) * CHAR_BIT> ab(a), bb(b); //sizeof() returns bytes, not bits!
	cout << "0: a=" << ab << ", b=" << bb << endl;
	cout << "0: a=" << a << ", b=" << b << endl;
	myswap(a,b);
	ab=a;
	bb=b;
	cout << "1: a=" << ab << ", b=" << bb << endl;
	cout << "2: a=" << a << ", b=" << b << endl;

	return 0;
}
