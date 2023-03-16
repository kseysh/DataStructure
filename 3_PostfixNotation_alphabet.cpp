#include <iostream>
using namespace std;

int main() {
    string postfix = "";
    cin >> postfix;

    string stack[100];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) {
        char alphabet = postfix[i];
        if (alphabet >= 'A' && alphabet <= 'Z') {
            stack[++top] = string(1, alphabet);

        }
        else {
            string temp1 = stack[top--];
            string temp2 = stack[top--];
            string result = temp2 + alphabet + temp1;
            stack[++top] = result;
        }

    }
    cout << stack[top] << endl;

    return 0;

}
