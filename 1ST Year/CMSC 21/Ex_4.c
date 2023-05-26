#include <stdio.h>
#include <stdlib.h>

int **matrix(int n, int m){
    int i, j;
    int **x;
    int bin;
    x = malloc(sizeof(int*) * n);

    for(i = 0; i < n; i++){
        x[i] = malloc(sizeof(int*) * m);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &bin);
            x[i][j] = bin;           
        }
    }
    return x;
}

int checkarr(int arrX[], int m, int grpval1){
    int k, j;
    int withgap = 0;
    int grpval2 = 0;

    //scan array left to right; small value wins
    for(k = 0; k < m; k++){
        if((arrX[k] == 0) && (k != 0) && (k != (m-1))){
            withgap = 1;
            continue;  
        }
        else if((arrX[k] < arrX[k + 1]) && (arrX[k] != 0) && arrX[k + 1] != 0){
            arrX[k + 1] = arrX[k];
            
            if(withgap == 0){
            grpval1 = arrX[k + 1];
            }
        }
        else if((arrX[k] > arrX[k + 1]) && (arrX[k] != 0) && arrX[k + 1] != 0){
            arrX[k] = arrX[k + 1];

            if(withgap == 0){
            grpval1 = arrX[k];
            }
        }
        else{
            continue;
        }
        
    }//end for for loop

    for(j = m - 1; j > -1; j--){
        if((arrX[j] == 0) && (j != 0) && (j != (m-1))){
            withgap = 1;
            continue;  
        }
        else if((arrX[j] < arrX[j - 1]) && (arrX[j] != 0) && arrX[j - 1] != 0){
            arrX[j - 1] = arrX[j];

            if(withgap == 0){
            grpval2 = arrX[j - 1];
            }
        }
        else if((arrX[j] > arrX[j - 1]) && (arrX[j] != 0) && arrX[j - 1] != 0){
            arrX[j] = arrX[j + 1];

            if(withgap == 0){
            grpval2 = arrX[j];
            }
        }
        else{
            continue;
        }        
    }//end for for loop

        if(grpval1 < grpval2){
            return grpval2;
        }
        else{
            return grpval1;
        }

}

