#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

void aoc5_part1()
{
    std::ifstream input("aoc5_data.txt");

    if (input.fail())
    {
        exit(1);
    }

    std::string data;
    std::getline(input, data);

    input.close();

    for (int i = 0; i < data.size() - 1; ++i)
    {
        bool upperLowerTest = (data[i] == static_cast<char>(std::toupper(data[i + 1]))) && std::islower(data[i + 1]);
        bool lowerUpperTest = (data[i] == static_cast<char>(std::tolower(data[i + 1]))) && std::isupper(data[i + 1]);

        if (upperLowerTest || lowerUpperTest)
        {
            data.erase(i, 2);
            i = -1;
        }
    }

    std::cout << "Part 1 result: " << data.size() << std::endl;

    return;
}

void aoc5_part2()
{
    std::ifstream input("aoc5_data.txt");

    if (input.fail())
    {
        exit(1);
    }

    std::string data;
    std::getline(input, data);

    input.close();

    int count[26] = {0};

    for (int l = 0; l < 26; ++l)
    {
        std::string dataCopy = data;

        // removing selected character
        for (int i = 0; i < dataCopy.size(); ++i)
        {
            if (dataCopy[i] == static_cast<char>(l + 65) || dataCopy[i] == static_cast<char>(l + 97))
            {
                dataCopy.erase(i, 1);
                i = -1;
            }
        }

        for (int i = 0; i < dataCopy.size() - 1; ++i)
        {
            bool upperLowerTest = (dataCopy[i] == static_cast<char>(std::toupper(dataCopy[i + 1]))) && std::islower(dataCopy[i + 1]);
            bool lowerUpperTest = (dataCopy[i] == static_cast<char>(std::tolower(dataCopy[i + 1]))) && std::isupper(dataCopy[i + 1]);

            if (upperLowerTest || lowerUpperTest)
            {
                dataCopy.erase(i, 2);
                i = -1;
            }
        }

        count[l] = dataCopy.size();
    }

    int min = count[0];

    for (const auto& n : count)
    {
        if (n < min)
        {
            min = n;
        }
    }

    std::cout << "Part 2 result: " << min << std::endl;

    return;
}

int main()
{
    aoc5_part1();
    aoc5_part2();

    return 0;
}