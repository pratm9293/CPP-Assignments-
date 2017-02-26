#include <iostream>
#include <cstdlib>

#include <cmath>

using namespace std;


bool ok(int q[], int col)
{
    int mp[3][3] = {{0,2,1},
                    {0,2,1},
                    {1,2,0}};
    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    int current_man, new_man, current_woman, new_woman;

    for(int i=0; i<col; i++)
    {
        current_man = i;
        current_woman = q[i];

        new_man= col;
        new_woman = q[col];

        if(current_woman==new_woman)   // check through each iteration in q[] to see if any of the woman picked is already in a relationship.
        {
            return false;
        }
    }

    for(int i=0; i<col; i++)
    {
        current_man = i;
        current_woman = q[i];
        new_man = col;
        new_woman = q[col];



        if(mp[current_man][current_woman]>mp[current_man][new_woman]&& //if the numb of pref for current man/woman is larger than current man/new woman
           wp[new_woman][current_man]<wp[new_woman][new_man]) //if numb of new woman and her current man is less than new woman and new man, this fails as its unstable.
           {
            return false;
           }



        if(mp[new_man][current_woman]<mp[new_man][new_woman]&& // if number of pref for newman and his current woman is less than his pref for new woman
           wp[current_woman][new_man]<wp[current_woman][current_man])
           { //if number of pref for current woman and new man is less than her pref for current man
                return false;
           }

    }
    return true;
}

void print(int q[]){
    cout<< "Solution: " << endl;
    cout << "Man" << " " << "Woman" << endl;
    for(int i=0; i<3; i++){
        cout << " " << i << "    " << q[i] << endl;
    }
    cout << endl << endl;
};



void backtrack(int &col)
{
    col--;
    if(col==-1){
        exit(1);
    }
}

int main()
{

    int q[3];
    q[0]=0;
    int c=0;
    bool checkNewSol = false;



   while(true){ //keeps running our check for each col until backtrack exits and we cant backtrack anymore.
     while(c<3){ //we check all columns (men) from 0-3.
        if(checkNewSol==false) //this is saying if we succeeded and found a solution for a man, lets goto next col and start at the top.
        {
            q[c]=-1; // we need to do this because we dont want to start at index 1 at the new col, that skips the first element (at index 0)
        }

        while(q[c]<3) //keep checking until the value held in that mans pref is atleast until 2 (0,1,2).
        {
            q[c]++; // try next value and see if that matches.
            if(q[c]==3) // if theyre equal -> too far, backtrack and try again.
            {
                backtrack(c);
                continue;
            }
            if(ok(q,c)) // this tests and says if whats in this mans pref coincides with our hardcoded arrays, break the loop and go to next col(man)
            {
                break;
            }
        }
        c++; //our last col found the sol, go to next man
        checkNewSol = false; // set this now so prog starts at the top of next elements row.
    }
    print(q); //we get to this point once c hits 3 (while(c<3) fails and we carry onto next statement outside that loop.
    backtrack(c); //once all sols are found -> backtrack and try more sols.
    checkNewSol = true; // lets the outerloop run again so we try newer sols.
}
return 0;
}

