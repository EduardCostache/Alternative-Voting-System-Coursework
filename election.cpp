#include "election.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<vote> votes;

// Adds a vote to the election
void election::add_vote(const vote &v)
{
    votes.push_back(v);
}

// Returns the size of the votes vector
int election::vote_count() const
{
    return votes.size();
}

// Eliminates a candidate form the rounds
void election::eliminate(candidate c)
{
    typedef vector<vote>::size_type vec_size;
    for (vec_size i = 0; i < votes.size(); i++)
    {
        votes[i].discard(c);
        if (votes[i].spent())
        {
            votes.erase(votes.cbegin() + i);
            i = i - 1;
        }
    }
}

// Ranks the candidates according to their preferences
vector<pair<candidate, int>> election::ranked_candidates() const
{
    vector<pair<candidate, int>> elec;
    vector<pair<candidate, int>> sorted_elec;
    bool inside = false;
    vote x = votes[0];
    int size = votes.size();
    for (int i = 0; i < size; i++)
    {
        candidate a = votes[i].size();
        x = votes[i];
        for (int q = 0; q < x.size(); q++)
        {
            for (auto &z : elec)
            {
                if (z.first == x.find_vote(q))
                {
                    inside = true;
                }
            }
            if (!inside)
            {
                elec.emplace_back(x.find_vote(q), 0);
            }
            inside = false;
        }
        for (auto &z : elec)
        {
            if (z.first == x.first_preference())
            {
                z.second = z.second + 1;
            }
        }
    }
    while (sorted_elec.size() < elec.size())
    {
        for (int z = votes.size(); z > 0; --z)
        {
            for (auto &x : elec)
            {
                if (x.second == z)
                {
                    sorted_elec.emplace_back(x.first, x.second);
                }
            }
        }
    }
    return sorted_elec;
}

// Reads a file containing votes, and returns an election object
election read_votes(istream &myFile)
{
    election elec;
    vector<candidate> preference;
    candidate can;
    string string1;
    vote x = vote(preference);
    while (getline(myFile, string1))
    {
        preference.clear();
        stringstream s(string1);
        while (s >> can)
        {
            preference.push_back(can);
        }
        elec.add_vote(vote(preference));
    }
    return elec;
}
