#include "pch.h"

TEST(TestSortare, TestElementeSortate)
{
	int elemente[100] = { -1, 372783, 677, 0 };
	int nrElem = 4, i;
	int copie_elem[100];
	for (i = 0; i < nrElem; i++)
		copie_elem[i] = elemente[i];
	sortElemente<int>(elemente, nrElem);
	for ( i = 0; i < nrElem-1; i++)
	{
		ASSERT_LE(elemente[i], elemente[i + 1]);
	}
	for (i = 0; i < nrElem; i++)
	{
		ASSERT_EQ(elemente[i], copie_elem[i]);
	}

}