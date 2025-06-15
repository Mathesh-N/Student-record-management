#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int id;
    float marks;
};

void addStudent(FILE *fp) {
    struct Student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Student added successfully.\n");
}

void viewStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Name: %s, ID: %d, Marks: %.2f\n", s.name, s.id, s.marks);
    }
}

int main() {
    FILE *fp;
    fp = fopen("students.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\n1. Add Student\n2. View Students\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        if (choice == 1) {
            addStudent(fp);
        } else if (choice == 2) {
            viewStudents(fp);
        } else {
            break;
        }
    }

    fclose(fp);
    return 0;
}
