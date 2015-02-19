#include "Sudoku.h"

using namespace std;
Sudoku::Sudoku ()
{
    ans_count = 0 ;
}
void Sudoku::ReadIn()
{
    int i , j;
    for (i = 0 ; i < 9 ; i++)
    {
        for (j = 0 ; j < 9 ; j++)
        {
            cin >> n[i][j] ;
            correct [i][j] = n[i][j];
        }
    }
}
void Sudoku::Solve()
{
    int i , j ;
    Sudoku_Solve() ;
    if (ans_count == 0)
        cout << "0" << endl;
    if (ans_count == 1)
    {
        cout << "1" << endl;
        for (i = 0 ; i< 9 ; i++)
        {
            for (j = 0 ; j < 9 ; j++)
                cout << correct[i][j] << " " ;
            cout << endl;
        }

    }

}
void Sudoku::Sudoku_Solve()
{
    int i , j ,a ,b , num ;
    if (get_count() == 81)
    {
        ans_count++ ;
        for (i = 0 ; i< 9 ; i++)
        {
            for (j = 0 ; j < 9 ; j++)
                correct[i][j] = n[i][j];
        }
        if (ans_count >= 2)
        {
            cout << "2" << endl ;
            return ;
        }
    }

    for (a = 0; a < 9; a++)
    {
        for (b = 0 ; b < 9 ; b++)
        {
            if (  n[a][b] == 0)
            {
                for ( num = 1 ; num <= 9 ; num ++)
                {
                    if ( compare_row( num , a) == 1 && compar_column( num , b ) == 1 && compar_night( num , b, a) == 1 )
                    {
                        n[a][b] = num ;
                        Sudoku_Solve();

                        n[a][b] = 0;
                        if (ans_count >= 2)
                            return;
                    }
                }
                return ;
            }
        }
    }
}
int Sudoku::get_count ()
{
    int i , j , count = 0;
    for ( i =0 ; i< 9 ; i++)
    {
        for (j = 0 ; j< 9 ; j++)
        {
            if (n[i][j] != 0 )
                count ++;
        }
    }
    return count ;
}

int Sudoku::compare_row( int num , int row)
{
    int i ;
    for ( i = 0 ; i < 9 ; i++)
    {
        if ( n[row][i] == num)
            return 0 ;
    }
    return 1;

}
int Sudoku::compar_column( int num , int column)
{
    int i ;
    for ( i = 0 ; i < 9 ; i++)
    {
        if ( n[i][column] == num)
            return 0 ;
    }
    return 1 ;
}

int Sudoku::compar_night( int num , int row , int column)
{
    int i , j , a , b ;
    if ( row <=2 && row >= 0 && column <=2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column <= 2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column <= 2 && column >= 0)
    {
        for ( i = 0 ; i <= 2 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 2  && row >= 0 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column >= 3 && column <= 5)
    {
        for ( i = 3 ; i <= 5 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 2 && row >= 0 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 0 ; j <= 2 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 5 && row >= 3 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 3 ; j <= 5 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
    if ( row <= 8 && row >= 6 && column >= 6 && column <= 8)
    {
        for ( i = 6 ; i <= 8 ; i++)
        {
            for (j = 6 ; j <= 8 ; j++)
            {
                if ( n[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }
}

void Sudoku::GiveQuestion()
{
    int i = 0;
    srand(time (NULL));
    i = rand()%5+1 ;
    switch (i)
    {
    case 1:
        cout << "0 0 7 0 0 2 0 0 0\n0 1 0 0 0 0 0 0 9\n0 5 0 0 4 0 0 0 6\n0 9 0 0 0 0 0 0 1\n0 7 0 5 0 0 0 3 0\n6 0 0 0 0 7 0 5 0\n4 0 0 0 6 0 0 2 0\n8 0 0 0 0 0 0 1 0\n0 0 0 1 0 0 3 0 0\n" <<endl ;
        break ;
    case 2:
        cout << "1 8 4 2 0 9 5 0 0\n6 3 9 1 5 0 0 8 0\n0 0 0 8 3 0 1 9 0\n4 9 0 0 0 7 0 0 0\n8 1 0 3 0 0 0 6 0\n0 0 0 9 0 0 0 5 0\n5 0 3 0 8 0 0 0 0\n7 6 8 0 0 5 0 0 0\n0 0 0 0 0 0 0 0 0\n" <<endl ;
        break ;
    case 3:
        cout << "5 1 0 8 2 0 4 3 0\n0 0 6 0 0 0 0 1 0\n9 0 0 0 1 0 5 2 0\n4 0 0 7 3 0 8 0 0\n6 9 2 1 0 8 0 5 0\n0 7 0 2 0 0 0 0 0\n2 6 4 3 8 0 0 0 0\n1 0 9 0 0 2 0 0 0\n0 0 0 0 0 0 0 0 0\n" <<endl ;
        break ;
    case 4:
        cout << "2 6 8 3 5 0 4 0 0\n5 9 1 4 0 7 8 3 0\n4 0 0 8 0 0 5 0 0\n1 5 6 0 4 0 3 9 0\n0 2 0 0 0 0 0 0 0\n9 0 0 1 0 0 6 0 0\n0 1 2 0 8 5 0 0 0\n7 3 5 6 0 0 0 0 0\n0 0 0 0 0 0 0 0 0\n" <<endl ;
        break ;
    case 5:
        cout << "0 2 0 6 0 8 5 7 0\n4 8 7 1 0 0 2 6 0\n3 0 0 7 0 0 0 0 0\n2 4 5 0 0 9 7 0 0\n6 0 0 4 0 0 1 0 0\n0 0 0 0 0 0 3 0 0\n0 6 0 0 0 2 0 0 0\n9 0 1 0 4 0 0 0 2\n0 0 0 0 0 0 0 0 0\n" <<endl ;
        break ;
    }
}