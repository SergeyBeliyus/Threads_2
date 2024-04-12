#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>

void sum(int number) {
    std::vector<int> v1(number);
    std::vector<int> v2(number);
    std::transform(v1.begin(), v1.end(), v2.begin(), v2.begin(), std::plus<int>());
}

void threading(int numberThreads, int vectorNumber) {
    auto start = std::chrono::steady_clock::now();
    if (numberThreads == 2)
    {
        std::thread t1(sum, vectorNumber);
        std::thread t2(sum, vectorNumber);
        t1.join();
        t2.join();
    }
    else if (numberThreads == 4) {
        std::thread t1(sum, vectorNumber);
        std::thread t2(sum, vectorNumber);
        std::thread t3(sum, vectorNumber);
        std::thread t4(sum, vectorNumber);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }
    else if (numberThreads == 8) {
        std::thread t1(sum, vectorNumber);
        std::thread t2(sum, vectorNumber);
        std::thread t3(sum, vectorNumber);
        std::thread t4(sum, vectorNumber);
        std::thread t5(sum, vectorNumber);
        std::thread t6(sum, vectorNumber);
        std::thread t7(sum, vectorNumber);
        std::thread t8(sum, vectorNumber);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
    }
    else if (numberThreads == 16) {
        std::thread t1(sum, vectorNumber);
        std::thread t2(sum, vectorNumber);
        std::thread t3(sum, vectorNumber);
        std::thread t4(sum, vectorNumber);
        std::thread t5(sum, vectorNumber);
        std::thread t6(sum, vectorNumber);
        std::thread t7(sum, vectorNumber);
        std::thread t8(sum, vectorNumber);
        std::thread t9(sum, vectorNumber);
        std::thread t10(sum, vectorNumber);
        std::thread t11(sum, vectorNumber);
        std::thread t12(sum, vectorNumber);
        std::thread t13(sum, vectorNumber);
        std::thread t14(sum, vectorNumber);
        std::thread t15(sum, vectorNumber);
        std::thread t16(sum, vectorNumber);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
        t9.join();
        t10.join();
        t11.join();
        t12.join();
        t13.join();
        t14.join();
        t15.join();
        t16.join();
    }
    else {
        std::thread t1(sum, vectorNumber);
        t1.join();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << elapsed_seconds.count() << "        ";
}

int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "Количество аппаратных ядер - "<< n <<"\n\n";

    std::cout << "               " << 1000 << "            " << 10000 << "            " << 100000 << "            " << 1000000 << "\n";

    //Запуск одного потока программы
    std::cout << "1 потоков   ";
    threading(1, 1000);
    threading(1, 10000);
    threading(1, 100000);
    threading(1, 1000000);
    std::cout << "\n";

    std::cout << "2 потоков   ";
    threading(2, 1000);
    threading(2, 10000);
    threading(2, 100000);
    threading(2, 1000000);
    std::cout << "\n";

    std::cout << "4 потоков   ";
    threading(4, 1000);
    threading(4, 10000);
    threading(4, 100000);
    threading(4, 1000000);
    std::cout << "\n";

    std::cout << "8 потоков   ";
    threading(8, 1000);
    threading(8, 10000);
    threading(8, 100000);
    threading(8, 1000000);
    std::cout << "\n";

    std::cout << "16 потоков   ";
    threading(16, 1000);
    threading(16, 10000);
    threading(16, 100000);
    threading(16, 1000000);
    std::cout << "\n";
}