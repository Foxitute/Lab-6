#include "Point.h"
#include "WorkWithFiles.h"

int make_choice()
{
    int choice;
    std::cout << "Select an option:"  << std::endl
              << "0.Quit the program" << std::endl
              << "1.Save in File."    << std::endl
              << "2.Read from file"   << std::endl
              << "3.Empty Container"  << std::endl
            << std::endl << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    setlocale(LC_ALL, "ru-RU");
    
    std::vector<Point> pointsVec;
    std::string PATH = "poits.txt";
    int choice = make_choice();

    while (choice != 0)
    {   
        try
        {
            if (choice == 1)
            {
                save_points(PATH, pointsVec);
            }
            else if (choice == 2)
            {
                read_points(PATH, pointsVec);
            }
            else if (choice == 3)
            {
                pointsVec.clear();
            }
            else
            {
                std::cout << "NO SUCH INPUT PREDICATED" << std::endl << std::endl;
            }
            choice = make_choice();
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
            choice = 0;
        }    
    }

    std::cin.ignore();
    return 0;
}