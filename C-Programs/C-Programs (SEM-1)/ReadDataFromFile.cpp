#include <stdio.h>

int main() {
    FILE *file;
    char buffer[255];
    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Reading data from student_records.txt:\n\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}

