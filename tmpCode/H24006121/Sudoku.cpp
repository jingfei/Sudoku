#include "Sudoku.h"

//#define DEBUG

const int step[] = {0, 1, 2, N, N + 1, N + 2, 2 * N, 2 * N + 1, 2 * N + 2};
const int col_step[] = {0, 9, 18, 1, 10, 19, 2, 11, 20};

//======================================================================



//======================================================================

Possibility::Possibility(char d) : p(N, true) {
    if (d != '0')
        for (int i = 0 ; i < N ; ++i)
            p[i] = false;
}

//======================================================================

Sudoku::Sudoku() : board(N * N, '0'), option(N * N) {}

//======================================================================

void Possibility::print_string() const {
    string str;

    for (int i = 1 ; i <= N ; ++i) {
        if (Possibility::p[i - 1] == true)
            str.push_back('0' + i);
    }

    cout << str << endl;
}

//======================================================================



//======================================================================

char Possibility::find_chance(unsigned i) const {
    string search_result;

    for (int j = 1 ; j <= N ; ++j) {
        if (Possibility::p[j - 1] == true)
            search_result.push_back('0' + j);
    }

    if (i <= search_result.size())
        return search_result[i - 1];
    else
        return '0';
}

//======================================================================

void Sudoku::print_board() {
    for (int r = 0 ; r < N ; ++r) {
        for (int c = 0 ; c < N ; ++c)
            cout << board[r * N + c] << ' ';

        cout << endl;
    }
}

//======================================================================

vector<Sudoku::Peer> get_peers()
{
    vector<Sudoku::Peer> peers;

    for (int r = 0 ; r < N ; ++r) {
        for (int c = 0 ; c < N ; ++c) {
            vector<int> p;
            int index = r * N + c;

            // block peers: 8
            int block_head = (r / 3) * 3 * N + (c / 3) * 3;
            for (int j = 0 ; j < 9 ; ++j) {
                if (block_head + step[j] != index)
                    p.push_back(block_head + step[j]);
            }

            // row peers: 6
            int lb, ub;
            if (c % 3 == 0) {
                lb = index, ub = index + 2;

            } else if (c % 3 == 1) {
                lb = index - 1, ub = index + 1;

            } else {
                lb = index - 2, ub = index;
            }

            for (int i = r * N ; i < (r + 1) * N ; ++i) {
                if (i < lb || i > ub)
                    p.push_back(i);
            }

            // col peers: 6
            if (r % 3 == 0) {
                lb = index, ub = index + 2 * N;

            } else if (r % 3 == 1) {
                lb = index - N, ub = index + N;

            } else {
                lb = index - 2 * N, ub = index;
            }
            for (int i = c ; i < N * N ; i += N)
                if (i < lb || i > ub)
                    p.push_back(i);

            peers.push_back(p);
        }
    }

    return peers;
}

const vector<Sudoku::Peer> Sudoku::peers = get_peers();

//======================================================================

