#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudRec{
    char studNum[256];
    int yrLevel;
    int age;
    int FinGrade;
    char LName[256];
    char FName[256];
    char course[256];
    char sex[256];
    struct StudRec* next;
}* head;

typedef struct StudRec StudRec;

int NumNodes(StudRec* node){
    int count = 0;
    StudRec* ptr = NULL;

    if(node == NULL){
        count = 0;
    }

    ptr = node;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    return count;    
}

void menudisp(){
    printf("\n");
    printf("1. Enrol a student\n");
    printf("2. Drop a student\n");
    printf("3. Edit a student\n");
    printf("4. Display all students\n");
    printf("5. Filter students by last name\n");
    printf("6. Filter students by student number\n");
    printf("7. Filter students by year level\n");
    printf("8. Filter students by course\n");
    printf("9. Filter students by sex\n");
    printf("10. Filter students by passing\n");
    printf("11. Filter students by failing\n");
    printf("12. Sort students by last name\n");
    printf("13. Sort students by student number\n");
    printf("14. Exit\n");
    printf("\n");
    printf("? ");
}

void insertstudent(StudRec* student, char* SNum, char* first, char* last, char* Course, int YrLvl, int Age, char* Sex, int FinGr){
    student = (StudRec*) malloc(sizeof(StudRec));
    strcpy(student->studNum, SNum);
    strcpy(student->LName, last);
    strcpy(student->FName, first);
    strcpy(student->course, Course);
    student->yrLevel = YrLvl;
    student->age = Age;
    strcpy(student->sex, Sex);
    student->FinGrade = FinGr;
    student->next = NULL;

//if head is empty
    if(head == NULL){
        head = student;
    }
//if there already exists, insert the student in the head
    else{
        student->next = head;
        head = student;
    }
}

void DoubCheck(StudRec* temp, char* snum){
    temp = head;
    int x;

    while(temp != NULL){

        x = strcmp(temp->studNum, snum);
            if(x == 0){
                printf("\nStudent %s already exists.\n", temp->studNum);
                printf("Student Number: ");
                scanf("%s", snum);
            }
            else{
                continue;
            }

        temp = temp->next;
    }    
    
}

