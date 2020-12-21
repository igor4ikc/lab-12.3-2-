#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spysok
{
    Spysok* link1,
        * link2;
    inform inf;
};

int Create(Spysok*& first, Spysok*& last, int index, int N, int i);
int Cout(Spysok*& T, inform inf, int N, int index);
void Process(Spysok*& T, inform L1, Spysok*& last);

int main(void)
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Spysok* first = NULL;
    Spysok* last = NULL;

    int index = rand() % 6, N = 10, i = 0;
    Create(first, last, index, N, i);

    Spysok* T = first;
    cout << "L2: " << endl << endl;
    Cout(T, 0, N, index);
    cout << endl << endl;

    int L1;

    cout << "¬вед≥ть L1: ";  cin >> L1;
    cout << endl;


    T = first;
    Process(T, L1, last);
    T = first;
    Cout(T, 0, N, index);

    return 0;
}

int Create(Spysok*& first, Spysok*& last, int index, int N, int i)
{
    Spysok* tmp = new Spysok;

    tmp->inf = index;
    tmp->link1 = NULL;
    tmp->link2 = NULL;
    if (first == NULL)
        first = tmp;
    else
    {
        last->link1 = tmp;
        tmp->link2 = last;
    }
    last = tmp;

    if (i < N - 1)
        return Create(first, last, rand() % 6, N, i + 1);
    else
        return 0;
}

int Cout(Spysok*& T, inform inf, int N, int index)
{
    if (T != NULL)
    {
        inf = T->inf;
        cout << inf << "   ";
    }

    if (T != NULL)
        return Cout(T->link1, inf, N, index + 1);
    else
        return 0;
}

void Process(Spysok*& T, inform L1, Spysok*& last)
{
    if (T != NULL)
    {
        if (T->inf == L1)
        {
            Spysok* tmp = new Spysok;
            tmp->inf = L1;
            tmp->link1 = T->link1;
            if (T->link1 != NULL)
                T->link1->link2 = tmp;
            else
                last = tmp;
            T->link1 = tmp;
            tmp->link2 = T;
            return Process(T->link1->link1, L1, last);
        }
        else
            return Process(T->link1, L1, last);
    }
}