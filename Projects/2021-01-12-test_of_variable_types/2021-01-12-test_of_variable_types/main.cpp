//
//  main.cpp
//  2021-01-12-test_of_variable_types
//
//  Created by Mario Elsnig on 12.01.21.
//
#include <iostream>


#pragma region VARIABLES
// MARK: - =VARIABLES

#pragma endregion



#pragma region FUNCTIONS
// MARK: - =FUNCTIONS

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

#pragma endregion



#pragma region CALLBACKS
// MARK: - =CALLBACKS

int main() {
    int varGlobal = 5;
    
    printf("before: varGlobal: %d\n", varGlobal); // 5
    
    // MARK: subGlobalstatic
    subGlobalstatic(varGlobal);
    printf("after1: varGlobal: %d\n", varGlobal); // 5
    subGlobalstatic(varGlobal);
    printf("after2: varGlobal: %d\n", varGlobal); // 5
    
    // MARK: subGlobal
    subGlobal(varGlobal);
    printf("after3: varGlobal: %d\n", varGlobal); // 5
    subGlobal(varGlobal);
    printf("after4: varGlobal: %d\n", varGlobal); // 5
}

#pragma endregion
