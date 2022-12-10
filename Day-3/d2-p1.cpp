#include <iostream>
#include <fstream>
#include <string>

int line_priority(std::string line);
int group_priority(std::string lineA, std::string lineB, std::string lineC);

char find_similar(char alpha[], char beta[], int a, int b);
char find_similar(char alpha[], char beta[], char gamma[], int a, int b, int c);

int main() {
    std::fstream fin;

    int sum = 0;

    fin.open("puzzle-input.txt", std::ios::in);
    while(!fin.eof()) {
        //std::string line;
        //getline(fin, line, '\n');
        //sum += line_priority(line); // part 1
        std::string lineA, lineB, lineC;
        getline(fin, lineA, '\n');
        getline(fin, lineB, '\n');
        getline(fin, lineC, '\n');

        int value = group_priority(lineA, lineB, lineC);

        if(value >= 65 && value <= 90) value = value - 64 + 26;
        if(value >= 97 && value <= 122) value = value - 96;

        sum += value;
    }


    std::cout << "sum: " << sum << std::endl;
}

int line_priority(std::string line) {
    int length = line.size();
    int pack_size = length/2;

    char A[pack_size];
    char B[pack_size];

    for(int i = 0; i < pack_size; i++) {
        A[i] = line[i];
        B[i] = line[pack_size + i];
    }

    char found = find_similar(A, B, pack_size, pack_size);

    int value = (int) found;
    return value;
}

int group_priority(std::string lineA, std::string lineB, std::string lineC) {
    int lengthA = lineA.size();
    int lengthB = lineB.size();
    int lengthC = lineC.size();

    char* A = &lineA[0];
    char* B = &lineB[0];
    char* C = &lineC[0];

    char found = find_similar(A, B, C, lengthA, lengthB, lengthC);

    int value = (int) found;
    return value;
}

char find_similar(char alpha[], char beta[], int a, int b) {
    char found;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            if(alpha[i] == beta[j]) found = alpha[i];
        }
    }
    return found;
}

char find_similar(char alpha[], char beta[], char gamma[], int a, int b, int c) {
    char found;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                if(alpha[i] == beta[j] && alpha[i] == gamma[k]) found = alpha[i];
            }
        }
    }
    return found;
}

