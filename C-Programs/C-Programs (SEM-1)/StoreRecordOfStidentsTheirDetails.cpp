#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char Class[10];
    int roll_no;
    char enrollment[20];
    float marks;
};
int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);
    struct Student students[N];
    for (int i = 0; i < N; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter class: ");
        scanf("%s", students[i].Class);
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter enrollment number: ");
        scanf("%s", students[i].enrollment);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nStudent Information:\n");
    for (int i = 0; i < N; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Class: %s\n", students[i].Class);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Enrollment: %s\n", students[i].enrollment);
        printf("Marks: %.2f\n", students[i].marks);
    }
   return 0;
}

