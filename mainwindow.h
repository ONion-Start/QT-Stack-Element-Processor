#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGenerateElements();
    void onSaveInput();
    void onProcessElements();
    void onSaveOutput();

private:
    Ui::MainWindow *ui;
    QTableWidget *inputTableWidget;
    QTableWidget *outputTableWidget;
    QLabel *inputIndicator;
    QLabel *outputIndicator;
    void swapPairs(std::vector<int> &numbers);
};
#endif // MAINWINDOW_H
