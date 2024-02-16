@echo off

g++ -I "%cd%\lib\testlib" -O2 -std=c++14 %*
