// a.

#include <iostream>

using namespace std;

int main()
{
    int T[10];
    int i, max, min;
    for (i = 0; i < 10; i++)
    {
        cout << "T[" << i << "]=";
        cin >> T[i];
    }
    max = T[0];
    min = T[0];
    for (i = 1; i < 10; i++)
    {
        if (T[i] > max)
            max = T[i];
    }
    for (i = 1; i < 10; i++)
    {
        if (T[i] < min)
            min = T[i];
    }
    cout << "le max est:" << max << endl;
    cout << "le min est:" << min;

    return 0;
}

