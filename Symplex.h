#pragma once

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Symplex
{
    std::vector<std::vector<double>> A;

    /*матрица преобразований*/
    std::vector<std::vector<double>> table_;
    std::vector<double> goal_func;

    /*резрешающие таблица и строка*/
    int permissive_str_;
    int permissive_column_;

    /*вектора переменных для таблицы*/
    std::vector<std::string> basis_;
    std::vector<std::string> free_;

    std::vector<std::pair<std::string, double>> solutions_vec;

public:
    /*конструктор для сборки таблицы из файла*/
    Symplex(std::ifstream& input);
    Symplex(const Symplex& other);
    Symplex(const Symplex& other, const std::pair<int, double>& add, bool side);

    /*проверка на оптимальность*/
    bool is_optimal() const;

    /*печать таблицы*/
    void print() const;

    /*поиск разрешающей колнки и сроки*/
    int find_column() const;
    int find_str() const;
    int find_min() const;

    /*метод ветвей и границ*/
    std::pair<int, double> find_float() const;

    /*одна итерация преобразования*/
    bool do_step();

    /*геттер оптимального решения*/
    double get_solution() const;

    void do_examination();

    void brute_force();

    ~Symplex()
    {
        for (auto& i : table_)
            i.clear();
        table_.clear();
        basis_.clear();
        free_.clear();
    }
};
