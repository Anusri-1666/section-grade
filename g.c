#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

Student students[MAX];
int count = 0;

/* Function declarations */
void loadData();
void saveData();
void addStudent();
void listStudents();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    loadData();

    do {
        printf("\n--- Student Data Management ---\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveData(); printf("Data saved. Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

/* Load data from file */
void loadData() {
    FILE *fp = fopen("data.txt", "r");
    if (!fp) return;

    count = 0;
    while (fscanf(fp, "%d %s %d", 
                  &students[count].id, 
                  students[count].name, 
                  &students[count].age) == 3) {
        count++;
    }
    fclose(fp);
}

/* Save data to file */
void saveData() {
    FILE *fp = fopen("data.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n",
                students[i].id,
                students[i].name,
                students[i].age);
    }
    fclose(fp);
}

/* Add new student */
void addStudent() {
    if (count >= MAX) {
        printf("Storage full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    count++;
    printf("Student added successfully!\n");
}

/* List students */
void listStudents() {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. ID: %d | Name: %s | Age: %d\n",
               i + 1,
               students[i].id,
               students[i].name,
               students[i].age);
    }
}

/* Update a student */
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

/* Delete a student */
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            /* shift left */
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}