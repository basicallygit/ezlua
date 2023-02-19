#ifndef EZLUA_HPP
#define EZLUA_HPP

#include "lua.hpp"

class LuaVirtualMachine
{
private:
    lua_State *L;

    void PrintLastError();

public:
    LuaVirtualMachine();

    void LoadStdLib();

    bool Execute(const char* code);

    float GetNumber(const char* identifier);

    bool ExecuteFile(const char* filename);

    ~LuaVirtualMachine();
};

#endif // EZLUA_HPP
