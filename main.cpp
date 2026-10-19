//COMSC-210 | Lab 25 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

const int SIZE = 3, RACE_SIZE = 4;;

string getDataName(int num);

int main()
{
    vector<string> codes;
    list<string> codes2;
    set<string> codes3;
    int durations[RACE_SIZE];
    ifstream fin("codes.txt");

    //From there, start the chrono loops.
    //Race 1: Reading
    cout << "Race 1: Reading" << endl;
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
        cout << "Time taken (" << getDataName(i) << "): " << duration.count() << " milliseconds\n" << endl;

        //Clear the read pointer list
        fin.clear();
        //Also set the read pointer's position back to the beginning
        fin.seekg(0);
    }

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