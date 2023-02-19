#include <iostream>
#include <string>

#include "lua.hpp"

class LuaVirtualMachine
{
private:
    lua_State *L;

    void PrintLastError()
    {
        std::cout << "Error in lua virtual machine:\n" << lua_tostring(L, -1) << std::endl;
    }
public:
    LuaVirtualMachine()
    {
        L = luaL_newstate();
    }

    void LoadStdLib()
    {
        luaL_openlibs(L);
    }

    bool Execute(const char* code)
    {
        int r = luaL_dostring(L, code);
        if (r == LUA_OK) {
            return true;
        }
        else {
            PrintLastError();
            return false;
        }
    }

    float GetNumber(const char* identifier)
    {
        lua_getglobal(L, identifier);
        if (lua_isnumber(L, -1))
        {
            return (float)lua_tonumber(L, -1);
        }
        else
        {
            PrintLastError();
            return -1;
        }
    }

    bool ExecuteFile(const char* filename)
    {
        int r = luaL_dofile(L, filename);
        if (r == LUA_OK) {
            return true;
        }
        else {
            PrintLastError();
            return false;
        }
    }

    ~LuaVirtualMachine()
    {
        lua_close(L);
    }
};
