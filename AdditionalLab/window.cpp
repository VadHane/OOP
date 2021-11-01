#include "window.h"
#include "ui_window.h"
#include <QMessageBox>
#include "NewPolinom.hpp"
#include "list.hpp"
#include <iostream>
#include "CNum.hpp"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->groupBox_3->hide();
    ui->groupBox_5->hide();
    ui->groupBox_6->hide();
}

Window::~Window()
{
    delete ui;
}

NewPolinom* parse(QString& str){
    str.append(' ');

    float arr[str.length() / 2];
    int index = 0, begin = 0, end;

    for (int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            begin = i;
        } else continue;

        for (; i < str.length(); i++){
            if(str[i] == ' ' || str[i] == ')' || str[i] == '\0'){
                end = i;
                break;
            }
        }

        char tmp[end - begin + 2];
        for(int k = begin; k < end; k++){
            tmp[k - begin] = str[k].toLatin1();
        }

        arr[index++] = std::stof(tmp);

    }

    if(index % 2 != 0) return nullptr;

    SingleLinkList::List<CNumber::CNum> list;

    for(int i = 0; i < index; i += 2){
        list.add(CNumber::CNum(arr[i], arr[i+1]));
    }

    return new NewPolinom(list);
}

bool parseToInt(QString str, int *result){ // out result too
    for(int i = 0; i < str.length(); i++){
        if((str[i] < '0' || str[i] > '9') && str[i] != '.') return false;
    }

    char tmp[str.length() + 1];
    for(int k = 0; k < str.length(); k++){
        tmp[k] = str[k].toLatin1();
    }

    *result = std::stof(tmp);


    return true;
}


void Window::on_inputButton_clicked()
{

    QString inputLine = ui->input->text();
    polinom = parse(inputLine);

    if(polinom == nullptr) ui->statusbar->showMessage("Невірно передані аргументи!");
    else {
        ui->groupBox->hide();

        ui->groupBox_3->show();
        ui->polinom->setText(polinom->to_qstring());
        ui->statusbar->showMessage("Виберіть дію та отримайте результат! :)");
    }
}


void Window::on_power_clicked()
{
    ui->groupBox_6->show();
}


void Window::on_mult_min_one_clicked()
{
    NewPolinom tmp = !*polinom;
    ui->statusbar->showMessage("Результат: " + tmp.to_qstring());
}


void Window::on_increment_clicked()
{
    NewPolinom tmp = ++*polinom;
    ui->statusbar->showMessage("Результат: " + tmp.to_qstring());
    ui->polinom->setText(polinom->to_qstring());
}



void Window::on_derivative_clicked()
{
    ui->statusbar->showMessage("Результат: " + polinom->derivative().to_qstring());
}



void Window::on_indef_integral_clicked()
{
    ui->statusbar->showMessage("Результат: " + polinom->indefiniteIntegral().to_qstring());
}



void Window::on_definite_integral_clicked()
{
    ui->groupBox_5->show();


}


void Window::on_inputButton_2_clicked()
{
    QString inputPower = ui->input_2->text();
    int power;

    ui->groupBox_6->hide();

    if(!parseToInt(inputPower, &power)){
        ui->statusbar->showMessage("Невірно передані аргументи!");
        return;
    }

    ui->statusbar->showMessage("Результат: " + (*polinom ^ power).to_qstring());
}


void Window::on_inputButton_3_clicked()
{
    int topBorder, botBorder;

    ui->groupBox_5->hide();

    if(!parseToInt(ui->topBorder->text(), &topBorder) || !parseToInt(ui->lowBorder->text(), &botBorder)){
        ui->statusbar->showMessage("Невірно передані аргументи!");
        return;
    }

    CNumber::CNum result = polinom->definiteIntegral(botBorder, topBorder);

    char tmp[40];
    sprintf(tmp, "Результат: (%.2f, %.2f)", result.realPart, result.imaginaryPart);
    ui->statusbar->showMessage(tmp);
}


void Window::on_back_clicked()
{
    ui->groupBox_3->hide();
    ui->groupBox->show();
}

