#include "Symplex.h"
#pragma once

class SymplexTree
{
    SymplexTree* left_;
    SymplexTree* right_;
    Symplex information_;
    Symplex initial_information_;
    std::vector<Symplex> solution_vec;

public:
    SymplexTree(const Symplex& ob) : information_(ob),
                                     initial_information_(ob),
                                     right_(nullptr),
                                     left_(nullptr)
    {};

    SymplexTree* make_branch_method(SymplexTree* root);

    void make_results();
    void destructor(SymplexTree* root);


};
