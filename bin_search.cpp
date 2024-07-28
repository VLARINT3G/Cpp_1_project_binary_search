#include <iostream>
#include <vector>
#include <algorithm> // для std::sort
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time

// Функция для создания вектора случайных чисел заданной длины
std::vector<int> createRandomVector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() % 100; // случайные числа в диапазоне от 0 до 99
    }
    return vec;
}

// Функция бинарного поиска
int bin_reach(const std::vector<int>& bin_reach_arr, int target) {
    int left = 0;
    int right = bin_reach_arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target == bin_reach_arr[mid]) {
            return mid; // Возвращаем индекс найденного элемента
        }
        if (target > bin_reach_arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Элемент не найден
}

int main() {
    std::srand(std::time(0)); // инициализация генератора случайных чисел

    int n = 10; // длина вектора
    std::vector<int> main_arr = createRandomVector(n);

    // Вывод случайного вектора длиной 10
    std::cout << "Original vector: ";
    for (int i = 0; i < main_arr.size(); ++i) {
        std::cout << main_arr[i] << " ";
    }
    std::cout << std::endl;

    // Сортировка вектора
    std::sort(main_arr.begin(), main_arr.end());

    // Печать отсортированного вектора
    std::cout << "Sorted vector: ";
    for (int i = 0; i < main_arr.size(); ++i) {
        std::cout << main_arr[i] << " ";
    }
    std::cout << std::endl;

    // Значение для поиска
    int user_target;
    std::cout << "Type down a digit for search: ";
    std::cin >> user_target;

    // Вызов функции бинарного поиска
    int result = bin_reach(main_arr, user_target);

    if (result != -1) {
        std::cout << "Your element is in " << result << " place" << std::endl;
    } else {
        std::cout << "Your element is not foud" << std::endl;
    }

    return 0;
}


// Использование и std::upper_bound для поиска элемента - старая версия кода  !!!!!!!!!!!!!!
    // auto lower = std::lower_bound(arr.begin(), arr.end(), target);

    // if (lower != arr.end() && *lower == target) {
    //     std::cout << "Элемент " << target << " найден в массиве на позиции " 
    //               << (lower - arr.begin() + 1) << std::endl;
    // } else {
    //     std::cout << "Элемент " << target << " не найден в массиве." << std::endl;
    //     std::cout << "Число может быть вставлено на позицию " << (lower - arr.begin() + 1) << "элемента" << std::endl;
    // }
