#include <bits/stdc++.h>
using namespace std;

class ChecksPostFacto
{
    unordered_map<int, pair<int, int>> um;
    int n = 32;
    char arr[8][8];
    pair<int, int> p;
    bool present[33] = {};

public:
    int start, end;
    ChecksPostFacto()
    {

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)
                    {
                        arr[i][j] = '_';
                    }
                    else
                    {
                        arr[i][j] = '.';
                    }
                }
                else
                {
                    if (j % 2 == 0)
                    {
                        arr[i][j] = '.';
                    }
                    else
                    {
                        arr[i][j] = '_';
                    }
                }
            }
        }
        //Maping i,j;
        int count = 1;
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                start = 1;
                end = 8;
            }
            else
            {
                start = 0;
                end = 7;
            }
            for (int j = start; j < end; j += 2)
            {
                p.first = i;
                p.second = j;
                um[count++] = p;
            }
        }
    }

    pair<int, int> position(int i)
    {
        pair<int, int> p1;
        for (auto x : um)
        {
            if (x.first == i)
            {
                p1.first = x.second.first;
                p1.second = x.second.second;
            }
        }
        return p1;
    }

    void userInput()
    {
        pair<int, int> p1 ;
        int pos;
        //White king
        
        do{
        cout << "W : ";
        cin >> pos;
        cout << endl;

        if(pos>0 && pos<33){
         p1 = position(pos);
        arr[p1.first][p1.second] = 'W';
        present[pos] = true;
        }

        }while((pos<1 || pos>32));

        //black king
        cout << "B : ";
        cin >> pos;
        if ((pos>0 && pos<33) && present[pos] == false)
        {
            p1 = position(pos);
            arr[p1.first][p1.second] = 'B';
            present[pos] = true;
        }
        else
        {
            do
            {
                cout << "Enter valid pos" << endl;
                cout << "B : ";
                cin >> pos;
                if ((pos>0 && pos<33) && present[pos] == false)
                {
                    p1 = position(pos);
                    arr[p1.first][p1.second] = 'B';
                    
                }
            } while ((pos<1 || pos>32) && present[pos] == true);
            present[pos] = true;
        }
        cout << endl;

       //white man
        cout << "Enter 3 White Man position " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "w " << i + 1 << " : ";
            cin >> pos;
        if ((pos>0 && pos<33) && present[pos] == false)
        {
            p1 = position(pos);
            arr[p1.first][p1.second] = 'w';
            present[pos] = true;
        }
        else
        {
            do
            {
                cout << "Enter valid pos" << endl;
                cout << "w " << i + 1 << " : ";
                
                cin >> pos;
                if ((pos>0 && pos<33) && present[pos] == false)
                {
                    p1 = position(pos);
                    arr[p1.first][p1.second] = 'w';
                    
                }
            } while ((pos<1 || pos>32) && present[pos] == true);
            present[pos] = true;
        }

            cout << endl;
        }

        cout << "Enter 3 Black Man position " << endl;
        for (int i = 0; i < 3; i++)
        {

            cout << "b " << i + 1 << ": ";
                cin >> pos;
        if ((pos>0 && pos<33) && present[pos] == false)
        {
            p1 = position(pos);
            arr[p1.first][p1.second] = 'b';
            present[pos] = true;
        }
        else
        {
            do
            {
                cout << "Enter valid pos" << endl;
                cout << "b " << i + 1 << ": ";
                
                cin >> pos;
                if ((pos>0 && pos<33) && present[pos] == false)
                {
                    p1 = position(pos);
                    arr[p1.first][p1.second] = 'b';
                    
                }
            } while ((pos<1 || pos>32) && present[pos] == true);
            present[pos] = true;
        }

            cout << endl;
        }
    }

    void show()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
};

int main()
{
    ChecksPostFacto c1;

    c1.userInput();
    c1.show();

    // c1.show();

    /* pair<int,int>pos = c1.position(32);
    cout<<pos.first<<" "<<pos.second;*/
    return 0;
}