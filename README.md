# ezlua
## !! incomplete !!
This is very bare-bones at the moment and only enough to just get a REPL working for now.

## About
An easy-to-use library to interact with lua code from C++

## Installation
```bash
$ make && sudo make install
```

## Using in a project

To use this in a project, you must make sure that <kbd>/usr/local/lib/</kbd> is in your <kbd>LD_LIBRARY_PATH</kbd>
You can achieve this with:
```bash
export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH
```

Then #include "ezlua.hpp" (which should be placed in /usr/local/include)
And link with <kbd>-lezlua</kbd> and <kbd>-llua</kbd>

## Example Build
```bash
g++ examples/simple_repl.cpp -o simple_repl -lezlua -llua
