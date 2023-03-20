#include "GameEngine.h"
#include "CommandProcessor.h"
#include "Player.h"
#include "LoggingObserver.h"

int main()
{
    std::string value;
    std::cout << "Do you want to enter the Game Engine?";
    std::cin >> value;
    if (value.compare("yes") == 0)
    {
        std::cout << "WELCOME TO THE GAME ENGINE" << std::endl;

        GameEngine *gameEngine = new GameEngine();
        gameEngine->startUpPhase(); // Starts the Game engine
        return 0;
    }

    std::cout << "Do you want to enter Orders?";
    std::cin >> value;
    if (value.compare("yes") == 0)
    {
        std::cout << "WELCOME TO ORDERS" << std::endl;
      
        Player *p1 = new Player("John");
      
        p1->issueOrder("deploy");
        p1->issueOrder("negotiate");
        p1->issueOrder("blockade");
        p1->issueOrder("bomb");
        p1->issueOrder("airlift");
        p1->issueOrder("advance");
      
        return 0;
    }

    std::cout << "Do you want to enter the Command Processor?";
    std::cin >> value;
    if (value.compare("yes") == 0)
    {
        std::cout << "WELCOME TO THE COMMAND PROCESSOR" << std::endl;
        while (true)
        {
            string word;
            std::cout << "Commands are:\n"
                         "1) console\n"
                         "2) file   \n"
                         "3) quit   \n";
            std::cout << "Choose your command : ";
            std::cin >> word;

            if (word == "console")
            {
                CommandProcessor object;
                Command cmd = object.getCommand();
                object.validate(cmd);
                std::cout << "Command Effect: " << cmd.effectString << std::endl;
            }
            else if (word == "file")
            {
                FileCommandProcessorAdapter obj("gamelog.txt");
                Command cmd = obj.getCommand();
                obj.validate(cmd);
                std::cout << "Command Effect: " << cmd.effectString << std::endl;
            }
            else if (word == "quit")
            {
                break;
            }
            else
            {
                std::cout << "Please try again." << std::endl
                          << std::endl;
            }
        }
        return 0;
    }
}
