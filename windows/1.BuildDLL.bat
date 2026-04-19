@echo off
g++ -shared -o test.dll ../main.cpp -DMYLIB_EXPORTS
pause