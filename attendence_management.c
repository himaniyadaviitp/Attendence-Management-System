//my first project in c
/*ID:himani
password:himani
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
char stuName[10000][30];
int present[10000] = {0};
int absent[10000] = {0};
int indexNumber = 0;
FILE *fptr;
FILE *pre;
FILE *ab;
// FILE *final;

COORD coord = {
    0,
    0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void login();
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void update1()
{
    fptr = fopen("Stud.txt", "r");

    if (fptr == NULL)
    {
        return;
    }
    indexNumber = 0;

    char str[50];
    while (!feof(fptr))
    {
        fscanf(fptr, "%s", str);
        int j = strlen(str);
        int p = 0;
        while (p != j)
        {
            stuName[indexNumber][p] = str[p];
            p++;
        }
        stuName[indexNumber][p] = '\0';
        indexNumber++;
    }
    indexNumber--;
    fclose(fptr);
}
void update2()
{
    pre = fopen("pre.txt", "r");

    if (pre == NULL)
    {
        return;
    }
    indexNumber = 0;

    char p[10];
    while (!feof(pre))
    {
        fscanf(pre, "%s", p);
        // printf("%s",p);
        int q = atoi(p);
        present[indexNumber] = q;

        // stuName[indexNumber][p] = '\0';
        indexNumber++;
    }
    indexNumber--;
    fclose(pre);
}
void update3()
{
    ab = fopen("abs.txt", "r");
    indexNumber = 0;
    if (ab == NULL)
    {
        return;
    }

    char p[10];
    while (!feof(ab))
    {
        fscanf(ab, "%s", p);
        int q = atoi(p);
        absent[indexNumber] = q;

        indexNumber++;
    }
    indexNumber--;
    fclose(ab);
}

void delay()
{
    for (int i = 0; i < 2; i++)
    {
        SetColor(120);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Saving records...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Saving records..");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Saving records...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Saving records....");
        Sleep(300);
        system("cls");
        SetColor(10);
    }
}

void please_wait()
{
    for (int i = 0; i < 2; i++)
    {
        SetColor(14);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait.");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait..");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait....");
        Sleep(300);
        system("cls");
        SetColor(45);
    }
}

void checkAttendance()
{
    int i;
    // final = fopen("fin.txt", "w");
    printf("\n +-------+----------------------------+-------------+----------+--------+-|\n");
    printf(" | S.No. |                       Name |      prsent |   absent | percentage|\n");
    printf(" +-------+----------------------------+-------------+----------+--------+----\n");

    for (i = 0; i < indexNumber; i++)
    {
        printf("   %d     |", i + 1);
        printf("            %s   ", stuName[i]);

        int h = (present[i] * 100) / (present[i] + absent[i]);

        printf("          | %d            |%d         | %d\n", present[i], absent[i], h);
        // fprintf(final, "            %d           %d       %d\n", present[i], absent[i], h);
        printf(" +-------+----------------------------+-------------+----------+--------+|\n");
    }

    printf("Enter 0 to log out :");
    int n;

    scanf("%d", &n);
    if (n == 0)
    {

        Sleep(1500);
        login();
    }
    else
    {
        printf("Press a valid key.");

        checkAttendance();
    }
    // fclose(final);
}
void addStudent()
{

    fptr = fopen("Stud.txt", "w");
    pre = fopen("pre.txt", "w");
    ab = fopen("abs.txt", "w");
    fflush(stdin);
    int i, num, add;
    if (indexNumber == 0)
    {
        SetColor(10);
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            printf("\nEnter %d student name to add in attendance ragister: ", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            fprintf(fptr, "%s", stuName[i]);
            fprintf(pre, "%d", 0);

            fputs(" ", fptr);
            fputs(" ", pre);
            fprintf(ab, "%d", 0);
            fputs(" ", ab);

            indexNumber++;
        }

        delay();
    }
    else
    {
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        add = indexNumber + num;
        for (i = indexNumber; i < add; i++)
        {
            printf("\nEnter %d student name to add in attendance ragister: ", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            indexNumber++;
            fprintf(fptr, "%s", stuName[i]);
            fprintf(pre, "%d", 0);

            fputs(" ", fptr);
            fputs(" ", pre);
            fprintf(ab, "%d", 0);
            fputs(" ", ab);
        }
        delay();
    }
    fclose(fptr);
    fclose(pre);
    fclose(ab);
}
void removeStudent()
{
    char name[30];
    printf("Enter student name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < indexNumber; i++)
    {
        if (strcmp(name, stuName[i]) == 0)
        {
            for (int j = i; j < indexNumber; j++)
            {
                strcpy(stuName[j], stuName[j + 1]);
                present[i] = present[i + 1];
                absent[i] = absent[i + 1];
            }
            indexNumber--;
            printf("\n%s student is removed\n", name);
            break;
        }
        else if (i == indexNumber - 1)
        {
            printf("This name is not exits\n");
        }
    }
    fptr = fopen("Stud.txt", "w");
    for (int x = 0; x < indexNumber; x++)
    {
        fprintf(fptr, "%s ", stuName[x]);
    }
    fclose(fptr);
    pre = fopen("pre.txt", "w");
    for (int x = 0; x < indexNumber; x++)
    {
        fprintf(pre, "%d ", present[x]);
    }
    fclose(ab);
    pre = fopen("abs.txt", "w");
    for (int x = 0; x < indexNumber; x++)
    {
        fprintf(ab, "%d ", absent[x]);
    }
    fclose(ab);
}

void takeAttendance()
{
    int i;
    SetColor(14);
    char ch;
    printf("\nEnter Y for present and N for absent\n");
    for (i = 0; i < indexNumber; i++)
    {
    repeate:
        printf("%d. %s is present: ", i + 1, stuName[i]);
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            present[i] += 1;
        }
        else if (ch == 'N' || ch == 'n')
        {
            absent[i] += 1;
        }
        else
        {
            printf("Invalid character Try again\n");
            goto repeate;
        }
    }
    pre = fopen("pre.txt", "w");
    ab = fopen("abs.txt", "w");

    for (int x = 0; x < indexNumber; x++)
    {
        fprintf(pre, "%d ", present[x]);
    }
    for (int x = 0; x < indexNumber; x++)
    {
        fprintf(ab, "%d ", absent[x]);
    }
    fclose(pre);
    fclose(ab);
    delay();
}

void adminView()
{
    SetColor(12);

    int choose;

    do
    {
        printf("\n*Main Menu\n");
        printf("Enter 1 to  add a student\n\n\n\n\n");
        printf("Enter 2 for marking attendance\n\n\n\n\n");
        printf("Enter 3 for checking attendance\n\n\n\n\n");
        printf("Enter 4 for removing a student\n\n\n\n\n");
        printf("Enter 5 for logout\n\n\n\n\n");
        printf("Please choose any menu: ");
        fflush(stdin);
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            please_wait();
            addStudent();
            break;
        case 2:
            please_wait();
            takeAttendance();
            break;
        case 3:
            please_wait();
            checkAttendance();
            break;
        case 4:
            please_wait();
            removeStudent();
            break;
        case 5:
            please_wait();
            login();
            break;
        }
    } while (choose != 5);
}
void teacher_login()
{
    system("cls");
    int i, s = 0;
    char name[20], password[20], p;
    char ID[20] = {
        "himani"};
    char tPASS[20] = {
        "himani"};
    SetColor(14);
    printf("\n\n\t\t\t\t\t  ===Teacher's Portal===\n\n\n\n\n");
    SetColor(45);
    SetColor(11);
    printf("\n\n\t\t\t\t\tYou must log in first\n");
    SetColor(6);
    printf("\n\n\t\t\t\t\t Enter ID: ");
    SetColor(3);
    gets(name);
    SetColor(6);
    printf("\n\n\t\t\t\t\tPassword: ");
    SetColor(3);
    while (p != 13)
    {
        p = _getch();
        if (p != 13)
        {
            putch('*');
            password[s] = p;
            s++;
        }
    }
    password[s] = '\0';
    if (strcmp(ID, name) == 0)
    {
        if (strcmp(tPASS, password) == 0)
        {
            SetColor(11);
            printf("\n\n\n\t\t\t\t\tLog In Success\n");
            Sleep(1500);
            system("cls");
            please_wait();
            system("cls");
            adminView();
        }
        else
        {
            SetColor(4);
            printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
            Sleep(3000);
            SetColor(45);
            teacher_login();
        }
    }
    else
    {
        SetColor(4);
        printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
        Sleep(3000);
        SetColor(45);
        teacher_login();
    }
}

void student_login()
{
    system("cls");
    int i, s = 0;
    char name[20], password[20], p;
    char ID[20] = {
        "himani"};
    char tPASS[20] = {
        "himani"};
    SetColor(14);
    printf("\n\n\t\t\t\t\t  ===Student's portal===\n\n\n\n\n");
    SetColor(45);
    SetColor(11);
    printf("\n\n\t\t\t\t\tYou must log in first\n");
    SetColor(6);
    printf("\n\n\t\t\t\t\t Enter ID: ");
    SetColor(3);
    gets(name);
    SetColor(6);
    printf("\n\n\t\t\t\t\tPassword: ");
    SetColor(3);
    while (p != 13)
    {
        p = _getch();
        if (p != 13)
        {
            putch('*');
            password[s] = p;
            s++;
        }
    }
    password[s] = '\0';
    if (strcmp(ID, name) == 0)
    {
        if (strcmp(tPASS, password) == 0)
        {
            SetColor(11);
            printf("\n\n\n\t\t\t\t\tLog In Success\n");
            Sleep(1500);
            system("cls");
            please_wait();
            system("cls");
            checkAttendance();
        }
        else
        {
            SetColor(4);
            printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
            Sleep(3000);
            SetColor(45);
            student_login();
        }
    }
    else
    {
        SetColor(4);
        printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
        Sleep(3000);
        SetColor(45);
        student_login();
    }
}

void login()
{
    char req;
    system("cls");
    SetColor(14);
    printf("\n\n\n\t\t                             WELCOME TO                           \n");
    printf("\t                          STUDENT ATTENDANCE MANAGEMENT SYSTEM             \n\n\n");

    SetColor(45);
    printf("\n\n");
    printf("\t\t\t\t\t ==> 1. Log In as Teacher\n");
    printf("\t\t\t\t\t ==> 2. Log In as Student\n");
    SetColor(11);
    printf("\t\t\t\t\t Select an Option:");
    req = getche();
    SetColor(12);
    gotoxy(70, 25);
    SetColor(45);
    gotoxy(59, 14);
    switch (req)
    {
    case '1':
        teacher_login();
        break;
    case '2':
        student_login();
        break;

    default:
        printf("\n  INVALID KEYWORD. TRY AGAIN\n");
        Sleep(1000);
        login();
    }
}
int main()
{
    SetColor(45);
    // for copying name from file to array
    update1();

    update2();
    update3();
    login();
}