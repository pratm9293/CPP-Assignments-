#include <iostream>
using namespace std;

void moveDisk(char in, char out, char extra, int num);

int main(){
    int n;
    cout << "Please enter the number of disks" << endl;
    cin >> n;
	moveDisk('A', 'B', 'C', n);
	return 0;
}

void moveDisk(char in, char out, char extra, int num){

	if(num==1){
		cout << "We move the disk from" << in << " to " << out << endl;
		return;
	}
	moveDisk(in, extra, out, num-1);
	cout << "We move the disk from" << in << " to " << extra << endl;
	moveDisk(extra, out, in, num-1);
	return;
}
