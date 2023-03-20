#include "CommandProcessor.h"

#include <iostream>
#include <string>


int main(int argc, char* argv[]) {

    if (argc == 2 && std::string(argv[1]) == "-console") {
        // Use the console-based CommandProcessor
        CommandProcessor cp;
        while (true) {
            Command cmd = cp.getCommand();
            // Validate the command and execute it
            cp.validate(cmd);
            //cmd.saveEffect("Command executed successfully.");
            //std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            return 0;
        }
    } else if (argc == 3 && std::string(argv[1]) == "-file") {
         // Create a new instance of the adapter and pass in the name of the command file
    FileCommandProcessorAdapter adapter("commands.txt");

    //Process all commands from the file
    adapter.processCommands();

    return 0;
        }
     else {
        std::cerr << "Usage: " << argv[0] << " -console | -file <filename>" << std::endl;
        return 1;
    }
}
