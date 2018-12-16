#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QListWidgetItem>
#include <iostream>
#include "globals.h"
#include "adminwindow.h"
#include "customerwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent, QList<BDItemClothsData> clothsData,
                                        QList<BDItemFurnitureData> furnitureData,
                                        QList<BDItemProductData> productData) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Экран пользователя (" + user + ")");
    QIcon icon("D:/Qt/Design5/res/blue.png");
    QWidget::setWindowIcon(icon);


    //QSqlQuery q;
    //QSqlTableModel* model;

    QListWidgetItem *w = new QListWidgetItem(ui->listWidget);

    QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);

    if (user == "Администратор")
    {
        AdminWindow *window = new AdminWindow(NULL, clothsData, furnitureData, productData);
        widgetItem->setFlags(widgetItem->flags() & ~Qt::ItemIsSelectable);
        //cw->setMinimumWidth(cw->sizeHint());
        widgetItem->setSizeHint(QSize(window->sizeHint().width(), 600));
        ui->listWidget->addItem(widgetItem);
        ui->listWidget->setItemWidget(widgetItem, window);
        MainWindow::setCentralWidget(window);
    }
    else if (user == "Заказчик")
    {
        CustomerWindow *window = new CustomerWindow(/*NULL, clothsData, furnitureData, productData*/);
        widgetItem->setFlags(widgetItem->flags() & ~Qt::ItemIsSelectable);
        widgetItem->setSizeHint(QSize(window->sizeHint().width(), 600));
        ui->listWidget->addItem(widgetItem);
        ui->listWidget->setItemWidget(widgetItem, window);
        MainWindow::setCentralWidget(window);
    }


}

MainWindow::~MainWindow()
{
    db.close();
    qDebug() << "Connection closed " << QSqlDatabase::database().connectionNames();
    delete ui;
}
