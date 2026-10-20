#pragma once
#include<vector>
#include<map>
#include<iostream>
#include<climits>
#include<queue>
using namespace std;


//value(vertex), weight(edge)
template<class V, class W, W W_MAX = INT_MAX, bool Direction = false>
class Matrix
{
private:
	vector<V> _vertexs; //顶点
	map<V, size_t> _vertexmap; //顶点和数组下标的映射关系
	vector<vector<W>> _edge; //邻接矩阵

public:
	Matrix() = default; //默认生成

	Matrix(const V* vertexs, size_t n)
	{
		//初始化顶点
		_vertexs.reserve(n); //开出n个顶点的大小
		for (size_t i = 0; i < n; ++i)
		{
			_vertexs.push_back(vertexs[i]);
			_vertexmap[vertexs[i]] = i;
		}

		//初始化边（n*n的邻接矩阵，初始值为无穷大）
		_edge.resize(n);
		for (size_t i = 0; i < n; ++i)
		{
			_edge[i].resize(n, W_MAX);
		}
	}

	//获取顶点对应下标
	size_t GetVertexIndex(const V& v)
	{
		auto it = _vertexmap.find(v);
		//找到
		if (it != _vertexmap.end())
		{
			return it->second; //返回下标
		}
		
		//优化：抛异常
		throw invalid_argument("不存在的顶点");
		//return -1;
	}

	//根据下标添加边
	bool _AddEdge(size_t srci, size_t dsti, const W& w)
	{
		//检查下标合法性
		if (srci == dsti || srci >= _vertexs.size() || dsti >= _vertexs.size()) return false;

		_edge[srci][dsti] = w;

		//无向图：添加另外一条边
		if (!Direction) _edge[dsti][srci] = w;

		return true;
	}

	//根据顶点添加边
	bool AddEdge(const V& src, const V& dst, const W& w)
	{
		//获取顶点
		size_t srci = GetVertexIndex(src);
		size_t dsti = GetVertexIndex(dst);

		//添加边
		return _AddEdge(srci, dsti, w);
	}

	//打印图
	void Print()
	{
		////打印顶点和下标的映射关系
		//for (size_t i = 0; i < _vertexs.size(); ++i)
		//{
		//	cout << i << " -> " << _vertexs[i] << endl;
		//}
		//cout << endl;


		cout << "   ";
		//顶部顶点
		for (size_t i = 0; i < _vertexs.size(); ++i)
		{
			cout << _vertexs[i] << "  ";
		}
		cout << endl;

		//侧边栏顶点
		for (size_t i = 0; i < _vertexs.size(); ++i)
		{
			cout << _vertexs[i] << "  ";

			//打印边的权值
			for (size_t j = 0; j < _vertexs.size(); ++j)
			{
				if (_edge[i][j] == W_MAX)cout << "*   ";
				else cout << _edge[i][j] << "   ";
			}

			cout << endl;
		}
	}

	void _bfs(size_t srci, queue<size_t>& q, vector<bool>& visit)
	{
		q.push(srci);
		visit[srci] = true;
		int level = 0;

		while (q.size())
		{
			++level;
			cout << "bfs第" << level << "层" << endl;
			size_t levelsize = q.size();
			for (size_t i = 0; i < levelsize; ++i)
			{
				size_t topi = q.front();
				q.pop();

				cout << topi << "->" << _vertexs[topi] << endl;

				for (size_t j = 0; j < _vertexs.size(); ++j)
				{
					if (!visit[j] && _edge[topi][j] != W_MAX)
					{
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
	}

	//bfs宽度优先遍历
	void bfs(size_t srci)
	{
		queue<size_t> q;
		vector<bool> visit(_vertexs.size(), 0);

		//当前顶点
		_bfs(srci, q, visit);

		//检查是否存在外部非连通顶点
		cout << "存在非连通顶点：" << endl;
		for (size_t i = 0; i < _vertexs.size(); ++i)
		{
			if (!visit[i])
			{
				_bfs(i, q, visit);
			}
		}
	}
};
