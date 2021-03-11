//
//  main.cpp
//  2021-01-12-functionsAndPointer
//
//  Created by Mario Elsnig on 26.01.21.
//

#include <iostream>


// MARK: - VARIABLES
#pragma region VARIABLES


#pragma endregion



// MARK: - FUNCTIONS
#pragma region FUNCTIONS

float Divide(float num1, float num2) {
    return num1 / num2;
}

void DividePtr(float *num1, float *num2, float *res) {
    *res = *num1 / *num2;
}

void MultiplyPtr(float *num1, float *num2, float *res) {
    *res = *num1 * *num2;
}

void DivMultPtr(float *num1, float *num2, float *resDiv, float *resMult) {
    *resDiv = *num1 / *num2;
    *resMult = *num1 * *num2;
}

void CalcPtr(float *num1, float *num2, float *resDiv, float *resMult, float *resAdd, float *resSub) {
    *resDiv = *num1 / *num2;
    *resMult = *num1 * *num2;
    *resAdd = *num1 + *num2;
    *resSub = *num1 - *num2;
}

#pragma endregion



// MARK: - CALLBACKS
#pragma region CALLBACKS

int main() {
    float num1 = 11, num2 = 22, div12 = Divide(num1, num2);
    float *ptr1 = &num1, *ptr2 = &num2, *ptrdiv12 = &div12;
    
    
    printf("Division result  is: \t%f\n", div12);
    printf("Division pointer is: \t%d\n", ptrdiv12);
    printf("\n");
    printf("Adresses are: num1 \t%d \tnum2 \t%d\n", &num1, &num2);
    printf("Pointer  are: num1 \t%d \tnum2 \t%d\n", ptr1, ptr2);
    printf("\n");
    
    float resDiv = 0;
    DividePtr(ptr1, ptr2, &resDiv);
    printf("Pointer division \t%f\n", resDiv);
    
    float resMult = 0;
    MultiplyPtr(ptr1, ptr2, &resMult);
    printf("Pointer multiply \t%f\n", resMult);
    
    resDiv = 0;
    resMult = 0;
    DivMultPtr(ptr1, ptr2, &resDiv, &resMult);
    printf("Pointer division: \t%f \tmultiply \t%f\n", resDiv, resMult);
    
    resDiv = 0;
    resMult = 0;
    float resAdd = 0;
    float resSub = 0;
    CalcPtr(ptr1, ptr2, &resDiv, &resMult, &resAdd, &resSub);
    printf("Pointer division: \t%f \tmultiply \t%f \tadd \t%f \tsub \t%f\n", resDiv, resMult, resAdd, resSub);
    
    
    printf("\n");
    return 0;
}

#pragma endregion
