 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX_STUDENT 100
 #define FILE_NAME "student.dat"

 struct Student
 {
     int id;
     char name[50];
     char father_name[50];
     int age;
     char gender;
     char department[50];
     int semester;
     float cgpa;
     char phone[20];
     char email[50];
     char address[100];
     char fee_status[20];
     char grade;
 };
 struct Student students[MAX_STUDENT];
 int count=0;
 
void loadData();
void saveData();

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

void totalStudents();
void averageCGPA();
void topperStudent();
void lowestCGPA();
void departmentStudents();
void feeStatus();
int main()
{
    int choice;
    loadData();
    do
    {
        printf("\n=====================================\n");
        printf("     STUDENT MANAGEMENT SYSTEM\n");
        printf("=====================================\n");

        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Total Students\n");
        printf("7. Average CGPA\n");
        printf("8. Topper Student\n");
        printf("9. Lowest CGPA\n");
        printf("10. Department Students\n");
        printf("11. Fee Status\n");
        printf("12. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
{
case 1:
    addStudent();
    break;

case 2:
    viewStudents();
    break;

case 3:
    searchStudent();
    break;

case 4:
    updateStudent();
    break;

case 5:
    deleteStudent();
    break;

case 6:
    totalStudents();
    break;

case 7:
    averageCGPA();
    break;

case 8:
    topperStudent();
    break;

case 9:
    lowestCGPA();
    break;

case 10:
    departmentStudents();
    break;

case 11:
    feeStatus();
    break;

case 12:
    printf("\nThank You...\n");
    break;

default:
    printf("\nInvalid Choice!\n");
}

    }while(choice!=12);
    return 0;
}