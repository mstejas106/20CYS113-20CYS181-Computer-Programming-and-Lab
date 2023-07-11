#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 3

enum Score {
    A, B, C, D, F
};

typedef struct {
    char name[30];
    int age;
    enum Score grade;
} Student;

void addStudent(Student students[], int count) {
    if (count >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    char score;
    scanf("%s", students[count].name);
    scanf("%d", &students[count].age);
    scanf(" %c", &score);

    switch (score) {
        case 'A':
            students[count].grade = A;
            break;
        case 'B':
            students[count].grade = B;
            break;
        case 'C':
            students[count].grade = C;
            break;
        case 'D':
            students[count].grade = D;
            break;
        case 'F':
            students[count].grade = F;
            break;
        default:
            printf("Unknown score.\n");
            return;
    }

    printf("Student added successfully.\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("List of students:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d\n", (i + 1));
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Score: ");

        switch (students[i].grade) {
            case A:
                printf("A\n");
                break;
            case B:
                printf("B\n");
                break;
            case C:
                printf("C\n");
                break;
            case D:
                printf("D\n");
                break;
            case F:
                printf("F\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }

        printf("\n");
    }
}

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("1. Add a student\n");
        printf("2. Display students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, count);
                count++;
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                printf("Exiting the program. Thank you for using our system!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
