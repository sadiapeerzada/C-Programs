#include <stdio.h>
struct Employee {
    char name[25];
    int age;
    int basic;
    float totalSalary;
};
void calculateTotalSalary(struct Employee *emp) {
    float DA = 0.10 * emp->basic;
    float HRA = 0.05 * emp->basic;
    emp->totalSalary = emp->basic + DA + HRA;
}
void sortEmployees(struct Employee emp[], int n) {
    struct Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (emp[i].totalSalary < emp[j].totalSalary) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}
int main() {
    int n = 5;
    struct Employee emp[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Age: ");
        scanf("%d", &emp[i].age);
        printf("Basic Salary: ");
        scanf("%d", &emp[i].basic);
        calculateTotalSalary(&emp[i]);
    }
    sortEmployees(emp, n);
    printf("\nEmployee Records (Sorted by Total Salary):\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Age: %d\n", emp[i].age);
        printf("Total Salary: %.2f\n", emp[i].totalSalary);
        printf("\n");
    }

    return 0;
}


