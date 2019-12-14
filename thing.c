#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tax 28
#define nis 5
#define threshold 70000


///==================================================[ Employee Database Management System ] ===============================================


FILE*employeelist;
FILE*payrolllist;
FILE* e_keys;
FILE* p_keys;

///
int e_key, p_key;
struct portfolio  ///Structure #1

{

    char fname[99];
    char lname[99];
    char gender[99];
    char department[99];
    char dateofbirth[99];
    char datehired[99];
} portfolio;

struct calculation /// Structure #2
{

    int gross_salary;
    int net_salary;
    int taxded;
    int nisded;
    int totalded;

} calculation;


void create_portfolio();
int addpayroll();
void main_menu();
void viewallemployees();
void clrscr();
void viewallpayrolls();
void search_employeelist();
void preform_employee_search();
void search_payrolllist();
void preform_payroll_search();
int e_checkKey();
int e_createKey();
int p_checkKey();
int p_createKey();


/// [Main Menu]
void main_menu()
{
    printf("=======================================================[ EMPLOYEE DATABASE MANAGEMENT ] ===========================================\n\n\n\n\n\n");
    printf("\n\n\n");


    printf("                            Employee Profile Management    |---[]---|    Payroll Management\n\n");

    printf("                                1 >|  Add new Employee               4 >|  Create new Payroll\n");
    printf("                                2 >|  View all Employees             5 >|  View all Payrolls\n");
    printf("                                3 >|  Search Employees               6 >|  Search Payrolls\n");




    printf("\n\n\n\n\n\n");
    printf("[X]: Exit\n\n\n\n\n\n");


main_menu_failsafe:

    switch(tolower(getch()))
    {
    case '1':
        clrscr();
        create_portfolio();
        break;

    case '4':
        clrscr();
        addpayroll();
        break;
    case '2':
        clrscr();
        viewallemployees();
        break;
    case'3':
        clrscr();
        search_employeelist();
    case '5':
        clrscr();
        viewallpayrolls();
        break;
    case'6':
        clrscr();
        search_payrolllist();
    case'x':
        exit(0);
    default:
        goto main_menu_failsafe;



    }



}

void main()
{
    main_menu();
}


void search_employeelist()
{
    printf("Search by:\n1. First Name 2. Last Name   3. Department\n");
    printf("Choose an Option: ");
search_scope_retry:
    switch(getch())
    {
    case '1':
        preform_employee_search(1);
        break;
    case '2':
        preform_employee_search(2);
        break;
        case '3':
        	preform_employee_search(3);
        	break;
    default:
        goto search_scope_retry;
    }
}


void preform_employee_search(int search_option)
{
    clrscr();
    char keyword[20],*lname_search,*fname_search,*department_search,temp_fname[100],temp_lname[100],temp_department[100];
    printf("Enter Keyword: ");
    scanf("%[^\n]",keyword);
    strlwr(keyword);
    employeelist=fopen("employeelist.txt","r");
    while(!feof(employeelist))
    {
        fscanf(employeelist,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",&portfolio.fname,&portfolio.lname,&portfolio.gender,&portfolio.dateofbirth,&portfolio.department,&portfolio.datehired);
        strcpy(temp_fname,portfolio.fname);
        strcpy(temp_lname,portfolio.lname);
        strcpy(temp_department,portfolio.department);

        strlwr(temp_fname);
        strlwr(temp_lname);
        strlwr(temp_department);

        fname_search = strstr(temp_fname,keyword);
        lname_search = strstr(temp_lname,keyword);
        department_search = strstr(temp_department,keyword);

        if((search_option == 1 && fname_search != NULL) || (search_option == 3 && department_search !=NULL) || (search_option == 2 && lname_search !=NULL))
        {
            printf("\nEID: %d",e_key);
            printf("\nFirst Name: %s", &portfolio.fname);
            printf("\nLast Name: %s", &portfolio.lname);
            printf("\nGender: %s",&portfolio.gender);
            printf("\nDate of Birth: %s", &portfolio.dateofbirth);
            printf("\nOccupation: %s", &portfolio.department);
            printf("\nDate Hired: %s\n",&portfolio.datehired);
        }
    }
    puts("M >| Back to Menu");
    puts("X >| Exit");

after_save_option:
    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto after_save_option;
    }
}

void search_payrolllist()
{
    clrscr();
    printf("///..Search Payroll List >\n\n\n\n ");
    printf("1. Names   2. Department\n");
    printf("Choose an Option: ");
search_scope_retry:
    switch(getch())
    {
    case '1':
        preform_payroll_search(1);
        break;
    case '2':
        preform_payroll_search(2);
        break;
    default:
        goto search_scope_retry;
    }
}


