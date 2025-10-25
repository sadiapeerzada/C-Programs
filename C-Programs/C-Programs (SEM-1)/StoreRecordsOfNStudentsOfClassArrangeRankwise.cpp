#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int rollNo;
    float marks;
};
void sortStudentsByMarks(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].marks < students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        getchar();
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    sortStudentsByMarks(students, n);
    printf("\nStudent Records (Rank wise):\n");
    for (int i = 0; i < n; i++) {
        printf("Rank %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
   return 0;
}


