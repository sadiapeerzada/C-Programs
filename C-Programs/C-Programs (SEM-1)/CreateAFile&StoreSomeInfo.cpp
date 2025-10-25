#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    char Class[10];
    int roll_no;
};
int main() {
    FILE *fp;
    struct Student student;
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    fp = fopen("student_records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
        for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", student.name);

        printf("Enter class: ");
        scanf("%s", student.Class);

        printf("Enter roll number: ");
        scanf("%d", &student.roll_no);

        fprintf(fp, "%s %s %d\n", student.name, student.Class, student.roll_no);
    }
    fclose(fp);
    printf("Student information saved to student_records.txt\n");
    return 0;
}

