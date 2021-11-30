#pragma once

#include<iostream>
#include<vector>
#include<cassert>

#include "union_find.h"

using namespace std;

// structure of point
struct Node
{
    Node(int x, int y)
    {
        this -> x = x;
        this -> y = y;
    }
    int x;
    int y;
};

// ----- FUNCTIONS -----
vector<vector<int>> generate_test_matrix(int n);
vector<int> convert_to_linearArray(const vector<vector<int>> &matrix);
int get_linearArray_index(int x, int y, const vector<vector<int>> &matrix);
void check_elements_relations(UnionFind &uf, const vector<vector<int>> &matrix);
bool matrix_isConnected(vector<vector<int>> input_matrix);