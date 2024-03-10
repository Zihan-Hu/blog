@echo off

g++ -finput-charset=utf-8 -fexec-charset=gbk -Wall -I "%cd%\lib" -O2 -std=c++14 %*