void Sudoku::ReadIn()
{
    string square, new_board;

    for (int i = 0 ; i < N * N ; ++i) {
        cin >> square;

        new_board += square;
    }

    if (new_board.size() != N * N) {
        cerr << "Some errors (wrong size or wrong element) happen in Sudoku::ReadIn()" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0 ; i < new_board.size() ; ++i) {
        if (new_board[i] < '0' || new_board[i] > '9') {
            cerr << "Some errors (wrong element) happen in Sudoku::ReadIn()" << endl;
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0 ; i < N * N ; ++i)
        Sudoku::board[i] = new_board[i];

    Sudoku::initialize_option(new_board);
}

//======================================================================

void Sudoku::initialize_option(const string &new_board)
{
    // update option
    for (int i = 0 ; i < N * N ; ++i) {
        const Peer &peers_i = Sudoku::peers[i];

        if (new_board[i] != '0') {
            Sudoku::option[i] = Possibility( new_board[i] );

        } else {
            // check peers of board[i]
            for (int j = 0 ; j < peers_i.size() ; ++j) {
                int index = peers_i[j];
                char val = new_board[index];

                if (val != '0' && Sudoku::option[i].chance(val - '0') == true) {
                    Sudoku::option[i].cancel(val - '0');
                }
            }

        }
    }
}

//======================================================================

void Sudoku::GiveQuestion()
{
    int block_head = 3 * N + 3;

    // random generate 9 number sequence, number is 1 ~ 9, each occurs exactly once
    srand (time(NULL));

    vector<int> seed;
    while (seed.size() < N) {
        int x = rand() % N + 1;

        if (find(seed.begin(), seed.end(), x) == seed.end())
            seed.push_back(x);
    }

    // center block
    for (int i = 0 ; i < N ; ++i)
        Sudoku::board[block_head + step[i]] = '0' + seed[i];

    // middle left block
    block_head = 3 * N;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 3 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + seed[ii];
    }

    // middle right block
    block_head = 3 * N + 6;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 6 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + seed[ii];
    }

    // get col_seed
    vector<int> col_seed;
    for (int i = 0 ; i < 3 ; ++i) {
        for (int j = 0 ; j < 9 ; ++j) {
            if (j % 3 == i)
                col_seed.push_back(seed[j]);
        }
    }

    // top middle block
    block_head = 3;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 3 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + col_step[i]] = '0' + col_seed[ii];
    }

    // bottom middle block
    block_head = 6 * N + 3;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 6 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + col_step[i]] = '0' + col_seed[ii];
    }

    // get bottom seed
    vector<int> bottom_seed;
    for (int i = 0 ; i < N ; ++i) {
        char x = Sudoku::board[block_head + step[i]];

        bottom_seed.push_back(x - '0');
    }

    // bottom left block
    block_head = 6 * N;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 3 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + bottom_seed[ii];
    }

    // bottom right block
    block_head = 6 * N + 6;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 6 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + bottom_seed[ii];
    }

    // get top_seed
    vector<int> top_seed;
    block_head = 3;
    for (int i = 0 ; i < N ; ++i) {
        char x = Sudoku::board[block_head + step[i]];

        top_seed.push_back(x - '0');
    }

    // top left block
    block_head = 0;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 3 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + top_seed[ii];
    }

    // top right block
    block_head = 6;
    for (int i = 0 ; i < N ; ++i) {
        int ii = 6 + i;

        if (ii >= N)
            ii %= N;

        Sudoku::board[block_head + step[i]] = '0' + top_seed[ii];
    }

#ifdef DEBUG
    Sudoku::print_board();
#endif

    vector<int> empty_index;
    for (int i = 0 ; i < 17 ; ++i) {
        int x = rand() % 81;

        if (find(empty_index.begin(), empty_index.end(), x) == empty_index.end())
            empty_index.push_back(x);
    }

    for (int i = 0 ; i < empty_index.size() ; ++i)
        Sudoku::board[ empty_index[i] ] = '0';

    Sudoku::print_board();
}

//======================================================================

bool Sudoku::check_duplicate_sol()
{
    int num_nonempty = 0;
    vector<bool> check(N, false);

    for (int i = 0 ; i < N * N ; ++i) {
        if (Sudoku::board[i] != '0') {
            check[Sudoku::board[i] - '1'] = true;
            ++num_nonempty;

        }
    }

    int count_distinct = count(check.begin(), check.end(), true);

            #ifdef DEBUG
                cout << "Successful counting" << endl;
                cout << "count_distinct = " << count_distinct << " ; " << "num_nonempty = " << num_nonempty << endl;
            #endif // DEBUG

    if (num_nonempty < 17 || count_distinct < 8)
        return true;
    else
        return false;
}

//======================================================================

void Sudoku::simple_strategy(vector<string> &result)
// fill in the certain square
{
    // If a square has only one possible value, then eliminate that value from the square's peers.
    // If a unit has only one possible place for a value, then put the value there.
    string &board = Sudoku::board;
    vector<Possibility> &option = Sudoku::option;
    const vector<Sudoku::Peer> &peers = Sudoku::peers;

    bool have_choice = true;

    while (have_choice) {
        bool update = false;

        for (int i = 0 ; i < N * N ; ++i) {
            if (board[i] == '0' && option[i].count_chance() == 1) {
                char val = option[i].find_chance(1);
                        #ifdef DEBUG
                            cout << i << " find: " << val << endl;
                        #endif // DEBUG


                option[i].cancel(val - '0');

                board[i] = val;

                // update the peers of board[i]
                Sudoku::Peer peers_i = peers[i];
                for (int j = 0 ; j < peers_i.size() ; ++j) {
                    int index = peers_i[j];

                    if (option[index].chance(val - '0') == true) {
                        option[index].cancel(val - '0');
                    }
                }

                update = true;
            }
        }

        #ifdef DEBUG
            Sudoku::print_board();
        #endif // DEBUG

        have_choice = update;
    }

    if (find(board.begin(), board.end(), '0') == board.end())
        result.push_back(board);

}

