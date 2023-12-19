//
// CS2024  Lecture #15, Demo #6
//
// More about maps
//
#include <iostream>
#include <map>

using namespace std;  //introduces namespace std

typedef map<string,string>::value_type IDRecord;
typedef map<string,string>::iterator   IDRecordIterator;

int main()
{
    map<string,string> ids;
    
    IDRecord rec1("abced","Joe Giliberto");
    IDRecord rec2("fgh", "kristie LeBeau");
    ids.insert(rec1);
    ids.insert(rec2);

    // See warning about using operator[] in demo #4!
    cout << "ID abced belongs to: " << ids["abced"] << endl;

}