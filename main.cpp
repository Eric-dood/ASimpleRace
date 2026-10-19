//COMSC-210 | Lab 25 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        //RACE 1: READING
        string name;
        switch (i)
        {
            case 1: name = "Reading"; break;
            case 2: name = "Sorting"; break;
            case 3: name = "Inserting"; break;
            case 4: name = "Deleting"; break;
        }
        cout << "Race " << i << ": " << name << endl << "--------------------" << endl;
        //Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        list<string> codes;
        ifstream fin("codes.txt");

        int j = 0;
        while (fin >> codes[j++]);
        fin.close();

        //End timing
        auto end = high_resolution_clock::now();

        //Compile the duration & print it
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Time taken: " << duration.count() << " milliseconds\n";

        //RACE 2: SORTING

        //RACE 3: INSERTING

        //RACE 4: DELETING
    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/