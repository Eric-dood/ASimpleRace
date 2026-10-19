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

string getRaceName(int num);

int main()
{
    vector<string> codes;
    list<string> codes2;
    set<string> codes3;
    ifstream fin("codes.txt");

    //Print out the Table's header
    cout << "Race" << setw(WIDTH/2) << "|" << setw(WIDTH) << "Vector" << setw(WIDTH) << "List" << setw(WIDTH) << "Set" << endl;
    for (int i = 0; i < 50; i++) cout << "-";
    cout << endl;

    //From there, start the chrono loops.
    for (int j = 0; j < 4; j++)
    {
        //Race 1: Reading
        cout << getRaceName(j) << setw(WIDTH/2) << "|";
        for (int i = 0; i < SIZE; i++)
        {
            //Start timing
            auto start = high_resolution_clock::now();

            string lines;
            if (j == 0) //Race 1: Reading
            {
                while (getline(fin, lines))
                {
                    switch (i)
                    {
                        case 0: codes.push_back(lines); break;
                        case 1: codes2.push_back(lines); break;
                        case 2: codes3.insert(lines); break;
                    }
                }

                //Clear the read pointer list
                fin.clear();
                //Also set the read pointer's position back to the beginning
                fin.seekg(0);
            }
            else if (j == 1) //Race 2: Sorting
            {
                switch (i)
                {
                    case 0: sort(codes.begin(), codes.end()); break;
                    case 1: codes2.sort(); break;
                    //Sets are already sorted, so that is already excluded
                }
            }
            else if (j == 2) //Race 3: Inserting
            {
                int middle = 0;
                string test_code = "TESTCODE";
                switch (i)
                {
                    case 0:
                        middle = (codes.size()) / 2;
                        auto it = codes.begin();
                        advance(it, middle);
                        codes.insert(it, test_code);
                        break;
                    case 1:
                        middle = codes2.size() / 2;
                        auto it2 = codes2.begin();
                        advance(it2, middle);
                        codes2.insert(it2, test_code);
                        break;
                    case 2:
                        middle = codes3.size() / 2;
                        auto it3 = codes3.begin();
                        advance(it3, middle);
                        codes3.insert(it3, test_code);
                        break;
                }
            }


            //End timing
            auto end = high_resolution_clock::now();

            //Compile the duration & print it
            auto duration = duration_cast<milliseconds>(end - start);
            cout << setw(WIDTH) << duration.count();
        }
        cout << endl;
    }

    //Print the table
    return 0;
}

string getRaceName(int num)
{
    switch (num)
    {
        case 0: return "Reading"; break;
        case 1: return "Sorting"; break;
        case 2: return "Inserting"; break;
        case 3: return "Deleting"; break;
        default: return "N/A"; break;
    }
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/