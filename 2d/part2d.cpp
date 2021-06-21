#include "part2d.h"

Sizes2d shrinkMatrix(std::string **matrix, int size);

void findSimilar(std::string **matrix, std::string elem, int i, int y, int *x, int j);


void task1_2d() {

}

void task2_2d() {
    int size;
    do {
        std::cout << "Enter size of matrix: ";
        std::cin >> size;
    } while (size <= 0);

    auto **matrix = (std::string **) malloc(size * sizeof(std::string *));
    for (int i = 0; i < size; ++i) {
        matrix[i] = (std::string *) malloc(size * sizeof(std::string));
        for (int j = 0; j < size; ++j) {
            std::cout << "Enter element[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    auto newSizes = shrinkMatrix(matrix, size);

    for (int i = 0; i < newSizes.height; ++i) {
        for (int j = 0; j < newSizes.width; ++j) {
            std::cout << "\t[" << i << "][" << j << "]: ";
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

Sizes2d shrinkMatrix(std::string **matrix, int size) {
    int height, width;
    height = width = size;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] != "[_]") {
                findSimilar(matrix, matrix[i][j], i, height, &width, j);
            }
        }
    }

    Sizes2d sizes = {height, width};

    return sizes;
}

void findSimilar(std::string **matrix, std::string elem, int i, int y, int *x, int j) {
    bool hasFoundAny = false;
    int deleter = 0;
    for (int k = 0; k < y; ++k) {
        for (int l = 0; l < *x; ++l) {
            if (matrix[k][l] == elem && (k != i || l != j)) {
                hasFoundAny = true;
                matrix[k][l] = "[_]";
                ++deleter;
            }
        }
    }
    if (hasFoundAny) {
        matrix[i][j] = "[_]";
        ++deleter;
    }

    *x -= deleter;
}


