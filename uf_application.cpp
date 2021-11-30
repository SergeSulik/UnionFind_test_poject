#include "uf_application.h"

/*
 *
 */
vector<vector<int>> generate_test_matrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 2;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrix;
}

/*
 *
 */
vector<int> convert_to_linearArray(const vector<vector<int>> &matrix)
{
    int         array_size  = matrix.size() * matrix.size();
    vector<int> cnv_matrix  = vector<int>(array_size);
    int         index       = 0;
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cnv_matrix[index] = matrix[i][j];
            index++;
        }
    }
    return cnv_matrix;
}

/*
 *
 */
int get_linearArray_index(int x, int y, const vector<vector<int>> &matrix)
{
    assert(x >= 0 && x < matrix.size());
    assert(y >= 0 && y < matrix.size());
    
    return x * matrix.size() + y;
}

/*
 *
 */
void check_elements_relations(UnionFind &uf, const vector<vector<int>> &matrix)
{
    int q = 0;
    int p = 0;
    
    for (int x = 0; x < matrix.size(); x++)
    {
        for (int y = 0; y < matrix.size(); y++)
        {
            Node up     = Node(x - 1, y);
            Node down   = Node(x + 1, y);
            Node left   = Node(x, y - 1);
            Node right  = Node(x, y + 1);
            
            q = get_linearArray_index(x, y, matrix);
            // UP direction
            if (up.x >= 0 && up.x < matrix.size() &&
                up.y >= 0 && up.y < matrix.size())
            {
                if (matrix[up.x][up.y] == matrix[x][y])
                {
                    p = get_linearArray_index(up.x, up.y, matrix);
                    uf.union_elements(p, q);
                }
            }
            // DOWN direction
            if (down.x >= 0 && down.x < matrix.size() &&
                down.y >= 0 && down.y < matrix.size())
            {
                if (matrix[down.x][down.y] == matrix[x][y])
                {
                    p = get_linearArray_index(down.x, down.y, matrix);
                    uf.union_elements(p, q);
                }
            }
            // LEFT direction
            if (left.x >= 0 && left.x < matrix.size() &&
                left.y >= 0 && left.y < matrix.size())
            {
                if (matrix[left.x][left.y] == matrix[x][y])
                {
                    p = get_linearArray_index(left.x, left.y, matrix);
                    uf.union_elements(p, q);
                }
            }
            // RIGHT direction
            if (right.x >= 0 && right.x < matrix.size() &&
                right.y >= 0 && right.y < matrix.size())
            {
                if (matrix[right.x][right.y] == matrix[x][y])
                {
                    p = get_linearArray_index(right.x, right.y, matrix);
                    uf.union_elements(p, q);
                }
            }
        }
    }
}

/*
 *
 */
bool matrix_isConnected(vector<vector<int>> input_matrix)
{
    int     p       = 0;
    int     q       = 0;
    bool    result  = false;
    
    assert(input_matrix.size() >= 2 && input_matrix.size() <= 50);
    
    if (input_matrix[0][0] == 0 || 
        input_matrix[input_matrix.size() - 1][input_matrix.size() - 1] == 0)
    return false;
    
    for (int i = 0; i < input_matrix.size(); i++)
    {
        for (int j = 0; j < input_matrix.size(); j++)
            assert(input_matrix[i][j] == 0 || input_matrix[i][j] == 1);
    }
    
    vector<int> linear_array    = convert_to_linearArray(input_matrix);
    UnionFind   uf              = UnionFind(input_matrix.size() * input_matrix.size());
    
    check_elements_relations(uf, input_matrix);
    p = get_linearArray_index(0, 0, input_matrix);
    q = get_linearArray_index(input_matrix.size() - 1, input_matrix.size() - 1, input_matrix);
    
    result =  uf.isConnected(p, q);
    
    return result;
}

