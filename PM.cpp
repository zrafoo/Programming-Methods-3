PM.cpp
/*
* @file main.cpp
* @brief main-файл
*/
#include <iostream>
#include "lect.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "sortings.h"
#include <chrono>
#include "finds.h"
#include "hash.h"
#include <map>
#include <iterator>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int data_size = 100000; // Количество строк, изменять здесь!
    std::vector<lect> data(data_size);
    int i = 0;

    std::ifstream file("Array.txt");

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            if (i >= data_size) break;
            std::string l_name1, l_name2, l_name3, l_fac, l_degree, l_title1, l_title2;
            std::istringstream iss(line);
            iss >> l_name1 >> l_name2 >> l_name3 >> l_fac >> l_degree >> l_title1 >> l_title2;
            std::string l_name = l_name1 + " " + l_name2 + " " + l_name3;
            std::string l_title = l_title1 + " " + l_title2;
            data[i].setData(l_name, l_fac, l_degree, l_title);
            i++;
        }
    }
    else { std::cout << "не удалось открыть файл Array.txt"; }
    file.close();

    ht_item A;
    HashTable T;
    T.set_Size(data_size);
    for (int i = 0; i < data_size;i++)
    {
        T.add_item(data[i].hash, data[i].name);
    }
    T.ht_col.erase(T.ht_col.begin());
    
    int hash = 1951;
    std::cout << "Поиск по хешу " << hash << " в хеш-таблице." << '\n';
    auto start = chrono::steady_clock::now();
    std::cout<<'\n'<<"Результат - "<<findh(hash,T)<<'\n';
    auto end = chrono::steady_clock::now();
    cout << "Размер - " << data_size << '\n' << "Затраченное время в микросекундах : "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << '\n' << '\n';
    int collisions = 0;
    for (int i = 0; i < T.ht_col.size(); i++)
    {
        collisions += T.ht_col[i].count;
    }
    std::cout << "(easy)Коллизий: " << collisions << ".\n";
    return 0;
}
