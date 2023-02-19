#include <iostream>
#include <string>

#include "lua.hpp"

#define EXECUTABLE 1

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

#if EXECUTABLE == 1

int main()
{
	using namespace std;

	LuaVirtualMachine lvm;
	string input;
	while (true) {
		cout << "> ";
		getline(cin, input);
		if (input == ":exit" || input == ":quit") {
			break;
		}
		else if (input == ":loadlibs" || input == ":loadstd") {
			lvm.LoadStdLib();
		}
		else if (input == ":loadfile" || input == ":runfile") {
			cout << "Filename: ";
			getline(cin, input);
			lvm.ExecuteFile(input.c_str());
		}
		else {
			lvm.Execute(input.c_str());
		}
	}
	return 0;
}

#endif
