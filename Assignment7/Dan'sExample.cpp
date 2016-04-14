#include <iostream>
#include <list>
using namespace std;

int Difference(int n1, int n2);
void FirstInFirstOut(int first, list<int> tracks);
void ShortestSeekTimeFirst(int first, list<int> tracks);
void ScanLookElevator(int first, list<int> tracks);

int main(int argc, char* argv[])
{
	int track;
	list<int> tracks;

	cin >> track;
	while( track >= 0 )
	{	
		tracks.push_back(track);
		cin >> track;
	}

	cout << endl << "-----------------------------------------" << endl;
	cout << "First Come First Served" << endl;
	cout << "-----------------------------------------" << endl;
	FirstInFirstOut(15, tracks);

	cout << endl << "-----------------------------------------" << endl;
	cout << "Shortest Seek Time First" << endl;
	cout << "-----------------------------------------" << endl;
	ShortestSeekTimeFirst(15, tracks);

	cout << endl << "-----------------------------------------" << endl;
	cout << "Scan-Look/Elevator" << endl;
	cout << "-----------------------------------------" << endl;
	ScanLookElevator(15, tracks);
}

void FirstInFirstOut(int first, list<int> tracks)
{
	cout << "Head Movement\t\tTracks Traversed" << endl;

	int total = 0;
	list<int>::iterator it;
	for ( it = tracks.begin(); it != tracks.end(); it++ )
	{
		int diff = Difference(first, (*it));
		total += diff;
	
		cout << "Tracks " << first << " - " << (*it) << "\t\t" << diff << endl;
		first = (*it);
	}

	cout << endl << "Total Tracks Traversed\t" << total << endl;
}

int Difference(int n1, int n2)
{
	if ( n1 > n2 )
		return n1 - n2;
	else if ( n1 < n2 )
		return n2 - n1;
	else
		return 0;
}

void ShortestSeekTimeFirst(int first, list<int> tracks)
{
	cout << "Head Movement\t\tTracks Traversed" << endl;

	int total = 0;
	while ( !tracks.empty() )
	{
		int bestDiff = 10000000;
		list<int>::iterator hold;
		list<int>::iterator it;
		for ( it = tracks.begin(); it != tracks.end(); it++ )
		{
			int diff = Difference(first, (*it));
			if ( diff < bestDiff )
			{
				bestDiff = diff;
				hold = it;
			} 
		}

		cout << "Tracks " << first << " - " << (*hold) << "\t\t" << bestDiff << endl;
		
		first = (*hold);
		total += bestDiff;
		tracks.erase(hold);
	}

	cout << endl << "Total Tracks Traversed\t" << total << endl;
}

// Wow, the code for this is almost too embarassing to turn in...
// I honestly think this might be the singly worst chunk of code I've
// ever written.  Too lazy/busy to bother fixing it.
void ScanLookElevator(int first, list<int> tracks)
{
	cout << "Head Movement\t\tTracks Traversed" << endl;

	tracks.sort();
	list<int> newlist;
	list<int>::iterator it = tracks.begin();
	while ( (*it) < first )
	{
		newlist.push_front((*it));
		it++;
	}
	
	list<int>::iterator it2 = tracks.end();
	it--; // back up the first iterator.  it's a bit far.
	it2--; // the end() isn't actually the last element, it's after.
	while ( it != it2 )
	{
		newlist.push_front((*it2));
		it2--;
	}

	int total = 0;
	for ( it = newlist.begin(); it != newlist.end(); it++ )
	{
		int diff = Difference(first, (*it));
		total += diff;

		cout << "Tracks " << first << " - " << (*it) << "\t\t" << diff << endl;
		first = (*it);
	}

	cout << endl << "Total Tracks Traversed\t" << total << endl;
}
