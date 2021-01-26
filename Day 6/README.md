![](https://raw.githubusercontent.com/dsiberia9s/ELTEX_School/main/Day%206/screenshot.png)

**[по-русски]**

Калькулятор. Каждая функция вынесена в отдельный объектный модуль статической библиотеки.

Создание объектных модулей:

`gcc sum.c sub.c mul.c div.c -c`

Создание статической библиотеки:

`ar rc libcalc.a sum.c sub.c mul.c div.c`

Компиляция:

`gcc calc.c -o calc -L. -lcalc`

Запуск бинарного файла:

`./calc`

**[English]**

Calculator. Each function is moved to a separate object modules of the dynamic library.

Create object-modules:

`gcc sum.c sub.c mul.c div.c -c`

Create static library:

`ar rc libcalc.a sum.c sub.c mul.c div.c`

Compile:

`gcc calc.c -o calc -L. -lcalc`

Run binary:

`./calc`