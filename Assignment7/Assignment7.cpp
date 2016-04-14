#include <vector> 
#include <iostream> 
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iterator>
#include <list>

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
		total += abs(diskLocation[i] - diskLocation[i + 1]);
	}
	print(name, total);
	return;
}

void SSTF(const vector<int>& diskLocation) {
	int a = 0;
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

			it = find(tracker.begin(), tracker.end(), j);
			if (it != tracker.end())
				continue;


			if (temp == -1 || temp > abs(diskLocation[a] - b)) {
				temp = abs(diskLocation[a] - b);
				counter = j;
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

	vector<int> sorted = diskLocation; 

	sort(sorted.begin(), sorted.end());

	int total = 0;
	string name = "LOOK";

	vector<int> highList;
	vector<int> lowList;

	vector<int>::iterator it = sorted.begin();

	while ((*it) <= diskLocation[0])
	{
		lowList.push_back((*it));
		it++;
	}

	it--; // back up the first iterator.  it's a bit far.
	while (it != sorted.end())
	{
		highList.push_back((*it));
		it++;
	}

	it = lowList.begin();
	
	while (it+1 != lowList.end()){
		total += abs(*it - *(it+1));
		it++;
	}

	it = highList.begin();
	total += abs(lowList.front() - *it);
	it++;

	while (it+1 != highList.end()){
		total += abs(*it - *(it+1));
		it++;
	}

	print(name, total);
	return;
	
	
	
	
	/*	int a = 0;
	int b = 0;
	int counter = 0;
	int temp = -1;
	int total = 0;
	vector<int> tracker;
	vector<int>::const_iterator it;
	string name = "LOOK";

	tracker.push_back(0);

	for (int i = 0; i < diskLocation.size(); i++) {
		for (int j = 0; j < diskLocation.size(); j++) {
			b = diskLocation[j];

			it = find(tracker.begin(), tracker.end(), j);
			if (it != tracker.end())
				continue;

			if (diskLocation[a] >= b) {
				if (temp == -1 || temp > (diskLocation[a] - b)) {
					temp = diskLocation[a] - b;
					counter = j;
				}
			}
		}
		cout << temp << endl;
		total += temp;
		temp = -1;
		a = counter;
		tracker.push_back(counter);

		if (diskLocation[a] == *min_element(diskLocation.begin(), diskLocation.end()))
			break;
	}
	//cout << "tracker size: " << tracker.size() << endl;
	for (int i = 0; i < diskLocation.size(); i++){
		for (int j = 0; j < diskLocation.size(); j++) {
			b = diskLocation[j];

			it = find(tracker.begin(), tracker.end(), j);
			if (it != tracker.end())
				continue;

			if (diskLocation[a] < b) {
				if (temp == -1 || temp > (b - diskLocation[a])) {
					temp = b - diskLocation[a];
					counter = j;
				}
			}
		}
		cout << temp << endl;

		total += temp;
		temp = -1;
		a = counter;
		tracker.push_back(counter);

		if (tracker.size() == diskLocation.size())
			break;
	}

	print(name, total);
	return;*/

}

void cLook(const vector<int>& diskLocation) {




	/*

	if (diskLocation[counter] == *min_element(diskLocation.begin(), diskLocation.end())){
		a = distance(diskLocation.begin(), max_element(diskLocation.begin(), diskLocation.end()));

		break;
	}*/
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
	Look(diskVect);
	//cLook(diskVect);

	system("PAUSE");
	return 0;
}