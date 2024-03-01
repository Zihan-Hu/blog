@echo off

g++ -I "%cd%\lib" -O2 -std=c++14 %*
