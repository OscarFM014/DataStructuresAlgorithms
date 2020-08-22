/* You can use this class to represent how classy someone
or something is.
"Classy" is interchangable with "fancy".
If you add fancy-looking items, you will increase
your "classiness".
Create a function in "Classy" that takes a string as
input and adds it to the "items" list.
Another method should calculate the "classiness"
value based on the items.
The following items have classiness points associated
with them:
"tophat" = 2
"bowtie" = 4
"monocle" = 5
Everything else has 0 points.
Use the test cases below to guide you! */

#include <iostream>
#include <vector>

using namespace std;

class Classy
{
public:
    vector<string> items;

    void addItem(string item)
    {
        items.push_back(item);
    }

    int getClassiness()
    {
        int classiness = 0;
        if (items.size() > 0)
        {
            for (int i = 0; i < items.size(); i++)
            {
                if (items.at(i).compare("tophat") == 0)
                {
                    classiness += 2;
                }
                else if (items.at(i).compare("bowtie") == 0)
                {
                    classiness += 4;
                }
                else if (items.at(i).compare("monocle") == 0)
                {
                    classiness += 5;
                }
            }
        }
        return classiness;
    }
};

int main()
{
    Classy me;

    cout << me.getClassiness() << endl;

    me.addItem("tophat");

    cout << me.getClassiness() << endl;
    return 0;
}
