#include "GraphMatrix.h"
#include "GraphList.h"
#include<iostream>
#include<vector>

using namespace std;

void testMatrix()
{
	int num = 10;
	vector<int> v(10);
	for (int i = 0; i < 10; ++i) v[i] = num++;

	//for (auto x : v) cout << x << ' ' << endl;

	Matrix<int, int> gh(v.data(), 10);

	gh.AddEdge(10, 11, 1);
	gh.AddEdge(10, 12, 2);
	gh.AddEdge(10, 13, 3);
	gh.AddEdge(10, 14, 4);
	gh.AddEdge(10, 15, 5);
	gh.AddEdge(10, 16, 6);
	gh.AddEdge(11, 12, 7);
	gh.AddEdge(11, 13, 7);
	gh.AddEdge(11, 14, 7);
	gh.AddEdge(11, 15, 7);
	gh.AddEdge(11, 16, 7);
	gh.AddEdge(11, 17, 7);
	gh.AddEdge(11, 18, 7);
	gh.AddEdge(11, 19, 7);

	gh.Print();
	cout << endl;
	gh.bfs(0);
	cout << endl;
}

void testLink()
{
	LinkGraph<int, int>().TestLinkGraph();
}

int main()
{
	testMatrix();
	testLink();

	return 0;
}