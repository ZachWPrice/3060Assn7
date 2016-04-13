#include <vector> 
#include <iostream> 
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

void print(string method, int search) {
	cout << method << " Total Seek: " << search << endl;
	return;
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
	return;
}

void SSTF(const vector<int>& diskLocation) {
	//last
	int a = 0;
	//next
	int b = 0;
	int counter = 0;
	int temp = -1;
	int total = 0;
	vector<int> tracker;
	vector<int>::const_iterator it;
	string name = "SSTF";

	tracker.push_back(0);

	for (int i = 0; i < diskLocation.size() -1; i++) {
		for (int j = 0; j < diskLocation.size(); j++) {
			b = diskLocation[j];

			it = find(diskLocation.begin(), diskLocation.end(), j);
			if (it != diskLocation.end())
				continue;

			if (diskLocation[a] <= b) {
				if (temp == -1 || temp > (b - diskLocation[a])) {
					temp = b - diskLocation[a];
					counter = j;
				}
			}
			else if (diskLocation[a] > b) {
				if (temp == -1 || temp > (diskLocation[a] - b)) {
					temp = diskLocation[a] - b;
					counter = j;
				}
			}
		}
		total += temp;
		temp = -1;
		a = counter;
		tracker.push_back(counter);
	}

	print(name, total);
	return;
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
	SSTF(diskVect);
	//Look(diskVect);
	//cLook(diskVect);

	system("PAUSE");
	return 0;
}