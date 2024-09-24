#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
    // TODO: Define variables with appropriate data type
    char *name;
    int id;
    int num_grades;
    float *grades;
} Student;


Student *create_student(const char *name, int id, int num_grades) {
    Student *s = (Student *)malloc(sizeof(Student));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    s->name = (char *)malloc(strlen(name) + 1);
    if (s->name == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        free(s);
        return NULL;
    }
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    s->id = id;
    s->num_grades = num_grades;
    s->grades = (float *)malloc(num_grades * sizeof(float));
    if (s->grades == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(s);
        return NULL;
    }
    return s;
}


void update_grades(Student *s, float *new_grades) {
    // TODO: Write logic to update grades for each student
    // Step 1: Loop through each grade and update it
    // Step 2: Ensure the loop doesn't go out of bounds
    // Step 3: Optionally, you can check for valid grades (e.g., non-negative)
    for (int i = 0; i < s->num_grades; i++) {
    if (i < s->num_grades) {
        s->grades[i] = new_grades[i];
    }
}
}


void print_student(const Student *s) {
    // TODO: Write logic to print student details
    // Step 1: Print student name and ID
    // Step 2: Print all grades, ensuring proper formatting
    // Step 3: Optionally, calculate and print the average of grades
    printf("Name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("Grades: ");
    for (int i = 0; i < s->num_grades; i++) {
        printf("%.2f ", s->grades[i]);
    }
    printf("\n");
}


void free_student(Student *s) {
    // TODO: Free the allocated memory properly
    // Step 1: Free the memory for the grades array
    // Step 2: Free the memory for the student struct itself
    // Step 3: Ensure no memory leaks or double frees
    free(s->grades);
    free(s);
}


int main() {
    int num_grades;
    printf("Enter number of grades: ");
    scanf("%d", &num_grades);
    // TODO: Create a student instance
    // Step 1: Allocate memory for the student
    // Step 2: Initialize the student's name, ID, and grades array size
    Student *s = create_student("John Doe", 12345, num_grades);
    if (s == NULL) {
        return 1;
    }
    // TODO: Allocate memory for the grades array
    // Step 1: Ensure memory allocation for grades is successful
    // Step 2: Handle memory allocation failure if needed
    float *grades = (float *)malloc(num_grades * sizeof(float));
    if (grades == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free_student(s);
        return 1;
    }
    // TODO: Input grades from the user
    // Step 1: Loop through and read all grades from the user input
    // Step 2: Store the grades in the allocated array
    printf("Enter grades:\n");
    for (int i = 0; i < num_grades; i++) {
        scanf("%f", (grades + i));
    }
    // TODO: Update and print student information
    // Step 1: Update the grades for the student
    // Step 2: Print the updated student information
    update_grades(s, grades);
    print_student(s);
    // TODO: Free all allocated memory
    // Step 1: Free the memory allocated for grades
    // Step 2: Free the student struct itself
    free(grades);
    free_student(s);
    return 0;
}