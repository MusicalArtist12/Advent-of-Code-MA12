#include <iostream>
#include <fstream>
#include <vector>

int addElf(std::fstream& fin); // gets values inbetween spaces, also avoids nested while loops
bool includes(int arr[], int n, int check); // int array function to check if a int is in the int array

int main() {
    // Load vector of elves from file
    std::fstream fin;
    std::vector <int> elves;
    std::string line;

    fin.open("puzzle-input.txt", std::ios::in);
    while(!fin.eof()) {
        elves.push_back(addElf(fin));

    } fin.close();
    
    // declare and initialize an array for the top 3
    int n = 3;
    int top[n];  
    for(int i = 0; i < n; i++) top[i] = -1; // -1 avoids bugs and acts as an int NULL

    // get the top 3 from the vector
    for(int i = 0; i < n; i++) { // do this n times
        for(int j = 0; (j < elves.size()); j++) { // check against all elves
            if( elves[j] > elves[top[i]] && !includes(top, n, j)) {
                top[i] = j;
            }
        }
    }/*  
        This automatically sorts the list too; 
        we exclude the last one the next time around
    */

    // Get the sum of the top 3
    int sum = 0;
    for(int i = 0; i < n; i++) {
        std::cout << "elf(" << top[i] << ") = " << elves[top[i]] << std::endl;
        sum += elves[top[i]];
    }

    std::cout << "\nsum of top 3: " << sum << std::endl;

    return 0;
}

int addElf(std::fstream& fin) {
    std::string line;
    int cal = 0;

    getline(fin, line, '\n'); // initialize line

    while(!line.empty()) { 
        cal += stoi(line); // get the sum between spaces
        getline(fin, line, '\n');

        if(fin.eof()) break; // check since the last line isn't "empty"
    }

    return cal;
}

bool includes(int arr[], int n, int check) {
    for(int i = 0; i < n; i++) {
        if(check == arr[i]) return true;
    }

    return false;
}