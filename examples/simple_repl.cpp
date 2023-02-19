#include "ezlua.hpp"
#include <string>
#include <iostream>

int main() {
    using namespace std;
    string input;

    LuaVirtualMachine lvm;
    lvm.LoadStdLib();
    while (true) {
        cout << "REPL> ";
        getline(cin, input);
        if (input == ":loadfile") {
            getline(cin, input);
            lvm.ExecuteFile(input.c_str());
        }
        else {
            lvm.Execute(input.c_str());
        }
    }
}
