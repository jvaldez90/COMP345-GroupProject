#include "CommandProcessor.cpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

    if (argc == 2 && std::string(argv[1]) == "-console")
    {
        // Use the console-based CommandProcessor
        CommandProcessor cp;
        while (true)
        {
            Command cmd = cp.getCommand();
            // Validate the command and execute it
            cp.validate(cmd);
            cmd.saveEffect("Command executed successfully.");
            // std::cout << "Effect: " << getEffectString(cmd) << std::endl;
            return 0;
        }
    }
    else if (argc == 3 && std::string(argv[1]) == "-file")
    {
        // Create a new instance of the adapter and pass in the name of the command file
        FileCommandProcessorAdapter adapter("commands.txt");

        // Process all commands from the file
        adapter.processCommands();

        return 0;
    }
    else if (argc == 9 && std::string(argv[1]) == "tournament")
    {
        string mapArg = "";
        string playerArg = "";
        int games = 0;
        int maxTurns = 0;

        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-')
            {
                switch (argv[i][1])
                {
                case 'M':
                    mapArg = argv[i + 1];
                    break;
                case 'P':
                    playerArg = argv[i + 1];
                    break;
                case 'G':
                    games = stoi(argv[i + 1]);
                    break;
                case 'D':
                    maxTurns = stoi(argv[i + 1]);
                    break;
                default:
                    cerr << "Invalid argument." << endl;
                    return 1;
                }
            }

            if (mapArg.empty() || playerArg.empty() || games == 0 || maxTurns == 0)
            {
                cerr << "Invalid arguments." << endl;
                return 1;
            }
        }
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " -console | -file <filename> | tournament -M <listofmapfiles> -P <listofplayerstrategies> -G <numberofgames> -D <maxnumberofturns>" << std::endl;
        return 1;
    }
}
