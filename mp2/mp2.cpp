/*
 *  This program here is a simulator of the Lion, Rabbit,
 *  and Carrot Problem.
 *
 */

#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

/*
 *  This function resets the state and locations
 *  of the Lion, Rabbit, and Carrot.
 */
void resetValues(bool left[3], bool right[3]) {
    for(int i = 0; i < 3; i++) {
        left[i] = true;
        right[i] = false;
    }
}

/*
 *  This function is used as a test function to print
 *  the state of the Lion, Rabbit and Carrot.
 */
void printState(bool left[3], bool right[3]) {

    for(int i = 0; i < 3; i++) {
        if(left[i])
            std::cout << "1";
        else
            std::cout << "-";
    }
    for(int i = 0; i < 3; i++) {
        if(right[i])
            std::cout << "1";
        else
            std::cout << "-";
    }
    std::cout << std::endl;
}

/*
 *  This function here reads every line in the file and stores them
 *  in a vector or strings.
 *  Returns a vector of string.
 */
std::vector<std::string> getCommands(FILE *fp) {
    std::vector<std::string> commands;
    commands.push_back("");

    char ch;
    ch = getc(fp);
    int ctr = 0;

    while(ch != EOF) {
        if(ch == '\n') {
            commands.push_back("");
            ctr++;
        }
        else
            commands.at(ctr).push_back(ch);
        ch = getc(fp);
    }
    return commands;
}

/*
 *  This function processes the commands and if valid
 *  and not a bad move, executes them and returns
 *  True and if not then returns False.
 */
bool commands(char cmd, bool from[3], bool to[3]) {
    if((cmd == 'L' || cmd == 'l' ) && from[0] == true) {
        from[0] = false;
        to[0] = true;
    }
    else if((cmd == 'R' || cmd == 'r') && from[1] == true) {
        from[1] = false;
        to[1] = true;
    }
    else if((cmd == 'C' || cmd == 'c') && from[2] == true) {
        from[2] = false;
        to[2] = true;
    }
    else if(cmd == 'n' || cmd == 'N'){
        //do nothing
    }
    else {
        return false;       //invalid command or invalid move
    }
    return true;
}

/*
 *  This function evaluates whether to do the command
 *  left to right or right to left and executes the
 *  entire command.
 *  Returns true if and only if the Lion, Rabbit,
 *  and Carrot is on the other side of the river after
 *  executing the command and false if it is a bad move.
 */
bool doCommand(std::string command, bool left[3], bool right[3]) {
    for(int i = 0; i < command.size(); i++) {
        char cmd = command.at(i);

        if(command.size() <= 0)
            return false;

        if(i % 2 == 0) {
            //do operation on left to right
            if(!commands(cmd, left, right))
                return false;

            if((left[0] && left[1]) || (left[1] && left[2]))
                return false;
        }
        else {
            //do operation right to left
            if(!commands(cmd, right, left))
                return false;

           if((right[0] && right[1]) || (right[1] && right[2]))
                return false;
        }
    }

    if(right[0] && right[1] && right[2])
        return true;        //true since everything is on the other side of the river.

    return false;
}

int main() {
    bool left[3], right[3];
    FILE *fp = fopen("mp2.in","r");
    std::ofstream file;
    file.open("mp2.out");
    std::vector<std::string> commands = getCommands(fp);

    for(int i = 0; i < commands.size()-1; i++) {    //till size-1 since last line is always an empty string
        file << i+1 << " - ";                       //print which line is it on

        resetValues(left, right);
        if(doCommand(commands.at(i), left, right)) {
            file << "OK";
        }
        else {
            file << "Nope";
        }
        file << std::endl;
    }
    file.close();
    return 0;
}
