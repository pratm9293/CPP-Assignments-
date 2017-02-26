#include <iostream>
#include <cstdlib>
using namespace std;

bool isThisValid(int q[8],int col){

    int adj[8][7]={{-1},
                    {0,-1,-1},
                    {1,-1, -1},
                    {0,1,2,-1,-1},
                    {1,2,3,-1,-1},
                    {0,3,4,-1,-1},
                    {3,4,5,-1,-1},
                    {2,4,6,-1,-1}
                    };

    for(int i=0;i<col;i++){
        if(q[i]==q[col])
        {
            return false;
        }
    }

    for(int i=0; adj[col][i]!=-1;i++){
        if(abs(q[col]-q[adj[col][i]])==1)
        {
            return false;
        }
    }

    return true;
}

void print(int q[8]){

    cout << q[0] << q[1] << endl;
    cout << q[2] << q[3] <<q[4] << q[5] << endl;
    cout << q[6] << q[7] << endl;
}

void placeNum(int* q, int i){

    int num = 1;

    if(i==8){
        print(q);
        return;
    }

    while(num<=8)   //create a loop to keep checking nums upto 8
    {
        num++;
        q[i] = num;
        if(isThisValid(q, i))
        {
            placeNum(q, i+1); //recursively call and place numbers in 8 cross until base case is reached.
        }
    }

};

int main(){
    int q[8]; // create an array of 8 elements
    placeNum(q,0); //start off at element 0 and pass address to array q
    return 0;
}
