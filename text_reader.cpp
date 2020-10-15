#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

int main(int argc, char *argv[]) 
{
    std::string filename ;
    if(argc == 1)
    {
        std::cout << "Enter file name :";
        std::cin >> filename;
    }
    else if(argc == 2)
    {
        filename = argv[1];
    }
    else
    {
        std::cout << "Invalid Arguments...\nExiting";
        return 0;
    }
    std::ifstream inputfile(filename);
    if(inputfile.fail())
    {
        std::cout << "Failed to open file...\nExiting";
        return 0;
    }
    std::vector<std::string> lines;
    lines.push_back("^");
    while(inputfile.good())
    {
        std::string temp;
        std::getline(inputfile,temp);
        lines.push_back(temp);
    }
    inputfile.close();

    // lines is a vector that contains every single line in the text file as an element 
    // with an extra line for the cursor
    std::swap(lines[0] , lines[1]);     //put the cursor under the first line
    char keypressed = 0;
    int row=0 , col=0;
    while(keypressed != 'e')
    {
        if(keypressed == 'w')
        {
            if(row > 0)
            {
                if(lines[row-1].length()!=0 && col >= lines[row-1].length())
                {
                    col=lines[row-1].length()-1;
                    lines[row+1]=std::string(col-1,' ')+"^";
                }
                std::swap(lines[row],lines[row+1]);
                row--;
            }
        }
        else if(keypressed == 's')
        {
            if(row < lines.size()-1)
            {
                if(lines[row+2].length()!=0 && col >= lines[row+2].length())
                {
                    col=lines[row+2].length()-1;
                    lines[row+1]=std::string(col-1,' ')+"^";
                }
                std::swap(lines[row+2],lines[row+1]);
                row++;
            }
        }
        else if(keypressed == 'a')
        {
            if(col > 0)
            {
                col--;
                lines[row+1]=lines[row+1].substr(1);
            }
            else
            {
                col=lines[row-1].length();
                if(col!=0)
                {
                    col--;
                }
                lines[row+1]=std::string(col-1,' ')+"^";
                std::swap(lines[row],lines[row+1]);
                row--;
            }
        }
        else if(keypressed == 'd')
        {
            if(col < lines[row].length()-1)
            {
                col++;
                lines[row+1]=" "+lines[row+1];
            }
            else
            {
                col=0;
                lines[row+1]="^";
                std::swap(lines[row+2],lines[row+1]);
                row++;
            }
        }
        system("cls");
        for(auto it =lines.begin(); it != lines.end(); it++)
        {
            std::cout<< *it<<std::endl;
        }
        keypressed = getch();
    }

    return 0;
}