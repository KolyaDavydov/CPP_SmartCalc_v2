# SmartCalc v2.0
  Copyright (C) 2023 Davydov Nikolay \
    Author:     Davydov Nikolay \
     Date:      2023, october \
     Version:   2.0 

#### Калькулятор собирается на Linux Ubuntu 22.04.3 LTS (остальные системы не проверялись)
#### СОздание осуществлялось на Windows 11 с помощью установленного Linux с использованием WSL

-  Программа разработана на языке С++ стандарта C++17 с использованием компилятора g++. 
- Сборка программы настроена с помощью Makefile со стандартным набором целей для GNU-программ: all, install, uninstall, clean, dvi, dist, test, gcov_report. Установка ведется в каталог build/
- Вычисление выражение происходит через обратну польскую нотацию с использованием стэка
- Обеспечено покрытие unit-тестами модулей, связанных с вычислением выражений, с помощью библиотеки GTest

### Примечание:
- Для сборки может использоваться как 'cmake' (проект находится в папке 'src'), так и qmake (проект находится в папке 'src_qmake') \
Для отрисовки графики используется библиотека 'qcustomplot'. Для сборки проекта с помощью qmake достаточно скопировать исходник и хедер в папку и подключить их как стандартные самописные файлы. Для сборки с помощью Cmake необходимо провести дополнительные маниауляции как показанно по [ссылке](https://github.com/legerch/QCustomPlot-library)

### Примечание по установки компонентов для возможности редактировать и собирать проект Ubuntu_22.04:
1) установка WSL На Windows 11.
2) установка дистрибутива Linux 22.04 процедуру можно посмотреть по [ссылке](https://learn.microsoft.com/ru-ru/windows/wsl/install)
3) теперь можно использовать Linux одновременно с Windows. Для возможности использование программ Linux имеющих графический интерфейс необходим wsl версии 2.
проверить версию WSL, задав команду `wsl -l -v` в PowerShell или в Командной строке Windows

### Примечание по установки компонентов для возможности редактировать и собирать проект Ubuntu_20.04:
1) установка WSL На Windows 11.
2) установка дистрибутива Linux 22.04 процедуру можно посмотреть по [ссылке](https://learn.microsoft.com/ru-ru/windows/wsl/install)
3) заходим в линукс и дальнейшие операции по установке необходимых компонентов будем выполнять там.
Обновить список пакетов:
```bash
sudo apt update
```
Установим компилятор g++:
```bash
sudo apt install g++
```
Установка библиотеки gtest Для тестов:
```bash
sudo apt install libgtest-dev libcppunit-subunit-dev lcov
```
Для просмотра отчета по покрытию тестов:
```bash
sudo apt install chromium-browser
sudo apt install xdg-open-utils
```
Для проверки на стилистику написания:
```bash
sudo apt install clang-format
```
Для проверки на утечку памяти:
```bash
sudo apt install valgrind
```

#### 3.1. Для ubunte 20.04:

Теперь, чтобы установить Qt Ubuntu выполните:
```bash
sudo apt install qt5-default
```
Установим IDE QtCreator:
```bash
sudo apt install qtcreator
```
установить cmake:
```bash
sudo apt install cmake
```
Установится версия Qt Creator 4.11.0 based on Qt 5.12.8 \
для запуска необходимо в командной строке написать 'qtcreqtor' \

