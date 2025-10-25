#include <stdio.h>

int main() {
    int year;

    
    int test_years[] = {1900, 2000, 2016, 2017, 2020, 2100};
    int num_tests = sizeof(test_years) / sizeof(test_years[0]);

    for (int i = 0; i < num_tests; i++) {
        year = test_years[i];

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d is a leap year.\n", year);
        } else {
            printf("%d is not a leap year.\n", year);
        }
    }

    return 0;
}

