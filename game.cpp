#include<iostream>
#include<vector>
#include<string>
using namespace std;

string** arr;
int n, row, col;
string token = "x";
string name1 = "", name2 = "";
bool tie;

// making the game board
// making board fn
void initializeBoard() {
    int l=1;
    arr = new string*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new string[n];
        for (int j = 0; j < n; ++j) {
            // Fill the board with numbers 1 to n*n
            arr[i][j] = to_string(l); 
            l++;
        }
    }
}

// display the game board
void displayBoard() {

    for(int j=1;j<=n+1;j++){
            cout<<"___";
        }
        cout<<endl;
    for(int i=0;i<(n);i++){
        
        cout << "   |";
        for(int j=1;j<=n-1;j++){
            cout<<"   |";
        }
        cout<<"   \n";

        cout<<" ";
        for(int j=0;j<n;j++){
            if(arr[i][j].size()==1){
            cout<<arr[i][j]<<" | ";}
            else{
                cout<<arr[i][j]<<"| ";
            }
        }
        cout<<"\n";
        cout<<"___|";
        for(int j=1;j<=n-1;j++){
            cout<<"___|";
        }
        //cout<<"___\n";
        cout<<"\n";
    }
}

// take input from the user
void getInput() {
    int digit;
    cout << (token == "x" ? name1 : name2) << " please enter: ";
    cin >> digit;

    // Convert input to row and column
    row = (digit - 1) / n;
    col = (digit - 1) % n;

    // Check for valid input

    if (digit < 1 || digit > n * n || arr[row][col] == "x" || arr[row][col] == "0") {
        cout << "Invalid input! Please try again." << endl;
        getInput();
    }
}

// update the game board
void updateBoard() {
    arr[row][col] = token;
    token = (token == "x") ? "0" : "x";
}

// Function to check win and late
// logic function 
bool checkResult() {
    //check rows and coloum
   for(int i=0;i<n;i++){
        string pivot1=arr[i][0];
        bool rowCheck=true;
        for(int j=1;j<n;j++){
           // cout<<arr[i][j]<<" ";
            if(pivot1!=arr[i][j])rowCheck=false;

        }
        if(rowCheck)return true;
    }
   
    for(int i=0;i<n;i++){
        string pivot2=arr[0][i];
        bool colCheck=true;
        for(int j=1;j<n;j++){
            if(pivot2!=arr[j][i])colCheck=false;
        }
        if(colCheck)return true;
    }
    

    // check diagonal

    bool diagonalCheck=true;
    string pivot3=arr[0][0];
    for(int i=1;i<n;i++){
        if(pivot3!=arr[i][i])diagonalCheck=false;
    }
    if(diagonalCheck)return true;


    //check antidiagonal

    bool antidiagonalcheck=true;
    string pivot4=arr[n-1][0];
    for(int i=1;i<n;i++){
        if(pivot4!=arr[n-1-i][i])antidiagonalcheck=false;
    }
    if(antidiagonalcheck)return true;

    // Check for a tie
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != "x" && arr[i][j] != "0") {
                return false;
            }
        }
    }

    // space filled and tie
    tie = true;
    return true;
}

// main function
int main() {
    cout << "Enter the size of the board (n x n): ";
    cin >> n;

    initializeBoard();

    cout << "Enter name of the first player: ";
    cin >> name1;
    cout << "Enter name of the second player: ";
    cin >> name2;

    displayBoard();

    while (!checkResult()) {
        getInput();
        updateBoard();
        displayBoard();
        checkResult();
    }

    if (token == "x" && !tie) {
        cout << name2 << " wins the game" << endl;
    } else if (token == "0" && !tie) {
        cout << name1 << " wins the game" << endl;
    } else {
        cout << "It's a draw" << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}