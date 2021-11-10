#include <iostream>
#include "SymplexTree.h"

int main()
{
    std::string path = "/Users/ivanmilchenko/MO_lab_02/input.txt";
    std::ifstream input(path);
    if (!input)
        throw std::runtime_error("Unable to open file " + path);

    Symplex problem(input);

    SymplexTree* tree = new SymplexTree(problem);
    tree->make_branch_method(tree);

    std::cout << "\n====The optimal plan is====\n";
    tree->make_results();

    tree->destructor(tree);

    std::cout << std::endl;

    problem.brute_force();

    return 0;
}
