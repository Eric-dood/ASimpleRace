//COMSC-210 | Lab 25 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int main()
{
    //Start timing
    auto start = high_resolution_clock::now();

    // Example loop to measure
    vector<string> codes;
    ifstream fin("codes.txt");
    int i = 0;
    while (fin >> codes[i++])
        codes.push_back(i);
    }

    auto end = high_resolution_clock::now();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/