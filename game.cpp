#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

char arr[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int row, col;
char token = 'x';
string name1 = "", name2 = "";
bool tie;

// This function makes playing space for players
void function1() {
    // Making gaming place
    cout << "   |   |   \n";
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << "\n";
    cout << "   |   |   \n";
}

// This function takes input from the user
void function2() {
    // Taking position value from the user
    int digit;
    if (token == 'x') {
        cout << name1 << " please Enter : ";
        cin >> digit;
    }
    if (token == '0') {
        cout << name2 << " please Enter : ";
        cin >> digit;
    }
    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        col = (digit - 1) % 3;
    }
    else {
        cout << "Invalid !!! ";
    }

    // Put the value
    if (token == 'x' && arr[row][col] != 'x' && arr[row][col] != '0') {
        arr[row][col] = 'x';
        token = '0';
    }
    else if (token == '0' && arr[row][col] != 'x' && arr[row][col] != '0') {
        arr[row][col] = '0';
        token = 'x';
    }
    else {
        cout << "Sorry no space is empty !!! ";
        function2();
    }
    function1();
}

bool function3() {
    for (int i = 0; i < 3; i++) {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) || (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])) {
            return true;
        }
    }
    if ((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 'x' && arr[i][j] != '0') {
                return false;
            }
        }
    }

    // If all spaces are filled and no winner, it's a tie
    tie = true;
    return true;
}


int main() {
    cout << "Enter name of first player : ";
    getline(cin, name1);
    cout << "Enter name of the second player : ";
    getline(cin, name2);
    function1();
    while (!function3()) {
        function2();
        function3();
    }
    if (token == 'x' && tie == false) {
        cout << name2 << " Wins the game" << endl;
    }
    else if (token == '0' && tie == false) {
        cout << name1 << " Wins the game" << endl;
    }
    else {
        cout << "It's a draw" << endl;
    }

    return 0;
}