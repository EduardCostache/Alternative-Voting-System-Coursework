#include "vote.h"
#include <vector>
#include <algorithm>

using namespace std;

// Constructor
vote::vote(const vector<candidate> &prefs) : preference(prefs) {}

// Returns True if preference is empty
bool vote::spent() const
{
    return preference.empty();
}

// Returns the first preference in the vector
candidate vote::first_preference() const
{
    return preference[0];
}

// Discards the candidate from preference
void vote::discard(candidate can)
{
    preference.erase(remove(preference.begin(), preference.end(), can), preference.end());
}

// Returns the vote at the position provided
candidate vote::find_vote(int x) const
{
    return preference[x];
}

int vote::size() const
{
    return preference.size();
}
