// input manatees: a list of "manatees", where one manatee is represented by a dictionary
// a single manatee has properties like "name", "age", et cetera
// n = the number of elements in "manatees"
// m = the number of properties per "manatee" (i.e. the number of keys in a manatee dictionary)

#include <iostream>
#include <vector>
using namespace std;
// #O(n)

void example1(vector<string> manatees)
{
    for (int i = 0; i < manatees.size(); i++)
    {
        cout << manatees.at(i) << endl;
    }
}

//O(1)
void example2(vector<string> manatees)
{
    cout << manatees.at(0) << endl;
    cout << manatees.at(1) << endl;
}

//O(n*m)
void example3(vector<string> manatees)
{
    for (int i = 0; i < manatees.size(); i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << "Hello " << manatees.at(i) << endl;
        }
        cout << "Bye Bye! " << manatees.at(i) << endl;
    }
}

//O(n^2)
void example4(vector<string> manatees)
{
    for (int i = 0; i < manatees.size(); i++)
    {
        for (int j = 0; j < manatees.size(); j++)
        {
            cout << manatees.at(i) << " is friend of " << manatees.at(j) << endl;
        }
    }
}

int main()
{
    vector<string> manatess;
    manatess.push_back("Oscar");
    manatess.push_back("Linda");
    manatess.push_back("Maria");
    example1(manatess);
    cout << endl;
    example2(manatess);
    cout << endl;
    example3(manatess);
    cout << endl;
    example4(manatess);

    return 0;
}
