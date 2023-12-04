//
// CS2024 Lecture #15, Demo 5
//
// Simple Map
//

#include <iostream>
#include <map>

using namespace std;  //introduces namespace std

typedef map<int,string>::value_type IDRecord;
typedef map<int,string>::iterator   IDRecordIterator;

int main()
{
	map<int,string> ids;
	
	IDRecord rec1(12345,"Ron DiNapoli");
	IDRecord rec2(34564,"Darpan Kaplan");
	ids.insert(rec1);
	ids.insert(rec2);
	
	IDRecordIterator p = ids.find(12345);
	cout << "ID 12345 belongs to: " << (*p).second << endl;
	
	IDRecordIterator q = ++p;
	cout << "Next entry is: " << (*q).second << endl;

	// Be careful using operator[] with a map.   If there is no key-value
	// pair with the specified key in the map, ONE WILL BE ADDED thus increasing
	// the number of key-value pairs in the map by 1.  (The value of the added
	// key-value pair should be the default value for whatever type the value is)
	cout << "ID 34564 belongs to: " << ids[34564] << endl;

	// Demonstrate the comment above... let's try to access a key-value pair that
	// doesn't exist
	cout << "Size of map is: " << ids.size() << endl;
	cout << "ID 99999 belongs to: " << ids[99999] << endl;

	// The size should be increased by 1!
	cout << "Size of map is: " << ids.size() << endl;

	// But, this means we can use operator[] to insert directly into the map
	ids[90000] = "Priya";
	cout << "Size of map is: " << ids.size() << endl;
	cout << "ID 90000 belongs to: " << ids[90000] << endl;
}


