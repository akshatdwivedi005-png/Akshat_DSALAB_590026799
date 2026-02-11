/*
Q1) Write a C program to dynamically allocate memory for an array, display elements, and properly free allocated memory before program termination.
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
        arr = (int*)malloc(n * sizeof(int));
    
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
        printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        printf("Array elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
        free(arr);
    
    return 0;
}
*/
/*Q2) Write a C program to dynamically allocate memory for an array of N integers and perform insertion, display, sum, and average operations.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    float avg;
    int *arr;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    avg = (float)sum / n;
    
    printf("\nArray elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);
    
    free(arr);
    return 0;
}
*/
/*
Q3) Write a C program to dynamically allocate an array and find the largest and smallest element.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int largest, smallest;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    largest = smallest = arr[0];
    
    for(i = 1; i < n; i++) {
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }
    
    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);
    
    free(arr);
    return 0;
}
*/

/*
Q4) Write a C program to dynamically allocate memory for a 2D matrix and perform matrix multiplication.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    int **mat1, **mat2, **prod;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Incompatible matrix dimensions\n");
        return 1;
    }

    mat1 = (int**)malloc(rows1 * sizeof(int*));
    mat2 = (int**)malloc(rows2 * sizeof(int*));
    prod = (int**)malloc(rows1 * sizeof(int*));

    for(i = 0; i < rows1; i++) {
        mat1[i] = (int*)malloc(cols1 * sizeof(int));
    }
    for(i = 0; i < rows2; i++) {
        mat2[i] = (int*)malloc(cols2 * sizeof(int));
    }
    for(i = 0; i < rows1; i++) {
        prod[i] = (int*)malloc(cols2 * sizeof(int));
    }

    printf("Enter first matrix:\n");
    for(i = 0; i < rows1; i++)
        for(j = 0; j < cols1; j++)
            scanf("%d", &mat1[i][j]);
    printf("Enter second matrix:\n");
    for(i = 0; i < rows2; i++)
        for(j = 0; j < cols2; j++)
            scanf("%d", &mat2[i][j]);

    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            prod[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nProduct Matrix:\n");
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++)
            printf("%d ", prod[i][j]);
        printf("\n");
    }

    for(i = 0; i < rows1; i++) {
        free(mat1[i]);
        free(prod[i]);
    }
    for(i = 0; i < rows2; i++) {
        free(mat2[i]);
    }
    free(mat1); free(mat2); free(prod);

    return 0;
}
*/
/*
Q5) Write a C program using structure and dynamic memory allocation to store and display student details such as roll number, name, and marks.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i;
    struct Student *students;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    students = (struct Student*)malloc(n * sizeof(struct Student));
    
    for(i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    
    printf("\nStudent Details:\n");
    for(i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Roll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    
    free(students);
    return 0;
}
*/
/*
Q6) Write a C program using array of structures with dynamic memory allocation to store employee details and find the employee with the highest salary.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i, maxIndex = 0;
    struct Employee *emp;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    emp = (struct Employee*)malloc(n * sizeof(struct Employee));
    
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
        for(i = 1; i < n; i++) {
        if(emp[i].salary > emp[maxIndex].salary)
            maxIndex = i;
    }
    
    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\n", emp[maxIndex].id);
    printf("Name: %s\n", emp[maxIndex].name);
    printf("Salary: %.2f\n", emp[maxIndex].salary);
    
    free(emp);
    return 0;
}
*/
/*
Q7) Write a menu-driven C program using structure and dynamic memory allocation to add, display, delete records and free memory before exit.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *students = NULL;
    int count = 0, choice, i;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete All Records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                count++;
                students = (struct Student*)realloc(students, count * sizeof(struct Student));
                printf("Enter Roll: ");
                scanf("%d", &students[count-1].roll);
                printf("Enter Name: ");
                scanf("%s", students[count-1].name);
                printf("Enter Marks: ");
                scanf("%f", &students[count-1].marks);
                break;
                
            case 2:
                if(count == 0)
                    printf("No records!\n");
                else {
                    printf("\nStudent Records:\n");
                    for(i = 0; i < count; i++) {
                        printf("Roll: %d, Name: %s, Marks: %.2f\n", 
                               students[i].roll, students[i].name, students[i].marks);
                    }
                }
                break;
                
            case 3:
                if(students != NULL) {
                    free(students);
                    students = NULL;
                    count = 0;
                    printf("All records deleted!\n");
                }
                break;
                
            case 4:
                if(students != NULL)
                    free(students);
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}
*/
/*
Q8) Write a C program to demonstrate the use of union by storing integer, float, and character data and explain memory sharing.
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;
    
    printf("Size of union: %lu bytes\n", sizeof(union Data));
    
    data.i = 65;
    printf("\nStoring integer 65:\n");
    printf("As integer: %d\n", data.i);
    printf("As float: %f\n", data.f);
    printf("As character: %c\n", data.c);
    
    data.f = 65.5;
    printf("\nStoring float 65.5:\n");
    printf("As integer: %d\n", data.i);
    printf("As float: %f\n", data.f);
    printf("As character: %c\n", data.c);
    
    data.c = 'A';
    printf("\nStoring character 'A':\n");
    printf("As integer: %d\n", data.i);
    printf("As float: %f\n", data.f);
    printf("As character: %c\n", data.c);
    
    return 0;
}
*/

/*
Q9) Write a C program to show the difference in memory allocation between structure and union using sizeof().
#include <stdio.h>

struct StructData {
    int i;
    float f;
    char c;
};

union UnionData {
    int i;
    float f;
    char c;
};

int main() {
    struct StructData s;
    union UnionData u;
    
    printf("Size of structure: %lu bytes\n", sizeof(s));
    printf("Size of union: %lu bytes\n", sizeof(u));
    
    printf("\nAddresses in Structure:\n");
    printf("&s.i = %p\n", &s.i);
    printf("&s.f = %p\n", &s.f);
    printf("&s.c = %p\n", &s.c);
    
    printf("\nAddresses in Union:\n");
    printf("&u.i = %p\n", &u.i);
    printf("&u.f = %p\n", &u.f);
    printf("&u.c = %p\n", &u.c);
    
    return 0;
}
*/


/*Q10) Write a C program using structure and dynamic memory allocation to sort student record based on marks.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i, j;
    struct Student *students, temp;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    students = (struct Student*)malloc(n * sizeof(struct Student));
    
    for(i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    
    // Bubble sort by marks
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(students[j].marks < students[j+1].marks) {
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    
    printf("\nStudents sorted by marks (highest first):\n");
    for(i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", 
               students[i].roll, students[i].name, students[i].marks);
    }
    
    free(students);
    return 0;
}

