#include "Word_Reader.h"
#include <fstream>
#include <iostream>
#include <random>

std::map<std::string, int> Word_Reader::Word_Map = {};

void Word_Reader::Read_Words(bool random_Index)
{
    std::fstream file;
    std::string word, t, q, filename;

    filename = "Words.txt";

    file.open(filename.c_str());

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(10000, 60000); // distribution in range [1, 6]

    while (file >> word)
    {
        int index = 0;
        if (random_Index == true)
        {
            index = 1000000 + dist(rng);
        }
        
        Word_Map.emplace(std::make_pair(word, index));

        if (random_Index == false)
        {
            index++;
        }
    }
}

void Word_Reader::Print_Words()
{
    for (const auto& element : Word_Map)
    {
        std::cout << element.first << " " << element.second << "\n";
    }
}