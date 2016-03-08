#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

/*
 *  This function here reads every line in the file and stores them
 *  in a vector or strings.
 *  Returns a vector of string.
 *
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
        commands.at(ctr).push_back(ch);
        ch = getc(fp);
    }

    return commands;
}

/*
 *  This function populates the registers as how it is shown
 *  in the string given by the user.
 *
 */
void populateRegisters(std::string state, int registers[10]) {
    char temp[10];
    int ctr = 0, rctr = 0;

    for(int j = 0; j < 10; j++) {
        temp[j] = ' ';      //clear temp of garbage values
    }

    for(int i = 0; i < state.size(); i++) {
        if(state.at(i) == ' ' || i == state.size()-1) {
            std::cout << temp;
            registers[rctr] = atoi(temp);   //store converted string to integer in register
            rctr++;
            ctr = 0;

            for(int j = 0; j < 10; j++) {
                temp[j] = ' ';      //clean temp
            }
        }

        temp[ctr] = state.at(i);
        ctr++;
    }

}

/*
 *  This function evaluates the command given by the user and
 *  executes the command if and only if the command is valid.
 *
 */
void evalCommands(std::vector<std::string> commands, int registers[10]) {
    std::ofstream file;
    file.open("mp1.out", std::ios_base::app);

    for(int i = 1; i < commands.size(); i++) {
        std::string temp = commands.at(i);

        if(temp.size() <= 1)
            continue;

        if(temp.at(1) == 'j' || temp.at(1) == 'J') {    //this is for the Jump Command
            char cIndex1[10], cIndex2[10], cIndex3[10];

            for(int j = 0; j < 10; j++) {
                cIndex1[j] = ' ';       //clear cIndex1
                cIndex2[j] = ' ';       //clear cIndex2
                cIndex3[j] = ' ';       //clear cIndex3
            }
            //code below gets the indexes in the string
            bool space = false, space2 = false;
            int ctr = 3, ctr2 = 0;
            while(ctr < temp.size()) {
                if(temp.at(ctr) == ' ') {
                    ctr2 = 0;
                    if(space)
                        space2 = true;
                    else
                        space = true;
                }
                if(space2) {
                    cIndex3[ctr2] = temp.at(ctr);
                }
                else if(space) {
                    cIndex2[ctr2] = temp.at(ctr);
                }
                else {
                    cIndex1[ctr2] = temp.at(ctr);
                }
                ctr++;
                ctr2++;
            }
            int index1, index2, index3;
            index1 = atoi(cIndex1);
            index2 = atoi(cIndex2);
            index3 = atoi(cIndex3);
            if(registers[index1] == registers[index2]) {
                i = index3 - 1;
            }
        }
        else if(temp.at(1) == 'c' || temp.at(1) == 'C') {   //this is for the copy command
            char cIndex1[10], cIndex2[10];
            //clear cIndex
            for(int j = 0; j < 10; j++) {
                cIndex1[j] = ' ';
                cIndex2[j] = ' ';
            }
            //code below gets the indexes in the string
            bool space = false;
            int ctr = 3, ctr2 = 0;
            while(ctr < temp.size()) {
                if(temp.at(ctr) == ' ') {
                    ctr2 = 0;
                    space = true;
                }
                if(space) {
                    cIndex2[ctr2] = temp.at(ctr);
                }
                else {
                    cIndex1[ctr2] = temp.at(ctr);
                }
                ctr++;
                ctr2++;
            }
            int index1, index2;
            index1 = atoi(cIndex1);     //convert to int
            index2 = atoi(cIndex2);     //convert to int
            registers[index2] = registers[index1];
        }
        else {
            char cIndex[10];
            //clear cIndex
            for(int j = 0; j < 10; j++) {
                cIndex[j] = ' ';
            }
            //code below gets the index in the string
            for(int j = 2; j < temp.size(); j++) {
                cIndex[j-1] = temp.at(j);
            }

            int index = atoi(cIndex);
            if(temp.at(1) == 'z' || temp.at(1) == 'Z') {    //this is for the Zero command
                registers[index] = 0;
            }
            if(temp.at(1) == 's' || temp.at(1) == 'S') {    //this is for the Increment command
                registers[index]++;
            }
        }

        std::cout << std::endl;
        file << std::endl;

        for(int z = 0; z < 10; z++) {
            file << registers[z] << "\t";                   //print to file
            std::cout << registers[z] << "\t";              //echo to command line
        }
    }
    file.close();
}

int main() {
    FILE *fp = fopen("mp1.in","r");
    std::ofstream file;
    int registers[10];

    std::vector<std::string> commands;
    commands = getCommands(fp);
    fclose(fp);
    populateRegisters(commands.at(0), registers);
    file.open("mp1.out");

    for(int i = 0; i < 10; i++) {
        file << registers[i] << "\t";
        std::cout << registers[i] << "\t";
    }
    file.close();
    evalCommands(commands, registers);

}


