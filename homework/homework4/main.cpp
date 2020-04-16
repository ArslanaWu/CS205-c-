#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "utf8.h"


using namespace std;

const int SIZE = 300;

struct Block
{
    unsigned int code_start;
    unsigned int code_end;
    string block;
};

Block *blocks = new Block[SIZE];

void Create_struct(int i, string &line)
{
    int position[2]; //position of "." and ";"
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '.')
        {
            position[0] = i;
            break;
        }
    }
    //find position of "."
    for (int i = position[0]; i < line.length(); i++)
    {
        if (line[i] == ';')
        {
            position[1] = i + 1;
            break;
        }
    }
    //find position of ";"

    string start = line.substr(0, position[0]);
    line.erase(0, position[0] + 2);
    unsigned int start_dec = std::stoi(start, nullptr, 16);

    int length_of_end = position[1] - position[0] - 3;
    string end = line.substr(0, length_of_end);
    unsigned int end_dec = std::stoi(end, nullptr, 16);
    line.erase(0, length_of_end + 2);

    blocks[i].code_start = start_dec;
    blocks[i].code_end = end_dec;
    blocks[i].block = line;
}

int search(unsigned int codepoint)
{
    for (int i = 0; i < SIZE; i++)
    {
        unsigned int code_start = blocks[i].code_start;
        unsigned int code_end = blocks[i].code_end;

        if (codepoint <= code_end && codepoint >= code_start)
        {
            return i;
        }
    }
}

int main()
{
    ifstream inFile;
    inFile.open("Blocks.txt");

    if (!inFile.is_open())
    {
        cout << "Could not open the file, program terminate.\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++)
    {
        string line;
        getline(inFile, line);
        if (line == "# EOF")
        {
            break;
        }
        if(line[0] == '#' || line[0] == '\r' || line[0] == '\n' || line.empty())
        {
            i--;
            continue;
        }
        Create_struct(i, line);
    }
    //fill array

    vector<int> found;
    unsigned char input[SIZE];

    unsigned int codepoint;
    unsigned char *p;
    int bytes_in_char;

    while (true) //
    {
        cin >> input;
        if (cin.eof())
        {
            break;
        }

        p = (unsigned char *)input;
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        //utf8 to codepoint

        int i_of_blocks = search(codepoint);
        found.push_back(i_of_blocks);
        //store position of matched blocks
    }
    //sort(found.begin(), found.end());
    //found.erase(unique(found.begin(), found.end()), found.end());

    int times[found.size()] = {0};
    for (int i = 0; i < found.size(); i++)
    {
        for (int j = 0; j < found.size(); j++)
        {
            if (found[i] == found[j])
            {
                times[i]++;
            }
        }
    }
    //calculate number of occurrences

    int max = 0;
    for (int i = 1; i < found.size(); i++)
    {
        if (times[max] < times[i])
        {
            max = i;
        }
    }
    //find the one that appears the most

    cout << blocks[found[max]].block;
}