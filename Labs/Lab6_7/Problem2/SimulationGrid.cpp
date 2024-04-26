#include "SimulationGrid.h"
#include"Empty.h"
#include"Plant.h"
#include"Fox.h"
#include"Gopher.h"

#include<string>
#include<iostream>
#include<ostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<random>

SimulationGrid::SimulationGrid(): rows{0}, cols{0}
{}

SimulationGrid::SimulationGrid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::default_random_engine generator(std::rand());
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            int number = std::rand() % 10;
            if (number == 0)
                this->grid[i][j] = new Plant(i, j);
            else if (number == 1)
                this->grid[i][j] = new Fox(i, j, 0);
            else if (number == 2)
                this->grid[i][j] = new Gopher(i, j, 0);
            else
                this->grid[i][j] = new Empty(i, j);
        }
    }
}

SimulationGrid::SimulationGrid(const SimulationGrid& other)
{
    this->rows = other.rows;
    this->cols = other.cols;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->grid[i][j] = other.grid[i][j];
        }
    }
}

SimulationGrid::SimulationGrid(const std::string file)
{
    std::ifstream F(file);
    if (!F.is_open())
    {
        throw std::runtime_error("The file could not be open");
    }

    F >> *this;

    
}

SimulationGrid& SimulationGrid::operator=(const SimulationGrid& other)
{
    if (this != &other)
    {
 
        this->rows = other.rows;
        this->cols = other.cols;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->grid[i][j] = other.grid[i][j];
            }
        }
    }
    return *this;
}

SimulationGrid::~SimulationGrid()
{
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
        {
            delete grid[i][j];
        }
}

SimulationGrid* SimulationGrid::updateGrid()
{
    SimulationGrid *next = new SimulationGrid(*this);
    for (int i = 0; i < next->rows; i++)
    {
        for (int j = 0; j < next->cols; j++)
        {
            next->grid[i][j] = this->grid[i][j]->next(*this);
        }
    }
    return next;
}

Entity* SimulationGrid::getCell(int row, int column) const
{
    return this->grid[row][column];
}

void SimulationGrid::setEntity(int row, int col, Entity* entity)
{
    if (row >= 0 && row < this->rows)
    {
        if (col >= 0 && col < this->cols)
            grid[row][col] = entity;
    }
}

std::string SimulationGrid::toString() const
{
    std::string a = "";
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            a = a + grid[i][j]->toString() + " ";
        }
        a = a + "\n";
    }
    return a;

}

Entity* SimulationGrid::createEntity(std::string s)
{
    if (s.size() == 1)
    {
        if (s == "P" || s == "p")
        {
            return new Plant();
        }
        else if (s == "E" || s == "e")
        {
            return new Empty();
        }
    }
    else if (s.size() >= 2)
    {
        char c = s[0];
        int age = s[1] - '0';
        if (c == 'F' || c == 'f')
        {
            return new Fox(0, 0, age);
        }
        else if (c == 'G' || c == 'g')
        {
            return new Gopher(0, 0, age);
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const SimulationGrid& other)
{
    os << other.toString();
    return os;
}

std::istream& operator>>(std::istream& is, SimulationGrid& other)
{
    is >> other.rows >> other.cols;
    for (int i = 0; i < other.rows; i++)
    {
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
        std::string word;
        for (int j = 0; j < other.cols; j++)
        {
            std::getline(iss, word, ' ');
            other.grid[i][j] = other.createEntity(word);
            
        }
    }
    return is;
}
