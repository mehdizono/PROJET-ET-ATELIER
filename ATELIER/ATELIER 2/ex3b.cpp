#include <iostream>

using namespace std;

int main(){
    int T[10];
    int max, min;
    int *P;
    for (P = T; P < T + 10; P++)
    {
        cout << "T[" << P - T << "]=";
        cin >> *P;
    }
    P = T;
    max = *P;
    min = *P;
    for (P = T; P < T + 10; P++)
    {
        if (*P > max)
            max = *P;
    }
    for (P = T; P < T + 10; P++)
    {
        if (*P < min)
            min = *P;
    }
    cout << "le max est:" << max << endl;
    cout << "le min est:" << min;

    return 0;
}
