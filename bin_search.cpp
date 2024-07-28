#include <iostream>
#include <vector>
#include <algorithm> // для std::sort, std::lower_bound и std::upper_bound
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time

// Функция для создания вектора случайных чисел заданной длины
std::vector<int> createRandomVector(int n) {
    std::srand(std::time(0)); // инициализация генератора случайных чисел

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() % 100; // случайные числа в диапазоне от 0 до 99
    }
    return vec;
}

int main() {

    int n = 10; // длина вектора
    std::vector<int> arr = createRandomVector(n);
    
    //Вывод случайного вектора длиной 10
    std::cout << "Искомый вектор: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
        
    // Сортировка вектора
    std::sort(arr.begin(), arr.end());

    // Печать отсортированного вектора
    std::cout << "Отсортированный вектор: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Значение для поиска
    int target = 0;
    std:: cout<< "Введите число для поиска" << std::endl;
    std:: cin >> target ;
    	
    // Использование и std::upper_bound для поиска элемента
    auto lower = std::lower_bound(arr.begin(), arr.end(), target);

    if (lower != arr.end() && *lower == target) {
        std::cout << "Элемент " << target << " найден в массиве на позиции " 
                  << (lower - arr.begin() + 1) << std::endl;
    } else {
        std::cout << "Элемент " << target << " не найден в массиве." << std::endl;
        std::cout << "Число может быть вставлено на позицию " << (lower - arr.begin() + 1) << "элемента" << std::endl;
    }

    return 0;
}