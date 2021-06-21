#include "part1d.h"

Sizes1d shrinkMatrix(std::string *matrix, int size);

void findSimilar(std::string *matrix, std::string elem, int i, int y, int *x, int j);

void task1_1d() {

}


/*
 * Дан двумерный массив целых чисел. Сжать массив, удалив из него повторяющиеся элементы. Уменьшить размер строк массива на количество удаленных элементов.
 */

void task2_1d() {
    int size;
    do {
        std::cout << "Enter size of matrix: ";
        std::cin >> size;
    } while (size <= 0);

    auto *matrix = (std::string *) malloc(size * size * sizeof(std::string));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "Enter element[" << i << "][" << j << "]: ";
            std::cin >> matrix[i * size + j];
        }
    }

    auto newSizes = shrinkMatrix(matrix, size);

    for (int i = 0; i < newSizes.height; ++i) {
        for (int j = 0; j < newSizes.width; ++j) {
            std::cout << "\t[" << i << "][" << j << "]: ";
            std::cout << matrix[i * size + j];
        }
        std::cout << std::endl;
    }

    free(matrix);
}

Sizes1d shrinkMatrix(std::string *matrix, int size) {
    int height, width;
    height = width = size;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i * size + j] != "[_]") {
                findSimilar(matrix, matrix[i * size + j], i, height, &width, j);
            }
        }
    }

    Sizes1d sizes = {height, width};

    return sizes;
}

void findSimilar(std::string *matrix, std::string elem, int i, int y, int *x, int j) {
    bool hasFoundAny = false;
    int deleter = 0;
    for (int k = 0; k < y; ++k) {
        for (int l = 0; l < *x; ++l) {
            if (matrix[k * y + l] == elem && (k != i || l != j)) {
                hasFoundAny = true;
                matrix[k * y + l] = "[_]";
                ++deleter;
            }
        }
    }
    if (hasFoundAny) {
        matrix[i * y + j] = "[_]";
        ++deleter;
    }

    *x -= deleter;
}


