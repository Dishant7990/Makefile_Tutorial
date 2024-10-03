#include <stdio.h>
#include "calculator.h"

int main() {
    int a = 10, b = 5;
    printf("Addition:\t %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction:\t %d - %d = %d\n", a, b, sub(a, b));
    printf("Multiplication:\t %d * %d = %d\n", a, b, mul(a, b));
    printf("Division:\t %d / %d = %d\n", a, b, div(a, b));
    return 0;
}

