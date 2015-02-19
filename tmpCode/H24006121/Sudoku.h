#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>

#define N 9

using namespace std;

class Possibility
{
public:
    Possibility() : p(N, true) {}
    Possibility(char d);

    bool chance(int i) const { return p[i-1]; }
    int count_chance() const { return count(p.begin(), p.end(), true); }
    void cancel(int i) { p[i-1] = false; }
    void activate(int i) { p[i-1] = true; }

    char find_chance(unsigned i) const;
    void print_string() const;

private:
    vector<bool> p;

};

class Sudoku
{
public:
    typedef char Val;
    typedef vector<int> Peer;

    Sudoku();
    //Sudoku(string s);

    void GiveQuestion();
    void ReadIn();
    void Solve();

private:
    static const vector<Peer> peers;

    string board;
    vector<Possibility> option;

    void initialize_option(const string &new_board);
    void recursive_solve(vector<string> &result, string board, vector<Possibility> option);
    void simple_strategy(vector<string> &result);
    bool check_duplicate_sol();
    void print_board();
};

#endif
