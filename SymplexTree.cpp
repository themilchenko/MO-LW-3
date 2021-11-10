#include <cmath>
#include "SymplexTree.h"

SymplexTree* SymplexTree::make_branch_method(SymplexTree* root)
{
    std::cout << "There is a current Symplex table:\n";
    root->information_.print();

    std::cout << "\nSolution of Symplex table:\n";
    while (root->information_.is_optimal()) // решаем таблицу
    {
        root->information_.do_step();
        root->information_.print();
    }
    std::cout << std::endl;
    root->information_.do_examination();
    std::cout << "F = " << root->information_.get_solution() << std::endl;

    if (root->information_.find_float().first != -1)
    {
        std::pair<int, double> element_l = root->information_.find_float();
        element_l.second = std::floor(element_l.second);
        Symplex current_l(initial_information_, element_l, 1);
        std::cout << "\n***X <= " << element_l.second << "***\n\n";
        root->left_ = new SymplexTree(current_l);
        root->left_ = make_branch_method(root->left_);

        std::pair<int, double> element_r = root->information_.find_float();
        element_r.second = std::floor(element_r.second) + 1;
        Symplex current_r(initial_information_, information_.find_float(), 0);
        std::cout << "\n***X >= " << element_r.second << "***\n\n";
        root->right_ = new SymplexTree(current_r);
        root->right_ = make_branch_method(root->right_);
    }
    else
    {
        solution_vec.push_back(root->information_);
        return root;
    }
}

void SymplexTree::make_results()
{
    Symplex max_res = solution_vec[0];
    for (const auto& i : solution_vec)
        if (max_res.get_solution() < i.get_solution())
            max_res = i;

    max_res.do_examination();
    std::cout << "F = " << max_res.get_solution() << std::endl;
}

void SymplexTree::destructor(SymplexTree* root)
{
    if (root != nullptr)
    {
        destructor(root->left_);
        destructor(root->right_);
        delete root;
    }
}

