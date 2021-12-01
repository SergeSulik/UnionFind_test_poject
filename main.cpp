/******************************************************************************
The project demonstrates the use of the Union-Find algorithm to check the 
presence in the maze described by the two-dimensional square matrix consisting 
of 0 and 1, a path between the upper left and lower right angles.

The input matrix is in fact a maze where 1 means that the route is available 
while 0 means that it is not. Diagonal route paths are not allowed, only 
horizontal and vertical.
*******************************************************************************/
#include <iostream>
#include <string>

#include "uf_application.h"

using namespace std;

const int MATRIX_SIZE = 7;         // Size of test matrix

int main()
{
    string matrix_status;
    
    cout<<"Union-Find algorithm test application\n";
    
    vector<vector<int>> test_matrix = generate_test_matrix(MATRIX_SIZE);
    
    matrix_status = (matrix_isConnected(test_matrix)) ? "CONNECTED" : "NOT CONNECTED";
    cout<<"\ntest matrix connection status is: "<<matrix_status;
        
    return 0;
}
