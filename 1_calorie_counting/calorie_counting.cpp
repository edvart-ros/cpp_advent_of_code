#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string calories_str;
    ifstream input_file("input.txt");

    if (!input_file.is_open()) {
        cerr << "failed to read file" << endl;
        return 1;
    }
    
    int elf_cals = 0;
    int highest_elf_cals = 0;
    int second_highest_elf_cals = 0;
    int third_highest_elf_cals = 0;
    int tmp;

    while (getline (input_file, calories_str)) {
        if (calories_str.empty()) {
            if (elf_cals > highest_elf_cals) {
                tmp = second_highest_elf_cals;      
                second_highest_elf_cals = highest_elf_cals;
                third_highest_elf_cals = tmp;
                highest_elf_cals = elf_cals;
            } else if (elf_cals > second_highest_elf_cals) {
                third_highest_elf_cals = second_highest_elf_cals;
                second_highest_elf_cals = elf_cals;
            } else if (elf_cals > third_highest_elf_cals) {
                third_highest_elf_cals = elf_cals;
            }

            highest_elf_cals = (elf_cals > highest_elf_cals) ? elf_cals : highest_elf_cals; 
            elf_cals = 0;
        } else {
            elf_cals += stoi(calories_str);
        }
    }
    
    cout << endl << endl << elf_cals << endl << endl;
    if (elf_cals > highest_elf_cals) {
        tmp = second_highest_elf_cals;
        second_highest_elf_cals = highest_elf_cals;
        third_highest_elf_cals = tmp;
        highest_elf_cals = elf_cals;
    } else if (elf_cals > second_highest_elf_cals) {
        third_highest_elf_cals = second_highest_elf_cals;
        second_highest_elf_cals = elf_cals;
    } else if (elf_cals > third_highest_elf_cals) {
        third_highest_elf_cals = elf_cals;
    }

    cout << highest_elf_cals + second_highest_elf_cals + third_highest_elf_cals << endl;
    return 0;
}