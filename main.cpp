//COMSC-210 | Lab 25 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int main()
{
    vector<string> codes;
    ifstream fin("codes.txt");

    for (int i = 1; i <= 4; i++)
    {
        //RACE 1: READING
        string name;
        //Use a switch statement to define the race names
        switch (i)
        {
            case 1: name = "Reading"; break;
            case 2: name = "Sorting"; break;
            case 3: name = "Inserting"; break;
            case 4: name = "Deleting"; break;
        }
        //Print the race names & numbers
        cout << "Race " << i << ": " << name << endl;

        //From there, start the chrono loops.
        //Start timing
        auto start = high_resolution_clock::now();

        //Race 1: Reading
        if (i == 1)
        {
            // Example loop to measure
            string lines;
            while (getline(fin, lines))
                codes.push_back(lines);
            fin.close();
        }
        //Race 2: Sorting
        else if (i == 2)
            sort(codes.begin(), codes.end());
        //Race 3: Inserting
        else if (i == 3)
        {
            auto it = codes.begin();
            advance(it, (int)(codes.size() / 2));
            codes.insert(it, "TESTVALUE");
        }
        //Race 4: Deleting
        else if (i == 4)
        {

        }


        //End timing
        auto end = high_resolution_clock::now();

        //Compile the duration & print it
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Time taken: " << duration.count() << " milliseconds\n" << "--------------------" << endl;
    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/