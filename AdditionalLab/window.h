#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "NewPolinom.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    NewPolinom *polinom;

private slots:

    void on_inputButton_clicked();

    void on_power_clicked();

    void on_mult_min_one_clicked();

    void on_increment_clicked();

    void on_derivative_clicked();

    void on_indef_integral_clicked();

    void on_definite_integral_clicked();

    void on_inputButton_2_clicked();

    void on_inputButton_3_clicked();

    void on_back_clicked();

private:
    Ui::Window *ui;
};
#endif // WINDOW_H
