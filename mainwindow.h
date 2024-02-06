#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <cstdio>
#include <iostream>
#include <list>

typedef int posicion;

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

private:
    Ui::MainWindow *ui;
};

class Neurona{
private:
    int id;
    float voltaje;
    posicion x;
    posicion y;
    int red;
    int green;
    int blue;
public:
    Neurona(){
        id = 0;
        voltaje = 0;
        x = 0;
        y = 0;
        red = 0;
        green = 0;
        blue = 0;
    }
    Neurona(int id, float voltaje, posicion x, posicion y, int r, int g, int b){
        this->id = id;
        this->voltaje = voltaje;
        this->x = x;
        this->y = y;
        this->red = r;
        this->green = g;
        this->blue = b;
    }
    void putId(int * id){this->id = *id;}
    void putVoltaje(float * voltaje){this->voltaje = *voltaje;}
    void putX(posicion * x){this->x = *x;}
    void putY(posicion * y){this->y = *y;}
    void putRed(int * red){this->red = *red;}
    void putGreen(int * green){this->green = *green;}
    void putBlue(int * blue){this->blue = *blue;}

    int getId(){return id;}
    float getVoltaje(){return voltaje;}
    posicion getX(){return x;}
    posicion getY(){return y;}
    int getRed(){return red;}
    int getGreen(){return green;}
    int getBlue(){return blue;}
};

class AdminNeuronas{
private:
    std::list<Neurona*> neuronas;
    int cuentaNeuronas;
public:
    AdminNeuronas(){
        cuentaNeuronas = 0;
    }
    bool agregarPila(Neurona * n){
        neuronas.push_front(n);
        return true;
    }
    bool agregarCola(Neurona * n){
        neuronas.push_back(n);
        return true;
    }
    Neurona * dameNeurona(posicion p){
        return neuronas.back();
    }
    void imprimir(Neurona * n){
        std::cout << "Neuronas #" << dameCuenta() << std::endl
                  << "ID: " << n->getId() << std::endl
                  << "Voltaje: " << n->getVoltaje() << std::endl
                  << "Cord X: " << n->getX() << std::endl
                  << "Cord Y: " << n->getY() << std::endl
                  << "Red: " << n->getRed() << std::endl
                  << "Green: " << n->getGreen() << std::endl
                  << "Blue: " << n->getBlue() << std::endl
                  << "\n";
    }
    void listar(){
        for (Neurona * n : neuronas)
            imprimir(n);
    }
    int dameCuenta(){
        return (int)neuronas.size();
    }
};

#endif // MAINWINDOW_H
