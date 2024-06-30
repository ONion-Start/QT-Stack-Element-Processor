/*Условия задачи:\n"
13. В файле input.txt задан набор целых чисел.
Записать их в память используя свой стек.
Просматривая  стек, поменять у каждой четверки подряд идущих элементов первую и вторую пары.
Результат записать в новый стек и вывести в файл Output.txt
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
