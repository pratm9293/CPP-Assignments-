
#include <iostream>

using namespace std;

int main()
{
    int b[8][8] = {0};
    int r, c = 0;
    b[r][c] = 1;
    nc: c++;
    if(c==8){
        goto print;
    }
    r=-1;
    nr: r++;
    if(r==8){
        goto backtrack;
    }

    for(int i = 0; i<c; i++){
        if(b[r][i]==1){
            goto nr;                                        // Checks to the left of the current element
        }else{
            for(int i = 0; r-i>-1 && c-i>-1; i++){
                if(b[r-i][c-i]==1){                         // Checks to the diagonal going up.
                goto nr;
            }else{
                for(int i = 0; r+i<8 && c-i>-1; i++){
                        if(b[r+i][c-i]==1){                 // Checks to the diagonal going down.
                            goto nr;
                                }else{
                                    b[r][c]= 1;             // Once through all 3 tests, place queen and then go to the next column.
                                    goto nc;
                                    }
                                }
                            }
                        }
                    }
                }




//we backtrack after we have found the first solution to find others.
   backtrack: c--;
   if(c==-1){
    return 0;
   }else{
   r=0;
   while(b[r][c]!=1){
    r++;
    b[r][c] = 0;
    goto nr;
   }
   }
//printing 2d arrays
 print: for(int i=0; i<c; i++){
            for(int j=0; j<r; j++){
                cout << b[i][j] << " " ;
            }
            cout << endl;
            }
       goto backtrack;


}
