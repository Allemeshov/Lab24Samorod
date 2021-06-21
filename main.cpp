#include <iostream>
#include "1d/part1d.h"
#include "2d/part2d.h"

int main() {
    std::string inp;
    int task;
    while (true) {
        std::cout << "Task: ";
        std::cin >> inp;
        switch (inp[0]) {
            case '1':
                task = 1;
                break;
            case '2':
                task = 2;
                break;
            default: {
                if (inp == "exit")
                    return 1;

                std::cout << "Invalid!" << std::endl;
                continue;
            }
        }

        std::cout << "Type (1d/2d): ";
        std::cin >> inp;

        if (inp == "1d") {
            if (task == 1)
                task1_1d();
            else
                task2_1d();
        } else if (inp == "2d") {
            if (task == 1)
                task1_2d();
            else
                task2_2d();
        } else
            std::cout << "Invalid!\n";
    }
}
