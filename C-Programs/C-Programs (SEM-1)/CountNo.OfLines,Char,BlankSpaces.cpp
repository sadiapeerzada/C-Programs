#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int lines = 0, characters = 0, blankSpaces = 0;
    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == ' ') {
            blankSpaces++;
        }
        if (ch == '\n') {
            lines++;
        }
    }
    fclose(file);
    printf("Number of lines: %d\n", lines);
    printf("Number of characters: %d\n", characters);
    printf("Number of blank spaces: %d\n", blankSpaces);

    return 0;
}


