#ifndef FINAL_COURSEWORK_ELECTION_H
#define FINAL_COURSEWORK_ELECTION_H

#include "vote.h"
#include <vector>
#include <iostream>

class election
{

public:
    void add_vote(const vote &v);
    int vote_count() const;
    void eliminate(candidate c);
    std::vector<std::pair<candidate, int>> ranked_candidates() const;
};

election read_votes(std::istream &myFile);
#endif
