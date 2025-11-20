#include <stdio.h>
struct Student 
   {
    char name[50];
    char section;
    float grade;
  };

int main() 
   {
    struct Student s[50];
    int n, i;

    printf("How many students? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Section (A/B/C): ");
        scanf(" %c", &s[i].section);

        printf("Grade: ");
        scanf("%f", &s[i].grade);
    }

    printf("\n==== Student Records ====\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: %s | Section: %c | Grade: %.2f\n",
               i + 1, s[i].name, s[i].section, s[i].grade);
    }
    return 0;
}