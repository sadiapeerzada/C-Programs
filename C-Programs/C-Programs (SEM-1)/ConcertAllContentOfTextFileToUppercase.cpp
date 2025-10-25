#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file, *temp;
    char ch;
    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        fputc(toupper(ch), temp);
    }
    fclose(file);
    fclose(temp);
    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");

    printf("Content converted to uppercase successfully.\n");

    return 0;
}

