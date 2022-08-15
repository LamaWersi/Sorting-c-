#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

int massiv[1100];

int main()
{
    Clock ClSleep;
    Time TSleep;
    bool endSorting = false;//false - !end
    bool FlagSleep = true;//true = Sleep
    float FlSleep = 5.0;
    int scatter = 888;
    RenderWindow window(VideoMode(1100, 700), "Sorting");
    RectangleShape rectangle(Vector2f(1, 1));

    std::cout << "Sorting\n";
    while (scatter > 700 || scatter < 1)
    {
        std::cout << "Enter scatter(max 700): "; 
        std::cin >> scatter;
    }
    srand(time(NULL));
    for (int j = 0; j < 1100; j++)
    {
        int a = rand() % scatter + 1;
        massiv[j] = a;
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
       for (int j = 0; j < 1100; j++)
       {
            rectangle.setScale(1, -massiv[j]);
            rectangle.setPosition(Vector2f(j, 699));
            window.draw(rectangle);
       }
       if (FlagSleep == true)
       {
           FlSleep = ClSleep.getElapsedTime().asSeconds();
       }
       if (FlSleep >= 0.001)
       {
           FlagSleep = false;
           ClSleep.restart();
       }
       if (endSorting == false && FlagSleep == false)
       {
           bool Sorting = false;//flag of end
           for (int i = 0; i < 1100; i++)
           {
               if (massiv[i] > massiv[i + 1])
               {
                   int fakeMassiv = massiv[i + 1];
                   massiv[i + 1] = massiv[i];
                   massiv[i] = fakeMassiv;
                   Sorting = true;
               }
           }
           if (Sorting == false)endSorting = true;
           FlagSleep = true;
       }
        window.display();
    }
    return 0;
}