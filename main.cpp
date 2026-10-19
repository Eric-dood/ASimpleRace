//COMSC-210 | Lab 25 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

const int SIZE = 3, WIDTH = 10;

int main()
{
    vector<string> codes;
    list<string> codes2;
    set<string> codes3;
    ifstream fin("codes.txt");

    //Print out the Table's header
    cout << "Race" << setw(WIDTH/2) << "|" << setw(WIDTH) << "Vector" << setw(WIDTH) << "List" << setw(WIDTH) << "Set" << endl;
    for (int i = 0; i < 40; i++) cout << "-";
    cout << endl;

    //From there, start the chrono loops.
    //Race 1: Reading
    cout << "Reading" << setw(WIDTH/2) << "|";
    for (int i = 0; i < SIZE; i++)
    {
        //Start timing
        auto start = high_resolution_clock::now();

        string lines;
        while (getline(fin, lines))
        {
            switch (i)
            {
                case 0: codes.push_back(lines); break;
                case 1: codes2.push_back(lines); break;
                case 2: codes3.insert(lines); break;
            }
        }

        //End timing
        auto end = high_resolution_clock::now();

        //Compile the duration & print it
        auto duration = duration_cast<milliseconds>(end - start);
        cout << setw(WIDTH) << duration.count();

        //Clear the read pointer list
        fin.clear();
        //Also set the read pointer's position back to the beginning
        fin.seekg(0);
    }
    cout << endl;
    //Race 2: Sorting
    cout << "Sorting" << setw(WIDTH/2) << "|";
    for (int i = 0; i < SIZE; i++)
    {
        //Start timing
        auto start = high_resolution_clock::now();

        switch (i)
        {
            case 0: sort(codes.begin(), codes.end()); break;
            case 1: codes2.sort(); break;
            //Sets are already sorted, so that is already excluded
        }

        //End timing
        auto end = high_resolution_clock::now();

        //Compile the duration & print it
        auto duration = duration_cast<milliseconds>(end - start);
        cout << setw(WIDTH) << duration.count();

        //Clear the read pointer list
        fin.clear();
        //Also set the read pointer's position back to the beginning
        fin.seekg(0);
    }

    //Print the table
    return 0;
}

string getDataName(int num)
{
    switch (num)
    {
        case 0: return "Vector"; break;
        case 1: return "List"; break;
        case 2: return "Set"; break;
        default: return "N/A"; break;
    }
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/