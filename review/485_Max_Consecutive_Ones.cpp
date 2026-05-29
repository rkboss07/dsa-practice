#include <iostream>

using namespace std;

int main() {
    int maxim = 0, c = 0;

    for (int i = 0; i < array.size(); i++){
        if (array[i]== 1){
            c++;
        }
        else {
            c = 0;
        }

        maxim = max(maxim, c);
    }
    return maxim;
}