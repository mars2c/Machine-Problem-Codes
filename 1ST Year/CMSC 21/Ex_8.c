#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vector{
    int size;
    int capacity;
    char *arr;
};
typedef struct vector vector;

void resize(vector* vecarr){
    int new = 2 * vecarr->size;
    char* newarr = (char*) malloc(sizeof(char) * new);
    int l;

    for(l = 0; l < vecarr->size; l++){
        newarr[l] = vecarr->arr[l];
    }

    vecarr->capacity = new;
    free(vecarr->arr);
    vecarr->arr = newarr; 
}

void insertItem(vector* veclist, int index, char item) {
    if(index >= 0 && index <= veclist->size){
        if(veclist->size == veclist->capacity){
            resize(veclist);
        }

        for(int i = veclist->size; i > index; i--) {
            veclist->arr[i] = veclist->arr[i - 1];
        }
            veclist->arr[index] = item;
            veclist->size++;
    }
    
    return;
}

void initString(vector* vecarr, char* str){
    int i;

    vecarr->size = 0;
    vecarr->capacity = strlen(str) + 1;
    vecarr->arr = (char*) malloc(sizeof(char) * vecarr->capacity);
    
    for(i = 0; str[i] != '\0'; i++){
        insertItem(vecarr, i, str[i]);
    }

    vecarr->arr[i] = '\0';

}

void concatenate(vector* combined, vector* a, vector*b){
    int j, k;
    char* newstring = (char*)malloc(sizeof(char) * (a->size + b->size));

    j = 0;
    k = 0;

    while(j < a->size){
        newstring[j] = a->arr[j];
        j++;
    }
    
    while(k < b->size){
        newstring[j + k] = b->arr[k];
        k++;
    }

    newstring[j + k] = '\0';
    initString(combined, newstring);

    printf("%s\n", newstring);
}

void slice(vector* sliced, vector* c, int start, int end){
    int l;
    char* newstring = (char*) malloc(sizeof(char) * c->capacity);

    for(l = start; l < end; l++){
        newstring[l - start] = c->arr[l];
    }

    newstring[l - start] = '\0';
    initString(sliced, newstring);

    printf("%s\n", newstring);

}

int main(){
    int opt;
    int start, end;
    char str1[15];
    char str2[15];
    vector a, b, comb;
    vector c, sliced;

    opt = 0;
    start = 0;
    end = 0;

    scanf("%d", &opt);

    if(opt == 1){
        scanf("%s %s", str1, str2);
        initString(&a, str1);
        initString(&b, str2);

        concatenate(&comb, &a, &b);

    }
    else if(opt == 2){
        scanf("%s", str1);
        scanf("%d %d", &start, &end);

        initString(&c, str1);

        slice(&sliced, &c, start, end);

    }

    return 0;
}


