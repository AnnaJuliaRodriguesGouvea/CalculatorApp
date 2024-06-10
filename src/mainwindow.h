#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCalculate_clicked();

private:
    Ui::MainWindow *ui;
    void createItensComboBoxOperation();
    void createTableWidgetHistory();
    void updateHistory();
};
#endif // MAINWINDOW_H
