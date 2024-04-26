#include "BigInteger.h"
#include "BigIntegerTest.h"
#include<ostream>
#include <iomanip>
#include <iostream>
using namespace std;


BigInteger computeNthFibonacci(unsigned int n) {
    BigInteger a = BigInteger("1");
    BigInteger b = BigInteger("1");
    BigInteger c = BigInteger("1");
 
    if (n == 0)
        return c;
    n--;
    while (n != 0) {
        c = a + b;
        b = a;
        a = c;
        n--;
    }
    return b;
}


int main() {  

#if ENABLE_TESTS > 0
    run_bigint_tests(true);
#endif

    BigInteger crt = BigInteger("-1");
    BigInteger prev = BigInteger("-1");
    bool isOverflow = false;
    for (int n = 0; n < 100; n += 10) {
        prev = crt;
        crt = computeNthFibonacci(n);
        if (crt < prev)
            isOverflow = true;
        cout << setw(5) << n << "\t" << setw(30) << crt << "\t" << (isOverflow ? string(RED) + string("OVERFLOW !!!! ") + string(NC) : "") << endl;

    }
    return 0;
}