//======================================================================

void Sudoku::Solve()
{
    vector<string> result;

    if (Sudoku::check_duplicate_sol() == true) {
        cout << 2 << endl;
        return;
    }

        #ifdef DEBUG
            cout << "check_duplicate_sol finished" << endl;
        #endif

    Sudoku::simple_strategy(result);

        #ifdef DEBUG
        cout << "simple strategy finished" << endl;
        #endif

    if (result.size() == 1) { // means there is only one solution to the Sudoku
        string &sol = result[0];

        cout << 1 << endl;

        for (int r = 0 ; r < N ; ++r) {
            for (int c = 0 ; c < N ; ++c) {
                cout << sol[r * N + c] << ' ';
            }
            cout << endl;
        }

#ifdef DEBUG
    cout << "simple strategy succeeded" << endl;
#endif

        return;
    }

#ifdef DEBUG
    cout << "simple strategy not succeeded" << endl;
#endif

#ifdef DEBUG
    cout << "Before recursive_solve:" << endl;

    for (int r = 0 ; r < N ; ++r) {
        for (int c = 0 ; c < N ; ++c) {
            cout << Sudoku::board[r * N + c] << ' ';
        }
        cout << endl;
    }

    cout << "================" << endl;
#endif

    Sudoku::recursive_solve(result, Sudoku::board, Sudoku::option);

#ifdef DEBUG
    cout << "recursive_solve finished" << endl;
#endif

    if (result.size() > 1) {
        cout << 2 << endl;

        for (int r = 0 ; r < N ; ++r) {
            for (int c = 0 ; c < N ; ++c) {
                cout << (result[0])[r * N + c] << ' ';
            }
            cout << endl;
        }

        for (int r = 0 ; r < N ; ++r) {
            for (int c = 0 ; c < N ; ++c) {
                cout << (result[1])[r * N + c] << ' ';
            }
            cout << endl;
        }

    } else if (result.size() == 1) {
        for (int r = 0 ; r < N ; ++r) {
            for (int c = 0 ; c < N ; ++c) {
                cout << (result[0])[r * N + c] << ' ';
            }
            cout << endl;
        }

    } else if (result.size() == 0) {
        cout << 0 << endl;

    }

}

//======================================================================

void Sudoku::recursive_solve(vector<string> &result, string board, vector<Possibility> option)
// dfs
{
    if (find(board.begin(), board.end(), '0') == board.end()) {
        result.push_back(board);

#ifdef DEBUG
        cout << "New element of result:" << endl;

        for (int r = 0 ; r < N ; ++r) {
            for (int c = 0 ; c < N ; ++c) {
                cout << board[r * N + c] << ' ';
            }
            cout << endl;
        }
        cout << "================" << endl;
#endif
    }

    if (result.size() > 1)
        return;

    for (int n = 2 ; n <= 9 ; ++n) {
        // case: "Sudoku::option[i].count_chance() == 1" has been solved in simple_strategy()

        for (int i = 0 ; i < N * N ; ++i) { // 0 ~ 80

            if (board[i] == '0' && option[i].count_chance() == n) {

                for (unsigned j = 1 ; j <= n ; ++j) {
                    string board_copy = board;
                    vector<Possibility> option_copy = option;

#ifdef DEBUG
                    cout << "Possibility: " << n << ' ' << "index: " << i << ' ' << "Which: " << j << endl;
                    option_copy[i].print_string();
#endif
                    char val = option_copy[i].find_chance(j);

                    if (val == '0') // no value matches this empty square; that is, contradiction
                        return;

                    board_copy[i] = val;
                    option_copy[i].cancel(val - '0'); // I forgot to update peers

                    // update peers
                    Sudoku::Peer peers_i = peers[i];

                    for (int k = 0 ; k < peers_i.size() ; ++k) {
                        int index = peers_i[k];

                        if (option_copy[index].chance(val - '0') == true) {
                            option_copy[index].cancel(val - '0');
                        }
                    }
#ifdef DEBUG
                    cout << "Possibility: " << n << ' ' << "index: " << i << ' ' << "Which: " << j << endl;
                    for (int r = 0 ; r < N ; ++r) {
                        for (int c = 0 ; c < N ; ++c) {
                            cout << board_copy[r * N + c] << ' ';
                        }
                        cout << endl;
                    }
#endif
                    Sudoku::recursive_solve(result, board_copy, option_copy);

                }

            }
        }
    }
}