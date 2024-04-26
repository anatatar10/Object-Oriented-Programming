
#include <iostream>
#include<ostream>
#include"EmptyTest.h"
#include"PlantTest.h"
#include"FoxTest.h"
#include"GopherTest.h"
#include"SimulationGridTest.h"
#include"Simulation.h"
#include"SimulationTest.h"
#include<vector>

void polymorphicVector()
{
    Plant p1{ 1,1 };
    Entity* p2{ new Plant(2,3) };

    Fox f1{ 0,1,2 };
    Animal* f2{ new Fox{1,2,1} };
    Entity* f3{ new Fox{2,2,2} };

    Gopher g1{ 3,3,3 };
    Animal* g2{ new Gopher{3,4,2} };
    Entity* g3{ new Gopher{2,4,0} };

    Empty e1{ 4,0 };
    Entity* e2{ new Empty{4,1} };
    std::cout << "Vector with 10 entities:" << std::endl;
    Entity* entities[10] = { &p1, p2, &f1, f2, f3, &g1, g2, g3, &e1, e2 };

    for (int i = 0; i < 10; i++)
    {
        std::cout << entities[i]->toString() << " at ("<<entities[i]->getRow()<<"," << entities[i]->getCol()<<")"<< std::endl;
    }
    std::cout << std::endl;
};



int main()
{
    EmptyTest::runAllTests();
    PlantTest::runAllTests();
    FoxTest::runAllTests();
    GopherTest::runAllTests();
    SimulationGridTest::runAllTests();
    SimulationTest::runAllTests();
    Simulation s = Simulation();
    s.run();
    std::cout << "\n";
    polymorphicVector();
    return 0;
}