void preform_payroll_search(int search_option)
{
    clrscr();
    char keyword[20],*lname_search,*fname_search,*department_search,temp_fname[100],temp_lname[100],temp_department[100];
    printf("Enter Keyword: ");
    scanf("%[^\n]",keyword);
    strlwr(keyword);
    payrolllist=fopen("payrolllist.txt","r");
    while(!feof(payrolllist))
    {
        fscanf(payrolllist,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%d",p_key,&portfolio.fname,&portfolio.lname,&portfolio.department,&calculation.gross_salary,&calculation.taxded,&calculation.nisded,&calculation.net_salary);

        strcpy(temp_fname,portfolio.fname);
        strcpy(temp_lname,portfolio.lname);
        strcpy(temp_department,portfolio.department);

        strlwr(temp_fname);
        strlwr(temp_lname);
        strlwr(temp_department);

        fname_search = strstr(temp_fname,keyword);
        lname_search = strstr(temp_lname,keyword);
        department_search = strstr(temp_department,keyword);

        if((search_option == 1 && fname_search != NULL) || (search_option == 2 && department_search !=NULL) || (search_option == 1 && lname_search !=NULL))
        {
            printf("            \n>|PID: %d",p_key);
            printf("            \n>| First Name: %s", &portfolio.fname);
            printf("            \n>| Last Name: %s", &portfolio.lname);
            printf("            \n>| Occupation: %s",&portfolio.department);
            printf("            \n>| Gross Salary: %d",calculation.gross_salary);
            printf("            \n>| Tax Deduction: %d",calculation.taxded);
            printf("            \n>| NIS Deduction: %d",calculation.nisded);
            printf("            \n>| Net Salary: %d\n\n\n",calculation.net_salary);
        }
    }
    puts("M >| Back to Menu");
    puts("X >| Exit");

after_save_option:
    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto after_save_option;
    }
}



void create_portfolio()
{
    clrscr();
    printf("///..Employee Management > Add Employee\n\n\n");
    printf("...> Enter the employee's first name: ");
    scanf("%[^\n]",portfolio.fname);
    fflush(stdin);
    printf("...> Enter the employee's last name: ");
    scanf("%[^\n]",portfolio.lname);
    fflush(stdin);
    printf("...> Gender: ");
    scanf("%[^\n]");
    fflush(stdin);
    printf("...> Enter the department where this worker is employed: ");
    fflush(stdin);
    scanf("%[^\n]",portfolio.department);
    printf("...> Date of Birth (DD/MM/YYYY): ");
    fflush(stdin);
    scanf("%[^\n]", portfolio.dateofbirth);
    printf("...> Date hired (DD/MM/YYYY): ");
    fflush(stdin);
    scanf("%[^\n]",portfolio.datehired);
    

    clrscr();
    printf("Is this Okay?\n");
    printf("                >| Employee Name: %s %s\n",portfolio.fname,portfolio.lname);
    printf("                >| Gender: %s\n",portfolio.gender);
    printf("                >| Department: %s\n",portfolio.department);
    printf("                >| Date of Birth: %s\n",portfolio.dateofbirth);
    printf("                >| Date Hired: %s\n",portfolio.datehired);
    puts("\n\nS >: Save");
    puts("R >: Retry");
    puts("X >: Exit");
save_entry:
    switch(tolower(getch()))
    {
    case 's':
        e_checkKey();
        e_createKey();
        employeelist=fopen("employeelist.txt", "a");
        fprintf(employeelist,"%d\n",e_key);
        fprintf(employeelist,"%s\n",portfolio.fname);
        fprintf(employeelist,"%s\n",portfolio.lname);
        fprintf(employeelist,"%s\n",portfolio.gender);
        fprintf(employeelist,"%s\n",portfolio.department);
        fprintf(employeelist,"%s\n",portfolio.dateofbirth);
        fprintf(employeelist,"%s\n",portfolio.datehired);
    fclose(employeelist);

        break;


    case 'r':
        create_portfolio();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto save_entry;
    }
    printf("... Entry Saved!\n");
    puts("M >| Back to Menu");
    puts("X >| Exit");

after_save_option:
    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto after_save_option;
    }




}




