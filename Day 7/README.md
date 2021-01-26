![](https://raw.githubusercontent.com/dsiberia9s/ELTEX_School/main/Day%207/screenshot.png)

**[по-русски]**

Калькулятор. Каждая функция вынесена в отдельный объектный модуль динамической библиотеки.

Создание объектных модулей:

`gcc sum.c sub.c mul.c div.c -c`

Создание динамической библиотеки:

`gcc -shared sum.c sub.c mul.c div.c -o libcalc.so`

Компиляция:

`gcc calc.c -o calc -L. -lcalc`

Запуск бинарного файла:

`LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH ./calc`

**[English]**

Calculator. Each function is moved to a separate object modules of the dynamic library.

Create object-modules:

`gcc sum.c sub.c mul.c div.c -c`

Create dynamic library:

`gcc -shared sum.c sub.c mul.c div.c -o libcalc.so`

Compile:

`gcc calc.c -o calc -L. -lcalc`

Run binary:

`LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH ./calc`