#include <iostream>
#include <fstream>
#include <sstream>

int getScore(char p, char q);

int main() {
    std::fstream fin;
    fin.open("puzzle-input.txt", std::ios::in);

    int score = 0;
    std::string temp;
    while(!fin.eof()) {
        char a;
        getline(fin, temp, ' ');
        a = temp[0];

        char b;
        getline(fin, temp, '\n');
        b = temp[0];

        if(a == '\n' || b == '\n') break;
        score += getScore(a, b);
    }
    std::cout << score << std::endl;
}

int getScore(char a, char b) {
    int a_int = (int) a - (int) 'A'; // 65 - 65 = 0; 66 - 65 = 1; 67 - 65 = 2
    int b_int = (int) b - (int) 'X'; // 88 - 88 = 0; 89 - 88 = 1; 90 - 88 = 2
    
    //std::cout << a_int << ' ' << b_int << std::endl;

    /*
    int score = 1 + b_int;

    if(a_int == b_int) score += 3;
    if((a_int + 1) % n == b_int) score += 6;
    */

    int score = 1 + (b_int * 3); // since a_int % 3 produces 0 <= n <= 2

    if(b_int == 0) score += (a_int + 2) % 3;
    if(b_int == 1) score += a_int;
    if(b_int == 2) score += (a_int + 1) % 3;

    // std::cout << b_int * 3 << " (" << a_int + 1<< ") " << score - ((b_int) * 3) << " " << score << std::endl;
    
    return score;
}