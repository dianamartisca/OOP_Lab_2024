#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
	Array<int> v(10);
	v += 4;
	v += 5;
	v += 6;
	Array<int> w(v);
	w.Print();
	v.Insert(0, 3);
	v.Print();
	w.Insert(1, v);
	w.Print();
	w.Delete(0);
	w.Delete(w.GetSize());
	if (v == w)
		cout << "v este egal cu w\n";
	else
		cout << "v nu este egal cu w\n";
	Array<int> t(14);
	t += 3; t += 1; t += 6;
	cout << t.BinarySearch(1, compare) << '\n';
	t.Print();
	cout << t.Find(6, compare);
	ArrayIterator<int> it;
	for (it = v.GetBeginIterator(); it != v.GetEndIterator(); ++it)
		cout << it.GetElement() << ' ';
}