void RemoveStud(char* snum){
    StudRec* temp1 = head;
    StudRec* temp2 = head;
    int y;

    while(temp1 != NULL){
        y = strcmp(temp1->studNum, snum);

        if(y == 0){
            if(temp1 == temp2){
                head = head->next;
                free(temp1);
            }
            else{
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Deleted!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

}

void subdisplay(){ //menu for updating the student details
    printf("1. Student Number\n");
    printf("2. Last Name\n");
    printf("3. First Name\n");
    printf("4. Course\n");
    printf("5. Year Level\n");
    printf("6. Age\n");
    printf("7. Sex\n");
    printf("8. Final Grade\n");
    printf("9. Back\n");
    printf("\n");
    printf("? ");
}

void UpdateDeets(char*snum){
    int z;
    int choice;
    StudRec* tempo = head;

    while(tempo != NULL){
        z = strcmp(tempo->studNum, snum);

        if(z == 0){
            subdisplay();

            while(choice != 9){
                choice = 0;

                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("Student Number (%s): ", tempo->studNum);
                        scanf("%s", tempo->studNum);

                        printf("\nStudent Number updated!\n");

                        subdisplay();
                        break;

                    case 2:
                        printf("Last Name (%s): ", tempo->LName);
                        scanf("%s", tempo->LName);
                        
                        printf("\nLast Name updated!\n");

                        subdisplay();
                        break;

                    case 3:
                        printf("First Name (%s): ", tempo->FName);
                        scanf("%s", tempo->FName);

                        printf("\nFirst Name updated!\n");
                    
                        subdisplay();
                        break;

                    case 4:
                        printf("Course (%s): ", tempo->course);
                        scanf("%s", tempo->course);

                        printf("\nCourse updated!\n");

                        subdisplay();
                        break;

                    case 5:
                        printf("Year Level (%d): ", tempo->yrLevel);
                        scanf("%d", &tempo->yrLevel);    

                        printf("\nYear Level updated!\n");

                        subdisplay();
                        break;

                    case 6:
                        printf("Age (%d): ", tempo->age);
                        scanf("%d", &tempo->age);

                        printf("\nAge updated!\n");

                        subdisplay();
                        break;

                    case 7:
                        printf("Sex (%s): ", tempo->sex);
                        scanf("%d", tempo->sex);

                        printf("\nSex updated!\n");

                        subdisplay();
                        break;

                    case 8:
                        printf("Final Grade (%d): ", tempo->FinGrade);
                        scanf("%d", &tempo->FinGrade);

                        printf("\nFinal Grade updated!\n");

                        subdisplay();
                        break;

                    case 9:
                        break;
                        
                }
            }
            
        }
    }

    
}

void DisplayList(){
    StudRec* temp = head;
    int length;
    int count;

    length = NumNodes(temp);

    count = 0;

    while(temp != NULL){
        printf("Student Number: %s\n", temp->studNum);
        printf("Last Name: %s\n", temp->LName);
        printf("First Name: %s\n", temp->FName);
        printf("Course: %s\n", temp->course);
        printf("Year Level: %d\n", temp->yrLevel);
        printf("Age: %d\n", temp->age);
        printf("Sex: %s\n", temp->sex);
        printf("Final Grade: %d\n", temp->FinGrade);
        printf("\n");

        count++;

        printf("Displaying %d of %d student(s).\n", count, length);
        printf("\n");

        temp = temp->next;

    }

}

void FilterLName(char* lastname){
    StudRec* temp = head;
    int comp;

    while (temp != NULL){
        comp = strcmp(temp->LName, lastname);

        if(comp == 0){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");
        }

        temp = temp->next;
    }

}

void FilterSN(char* snum){
    StudRec* temp = head;
    int z;

    while(temp != NULL){
        z = strcmp(temp->studNum, snum);

        if(z == 0){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");

            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");

}

void FilterYLevel(int yearlvl){
    StudRec* temp = head;

    while(temp != NULL){
        if(temp->yrLevel == yearlvl){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");

        }

        temp = temp->next;
    }
}

void FilterCourse(char* course){
    StudRec* temp = head;
    int i;

    while(temp != NULL){
        i = strcmp(temp->course, course);

        if(i == 0){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");
        }

        temp = temp->next;
    }

}

void FilterSex(char* sex){
    StudRec* temp = head;
    int j;

    while(temp != NULL){
        j = strcmp(temp->sex, sex);

        if(j == 0){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");
        }

        temp = temp->next;
    }
}

void FilterPass(int fingr){
    StudRec* temp = head;

    while(temp != NULL){
        if(temp->FinGrade >= 60){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");
        }

        temp = temp->next;
    }
}

void FilterFail(int fingr){
    StudRec* temp = head;

    while(temp != NULL){
        if(temp->FinGrade < 60){
            printf("Student Number: %s\n", temp->studNum);
            printf("Last Name: %s\n", temp->LName);
            printf("First Name: %s\n", temp->FName);
            printf("Course: %s\n", temp->course);
            printf("Year Level: %d\n", temp->yrLevel);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final Grade: %d\n", temp->FinGrade);
            printf("\n");
        }

        temp = temp->next;
    }
}

void swap(StudRec* a, StudRec* b){    
    StudRec* temp;

//temp swap
    strcpy(temp->studNum, a->studNum);
    strcpy(temp->LName, a->LName);
    strcpy(temp->FName, a->FName);
    strcpy(temp->course, a->course);
    temp->yrLevel = a->yrLevel;
    temp->age = a->age;
    strcpy(temp->sex, a->sex);
    temp->FinGrade = a->FinGrade;

//a swap
    strcpy(a->studNum, b->studNum);
    strcpy(a->LName, b->LName);
    strcpy(a->FName, b->FName);
    strcpy(a->course, b->course);
    a->yrLevel = b->yrLevel;
    a->age = b->age;
    strcpy(a->sex, b->sex);
    a->FinGrade = b->FinGrade;

//b swap
    strcpy(b->studNum, temp->studNum);
    strcpy(b->LName, temp->LName);
    strcpy(b->FName, temp->FName);
    strcpy(b->course, temp->course);
    b->yrLevel = temp->yrLevel;
    b->age = temp->age;
    strcpy(b->sex, temp->sex);
    b->FinGrade = temp->FinGrade;

}

void Sort(StudRec* start, int opt){
    int swapped;
    int compare;
    int flag;
    StudRec* ptr1;
    StudRec* lptr = NULL;

    if(start == NULL){
        return;
    }

    do{
        swapped = 0;
        ptr1 = start;

        while(ptr1->next != lptr){

            if(opt == 12){
                StudRec* temp = ptr1->next;
                compare = strcmp(ptr1->LName, temp->LName);
                
                if(compare > 0){
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
            }
            else{
                StudRec* temp = ptr1->next;
                compare = strcmp(ptr1->studNum, temp->studNum);

                if(compare > 0){
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while(swapped);
}

void printSortLName(StudRec* temp){
    temp = head;

    while(temp != NULL){
        printf("Student Number: %s\n", temp->studNum);
        printf("Last Name: %s\n", temp->LName);
        printf("First Name: %s\n", temp->FName);
        printf("Course: %s\n", temp->course);
        printf("Year Level: %d\n", temp->yrLevel);
        printf("Age: %d\n", temp->age);
        printf("Sex: %s\n", temp->sex);
        printf("Final Grade: %d\n", temp->FinGrade);
        printf("\n");

        temp = temp->next;
    }
}

int main(){
    int opt;
    char* fname = (char*) malloc(sizeof(char)*15);
    char* lname = (char*) malloc(sizeof(char)*15);
    char* stnum = (char*) malloc(sizeof(char)*15);
    char* c = (char*) malloc(sizeof(char)*15);
    int yl, Age;
    char* s = (char*) malloc(sizeof(char)*15);
    int FG;
    StudRec stud;

    menudisp();

while(opt != 14){
    opt = 0;
        
    scanf("%d", &opt);

    switch(opt){
        case 1: //enrol
            printf("\n");
            printf("Enrol\n");

            printf("Student Number: ");
                scanf("%s", stnum);
                DoubCheck(&stud, stnum);

            printf("Last Name: ");
                scanf("%s", lname);
            printf("First Name: ");
                scanf("%s", fname);
            printf("Course: ");
                scanf("%s", c); //course
            printf("Year Level: ");
                scanf("%d", &yl); //year level
            printf("Age: ");
                scanf("%d", &Age);
            printf("Sex: ");
                scanf("%s", s); //sex
            printf("Final Grade: ");
                scanf("%d", &FG); //Final Grade            

            insertstudent(&stud, stnum, fname, lname, c, yl, Age, s, FG);

            printf("\n");
            printf("%s added!\n\n", stnum);

            

            menudisp();
            break;

        case 2: //drop
            printf("\n");
            printf("Drop\n");

            printf("Student Number: ");
                scanf("%s", stnum);
            printf("\n");

            RemoveStud(stnum);

            menudisp();
            break;

        case 3: //edit
            printf("\n");
            printf("Edit\n");

            printf("Student Number: ");
                scanf("%s", stnum);
            printf("\n");

            UpdateDeets(stnum);

            menudisp();
            break;

        case 4: //display
            printf("\n");
            DisplayList();
            
            menudisp();
            break;

        case 5: //filter - last name
            printf("\n");
            
            printf("Last Name: ");
                scanf("%s", lname);
            printf("\n");
            
            FilterLName(lname);

            menudisp();
            break;

        case 6: //filter - student num
            printf("\n");

            printf("Student Number: ");
                scanf("%s", stnum);
            printf("\n");
            
            FilterSN(stnum);

            menudisp();
            break;

        case 7: //filter - year level
            printf("\n");

            printf("Year Level: ");
                scanf("%d", &yl);
            printf("\n");
            
            FilterYLevel(yl);

            menudisp();
            break;

        case 8: //filter - course
            printf("\n");

            printf("Course: ");
                scanf("%s", c);
            printf("\n");

            FilterCourse(c);

            menudisp();
            break;

        case 9: //filter - sex
            printf("\n");

            printf("Sex: ");
                scanf("%s", s);
            printf("\n");

            FilterSex(s);

            menudisp();
            break;

        case 10: //filter - passing
            printf("\n");

            FilterPass(FG);

            menudisp();
            break;

        case 11: //filter - failing
            printf("\n");
            
            FilterFail(FG);

            menudisp();
            break;

        case 12: //sort - last name
            printf("\n");

            Sort(&stud, opt);

            printSortLName(&stud);

            menudisp();
            break;

        case 13: //sort - student num
            printf("\n");

            Sort(&stud, opt);

            printSortLName(&stud);

            menudisp();
            break;

        case 14: //exit

            break;
    }
}

    

}
/*
Construct a structure that represents a student record. The structure should at least have the following information:

hyphenated student number
last name
first name
course
year level
age
sex
final grade (0 - 100, 60 passing)
Construct the linked list that will contain the student records as well.

Prompt the user with a menu:

1. Enrol a student
2. Drop a student
3. Edit a student
4. Display all students
5. Filter students by last name
6. Filter students by student number
7. Filter students by year level
8. Filter students by course
9. Filter students by sex
10. Filter students by passing
11. Filter students by failing
12. Sort students by last name
13. Sort students by student number
14. Exit

?
For menu item:

1. Ask the user to enter information necessary for a student. Then add the student to the list. Make sure no duplicate students are enrolled in the class. The student number uniquely identifies a student.

2.Ask the user to enter the student number of the student to drop. Remove the student from the list.

3.Ask the user to enter the student number of the student to edit. Prompt the user with a sub-menu displaying all the fields that can be edited. Note that the user may edit more than 1 field.

4.Display all students in the list.

5.Ask the user for a last name. Display only the students with that last name.

6.Ask the user for a student number. Display that student's information.

7.Ask the user for a year level. Display only students with that year level.

8.Ask the user for a course. Display only students with that course.

9.Ask the user for a sex. Display only students with that sex.

10.Display only passing students' information.

11.Display only failing students' information.

12.Display all students' information sorted by last name.

13.Display all students' information sorted by student number.

14.Exit.

All text inputs should not have any spaces and will have at most 15 characters.

Sample Flow
1. Enrol a student
2. Drop a student
3. Edit a student
4. Display all students
5. Filter students by last name
6. Filter students by student number
7. Filter students by year level
8. Filter students by course
9. Filter students by sex
10. Filter students by passing
11. Filter students by failing
12. Sort students by last name
13. Sort students by student number
14. Exit

? 1

Enrol
Student number: 2030-12345
Last name: Wurtzbach
First name: Pia
Course: BSCS
Year level: 2
Age: 20
Sex: Female
Final grade: 89

2030-12345 added!

1. Enrol a student
2. Drop a student
3. Edit a student
4. Display all students
5. Filter students by last name
6. Filter students by student number
7. Filter students by year level
8. Filter students by course
9. Filter students by sex
10. Filter students by passing
11. Filter students by failing
12. Sort students by last name
13. Sort students by student number
14. Exit

? 3
Student number: 2030-12345

Edit
1. Student number
2. Last name
3. First name
4. Course
5. Year level
6. Age
7. Sex
8. Final grade
9. Back

? 8
Final grade (89): 94

Final grade updated!

Edit 2030-12345
1. Student number
2. Last name
3. First name
4. Course
5. Year level
6. Age
7. Sex
8. Final grade
9. Back

? 9 

1. Enrol a student
2. Drop a student
3. Edit a student
4. Display all students
5. Filter students by last name
6. Filter students by student number
7. Filter students by year level
8. Filter students by course
9. Filter students by sex
10. Filter students by passing
11. Filter students by failing
12. Sort students by last name
13. Sort students by student number
14. Exit

? 4

Student number: 2030-12345
Last name: Wurtzbach
First name: Pia
Course: BSCS
Year level: 2
Age: 20
Sex: Female
Final grade: 89

Displaying 1 of 1 student(s)

1. Enrol a student
2. Drop a student
3. Edit a student
4. Display all students
5. Filter students by last name
6. Filter students by student number
7. Filter students by year level
8. Filter students by course
9. Filter students by sex
10. Filter students by passing
11. Filter students by failing
12. Sort students by last name
13. Sort students by student number
14. Exit

? 14
*/