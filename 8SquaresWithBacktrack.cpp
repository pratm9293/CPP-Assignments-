#include <iostream>
#include <cstdlib>
using namespace std;

bool isThisValid(int q[8], int sq)
{
    int adj[8][7] = { {2,3,4,5,-1,-1,-1,},
                      {1,4,5,6,-1,-1,-1},
                      {1,4,7,-1,-1,-1,-1},
                      {1,2,3,5,7,8,-1},
                      {1,2,4,6,7,8,-1},
                      {2,5,8,-1,-1,-1,-1},
                      {3,4,5,8,-1,-1,-1},
                      {4,5,6,7,-1,-1,-1}};

      for(int i=0; i<sq; i++)
      {
          if(q[i]==q[sq])
          {
              return false;
          }
      }

      for(int j = 0; adj[sq][j]!= -1; j++) // until we run into -1, keep going.
      {
          if(abs(q[sq]-q[adj[sq][j]])==1) // if the diff of what we have put in one of our 8 squares and our adj test is 1, try again.
          {
              return false;
          }
      }

      return true;
};

void print(int q[8])
{
    cout << endl;
    cout << " " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << " " << q[6] << " " << q[7] << endl;
};

void backtrack(int &sq)
{
    sq--;
    if(sq==-1)
    {
        exit(0);
    }
};

int main()
{
      int q[8]={0};
      int sq=0;
      bool backTrack=false;

    while(true)
    {
        while(sq<8)
        {
            if(!backTrack)
            {
                q[sq]=0;
            }
            while(q[sq]<9)
            {
                q[sq]++;
                if(q[sq]==9)
                {
                    backtrack(sq);
                    continue;
                }
                if(isThisValid(q,sq))
                {
                        break;
                }
            }
            sq++;
            backTrack=false;
        }
        print(q);
        backtrack(sq);
        backTrack=true;
    }
    return 0;

}
