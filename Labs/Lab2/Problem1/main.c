#include <stdio.h>
#include <limits.h>
#include "tests.h"
#include<malloc.h>

// Write a function that takes as an input an array of integer numbers (both positive and 
// negative numbers and returns the value of the triplet with the maximum product,
//  as well as the elements that form this triplet (in increasing order). 
// Use pass by pointer/address to return the elements that form that triplet. 
// Think about the appropriate data type for the result. If the size of the array is less than 3, you should return the minimum
// representable value of the data type and the elements that form the triplet should be set to 0.
long long computeMaxTriplet(int arr[], unsigned int sz, int *t1, int* t2, int* t3){
    // TODO your code here
    if (sz < 3)
    {
        *t1 = *t2 = *t3 = 0;  // Set the triplet elements to 0
        return LLONG_MIN; //return the minimum representable value of the data type
    }
   
    long long maxProduct = LLONG_MIN;
    long long product;
    * t1 = arr[0];
    * t2 = arr[1];
    * t3 = arr[2];
    for (unsigned int i = 0; i < sz - 2; i++)
    {
        for (unsigned int j = i + 1; j < sz - 1; j++)
        {
            for (unsigned int k = j + 1; k < sz; k++)
            {
                product = (long long)arr[i] * (long long)arr[j] * (long long)arr[k];
                if (product > maxProduct)
                {
                    maxProduct = product;
                    *t1 = arr[i];
                    *t2 = arr[j];
                    *t3 = arr[k];
                }
            }
        }
    }
    printf("Final max product %lld\n", maxProduct);
    int aux;
    if (*t1 > *t2)
    {
        aux = *t1;
        *t1 = *t2;
        *t2 = aux;
    }
    if (*t2 > *t3)
    {
        aux = *t2;
        *t2 = *t3;
        *t3 = aux;
    }
    if (*t1 > *t3)
    {
        aux = *t1;
        *t1 = *t3;
        *t3 = aux;
    }
    return maxProduct;
}

int main()
{
#if ENABLE_TESTS > 0
    run_tests(true);
#endif
    /*unsigned int sz;
    scanf_s("%u", &sz);
    int *arr = (int*)malloc(sz * sizeof(int));
    int e;
    int t1, t2, t3;
    for (int i = 0; i < sz; i++)
    {
        scanf_s("%d", &e);
        arr[i] = e;
    }
    long long product = computeMaxTriplet(arr, sz, &t1, &t2, &t3);
    printf("%d %d %d, product = %lld", t1, t2, t3, product);
    */
    
    return 0;
}
