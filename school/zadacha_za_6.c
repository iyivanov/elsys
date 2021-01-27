// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Za Uchenicite
// Avtor: 
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_OF_STUDENTS 6

const char* names[] = 
{
    "Ivan Dimitrov",
    "Ivo Ivanov",
    "Ralica Vasileva",
    "Vasil Popov",
    "Iva Rangelova",
    "Ivaylo Georgiev"
};

float avg_marks[] = 
{
    5.27, 4.38, 6.0, 5.85, 5.98, 5.63
};

// tip za boolean
typedef
enum boolean_e
{
    false = 0, true
} boolean;

// tip uchenik
struct student_t 
{
    char* names;
    int grade;
    float avg_marks;
};
typedef struct student_t* student_p;

// spisak ot uchenicite v klasa
typedef struct node_t * node_p;
struct node_t 
{
    student_p student;
    node_p next;
};

// tip klas
typedef
struct group_t 
{
    char* name;
    node_p students;
} klas_t;
typedef klas_t* klas_p;

// sazdava uchenik
student_p create_student(const char* names, int grade, float avg_marks)
{
    student_p student = (student_p) malloc(sizeof(struct student_t));

    student->names = (char*) malloc(strlen(names) + 1);
    strcpy(student->names, names);
    student->grade = grade;
    student->avg_marks = avg_marks;

    return student;
}

// dobavq uchenik kam dadeniq klas
void insert(klas_p klas, student_p student)
{
    if (klas != NULL) 
    {
        node_p new_student = (node_p) malloc(sizeof(struct node_t));
        new_student->student = student;
        if (klas->students == NULL) 
        {
            klas->students = new_student;
        } 
        else 
        {
            node_p current = klas->students;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_student;
            new_student->next = NULL;
        }
    }
}

// free the students inthe group
void dismiss(klas_p klas)
{
    if (klas != NULL && klas->students != NULL)
    {
        node_p current = klas->students;
        while (current != NULL)
        {
            node_p to_free = current;
            current = current->next;
            free(to_free->student);
            free(to_free);
        }
        klas->students = NULL;
    }
}

// prints the student(s)
void print_students(node_p node)
{
    while (node != NULL) 
    {
        if (node->student != NULL)
        {
            printf("name: %s; grade: %d; avg marks: %0.2f\n", 
                node->student->names, 
                node->student->grade, 
                node->student->avg_marks);
        }
        else 
        {
            printf("no student\n");
        }
        node = node->next;
    }
}

//dumps the group and its students
void print_klas(klas_p klas)
{
    if (klas != NULL)
    {
        printf("\n================================\n");
        printf("group of %s\n", klas->name);
        printf("----------------------------------\n");
        print_students(klas->students);
        printf("================================\n");
    }
}

// find the students with the given (partial) name.
// returns a new list with the found students.
// if sorted == true, the the students are sorted by average marks in descending order.
node_p find_students(klas_p klas, char* name, boolean sorted)
{
    node_p found_students = NULL;

    if (klas != NULL && name != NULL)
    {

    }

    return found_students;
}

// MAIN ENTRY POINT
int main() 
{
    struct group_t klas10A;
    klas10A.name = "10A";
    klas10A.students = NULL;

    for (int i = 0; i < NUM_OF_STUDENTS; i++)
    {
        insert(&klas10A, create_student(names[i], 10, avg_marks[i]));
    }

    print_klas(&klas10A);

    node_p found_students = find_students(&klas10A, "Iva", true);

    printf("Searching for students with names containing 'Iva'\n");
    if (found_students != NULL)
    {
        printf("found students: \n");
        print_students(found_students);
    }
    else
    {
        printf("No students found\n");
    }

    dismiss(&klas10A);

    return 0;
}
