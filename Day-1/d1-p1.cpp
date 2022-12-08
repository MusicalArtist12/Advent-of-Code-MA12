// number of calories each elf is carrying 
// elves take turns writing down the number of calories contained in each meal
// They need to know which elf to ask if they run out

#include <iostream>
#include <fstream>

#include <vector>

int addElf(std::fstream& fin);

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

    int largest = 0; 
    for(int i = 0; i < elves.size(); i++){
        if(elves[largest] < elves[i]) largest = i;
    }

    std::cout << largest << ' ' << elves[largest] << std::endl;
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
