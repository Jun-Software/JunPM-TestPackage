g++ -c -fPIC ../main.cpp -o test.o
g++ -shared -o test.so test.o