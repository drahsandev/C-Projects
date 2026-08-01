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
    system("pause");
    system("cls");
    break;

case 2:
    viewStudents();
    system("pause");
    system("cls");
    break;

case 3:
    searchStudent();
    system("pause");
    system("cls");
    break;

case 4:
    updateStudent();
    system("pause");
    system("cls");
    break;

case 5:
    deleteStudent();
    system("pause");
    system("cls");
    break;

case 6:
    totalStudents();
    system("pause");
    system("cls");
    break;

case 7:
    averageCGPA();
    system("pause");
    system("cls");
    break;

case 8:
    topperStudent();
    system("pause");
    system("cls");
    break;

case 9:
    lowestCGPA();
    system("pause");
    system("cls");
    break;

case 10:
    departmentStudents();
    system("pause");
    system("cls");
    break;

case 11:
    feeStatus();
    system("pause");
    system("cls");
    break;

case 12:
    printf("\nThank You...\n");
    system("pause");
    system("cls");
    break;

default:
    printf("\nInvalid Choice!\n");
}

    }while(choice!=12);
    return 0;
}
void loadData()
{
    FILE *fp;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        count = 0;
        return;
    }

    count = fread(students, sizeof(struct Student), MAX_STUDENT, fp);

    fclose(fp);
}
void saveData()
{
    FILE *fp;

    fp = fopen(FILE_NAME, "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    fwrite(students, sizeof(struct Student), count, fp);

    fclose(fp);
}
void addStudent()
{
    if(count >= MAX_STUDENT)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\n========== ADD NEW STUDENT ==========\n");
    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);
    getchar();
    printf("Enter Name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';

    printf("Enter Father Name: ");
    fgets(students[count].father_name, sizeof(students[count].father_name), stdin);
    students[count].father_name[strcspn(students[count].father_name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &students[count].age);
    getchar();

    printf("Enter Gender (M/F): ");
    scanf("%c", &students[count].gender);
    getchar();

    printf("Enter Department: ");
    fgets(students[count].department, sizeof(students[count].department), stdin);
    students[count].department[strcspn(students[count].department, "\n")] = '\0';

    printf("Enter Semester: ");
    scanf("%d", &students[count].semester);
    getchar();

    printf("Enter CGPA: ");
    scanf("%f", &students[count].cgpa);
    getchar();

    printf("Enter Phone Number: ");
    fgets(students[count].phone, sizeof(students[count].phone), stdin);
    students[count].phone[strcspn(students[count].phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(students[count].email, sizeof(students[count].email), stdin);
    students[count].email[strcspn(students[count].email, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(students[count].address, sizeof(students[count].address), stdin);
    students[count].address[strcspn(students[count].address, "\n")] = '\0';

    printf("Enter Fee Status (Paid/Pending): ");
    fgets(students[count].fee_status, sizeof(students[count].fee_status), stdin);
    students[count].fee_status[strcspn(students[count].fee_status, "\n")] = '\0';

    printf("Enter Grade: ");
    scanf("%c", &students[count].grade);
    getchar();
    count++;

    saveData();

    printf("\nStudent Added Successfully.\n");
}
void viewStudents()
{
    if(count == 0)
    {
        printf("\nNo Student Record Found!\n");
        return;
    }

    printf("\n================== ALL STUDENTS ==================\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("-----------------------------------------\n");
        printf("ID         : %d\n", students[i].id);
        printf("Name       : %s\n", students[i].name);
        printf("Father Name: %s\n", students[i].father_name);
        printf("Age        : %d\n", students[i].age);
        printf("Gender     : %c\n", students[i].gender);
        printf("Department : %s\n", students[i].department);
        printf("Semester   : %d\n", students[i].semester);
        printf("CGPA       : %.2f\n", students[i].cgpa);
        printf("Phone      : %s\n", students[i].phone);
        printf("Email      : %s\n", students[i].email);
        printf("Address    : %s\n", students[i].address);
        printf("Fee Status : %s\n", students[i].fee_status);
        printf("Grade      : %c\n", students[i].grade);
    }
}
void searchStudent()
{
    int id;

    printf("Enter Student ID: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++)
    {
        if(students[i].id==id)
        {
            printf("\nStudent Found\n");
            printf("--------------------------\n");
            printf("ID         : %d\n", students[i].id);
            printf("Name       : %s\n", students[i].name);
            printf("Father Name: %s\n", students[i].father_name);
            printf("Age        : %d\n", students[i].age);
            printf("Gender     : %c\n", students[i].gender);
            printf("Department : %s\n", students[i].department);
            printf("Semester   : %d\n", students[i].semester);
            printf("CGPA       : %.2f\n", students[i].cgpa);
            printf("Phone      : %s\n", students[i].phone);
            printf("Email      : %s\n", students[i].email);
            printf("Address    : %s\n", students[i].address);
            printf("Fee Status : %s\n", students[i].fee_status);
            printf("Grade      : %c\n", students[i].grade);
            return;
        }
    }

    printf("Student Not Found!\n");
}
void totalStudents()
{
    printf("\nTotal Students = %d\n",count);
}
void averageCGPA()
{
    if(count==0)
    {
        printf("No Student Record!\n");
        return;
    }

    float sum=0;

    for(int i=0;i<count;i++)
    {
        sum+=students[i].cgpa;
    }

    printf("Average CGPA = %.2f\n",sum/count);
}
void topperStudent()
{
    if(count==0)
    {
        printf("No Student Record!\n");
        return;
    }

    int top=0;

    for(int i=1;i<count;i++)
    {
        if(students[i].cgpa>students[top].cgpa)
        {
            top=i;
        }
    }

    printf("\nTopper Student\n");
    printf("-----------------------\n");
    printf("Name : %s\n",students[top].name);
    printf("ID   : %d\n",students[top].id);
    printf("CGPA : %.2f\n",students[top].cgpa);
}
void lowestCGPA()
{
    if(count==0)
    {
        printf("No Student Record!\n");
        return;
    }

    int low=0;

    for(int i=1;i<count;i++)
    {
        if(students[i].cgpa<students[low].cgpa)
        {
            low=i;
        }
    }

    printf("\nLowest CGPA Student\n");
    printf("-----------------------\n");
    printf("Name : %s\n",students[low].name);
    printf("ID   : %d\n",students[low].id);
    printf("CGPA : %.2f\n",students[low].cgpa);
}
void updateStudent()
{
    int id;

    printf("Enter Student ID to Update: ");
    scanf("%d",&id);
    getchar();

    for(int i=0;i<count;i++)
    {
        if(students[i].id==id)
        {
            printf("\nEnter New Name: ");
            fgets(students[i].name,sizeof(students[i].name),stdin);
            students[i].name[strcspn(students[i].name,"\n")]='\0';

            printf("Enter Father Name: ");
            fgets(students[i].father_name,sizeof(students[i].father_name),stdin);
            students[i].father_name[strcspn(students[i].father_name,"\n")]='\0';

            printf("Enter Age: ");
            scanf("%d",&students[i].age);
            getchar();

            printf("Enter Gender (M/F): ");
            scanf("%c",&students[i].gender);
            getchar();

            printf("Enter Department: ");
            fgets(students[i].department,sizeof(students[i].department),stdin);
            students[i].department[strcspn(students[i].department,"\n")]='\0';

            printf("Enter Semester: ");
            scanf("%d",&students[i].semester);
            getchar();

            printf("Enter CGPA: ");
            scanf("%f",&students[i].cgpa);
            getchar();

            printf("Enter Phone: ");
            fgets(students[i].phone,sizeof(students[i].phone),stdin);
            students[i].phone[strcspn(students[i].phone,"\n")]='\0';

            printf("Enter Email: ");
            fgets(students[i].email,sizeof(students[i].email),stdin);
            students[i].email[strcspn(students[i].email,"\n")]='\0';

            printf("Enter Address: ");
            fgets(students[i].address,sizeof(students[i].address),stdin);
            students[i].address[strcspn(students[i].address,"\n")]='\0';

            printf("Enter Fee Status: ");
            fgets(students[i].fee_status,sizeof(students[i].fee_status),stdin);
            students[i].fee_status[strcspn(students[i].fee_status,"\n")]='\0';

            printf("Enter Grade: ");
            scanf("%c",&students[i].grade);

            saveData();

            printf("\nStudent Updated Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}
void deleteStudent()
{
    int id;

    printf("Enter Student ID to Delete: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++)
    {
        if(students[i].id==id)
        {
            for(int j=i;j<count-1;j++)
            {
                students[j]=students[j+1];
            }

            count--;

            saveData();

            printf("\nStudent Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}
