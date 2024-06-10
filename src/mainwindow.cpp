#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const QString q_windowTitle("Calculator");

    ui->setupUi(this);

    setWindowTitle(q_windowTitle);
}

MainWindow::~MainWindow()
{
    delete ui;
}
