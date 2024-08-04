#include "utils.h"
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time

std::vector<int> createRandomVector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() % 100; // случайные числа в диапазоне от 0 до 99
    }
    return vec;
}

int bin_reach(const std::vector<int>& bin_reach_arr, int target) {
    int left = 0;
    int right = bin_reach_arr.size() - 1;

    while (left < right) { // продолжаем поиск, пока left не пересечет right
        int mid = left + (right - left) / 2; // находим середину

        if (target <= bin_reach_arr[mid]) {
            // если целевое значение меньше или равно среднему элементу,
            // сужаем поиск до левой половины (включая середину)
            right = mid;
        } else {
            // иначе, сужаем поиск до правой половины (исключая середину)
            left = mid + 1;
        }
    }

    // после выхода из цикла left будет указывать на позицию для вставки
    if (bin_reach_arr[left] == target) {
        return left; // возвращаем индекс найденного элемента
    }

    return left; // если элемент не найден, возвращаем место, куда он мог бы быть вставлен
}
