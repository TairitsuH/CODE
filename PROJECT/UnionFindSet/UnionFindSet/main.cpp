#include<iostream>
#include "UnionFindSet.hpp"
using namespace std;

int main()
{
	UnionFindSet ufs(10);

	ufs.Union(1, 4);
	ufs.Union(1, 9);
	ufs.Union(2, 3);
	ufs.Union(2, 5);
	ufs.Union(0, 6);
	ufs.Union(0, 7);
	ufs.Union(0, 8);
	ufs.Union(0, 1);

	ufs.Print();

	return 0;
}