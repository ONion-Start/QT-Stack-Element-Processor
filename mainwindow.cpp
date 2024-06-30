#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QStack>
#include <QRegularExpression>
#include <QHeaderView>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout;


    inputTableWidget = new QTableWidget(this);
    inputTableWidget->setColumnCount(1);
    inputTableWidget->setHorizontalHeaderLabels(QStringList() << "Input Numbers");
    layout->addWidget(inputTableWidget);


    outputTableWidget = new QTableWidget(this);
    outputTableWidget->setColumnCount(1);
    outputTableWidget->setHorizontalHeaderLabels(QStringList() << "Output Numbers");
    layout->addWidget(outputTableWidget);


    QPushButton *generateButton = new QPushButton("Generate", this);
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateElements);
    layout->addWidget(generateButton);


    QPushButton *saveInputButton = new QPushButton("Save Input", this);
    connect(saveInputButton, &QPushButton::clicked, this, &MainWindow::onSaveInput);
    layout->addWidget(saveInputButton);


    inputIndicator = new QLabel(this);
    inputIndicator->setFixedSize(20, 20);
    inputIndicator->setStyleSheet("QLabel { background-color : red; }");
    layout->addWidget(inputIndicator);


    QPushButton *processButton = new QPushButton("Process", this);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::onProcessElements);
    layout->addWidget(processButton);


    QPushButton *saveOutputButton = new QPushButton("Save Output", this);
    connect(saveOutputButton, &QPushButton::clicked, this, &MainWindow::onSaveOutput);
    layout->addWidget(saveOutputButton);


    outputIndicator = new QLabel(this);
    outputIndicator->setFixedSize(20, 20);
    outputIndicator->setStyleSheet("QLabel { background-color : red; }");
    layout->addWidget(outputIndicator);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);

    // Initialize random seed
    std::srand(std::time(nullptr));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGenerateElements()
{
    int numRows = 12;  // Example: generate 12 numbers
    inputTableWidget->setRowCount(numRows);
    for (int i = 0; i < numRows; ++i) {
        int randomNumber = std::rand() % 100;  // Random number between 0 and 99
        inputTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(randomNumber)));
    }
    inputIndicator->setStyleSheet("QLabel { background-color : red; }");
}

void MainWindow::onSaveInput()
{
    qDebug() << "Current working directory:" << QDir::currentPath();

    QFile inputFile("input.txt");
    if (!inputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open input.txt for writing");
        return;
    }

    QTextStream out(&inputFile);
    for (int i = 0; i < inputTableWidget->rowCount(); ++i) {
        out << inputTableWidget->item(i, 0)->text() << "\n";
    }

    inputFile.close();

    // Change input save indicator to green
    inputIndicator->setStyleSheet("QLabel { background-color : green; }");
}

void MainWindow::onProcessElements()
{
    std::vector<int> numbers;
    for (int i = 0; i < inputTableWidget->rowCount(); ++i) {
        numbers.push_back(inputTableWidget->item(i, 0)->text().toInt());
    }

    swapPairs(numbers);

    outputTableWidget->setRowCount(numbers.size());
    for (size_t i = 0; i < numbers.size(); ++i) {
        outputTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(numbers[i])));
    }

    outputIndicator->setStyleSheet("QLabel { background-color : red; }");
}

void MainWindow::onSaveOutput()
{
    qDebug() << "Current working directory:" << QDir::currentPath();

    QFile outputFile("output.txt");
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open output.txt for writing");
        return;
    }

    QTextStream out(&outputFile);
    for (int i = 0; i < outputTableWidget->rowCount(); ++i) {
        out << outputTableWidget->item(i, 0)->text() << "\n";
    }

    outputFile.close();

    // Change output save indicator to green
    outputIndicator->setStyleSheet("QLabel { background-color : green; }");
}

void MainWindow::swapPairs(std::vector<int> &numbers)
{
    for (size_t i = 0; i + 3 < numbers.size(); i += 4) {
        std::swap(numbers[i], numbers[i + 2]);
        std::swap(numbers[i + 1], numbers[i + 3]);
    }
}
