//
//  main.cpp
//  2021-01-12-test_of_variable_types
//
//  Created by Mario Elsnig on 12.01.21.
//
#include <iostream>


// MARK: - VARIABLES
#pragma region VARIABLES

// OLD: int varGlobal = 5;

#pragma endregion



// MARK: - FUNCTIONS
#pragma region FUNCTIONS

void subGlobalstatic(int varGlobal) {
    static int ivar = 4;
    
    ivar = varGlobal - 10 + ivar;
    printf("\tivar: %d varGlobal: %d\n", ivar, varGlobal); // first: -1  5 second: -6  5
}

void subGlobal(int varGlobal) {
    int ivar = 4;
    ivar = varGlobal - 10 + ivar;
    printf("\tivar: %d varGlobal: %d\n", ivar, varGlobal); // first: -1  5 second: -1  5
}

int multiply(int a, int b) {
    int result = a * b;
    printf("\tx * y = %d\n", result);
    return result;
}

#pragma endregion



// MARK: - CALLBACKS
#pragma region CALLBACKS

int main() {
    int varGlobal1 = 5;
    int varGlobal2 = 3;
    int area = 0;
    
    printf("before: varGlobal: %d\n", varGlobal1); // 5
    
    // subGlobalstatic
    subGlobalstatic(varGlobal1);
    printf("after1: varGlobal1: %d\n", varGlobal1); // 5
    subGlobalstatic(varGlobal1);
    printf("after2: varGlobal1: %d\n", varGlobal1); // 5
    
    // subGlobal
    subGlobal(varGlobal2);
    printf("after3: varGlobal2: %d\n", varGlobal2); // 5
    subGlobal(varGlobal2);
    printf("after4: varGlobal2: %d\n", varGlobal2); // 5
    
    // mulGlobal
    area = multiply(varGlobal1, varGlobal2);
    printf("area: %d\n", area);
}

#pragma endregion
