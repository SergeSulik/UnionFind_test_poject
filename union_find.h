#pragma once

#include<cassert>

class UnionFind
{
    private:
        int *   nodes;
        int     count_nodes;
    public:
        UnionFind(int n);
        ~UnionFind();
        int find(int p);
        void union_elements(int p, int q);
        bool isConnected(int p, int q);
};