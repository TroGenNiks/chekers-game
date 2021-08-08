
/*
void show()					
pair<int, int> position(int i)				
int position(int x1, int y1)
void userPositionInput()
void checkValidPosition(int pos, char c, int i = -1)
int checkPossibleSimpleMoves(int curr, char character, int nxt)
int checkPossibleJumpMoves(int curr, char k, int nxt)
int checkValidMoves(vector<int> moves, char jump_type, char character)
int convertToNumber(string s)
void upLeft(int x1, int y1, int n)
void upRight(int x1, int y1, int n)
void downLeft(int x1, int y1, int n)
void downRight(int x1, int y1, int n)
vector<int> getMoves(string move)
void moves(int x1, int y1, int x2, int y2, char c)
void userMove(string move, char m)
char jump(string move)
void winner()
int main()
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> um;
pair<int, int> p1, p2;
int n;
char arr[8][8];
bool present[33] = {};
int num, b_king = 1, w_king = 1, b_man, w_man;

void show() //to show the play board
{
    int count = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << "\t";

        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
                cout << arr[i][j] << " ";
            else if (i % 2 == 0 && j % 2 == 1)
            {
                if (count < 10)
                    cout << "0";
                cout << count++ << " ";
            }
            else if (i % 2 == 1 && j % 2 == 0)
            {
                if (count < 10)
                    cout << "0";
                cout << count++ << " ";
            }
            else
                cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

class Input_And_Validating
{

public:
    pair<int, int> position(int i) //to find position in x,y form
    {
        //21 -> x,y
        return {um[i].first,um[i].second};
    }

    int position(int x1, int y1) //to find position in number form(linear search in unordered map)
    {
        //21 {x,y}
        for (auto x : um)
        {
            if (x.second.first == x1 && x.second.second == y1)
                return x.first;
        }
        return -1;
    }

    void userPositionInput() //for taking input from user
    {
        int pos;
        //White king
        cout << "W(king) : ";
        cin >> pos;
        checkValidPosition(pos, 'W');
        show();
        cout << endl;
        //black king
        cout << "B(king) : ";
        cin >> pos;
        checkValidPosition(pos, 'B');
        show();
        cout << endl;

        cout << "Enter the number of man's : ";
        cin >> num;

        b_man = num;
        w_man = num;
        for (int i = 0; i < num; i++)
        {
            cout << "w(man)" << i + 1 << " : ";
            cin >> pos;
            checkValidPosition(pos, 'w', i);
            show();
            cout << endl;

            cout << "b(man)" << i + 1 << ": ";
            cin >> pos;
            checkValidPosition(pos, 'b', i);
            show();
            cout << endl;
        }
    }

    void checkValidPosition(int pos, char c, int i = -1) //to check if position is valid or not
    {
        if ((pos > 0 && pos < 33) && present[pos] == false)
        {
            p1 = position(pos);
            arr[p1.first][p1.second] = c;
            present[pos] = true;
        }
        else
        {
            do
            {
                cout << "Enter valid pos" << endl;
                if (i != -1)
                    cout << c << i + 1 << " : ";
                else
                    cout << c << " : ";

                cin >> pos;
                if ((pos > 0 && pos < 33) && present[pos] == false)
                {
                    p1 = position(pos);
                    arr[p1.first][p1.second] = c;
                }
            } while ((pos < 1 || pos > 32) || (present[pos] == true));
            present[pos] = true;
        }

        cout << endl;
    }

    int checkPossibleSimpleMoves(int curr, char character, int nxt) //to check posible simple moves(dfs algo)
    {
        int x, y;
        x = um[curr].first;
        y = um[curr].second;

        switch (character)
        {
        case 'B':
            if ((x - 1) > -1 && (y - 1) > -1 && arr[x - 1][y - 1] != 'b')
            {
                if (position(x - 1, y - 1) == nxt)
                    return 1;
            }
            if ((x - 1) > -1 && (y + 1) < 8 && arr[x - 1][y + 1] != 'b')
            {
                if (position(x - 1, y + 1) == nxt)
                    return 1;
            }
            if ((x + 1) < 8 && (y - 1) > -1 && arr[x + 1][y - 1] != 'b')
            {
                if (position(x + 1, y - 1) == nxt)
                    return 1;
            }
            if ((x + 1) < 8 && (y + 1) < 8 && arr[x + 1][y + 1] != 'b')
            {
                if (position(x + 1, y + 1) == nxt)
                    return 1;
            }
            break;

        case 'W':
            if ((x - 1) > -1 && (y - 1) > -1 && arr[x - 1][y - 1] != 'w')
            {
                if (position(x - 1, y - 1) == nxt)
                    return 1;
            }
            if ((x - 1) > -1 && (y + 1) < 8 && arr[x - 1][y + 1] != 'w')
            {
                if (position(x - 1, y + 1) == nxt)
                    return 1;
            }
            if ((x + 1) < 8 && (y - 1) > -1 && arr[x + 1][y - 1] != 'w')
            {
                if (position(x + 1, y - 1) == nxt)
                    return 1;
            }
            if ((x + 1) < 8 && (y + 1) < 8 && arr[x + 1][y + 1] != 'w')
            {
                if (position(x + 1, y + 1) == nxt)
                    return 1;
            }
            break;
        case 'b':
            if ((x + 1) < 8 && (y - 1) > -1 && arr[x + 1][y - 1] != 'b' && arr[x + 1][y - 1] != 'B')
            {
                if (position(x + 1, y - 1) == nxt)
                    return 1;
            }
            if ((x + 1) < 8 && (y + 1) < 8 && arr[x + 1][y + 1] != 'b' && arr[x + 1][y + 1] != 'B')
            {
                if (position(x + 1, y + 1) == nxt)
                    return 1;
            }
            break;
        case 'w':
            if ((x - 1) > -1 && (y - 1) > -1 && arr[x - 1][y - 1] != 'w' && arr[x - 1][y - 1] != 'W')
            {
                if (position(x - 1, y - 1) == nxt)
                    return 1;
            }
            if ((x - 1) > -1 && (y + 1) < 8 && arr[x - 1][y + 1] != 'w' && arr[x - 1][y + 1] != 'W')
            {
                if (position(x - 1, y + 1) == nxt)
                    return 1;
            }
            break;
        }

        return 0;
    }

    int checkPossibleJumpMoves(int curr, char k, int nxt) //to check possible jump moves(dfs algo)
    {
        int x, y;
        x = um[curr].first;
        y = um[curr].second;
        switch (k)
        {
        case 'B':
            if ((x - 2) > -1 && (y - 2) > -1 && arr[x - 1][y - 1] != 'b' && arr[x - 2][y - 2] != 'b')
            {
                if (position(x - 2, y - 2) == nxt)
                    return 1;
            }
            if ((x - 2) > -1 && (y + 2) < 8 && arr[x - 1][y + 1] != 'b' && arr[x - 2][y + 2] != 'b')
            {
                if (position(x - 2, y + 2) == nxt)
                    return 1;
            }
            if ((x + 2) < 8 && (y - 2) > -1 && arr[x + 1][y - 1] != 'b' && arr[x + 2][y - 2] != 'b')
            {
                if (position(x + 2, y - 2) == nxt)
                    return 1;
            }
            if ((x + 2) < 8 && (y + 2) < 8 && arr[x + 1][y + 1] != 'b' && arr[x + 2][y + 2] != 'b')
            {
                if (position(x + 2, y + 2) == nxt)
                    return 1;
            }
            break;
        case 'W':
            if ((x - 2) > -1 && (y - 2) > -1 && arr[x - 1][y - 1] != 'w' && arr[x - 2][y - 2] != 'w')
            {
                if (position(x - 2, y - 2) == nxt)
                    return 1;
            }
            if ((x - 2) > -1 && (y + 2) < 8 && arr[x - 1][y + 1] != 'w' && arr[x - 2][y + 2] != 'w')
            {
                if (position(x - 2, y + 2) == nxt)
                    return 1;
            }
            if ((x + 2) < 8 && (y - 2) > -1 && arr[x + 1][y - 1] != 'w' && arr[x + 2][y - 2] != 'w')
            {
                if (position(x + 2, y - 2) == nxt)
                    return 1;
            }
            if ((x + 2) < 8 && (y + 2) < 8 && arr[x + 1][y + 1] != 'w' && arr[x + 2][y + 2] != 'w')
            {
                if (position(x + 2, y + 2) == nxt)
                    return 1;
            }
            break;

        case 'w':
            if ((x - 2) > -1 && (y - 2) > -1 && arr[x - 1][y - 1] != 'w' && arr[x - 1][y - 1] != 'W' && arr[x - 2][y - 2] != 'w' && arr[x - 2][y - 2] != 'W')
            {
                if (position(x - 2, y - 2) == nxt)
                    return 1;
            }
            if ((x - 2) > -1 && (y + 2) < 8 && arr[x - 1][y + 1] != 'w' && arr[x - 1][y + 1] != 'W' && arr[x - 2][y + 2] != 'w' && arr[x - 2][y + 2] != 'W')
            {
                if (position(x - 2, y + 2) == nxt)
                    return 1;
            }
            break;

        case 'b':
            if ((x + 2) < 8 && (y - 2) > -1 && arr[x + 1][y - 1] != 'b' && arr[x + 1][y - 1] != 'B' && arr[x + 2][y - 2] != 'b' && arr[x + 2][y - 2] != 'B')
            {
                if (position(x + 2, y - 2) == nxt)
                    return 1;
            }
            if ((x + 2) < 8 && (y + 2) < 8 && arr[x + 1][y + 1] != 'b' && arr[x + 1][y + 1] != 'B' && arr[x + 2][y + 2] != 'b' && arr[x + 2][y + 2] != 'B')
            {
                if (position(x + 2, y + 2) == nxt)
                    return 1;
            }
            break;
        }
        return 0;
    }
    int checkValidMoves(vector<int> moves, char jump_type, char character) //to check if move is valid
    {
        int ans;
        for (int i = 0; i < moves.size() - 1; i++)
        {

            if (jump_type == '-')
                ans = checkPossibleSimpleMoves(moves[i], character, moves[i + 1]);
            else
                ans = checkPossibleJumpMoves(moves[i], character, moves[i + 1]);

            if (ans == 0)
                return 0;
        }
        return 1;
    }
};

class Moves : public Input_And_Validating
{

private:
    int convertToNumber(string s) //to convert string in number
    {
        int num = 0;
        for (char c : s)
        {
            num = num * 10 + (c - '0');
        }
        return num;
    }
    void upLeft(int x1, int y1, int n) //to move up left
    {
        for (int i = 0; i < n; i++)
        {
            arr[x1][y1] = '.';
            if (arr[x1 - 1][y1 - 1] == 'b')
                b_man--;
            if (arr[x1 - 1][y1 - 1] == 'w')
                w_man--;
            if (arr[x1 - 1][y1 - 1] == 'B')
                b_king--;
            if (arr[x1 - 1][y1 - 1] == 'W')
                w_king--;
            arr[--x1][--y1] = '.';
        }
    }

    void upRight(int x1, int y1, int n) //to move up right(searching and dfs)
    {
        for (int i = 0; i < n; i++)
        {
            arr[x1][y1] = '.';
            if (arr[x1 - 1][y1 + 1] == 'b')
                b_man--;
            if (arr[x1 - 1][y1 + 1] == 'w')
                w_man--;
            if (arr[x1 - 1][y1 + 1] == 'B')
                b_king--;
            if (arr[x1 - 1][y1 + 1] == 'W')
                w_king--;
            arr[--x1][++y1] = '.';
        }
    }

    void downLeft(int x1, int y1, int n) //to move down left(searching and dfs)
    {
        for (int i = 0; i < n; i++)
        {
            arr[x1][y1] = '.';
            if (arr[x1 + 1][y1 - 1] == 'w')
                w_man--;
            if (arr[x1 + 1][y1 - 1] == 'b')
                b_man--;
            if (arr[x1 + 1][y1 - 1] == 'W')
                w_king--;
            if (arr[x1 + 1][y1 - 1] == 'B')
                b_king--;
            arr[++x1][--y1] = '.';
        }
    }

    void downRight(int x1, int y1, int n) //to move down right(searching and dfs)
    {
        for (int i = 0; i < n; i++)
        {
            arr[x1][y1] = '.';

            if (arr[x1 + 1][y1 + 1] == 'w')
                w_man--;
            if (arr[x1 + 1][y1 + 1] == 'b')
                b_man--;
            if (arr[x1 + 1][y1 + 1] == 'W')
                w_king--;
            if (arr[x1 + 1][y1 + 1] == 'B')
                b_king--;
            arr[++x1][++y1] = '.';
        }
    }

public:
    vector<int> getMoves(string move) //to get the moves in number form
    {
        string helper;
        helper = "";
        vector<int> Moves;
        int n = move.length();
        int i = 0;
        for (i = 0; i < n; i++)
        {
            while (i < n && move[i] != 'x' && move[i] != 'X' && move[i] != '*' && move[i] != '-')
            {
                if (move[i] >= '0' && move[i] <= '9')
                    helper += move[i++];
            }
            int num = convertToNumber(helper);

            if (num > 0 && num < 33)
                Moves.push_back(num);

            helper = "";
        }

        return Moves;
    }

    void moves(int x1, int y1, int x2, int y2, char c) //moving of character(dfs algo)
    {
        n = abs(y2 - y1);
        switch (c)
        {
        case 'K':
            if (x1 < x2)
            {
                if (y1 < y2)
                    downRight(x1, y1, n);
                else
                    downLeft(x1, y1, n);
            }
            else
            {
                if (y1 < y2)
                    upRight(x1, y1, n);
                else
                    upLeft(x1, y1, n);
            }
            break;

        case 'w':
            if (y1 < y2)
                upRight(x1, y1, n);
            else
                upLeft(x1, y1, n);
            break;

        case 'b':
            if (y1 < y2)
                downRight(x1, y1, n);
            else
                downLeft(x1, y1, n);
            break;
        }
    }

    void userMove(string move, char m) //to perform the user moves
    {
        int s;
        vector<int> M;

        M = getMoves(move);
        s = M.size() - 1;

        for (int i = 0; i < s; i++)
        {
            p1 = position(M[i]);
            p2 = position(M[i + 1]);
            int x1 = p1.first;
            int y1 = p1.second;
            int x2 = p2.first;
            int y2 = p2.second;

            if (m == 'w' || m == 'b')
                moves(x1, y1, x2, y2, m);
            else
                moves(x1, y1, x2, y2, 'K');

            arr[x2][y2] = m;
        }
    }
};

class ChecksPostFacto : public Moves
{
    int start, end, count = 1;

public:
    ChecksPostFacto() //constructor to initialize the board and map x,y co-ordinate with numbers(unordered map ->mapping char with x,y co-ordinate)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                    arr[i][j] = '_';
                else if (i % 2 == 0 && j % 2 == 1)
                    arr[i][j] = '.';
                else if (i % 2 == 1 && j % 2 == 0)
                    arr[i][j] = '.';
                else
                    arr[i][j] = '_';
            }
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j += 2)
            {
                p1.first = i;
                if (i % 2 == 0)
                    p1.second = j + 1;
                else
                    p1.second = j;
                um[count++] = p1;
            }
        }
        show();
        cout << endl;
        userPositionInput();
    }

    char jump(string move) //to get jump type[cross or simple](serching)
    {
        for (char c : move)
        {
            if (c == 'x' || c == 'X' || c == '*')
                return 'x';
            if (c == '-')
                return '-';
        }
        return ' ';
    }

    void winner() //to find winner
    {
        if (b_king > w_king)
            cout << "Black wins";
        else if (b_king < w_king)
            cout << "White wins";
        else
        {
            if (b_man > w_man)
                cout << "Black wins";
            else if (b_man < w_man)
                cout << "White wins";
            else
                cout << "Draw!!";
        }
    }
};

int main()
{
    ChecksPostFacto c1;

    int numberOfMoves, flag, flag2, flag3 = 0, i;
    char start, change, jump_type;
    string move;
    string s;
    vector<int> v;
    int check1 = 1, check2;

    cout << "Start Character(W or B) : ";
    cin >> start;

    if (start == 'w' || start == 'W')
        flag = 0;
    else
        flag = 1;
    cout << "number of moves : ";
    cin >> numberOfMoves;
    cin;
    for (i = 0; i < numberOfMoves; i++)
    {
        if (flag == 0)
            s = "(white move)";
        else
            s = "(Black move)";
        do
        {
            show();
            cout << endl;
            if ((b_man == 0 && b_king == 0) || (w_man == 0 && w_king == 0))
            {
                flag3 = 1;
                break;
            }
            cout << "\nEnter move " << i + 1 << " " << s << " :";
            cin >> move;

            v = c1.getMoves(move);
            jump_type = c1.jump(move);
            change = arr[um[v[0]].first][um[v[0]].second];

            if (change == 'w' || change == 'W')
                flag2 = 0;
            else
                flag2 = 1;

                //flag=0    flag2=1

            if (flag == flag2)
            {
                check1 = true;//to check if start is valid
                if (flag == 0)
                    flag = 1;
                else
                    flag = 0;
            }
            else
                check1 = 0;

            int num = v[0];
            if (check1 == 1 && change == 'b' && num > 28 && num < 33)
            {
                change = 'B';
                b_man--;
                b_king++;
            }

            if (check1 == 1 && change == 'w' && num > 0 && num < 5)
            {
                change = 'W';
                w_man--;
                w_king++;
            }

            check2 = c1.checkValidMoves(v, jump_type, change);//to check if move is valid

            if (!check1 || !check2)//to check if both are valid
                cout << "Enter valid move" << endl;
            else
                c1.userMove(move, change);
            cout << endl;
            if (check2 == 0 && check1 == 1)
            {
                if (flag == 0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        } while (!check1 || !check2);
        if (flag3==1)
            break;
    }
    if (i == numberOfMoves)
        show();
    cout << endl
         << "End of Moves!" << endl;
    c1.winner();
    return 0;
}

