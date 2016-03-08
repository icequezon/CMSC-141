#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>

void resetValues(bool left[3], bool right[3]) {
    for(int i = 0; i < 3; i++) {
        left[i] = true;
        right[i] = false;
    }
}

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

    }
    else {
        return false;
    }
    return true;
}

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
        return true;

    return false;
}

int main() {
    bool left[3], right[3];
    FILE *fp = fopen("mp2.in","r");
    std::ofstream file;
    file.open("mp2.out");
    std::vector<std::string> commands = getCommands(fp);
    for(int i = 0; i < commands.size(); i++) {
        file << i << " - ";

        resetValues(left, right);
        if(doCommand(commands.at(i), left, right)) {
            //std::cout << "OK";
            file << "OK:" << commands.at(i);
        }
        else {
            //std::cout << "Nope";
            file << "Nope";
        }
        file << std::endl;
        //std::cout << std::endl;
    }
    file.close();
    return 0;
}
