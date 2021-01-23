![](https://raw.githubusercontent.com/dsiberia9s/ELTEX_School/main/Day%206/screenshot.png)

**[по-русски]**

Калькулятор. Каждая функция вынесена в отдельный объектный модуль статической библиотеки.

**[English]**

Calculator. Each function is moved to a separate object modules of the static library.

`gcc sum.c -c`
`ar rc libcalc.a sum.o sub.o mul.o div.o`
`gcc main.c -o calc -L. -lcalc`