int addpayroll()/// [CREATE PAYROLL] Function #2
{
    printf("///...Payroll Management > Add New Payroll\n\n\n\n");
    printf("    ...>Enter Employee's First Name: ");

    scanf("%[^\n]", &portfolio.fname);
    fflush(stdin);
    printf("    ...>Enter Employee's Last Name: ");
    scanf("%[^\n]", &portfolio.lname);
    fflush(stdin);
    printf("        ...>Department: ");
    scanf("%[^\n]", &portfolio.department);
    fflush(stdin);
    printf("            ...>Enter Employee's Gross Salary: ");
    scanf("%d",&calculation.gross_salary);


    if(calculation.gross_salary>threshold)
    {
        calculation.taxded=(calculation.gross_salary*tax)/100;

    }
    else
    {
        calculation.taxded=0;
    }

    calculation.nisded=(calculation.gross_salary*nis)/100;
    calculation.net_salary=calculation.gross_salary-(calculation.nisded+calculation.taxded);
    clrscr();
    printf("///..Payroll Management > Add New Payroll > Preview\n\n\n\n\n\n");
    puts("Is this Okay?\n");

    printf("\n                 Employee's Name: %s %s", portfolio.fname,portfolio.lname);
    printf("\n                 Department: %s", portfolio.department);
    printf("\n                 Current Tax rate: %d",tax);
    printf("\n                 Current Tax threshold: %d",threshold);
    printf("\n                 Gross Income: $%d",calculation.gross_salary);
    printf("\n                 Tax Deduction: $%d ",calculation.taxded);
    printf("\n                 NIS Deduction: $%d",calculation.nisded);
    printf("\n                 Net Income: $%d\n", calculation.net_salary);

    puts("S: Save");
    puts("R: Start over");


    switch(tolower(getch()))
    {
    case 's':
        p_checkKey();
        p_createKey();
        payrolllist=fopen("payrolllist.txt", "a");
        fprintf(payrolllist,"%d\n",p_key);
        fprintf(payrolllist,"%s\n",portfolio.fname);
        fprintf(payrolllist,"%s\n",portfolio.lname);
        fprintf(payrolllist,"%s\n",portfolio.department);
        fprintf(payrolllist,"%d\n",calculation.gross_salary);
        fprintf(payrolllist,"%d\n",calculation.taxded);
        fprintf(payrolllist,"%d\n",calculation.nisded);
        fprintf(payrolllist,"%d",calculation.net_salary);
        fclose(payrolllist);
        break;

    case'r':
        clrscr();
        addpayroll();
        break;

    case 'x':
        exit(1);
        break;
    }
    clrscr();
    printf("///...Payroll Management > Add Payroll > Save Confirmed\n\n\n\n");
    puts("Entry Saved!");
    puts("M: Back to Menu");
    puts("X: Exit");

after_save:

    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
       goto after_save;
    }

}


void clrscr()///   [CLEAR SCREEN] Function #3
{
    system("@cls||clear");
}

void viewallpayrolls() /// [View all Payrolls] Function #4
{
    printf("///..View All Payrolls >\n\n\n");
    payrolllist=fopen("payrolllist.txt","r");

    while(!feof(payrolllist))
    {
        fscanf(payrolllist,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%d",&p_key,&portfolio.fname,&portfolio.lname,&portfolio.department,&calculation.gross_salary,&calculation.taxded,&calculation.nisded,&calculation.net_salary);
        printf("\nPID: %d",p_key);
        printf("\nFirst Name: %s,",&portfolio.fname);
        printf("\nLast Name: %s",&portfolio.lname);
        printf("\nOccupation: %s",&portfolio.department);
        printf("\nGross Salary: $%d",calculation.gross_salary);
        printf("\nTax Deduction: $%d",calculation.taxded);
        printf("\nNIS Deduction: $%d",calculation.nisded);
        printf("\nNet Salary: $%d\n\n",calculation.net_salary);
    }
    fclose(payrolllist);
    puts("M: Back to Menu");
    puts("X: Exit");

viewallpay:
    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto viewallpay;
    }
}
void viewallemployees()
{
    printf("///..View All Employees >\n\n\n\n");
    employeelist=fopen("employeelist.txt","r");
    while(!feof(employeelist))
    {
        fscanf(employeelist,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",&e_key,&portfolio.fname,portfolio.lname,&portfolio.gender,&portfolio.dateofbirth,&portfolio.department,&portfolio.datehired);
        printf("\n\n...>ID: %d",e_key);
        printf("\n...>Name: %s %s", &portfolio.fname, &portfolio.lname);
        printf("\n...>Gender: %s",&portfolio.gender);
        printf("\n...>Date of Birth: %s", &portfolio.dateofbirth);
        printf("\n...>Occupation: %s", &portfolio.department);
        printf("\n...>Date Hired: %s\n",&portfolio.datehired);
        printf("\n\n\n\n\n");
    }
    fclose(employeelist);
    puts("M: Back to Menu");
    puts("X: Exit");

viewallemp:
    switch(tolower(getch()))
    {
    case 'm':
        clrscr();
        main_menu();
        break;

    case 'x':
        exit(1);
        break;
    default:
        goto viewallemp;
    }
}

int e_checkKey()
{
    e_keys=fopen("e_key.txt","r");
    fscanf(e_keys,"%d",&e_key);
    fclose(e_keys);
}

int e_createKey()
{
    e_keys=fopen("e_key.txt","w");
    if(e_key<=0)
    {
        e_key=1;
    }
    else
    {
        e_key=e_key+1;
    }
    fprintf(e_keys,"%d",e_key);
    fclose(e_keys);
}


int p_checkKey()
{
    p_keys=fopen("p_key.txt","r");
    fscanf(p_keys,"%d",&p_key);
    fclose(p_keys);
}

int p_createKey()
{
    p_keys=fopen("p_key.txt","w");
    if(p_key<=0)
    {
        p_key=1;
    }
    else
    {
        p_key=p_key+1;
    }
    fprintf(p_keys,"%d",p_key);
    fclose(p_keys);
}


