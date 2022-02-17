#include "election.h"
#include "vote.h"
#include <fstream>
#include <iostream>
#include <vector>
//#include <chrono>

using namespace std;

int main()
{
    // auto t1 = std::chrono::high_resolution_clock::now();
    fstream myFile("Tests/input4.txt");

    // Only runs the code if a file is open
    if (myFile.is_open())
    {
        election elec = read_votes(myFile);
        vector<pair<candidate, int>> ranked_can = elec.ranked_candidates();
        int round = 1;
        bool run = true;
        while (run)
        {
            cout << "Round " << round << ": " << elec.vote_count() << " votes" << endl
                 << "First preferences:" << endl;
            for (auto &i : ranked_can)
            {
                cout << "  Candidate " << i.first << " : " << i.second << endl;
            }

            int threshold = elec.vote_count() / 2;
            if (ranked_can[0].second > threshold)
            {

                cout << "Candidate " << ranked_can[0].first << " is selected." << endl;
                run = false;
            }
            else
            {
                cout << "Candidate " << ranked_can[(ranked_can.size() - 1)].first << " is eliminated.\n"
                     << endl;
                elec.eliminate(ranked_can[(ranked_can.size() - 1)].first);
            }
            ranked_can = elec.ranked_candidates();
            round++;
        }
        myFile.close();
    }
    else
    {
        cout << "Something went wrong: File not opened";
    }
    // auto t2 = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return 0;
}
