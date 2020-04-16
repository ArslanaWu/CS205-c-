#include <iostream>
#include <string>
#include <algorithm>

#define START_CMD 0
#define STOP_CMD 1
#define RESTART_CMD 2
#define STATUS_CMD 3
#define RELOAD_CMD 4
#define EXIT_CMD 5
#define EMPTY 6

using namespace std;

int main()
{
    string commands[6] = {"start", "stop", "restart", "status", "reload", "exit"};
    string command;
    int com = -1;

    cout << ">";
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    string::size_type idx = command.find("exit");

    while (idx == string::npos)
    {
        command.erase(0, command.find_first_not_of(" "));
        command.erase(command.find_last_not_of(" ") + 1);

        while (command.empty())
        {
            cout << ">";
            getline(cin, command);
            
            command.erase(0, command.find_first_not_of(" "));
            command.erase(command.find_last_not_of(" ") + 1);
        }

        for (int i = 0; i < 7; i++)
        {
            if (command == commands[i])
            {
                com = i;
            }
        }

        switch (com)
        {
        case START_CMD:
            cout << "command start recognized";
            break;

        case STOP_CMD:
            cout << "command stop recognized";
            break;

        case RESTART_CMD:
            cout << "command restart recognized";
            break;

        case STATUS_CMD:
            cout << "command status recognized";
            break;

        case RELOAD_CMD:
            cout << "command reload recognized";
            break;

        case EXIT_CMD:
            return 1;
            break;

        default:
            cout << "Invalid command";
            break;
        }

        cout << "\n>";
        getline(cin, command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        idx = command.find("exit");
        com = -1;
    }
}
