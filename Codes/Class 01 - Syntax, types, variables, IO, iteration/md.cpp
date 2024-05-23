#include <iostream>
using namespace std;

// manhattan distance entre (x1, y1) e (x2, y2) = |x1 - x2| + |y1 + y2|

int main(){
    int x1, x2, y1, y2, pairs, distance, x, y;

    /*
    pairs = quantidade de pares ordenados
    (x1, y1) = 1o par
    (x2, y2) = 2o par / par mais recente
    (x, y) = i-ésimo par caso existam mais que 2 pares
    */

    cin >> pairs >> x1 >> y1 >> x2 >> y2;
    distance = abs(x1-x2) + abs(y1-y2);

    for (int i = 3; i <= pairs; i++){
        cin >> x >> y;
        distance = distance + (abs(x2 - x) + abs(y2 - y));
        x2 = x;
        y2 = y;
    }
    
    cout << distance << endl;
    return 0;
}