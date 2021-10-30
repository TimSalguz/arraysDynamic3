//3. Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
//Найти строку, сумма элементов которой наиболее близка к 0,
//и заменить все элементы этой строки числом 0.
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int W = 0;
    int H = 1;
    int min = INT_MAX;
    int nomstroki;
    int a;
    std::ifstream in("input.txt");
    std::string s;
    if (!in)
        std::cout << "Error" << std::endl;
    for (W = 0; !in.eof(); W++)
        std::getline(in, s);
    for (int i = 0; i<s.length(); i++)
        if(s[i] == ' ')
            H++;
    std::cout << "W = " << W << std::endl;
    std::cout << "H = " << H << std::endl;
    int** matrix = new int*[W];
    for(int i = 0; i<W; i++)
        matrix[i] = new int[H];

    std::cout << "Created matrix" << std::endl;
    in.close();
    std::cout << "Closed file" << std::endl;
    in.open("input.txt");
    std::cout << "Opened file" << std::endl;

    for (int i = 0; i < W; ++i)
    {
        std::cout << "i = " << i << std::endl;
        for (int j = 0; j < H; ++j)
        {
            std::cout << "j = " << j << std::endl;
            in >> matrix[i][j];
        }
    }

    //ВЫВОД
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }


    //Делаю че надо
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            int a = 0;
            //текущий элемент
            for (int j = 0; j < H; j++)
            {
                a += matrix[i][j];
            }
            std::cout << "sum = " << a << std::endl;

            if (a < 0)
            {
                a = -a;
            }
            if (a < min)
            {
                min = a;
                nomstroki = i;
            }
        }
    }
    for (int j = 0; j < H; j++)
    {
        matrix[nomstroki][j] = 0;
    }
    //ВЫВОД
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            std::cout << matrix[i][j] <<" ";
        }
        std::cout<< "\n";
    }
    for (int i = 0; i < W; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}