#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studrec{
    int studentnum;
    int yearlevel;
    int Age;
    int finalgrade;
    char lastname[15];
    char firstname[15];
    char Course[15];
    char Sex[15];
    int act;
};

typedef struct studrec studrec;

void displaymenu(){
    printf("\n\n");
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

studrec getStudRec(int find){
    FILE* fp = fopen("studdata.bin", "wb+");
    studrec student, ret;

    if(!fp){
        printf("Oh no, an error occurred!");
    }

    ret.act = 0;
    while(fread(&student, sizeof(studrec), 1, fp) && !feof(fp)){
        if(student.studentnum == find && student.act == 1){
            ret = student;
        }
    }

    fclose(fp);
    return ret;

}

int doublecheck(int find){
    FILE* fp = fopen("studdata.bin", "rb+");
    studrec student;
    int ex = 0;

    if(!fp){
        printf("Oh no, an error occurred!");
    }

    while(fread(&student, sizeof(studrec), 1, fp) && !feof(fp)){
        if(student.studentnum == find && student.act == 1){
            ex = 1;
        }
    }

    fclose(fp);
    return ex;

}

void insert(studrec* student, char* source, int type){
    int i;

    for(i = 0; source[i] != '\0'; i++){
        if(type == 1){
            student->lastname[i] = source[i];
        }
        if(type == 2){
            student->firstname[i] = source[i];
        }
        if(type == 3){
            student->Course[i] = source[i];
        }
        if(type == 4){
            student->Sex[i] = source[i];
        }
    }
}

char toUpperchar(char ch){
    if(ch >= 97 && ch <= 122){
        ch-=32;
    }
    return ch;
}

int compStr(char* a, char* b){
    int i;

    for(i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(toUpperchar(a[i]) != toUpperchar(b[i])){
            return 0;
        }
    }
    return 1;
}

int compStrsize(char* a, char* b){
    int i;

    for(i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(a[i] > b[i]){
            return 1;
        }
    }

    return 0;
}

void enrol(){
    studrec stud;
    FILE* fp = fopen("studdata.bin", "rb+");

    if(!fp){
        printf("Oh no, an error occurred!");
    }
    else{
        printf("Student Number: ");
        scanf("%d", &stud.studentnum);
            if(doublecheck(stud.studentnum)){
                printf("Student Number %d already exists.\n", stud.studentnum);
                    return;
                }
        printf("Last Name: ");
        scanf("%s", &stud.lastname);
        printf("First Name: ");
        scanf("%s", &stud.firstname);
        printf("Course: ");
        scanf("%s", &stud.Course);
        printf("Year Level: ");
        scanf("%d", &stud.yearlevel);
        printf("Age: ");
        scanf("%d", &stud.Age);
        printf("Sex: ");
        scanf("%s", &stud.Sex);
        printf("Final Grade: ");
        scanf("%d", &stud.finalgrade);
    
        stud.act = 1;
        fseek(fp, sizeof(studrec)*(stud.studentnum - 1), SEEK_SET);
        fwrite(&stud, sizeof(studrec), 1, fp);
        printf("%d added!", stud.studentnum);  
    }

    fclose(fp);
}

void drop(int studnum){
    studrec stud;
    char* new = (char*) malloc(sizeof(char) * 15);
    FILE* fp = fopen("studdata.bin", "rb+");

    if(!fp){
        printf("Oh no, an error occurred!");
    }
    else{
        if(studnum == -1){
            printf("Student Number: ");
            scanf("%d", &stud.studentnum);
        }
        else{
            stud.studentnum = studnum;
        }
        
        if(doublecheck(stud.studentnum)){
            if(studnum == -1){
                printf("Record Deleted!", stud.studentnum);
            }

            stud.act = 0;
            insert(&stud, new, 1);
            insert(&stud, new, 2);
            insert(&stud, new, 3);
            stud.yearlevel = 0;
            stud.Age = 0;
            insert(&stud, new, 4);
            stud.finalgrade = 0;

            fseek(fp, sizeof(studrec) * (stud.studentnum - 1), SEEK_SET);
            fwrite(&stud, sizeof(studrec), 1, fp);

        }
        else{
            if(studnum == -1){
                printf("%d does not exist.", stud.studentnum);
            }
        }
    }
    free(new);
    fclose(fp);
    
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

void update(){
    studrec student;
    int ex;
    int choice, choice2 = 0;
    char* new = (char*)malloc(sizeof(char) * 15);
    FILE* fp = fopen("studdata.bin", "rb+");

    if(!fp){
        printf("Oh no, an error occurred!");
    }
    else{
        printf("Student Number: ");
        scanf("%d", &student.studentnum);

        if(doublecheck(student.studentnum)){
            student = getStudRec(student.studentnum);

            if(student.act != 1){
                printf("Error!");
                return;
            }

            while(choice != 9){
                choice = 0;

                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        ex = student.studentnum;
                        printf("Student Number (%s): ", student.studentnum);
                        scanf("%s", &student.studentnum);
                        if(doublecheck(student.studentnum)){
                            printf("Student number %d already exists.\n", student.studentnum);
                            printf("(1) Overwrite\n(2) Back to submenu display?\n(3) Exit\n?");
                            scanf("%d", &choice2);

                            if(choice2 == 1){
                                printf("Overwritten successful!\n\n");
                            }
                            else if(choice2 == 2){
                                subdisplay();
                                break;
                            }
                            else if(choice2 == 3){
                                break;
                            }
                        }

                        drop(student.studentnum);
                        student.studentnum = ex;
                        printf("\nStudent Number updated!\n");

                        subdisplay();
                        break;
                    case 2:
                        printf("Last Name (%s): ", student.lastname);
                        scanf("%s", &student.lastname);
                        
                        printf("\nLast Name updated!\n");

                        subdisplay();
                        break;
                    case 3:
                        printf("First Name (%s): ", student.firstname);
                        scanf("%s", &student.firstname);

                        printf("\nFirst Name updated!\n");
                    
                        subdisplay();
                        break;
                    case 4:
                        printf("Course (%s): ", student.Course);
                        scanf("%s", &student.Course);

                        printf("\nCourse updated!\n");

                        subdisplay();
                        break;
                    case 5:
                        printf("Year Level (%d): ", student.yearlevel);
                        scanf("%d", &student.yearlevel);    

                        printf("\nYear Level updated!\n");

                        subdisplay();
                        break;
                    case 6:
                        printf("Age (%d): ", student.Age);
                        scanf("%d", &student.Age);

                        printf("\nAge updated!\n");

                        subdisplay();
                        break;
                    case 7:
                        printf("Sex (%s): ", student.Sex);
                        scanf("%d", &student.Sex);

                        printf("\nSex updated!\n");

                        subdisplay();
                        break;
                    case 8:
                        printf("Final Grade (%d): ", student.finalgrade);
                        scanf("%d", &student.finalgrade);

                        printf("\nFinal Grade updated!\n");

                        subdisplay();
                        break;
                    case 9:
                        break;
                }
            }
            fseek(fp, sizeof(studrec) * (student.studentnum - 1), SEEK_SET);
            fwrite(&student, sizeof(studrec), 1, fp);
        }

        else{
            printf("%d does not exist!", student.studentnum);
        }
    }
    free(new);
    fclose(fp);
}

void display(int type){
    studrec student;
    int count, fcount;
    FILE* fp = fopen("studdata.bin", "rb+");

    count = 0;
    fcount = 0;

    if(!fp){
        printf("Oh no, an error occurred!");
    }
    else{
        while(fread(&student, sizeof(studrec), 1, fp) && !feof(fp)){
            if(student.act == 1){
                printf("Student Number: %d\n", student.studentnum);
                printf("Last Name: %s\n", student.lastname);
                printf("First Name: %s\n", student.firstname);
                printf("Course: %s\n", student.Course);
                printf("Year Level: %d\n", student.yearlevel);
                printf("Age: %d\n", student.Age);
                printf("Sex: %s\n", student.Sex);
                printf("Final Grade: %d\n", student.finalgrade);
                printf("\n");

                count++;
            }
            fcount++;
        }
        printf("Displaying %d of %d students.\n", count, fcount);
    }

    fclose(fp);
}

void filterDisp(int type){
    studrec student;
    int count = 0, fcount = 0;
    char inpChar[15];
    int inpInt;
    FILE* fp = fopen("studdata.bin", "rb+");

    if(!fp){
        printf("Oh no, an error occurred!");
    }
    else{
        if(type == 1){
            printf("Last Name: ");
            scanf("%s", inpChar);
        }
        if(type == 2){
            printf("Student Number: ");
            scanf("%d", &inpInt);
        }
        if(type == 3){
            printf("Year Level: ");
            scanf("%d", &inpInt);
        }
        if(type == 4){
            printf("Course: ");
            scanf("%s", &inpChar);
        }
        if(type == 5){
            printf("Sex: ");
            scanf("%s", inpChar);
        }

        while(fread(&student, sizeof(studrec), 1, fp) && !feof(fp)){
            if(student.act == 1){
                if((type == 1 && compStr(student.lastname, inpChar)) || (type == 2 && student.studentnum == inpInt) || (type == 3 && student.yearlevel == inpInt) || (type == 4 && compStr(student.Course, inpChar)) || (type == 5 && compStr(student.Sex, inpChar)) || (type == 6 && student.finalgrade >= 60) || (type == 7 && student.finalgrade < 60)){
                    printf("Student Number: %d\n", student.studentnum);
                    printf("Last Name: %s\n", student.lastname);
                    printf("First Name: %s\n", student.firstname);
                    printf("Course: %s\n", student.Course);
                    printf("Year Level: %d\n", student.yearlevel);
                    printf("Age: %d\n", student.Age);
                    printf("Sex: %s\n", student.Sex);
                    printf("Final Grade: %d\n", student.finalgrade);
                    printf("\n");

                    count++;
                }
                fcount++;
            }
        }
        printf("Displaying %d of %d students.\n", count, fcount);
    }
    fclose(fp);

}

void swap(studrec* a, studrec* b){
    studrec temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int type){
    studrec stud;
    int size, a;
    int i, j;
    FILE* fp = fopen("studdata.bin", "rb+");
    FILE* fp2 = fopen("studdata.bin", "rb+");

    size = 0;
    a = 0;

    if(!fp || !fp2){
        printf("Oh no, an error occurred!");
    }
    else{
        while(fread(&stud, sizeof(studrec), 1, fp) && !feof(fp)){
            if(stud.act == 1){
                size++;
            }
        }

        studrec array[size];

        while(fread(&stud, sizeof(studrec), 1, fp2) && !feof(fp2)){
            if(stud.act == 1){
                array[a] = getStudRec(stud.studentnum);
                a++;
            }
        }

        for(i = 0; i < size; i++){
            for(j = 0; j < size-i-1; j++){
                if((type == 1 && compStrsize(array[j].lastname, array[j + 1].lastname)) || type == 2 && array[j].studentnum > array[j + 1].studentnum){
                    swap(&array[j], &array[j + 1]);
                }
            }
        }

        for(i = 0; i < size; i++){
            printf("Student Number: %d\n", array[i].studentnum);
            printf("Last Name: %s\n", array[i].lastname);
            printf("First Name: %s\n", array[i].firstname);
            printf("Course: %s\n", array[i].Course);
            printf("Year Level: %d\n", array[i].yearlevel);
            printf("Age: %d\n", array[i].Age);
            printf("Sex: %s\n", array[i].Sex);
            printf("Final Grade: %d\n", array[i].finalgrade);
            printf("\n");
        }

        printf("Displaying %d of %d students.\n", a, size);
    }

    fclose(fp);
    fclose(fp2);
}

int main(){
    int option;
    int StudNum;
    char lname;
    char fname;
    char course;
    int yrlvl;
    int age;
    char sex;
    int fingr;
    studrec stud;

    displaymenu();

while(option != 14){
    option = 0;

    scanf("%d", &option);

    switch(option){
        case 1:
            printf("\n");
            printf("Enroll\n\n");

            enrol();
        
            displaymenu();
            break;
        case 2:
            printf("\n");
            printf("Drop\n\n");
            
            drop(-1);
        
            displaymenu();
            break;
        case 3:
            printf("\n");
            printf("Edit\n\n");
        
            displaymenu();
            break;
        case 4:
            printf("\n");
            display(1);

            displaymenu();
            break;
        case 5:
            printf("\n");
            filterDisp(1);
        
            displaymenu();
            break;
        case 6:
            printf("\n");
            filterDisp(2);

            displaymenu();
            break;
        case 7:
            printf("\n");
            filterDisp(3);

            displaymenu();
            break;
        case 8:
            printf("\n");
            filterDisp(4);
        
            displaymenu();
            break;
        case 9:
            printf("\n");
            filterDisp(5);
        
            displaymenu();
            break;
        case 10:
            printf("\n");
            filterDisp(6);
        
            displaymenu();
            break;
        case 11:
            printf("\n");
            filterDisp(7);
        
            displaymenu();
            break;
        case 12:
            printf("\n");
            sort(1);

            displaymenu();
            break;
        case 13:
            printf("\n");
            sort(2);

            displaymenu();
            break;
        case 14:
            break;
    }
}

}