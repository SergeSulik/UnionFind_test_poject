#include "union_find.h"

/*
 *
 */
UnionFind:: UnionFind(int n)
{
    count_nodes = n;
    nodes = new int[n];
    
    for (int i = 0; i < count_nodes; i++)
        nodes[i] = i;
}

/*
 *
 */
UnionFind::~UnionFind()
{
    delete[] nodes;
}

/*
 *
 */
int UnionFind::find(int p)
{
    assert(p >= 0 && p < count_nodes);
    return nodes[p];
}

/*
 *
 */
void UnionFind::union_elements(int p, int q)
{
    int pNode = find(p);
    int qNode = find(q);
    
    if (pNode == qNode)
        return;
    
    for (int i = 0; i < count_nodes; i++)
    {
        if (nodes[i] == pNode)
            nodes[i] = qNode;
    }
}

/*
 *
 */
bool UnionFind::isConnected(int p, int q)
{
    return find(p) == find(q);
}
