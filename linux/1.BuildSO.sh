g++ -c -fPIC ../main.cpp -o test.o
g++ -shared test.o -o test.so
