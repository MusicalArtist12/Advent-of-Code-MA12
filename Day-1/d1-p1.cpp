// number of calories each elf is carrying 
// elves take turns writing down the number of calories contained in each meal
// They need to know which elf to ask if they run out

#include <iostream>
#include <fstream>

#include <vector>

int addElf(std::fstream& fin);
bool includes(int arr[], int n, int check);

int main() {
    std::fstream fin;
    fin.open("puzzle-input.txt", std::ios::in);

    std::vector <int> elves;

    std::string line;
    int linenum = 1;

    while(!fin.eof()) {

        elves.push_back(addElf(fin));

        linenum++;
    } fin.close();
    
    int n = 3;
    int top[] = {-1, -1, -1};  

    for(int i = 0; i < n; i++) {
        for(int j = 0; (j < elves.size()); j++) {
            if(
                elves[j] > elves[top[i]] &&
                !includes(top, n, j)
            ) top[i] = j;
        }
    }

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += elves[top[i]];
    }

    std::cout << sum << std::endl;
    return 0;
}

int addElf(std::fstream& fin) {
    std::string line;
    int cal = 0;

    getline(fin, line, '\n');

    while(!line.empty()) {
        cal += stoi(line);
        getline(fin, line, '\n');

        if(fin.eof()) break;
    }

    return cal;
}

bool includes(int arr[], int n, int check) {
    for(int i = 0; i < n; i++) {
        if(check == arr[i]) return true;
    }

    return false;
}