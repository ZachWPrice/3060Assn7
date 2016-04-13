#include <vector> 
#include <iostream> 
#include <string>
#include <cstdlib>

using namespace std;

void print(string method, int search) {
	cout << method << " Total Seek: " << search << endl;
}


void FCFS(const vector<int>& diskLocation) {
	int a = 0;
	int b = 0;
	int total = 0;
	string name = "FCFS";


	for (int i = 0; i < diskLocation.size() - 1 ; i++){
		a = diskLocation[i];
		b = diskLocation[i + 1];
		if (a <= b)
			total += b - a;
		else
			total += a - b;
	}

	print(name, total);
}

void SJF(const vector<int>& diskLocation) {

}

void Look(const vector<int>& diskLocation) {

}

void cLook(const vector<int>& diskLocation) {

}


int main(int argc, char *argv[]) {

	cout << "\nAssignment 5 by Zachary Price\n\n";

	int diskPos = 0;
	vector<int> diskVect;

	while (cin >> diskPos)
	{
		diskVect.push_back(diskPos);
	}

	FCFS(diskVect);
	//SJF(diskVect);
	//Look(diskVect);
	//cLook(diskVect);

	system("PAUSE");
	return 0;
}