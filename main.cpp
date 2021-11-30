/******************************************************************************


*******************************************************************************/
#include <stdio.h>

#include "uf_application.h"
#include "union_find.h"

using namespace std;

const int MATRIX_SIZE = 3;

int main()
{
    printf("Union-Find algorithm test application\n");
    
    vector<vector<int>> test_matrix = generate_test_matrix(MATRIX_SIZE);
    
    printf("\ntest matrix connection status is: ");
    if (matrix_isConnected(test_matrix))
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");
        
    return 0;
}
