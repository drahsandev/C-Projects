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
    for(int i=0;i<count;i++)
    {
        if(students[i].id==students[count].id)
        {
            printf("Student ID already exists!\n");
            return;
        }
    }
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