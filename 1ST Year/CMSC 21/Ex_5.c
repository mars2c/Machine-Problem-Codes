#include <stdio.h>

void sortfunc(int n, int* pointer){
    int i, j, k;

    //Sort numbers using pointers
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            // Compare the values
            if(*(pointer + j) < *(pointer + i)){
                k = *(pointer + i);
                *(pointer + i) = *(pointer + j);
                *(pointer + j) = k;
            }//end of if
        }//end of for j
    }//end of for i

    for(i = 0; i < n; i++){
    printf("%d ", *(pointer + i));
    }
}//end of function

int main(){
    int n;
    int nums[256];
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", (nums + i));
    }

    sortfunc(n, nums);

    return 0;
}