int groupcount(int lineA[], int lineB[], int group, int m, int flag){
    int y, a, count;
    int arrA[256], arrB[256];

// dbg: process each element of array
    for(y = 0; y < m; y++){
// dbg: process arrA            
        if(flag == 0){
// dbg: process index 0
            if(y == 0){
                // check up index if there is group 
                if( (lineB[y] > 0) && (lineA[y] == 1)){
                // it should be same group   
                    lineA[y] = lineB[y]; 
                }
                // check up-next index if there is group
                else if( (lineB[y+1] > 0) && (lineA[y] == 1)){
                // it should be same group   
                    lineA[y] = lineB[y+1]; 
                }
                // check if next is 1
                else if((lineA[y + 1] > 0) && (lineA[y] == 1)){
                // current should have group value    
                  group++;
                  lineA[y] = group;
                }
                else if(lineA[y] == 1){
                    group++;
                    lineA[y] = group;
                }
                else 
                     continue;
            } //end of if y == 0
// dbg: process the last index
            else if(y == m){
                // check up index if there is group
                if((lineB[y] > 0) && (lineA[y] > 0)){
                   // it should be same group
                   lineA[y] = lineB[y];
                }
                // check up-left index if there is group
                else if((lineB[y-1] > 0) && (lineA[y] > 0)){
                    // it should be same group
                    lineA[y] = lineB[y-1];
                }
                // check left index 
                else if((lineA[y - 1] > 0) && (lineA[y] > 0)){
                    lineA[y] = lineA[y - 1]; 
                }
                else if(lineA[y] > 0){
                    group++;
                    lineA[y] = group;
                }
                else
                   continue;
            } // end of if y == m           
// dbg: process the middle indeces
            else{
                // check left-top if there is group
                if((lineB[y - 1] > 0) && (lineA[y] > 0)){
                    // it should be same group
                    lineA[y] = lineB[y - 1];
                }
                // check top if there is group
                else if((lineB[y] > 0) && (lineA[y] > 0)){
                    // it should be same group
                    lineA[y] = lineB[y];
                }
                // check top-right if there is group
                else if((lineB[y + 1] > 0) && (lineA[y] > 0)){
                    lineA[y] = lineB[y + 1];
                }
                // check left if there is group
                else if((lineA[y - 1] > 0) && (lineA[y] > 0)){
                    // it should be same groupo
                    lineA[y] = lineA[y - 1];
                }
                else if(lineA[y] > 0){
                    group++;
                    lineA[y] = group;
                }
                else
                    continue;        
            } // end of else
        } // end of flag == 0
// dbg: process arrB        //flag = 1
        else{ 
            if(y == 0){
                // check up index if there is group
                if((lineA[y] > 0) && (lineB[y] == 1)){
                // should be same group
                    lineB[y] = lineA[y];
                }
                else if((lineA[y + 1] > 0) && (lineB[y] == 1)){
                // should be same group
                    lineB[y] = lineA[y + 1];
                }
                // check if next is 1
                else if((lineB[y + 1] > 0) && (lineB[y] == 1)){
                // current should have group value
                    group++;
                    lineB[y] = group;
                }
                else if(lineB[y] == 1){
                    group++;
                    lineB[y] = group;
                }
                else{
                    continue;
                }                        
            }// end of y == 0
//dbg: process the last index
            else if(y == m){
                //check up index if there is group
                if((lineA[y] > 0) && (lineB[y] > 0)){
                    //should be same group
                    lineB[y] = lineA[y];
                }
                //check up left index if there is group
                else if((lineA[y - 1] > 0) && (lineB[y] > 0)){
                    //should be same group
                    lineB[y] = lineA[y - 1];
                }
                //check left index
                else if((lineB[y - 1] >0) && (lineB[y] > 0)){
                    lineB[y] = lineB[y - 1];
                }
                else if(lineB[y] > 0){
                    group++;
                    lineB[y] = group;
                }
                else{
                    continue;
                }
            } //end of y == m
// dbg: process the middle indeces
            else{
                //check left-top if there is group
                if((lineA[y - 1] > 0) && (lineB[y] > 0)){
                    //should be same group
                    lineB[y] = lineA[y - 1];
                }
                //check top if there is group
                else if((lineA[y] > 0) && (lineB[y] > 0)){
                    //should be same group
                    lineB[y] = lineA[y];
                }
                //check tip-right if there is group
                else if((lineA[y + 1] > 0) && (lineB[y] > 0)){
                    lineB[y] = lineA[y + 1];
                }
                //check left if there is group
                else if((lineB[y - 1] > 0) && (lineB[y] > 0)){
                    //should be same group
                    lineB[y] = lineB[y - 1];
                }
                else if(lineB[y] > 0){
                    group++;
                    lineB[y] = group;
                }
                else{
                    continue;
                }
            } //end of else
        }// end of else flag = 1
    }//end of for loop

    if(flag == 0){
        group = checkarr(lineA, m, group);
    }
    else{
        group = checkarr(lineB, m, group);
    }

    return group;
}

int main(){    
    int n, m;
    int **arr;
    int i, j, index, x, y;
    int group = 0; 
    int arrA[256] = {0};
    int arrB[256] = {0};
    int flag = 0;
    int a;

    scanf("%d %d", &n, &m);

    arr = matrix(n, m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if((j == m - 1)){
            } 
        }
    }

// row
    for(x = 0; x < n; x++){
// column
        for(y = 0; y < m; y++){
// if index is 1
            if(flag == 0){
                arrA[y] = arr[x][y];
            }
            else{
                arrB[y] = arr[x][y];
            }               
        }//end for y
        group = groupcount(arrA, arrB, group, y, flag);
        if(flag == 0){
            flag = 1;
        }
        else{
            flag = 0;
        }
    }//end for x

    printf("%d\n", group);
    return 0;
}