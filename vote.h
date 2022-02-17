#ifndef COURSEWORK_VOTE_H
#define COURSEWORK_VOTE_H

#include <vector>
typedef unsigned int candidate;

class vote
{
    std::vector<candidate> preference;

public:
    vote(const std::vector<candidate> &prefs);
    bool spent() const;
    candidate first_preference() const;
    void discard(candidate candidate1);
    candidate find_vote(int x) const;
    int size() const;
};
#endif
