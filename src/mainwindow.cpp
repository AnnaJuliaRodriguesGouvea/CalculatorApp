#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operationtype.h"
#include "calculation.h"
#include "calculator.h"

namespace {
constexpr QSize g_windowSize(650, 300);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const QString q_windowTitle("Calculator");

    ui->setupUi(this);

    setBackgroundColorCentralWidget();
    createItensComboBoxOperation();
    createTableWidgetHistory();

    setWindowTitle(q_windowTitle);
    setFixedSize(g_windowSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBackgroundColorCentralWidget()
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, "#E5DDC5");
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);
}

void MainWindow::createItensComboBoxOperation()
{
    // Add items to operation combo box
    ui->comboBoxOperation->addItem("+", Addition);
    ui->comboBoxOperation->addItem("-", Subtraction);
    ui->comboBoxOperation->addItem("*", Multiplication);
    ui->comboBoxOperation->addItem("/", Division);
}

void MainWindow::createTableWidgetHistory()
{
    // Set column headers for the history table
    QStringList headers = {"#1", "Operator", "#2", "Result"};
    ui->tableWidgetHistory->setColumnCount(headers.size());
    ui->tableWidgetHistory->setHorizontalHeaderLabels(headers);

    // Set column widths
    ui->tableWidgetHistory->setColumnWidth(0, 50);
    ui->tableWidgetHistory->setColumnWidth(1, 100);
    ui->tableWidgetHistory->setColumnWidth(2, 50);
    ui->tableWidgetHistory->setColumnWidth(3, 100);

    ui->tableWidgetHistory->setFixedWidth(300);
    ui->tableWidgetHistory->setFixedHeight(230);
    ui->tableWidgetHistory->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetHistory->verticalHeader()->setVisible(false);

    ui->verticalLayoutHistory->setContentsMargins(0, 20, 0, 20);

}

void MainWindow::updateHistory()
{
    const QList<Calculation>& calculations = Calculator::getInstance().getCalculations();
    ui->tableWidgetHistory->setRowCount(calculations.size());

    for (int i = 0; i < calculations.size(); ++i) {
        const Calculation& calc = calculations.at(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(calc.getValue1()));
        QTableWidgetItem *item2 = new QTableWidgetItem(calc.getOperationString());
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(calc.getValue2()));
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(calc.getResult()));

        ui->tableWidgetHistory->setItem(i, 0, item1);
        ui->tableWidgetHistory->setItem(i, 1, item2);
        ui->tableWidgetHistory->setItem(i, 2, item3);
        ui->tableWidgetHistory->setItem(i, 3, item4);
    }
}

void MainWindow::on_pushButtonCalculate_clicked()
{
    double value1 = ui->doubleBoxValue1->value();
    double value2 = ui->doubleBoxValue2->value();
    OperationType op = static_cast<OperationType>(ui->comboBoxOperation->currentData().toInt());

    double result;
    Calculator& calc = Calculator::getInstance();

    switch (op) {
    case Addition: result = calc.add(value1, value2); break;
    case Subtraction: result = calc.subtract(value1, value2); break;
    case Multiplication: result = calc.multiply(value1, value2); break;
    case Division: result = calc.divide(value1, value2); break;
    }

    ui->labelResult->setText("Result: " + QString::number(result));
    updateHistory();
}

