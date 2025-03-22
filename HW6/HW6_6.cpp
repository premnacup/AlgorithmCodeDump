#include <iostream>
#include <algorithm> // Only for sorting

using namespace std;

const int MAXN = 8000;
int Bookcosts[MAXN], Ans[3] = {0};
int N, M;
bool found = false;
int maxsum = 0;

void Subset(int i, int count, int sum, int selected[])
{
    if (i >= N)
    {
        return;
    }
    if (count == 3)
    {
        if (sum <= M && sum > maxsum)
        {
            maxsum = sum;
            Ans[0] = selected[0];
            Ans[1] = selected[1];
            Ans[2] = selected[2];
            found = true;
        }
        return;
    }
    selected[count] = Bookcosts[i];
    Subset(i + 1, count + 1, sum + Bookcosts[i], selected);
    Subset(i + 1, count, sum, selected);
}

int main()
{

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> Bookcosts[i];
    }
    sort(Bookcosts, Bookcosts + N);

    int selected[3] = {0};
    Subset(0, 0, 0, selected);

    if (!found)
    {
        cout << "0" << endl
             << "0" << endl
             << "0" << endl;
    }
    else
    {
        cout << Ans[0] << endl
             << Ans[1] << endl
             << Ans[2] << endl;
    }

    return 0;
}