using namespace std;
#include <iostream>
#include <vector>

#define MAX(a, b) ((a > b) ? a : b)

int main(int argc, char *argv[])
{

    //Control the arguments are correct (the first and last ones are 0 and there are a even number)
    if (argc % 2 == 0)
    {
        cerr << "You must enter a even number in argument !" << endl;
        return 0;
    }

    if ((int)*argv[1] - 48 != 0)
    {
        cerr << "The number of people getting off must be 0 for the first stop !" << endl;
        return 0;
    }

    if ((int)*argv[argc - 1] - 48 != 0)
    {
        cerr << "The number of people getting in must be 0 for the last stop !" << endl;
        return 0;
    }

    unsigned int count = 0;   //number of passengers in the bus
    int result = count;       //maximum capacity of the bus
    vector<vector<int>> stop; //stops of the line and the number of passengers getting in and off

    //The arguments are recorded in the vector stop
    vector<int> temp;
    int a;
    for (int i = 1; i < argc; i += 2)
    {
        sscanf(argv[i], "%d", &a);
        temp.push_back(a);
        sscanf(argv[i + 1], "%d", &a);
        temp.push_back(a);
        stop.push_back(temp);
        temp.clear();
    }
    
    /*
    //Display the stops
    for (int i = 0; i < stop.size(); i++)
        cout << stop[i][0] << " " << stop[i][1] << endl;
    */
    
    int i = 0;
    while (i < stop.size() && count >= 0)
    {
        //cout << count << endl; //display the number of passenger in the bus between 2 stops
        if (count < stop[i][0])
        {
            cerr << "More passengers got off than those were in to stop " << i + 1 << "..." << endl;
            return 0;
        }
        count -= stop[i][0];
        count += stop[i][1];
        result = MAX(count, result);
        i++;
    }

    if (count == 0)
        cout << "The result is : " << result << endl;
    else
        cerr << "There are still passengers left ! " << count << endl;

    return 0;
}