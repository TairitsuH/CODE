#pragma once
#pragma once
#include<vector>
#include<map>
#include<iostream>
#include<climits>
using namespace std;

//边结构体
template<class W>
struct LinkEdge
{
	size_t _srcIndex; //起点下标
	size_t _dstIndex; //终点下标
	W _w; //权值
	LinkEdge<W>* _next; //next指针（指向同起点下一条边）

	LinkEdge(const W& w)
		:_srcIndex(-1)
		,_dstIndex(-1)
		,_w(w)
		,_next(nullptr)
	{ }
};

//value(vertex), weight(edge)
template<class V, class W, W W_MAX = INT_MAX, bool Direction = false>
class LinkGraph
{
	typedef LinkEdge<W> Edge;

private:
	vector<V> _vertexs; //顶点
	map<V, size_t> _vertexmap; //顶点和数组下标的映射关系
	vector<Edge*> _linkTable; //顶点下标

public:
	LinkGraph() = default; //默认生成

	LinkGraph(const V* vertexs, size_t n)
	{
		//初始化顶点
		_vertexs.reserve(n); //开出n个顶点的大小
		for (size_t i = 0; i < n; ++i)
		{
			_vertexs.push_back(vertexs[i]);
			_vertexmap[vertexs[i]] = i;
		}

		//初始化边
		_linkTable.resize(n, nullptr);
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

	//根据顶点添加边
	void AddEdge(const V& src, const V& dst, const W& w)
	{
		//获取顶点
		size_t srci = GetVertexIndex(src);
		size_t dsti = GetVertexIndex(dst);

		//添加边（头插法）
		Edge* newedge = new Edge(w);
		newedge->_srcIndex = srci;
		newedge->_dstIndex = dsti;
		newedge->_next = _linkTable[srci];
		_linkTable[srci] = newedge;

		//无向图：添加另一条边
		if (!Direction)
		{
			Edge* newedge = new Edge(w);
			newedge->_srcIndex = dsti;
			newedge->_dstIndex = srci;
			newedge->_next = _linkTable[dsti];
			_linkTable[dsti] = newedge;
		}
	}

	//打印图测试
	void Print()
	{
		//输出相连的边和权值
		for (int i = 0; i < _vertexs.size(); ++i)
		{
			cout << i << " -> " << _vertexs[i] << " : ";
			Edge* tmp = _linkTable[i];
			if (!tmp) cout << "nullptr";
			while (tmp)
			{
				cout << _vertexs[tmp->_dstIndex] << "(" << tmp->_w << ")  ";
				
				tmp = tmp->_next;
			}
			cout << endl;
		}

		cout << endl;
	}

	void TestLinkGraph()
	{
		string a[] = { "张三", "李四", "王五", "赵六" };
		LinkGraph<string, int> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}
};