#### 3.1. Для ubunte 22.04: 
[ссылка](https://wiki.qt.io/Building_Qt_Creator_from_Git_on_Ubuntu_22.04)
Здесь установка Qt Creator уже более замысловатая:
Устанавливаем иснтрументы сборки:
```bash
sudo apt install build-essential cmake ninja-build git
```
Установливаем все пакеты Ubuntu Qt 6 SDK;
```bash
sudo apt install qt6-base-dev qt6-base-private-dev qt6-declarative-dev qt6-declarative-private-dev qt6-tools-dev qt6-tools-private-dev qt6-scxml-dev qt6-documentation-tools libqt6core5compat6-dev qt6-tools-dev-tools qt6-l10n-tools qt6-shader-baker libqt6shadertools6-dev qt6-quick3d-dev qt6-quick3d-dev-tools libqt6svg6-dev libqt6quicktimeline6-dev libqt6serialport6-dev
```
Установка зависимостей LLVM / Clang:
```bash
sudo apt install clang-15 clangd-15 libclang-15-dev
```
Установка зависимости Qt Creator:
```bash
sudo apt install libgl1-mesa-dev libvulkan-dev libxcb-xinput-dev libxcb-xinerama0-dev libxkbcommon-dev libxkbcommon-x11-dev libxcb-image0 libxcb-keysyms1 libxcb-render-util0 libxcb-xkb1 libxcb-randr0 libxcb-icccm4
```
Скачиваем исходный код Qt Creator с репозитория git (процесс достаточно долгий):
```bash
git clone --recursive https://code.qt.io/qt-creator/qt-creator.git repo
```
Сборка Qt Creator:
```bash
cmake -G Ninja -S repo -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build
cmake --install build/ --prefix qtcreator-install
```

Однако Qt Creator будет настроен на использование qt6,
Нужно ввести команду `qtchooser -l`, что бы увидеть список доступных qt и их версии, если там не будет версии 6, то сделать следующие операции:

Генерация на основе пути к `qt6.conf` `qmake6`:
```bash
qtchooser -install qt6 $(which qmake6)
```
Переместить `qt.conf` в системную директорию:
```bash
sudo mv ~/.config/qtchooser/qt6.conf /usr/share/qtchooser/qt6.conf
```
установить Qt6 как дефолтный:
```bash
sudo mkdir -p /usr/lib/$(uname -p)-linux-gnu/qt-default/qtchooser/qt6.conf
sudo ln -n /usr/share/qtchooser/qt6.conf /usr/lib/$(uname -p)-linux-gnu/qt-default/qtchooser/default.conf
```
Запустить Qt Creator следующей командой ():
```bash
./qtcreator-install/bin/qtcreator
```


<image src="img/report_lcov.png" alt="Покрытие тестами">

- Графический интерфейс калькулятора реализован с использованием фреймворка Qt Creator 6.0.2

- Скобочные арифметические выражения в инфиксной нотации поддерживают следующие арифметические операции и математические функции:
    - **Арифметические операторы**:

        | Название оператора | Инфиксная нотация <br /> (Классическая) | Префиксная нотация <br /> (Польская нотация) |  Постфиксная нотация <br /> (Обратная польская нотация) |
        | ------ | ------ | ------ | ------ |
        | Скобки | (a + b) | (+ a b) | a b + |
        | Сложение | a + b | + a b | a b + |
        | Вычитание | a - b | - a b | a b - |
        | Умножение | a * b | * a b | a b * |
        | Деление | a / b | / a b | a b \ |
        | Возведение в степень | a ^ b | ^ a b | a b ^ |
        | Остаток от деления | a mod b | mod a b | a b mod |
        | Унарный плюс | +a | +a | a+ |
        | Унарный минус | -a | -a | a- |

        >Оператор умножения содержит обязательный знак `*`.

    - **Функции**:
  
        | Описание функции | Функция |   
        | ---------------- | ------- |  
        | Вычисляет косинус | cos(x) |   
        | Вычисляет синус | sin(x) |  
        | Вычисляет тангенс | tan(x) |  
        | Вычисляет арккосинус | acos(x) | 
        | Вычисляет арксинус | asin(x) | 
        | Вычисляет арктангенс | atan(x) |
        | Вычисляет квадратный корень | sqrt(x) |
        | Вычисляет натуральный логарифм | ln(x) | 
        | Вычисляет десятичный логарифм | log(x) |


### Внешний вид калькулятора:
<image src="img/calc.png" alt="Внешний вид калькулятора">

 - Дополнительно реализована возможность построения графика по заданной функции:

<image src="img/graph.png" alt="Внешний вид калькулятора">

 - Дополнительно добавлен кредитный калькулятор с расчетом ежемесячных платежей:
  
<image src="img/credit.png" alt="Внешний вид калькулятора">