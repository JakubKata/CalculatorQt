#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MathEngine.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::clicked, this, [this]() { appendToInput("0"); });
    connect(ui->pushButton_1, &QPushButton::clicked, this, [this]() { appendToInput("1"); });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() { appendToInput("2"); });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() { appendToInput("3"); });
    connect(ui->pushButton_4, &QPushButton::clicked, this, [this]() { appendToInput("4"); });
    connect(ui->pushButton_5, &QPushButton::clicked, this, [this]() { appendToInput("5"); });
    connect(ui->pushButton_6, &QPushButton::clicked, this, [this]() { appendToInput("6"); });
    connect(ui->pushButton_7, &QPushButton::clicked, this, [this]() { appendToInput("7"); });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [this]() { appendToInput("8"); });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [this]() { appendToInput("9"); });

    connect(ui->pushButton_plus, &QPushButton::clicked, this, [this]() { appendToInput("+"); });
    connect(ui->pushButton_minus, &QPushButton::clicked, this, [this]() { appendToInput("-"); });
    connect(ui->pushButton_multiplication, &QPushButton::clicked, this, [this]() { appendToInput("*"); });
    connect(ui->pushButton_division, &QPushButton::clicked, this, [this]() { appendToInput("/"); });
    connect(ui->pushButton_power, &QPushButton::clicked, this, [this]() { appendToInput("^"); });
    connect(ui->pushButton_openBracket, &QPushButton::clicked, this, [this]() { appendToInput("("); });
    connect(ui->pushButton_closeBracket, &QPushButton::clicked, this, [this]() { appendToInput(")"); });
    connect(ui->pushButton_point, &QPushButton::clicked, this, [this]() { appendToInput("."); });
    connect(ui->pushButton_sqrt, &QPushButton::clicked, this, [this]() { appendToInput("sqrt("); });
    connect(ui->pushButton_sin, &QPushButton::clicked, this, [this]() { appendToInput("sin("); });
    connect(ui->pushButton_cos, &QPushButton::clicked, this, [this]() { appendToInput("cos("); });
    connect(ui->pushButton_tan, &QPushButton::clicked, this, [this]() { appendToInput("tan("); });
    
    connect(ui->pushButton_equals, &QPushButton::clicked, this, &MainWindow::calculateResult);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::clearInput);
    connect(ui->pushButton_back, &QPushButton::clicked, this, &MainWindow::backspaceInput);
    connect(ui->pushButton_right, &QPushButton::clicked, this, [this]() { moveCursor("right"); });
    connect(ui->pushButton_left, &QPushButton::clicked, this, [this]() { moveCursor("left"); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendToInput(const QString& text)
{
    ui->input->insert(text);
    ui->input->setFocus();
}

void MainWindow::clearInput()
{
    ui->input->clear();
    ui->value->setText("0.0");
}

void MainWindow::backspaceInput()
{
    ui->input->backspace();
    ui->input->setFocus();
}

void MainWindow::moveCursor(const QString& direction)
{
    int cursorPosition = ui->input->cursorPosition();
    if (direction == "left" && cursorPosition > 0) {
        ui->input->setCursorPosition(cursorPosition - 1);
    } else if (direction == "right" && cursorPosition < ui->input->text().length()) {
        ui->input->setCursorPosition(cursorPosition + 1);
    }
    ui->input->setFocus();
}

void MainWindow::calculateResult()
{
    std::string expression = ui->input->text().toStdString();
    auto result = MathEngine::Math::calculateSafe(expression);
    if (result.isSuccess) {
        ui->value->setText(QString::number(result.value));
    } else {
    ui->value->setText(QString::fromStdString("Error: " + result.errorMessage));
    }
}
