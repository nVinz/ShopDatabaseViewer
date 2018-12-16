#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QtSql>
#include "globals.h"
#include "bditem.h"
#include "bditemfurniture.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "bditemproduct.h"

AdminWindow::AdminWindow(QWidget *parent, QList<BDItemClothsData> clothsData,
                                          QList<BDItemFurnitureData> furnitureData,
                                          QList<BDItemProductData> productData) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    ui->horizontalLayout->setSpacing(0);
    ui->verticalLayout_3->setSpacing(0);
    ui->listWidget_Cloths->setSpacing(-6);
    ui->listWidget_Furniture->setSpacing(-6);
    ui->listWidget_Products->setSpacing(-6);
    ui->listWidget_Cloths->hide(); ui->listWidget_Furniture->hide(); ui->listWidget_Products->hide();

    cdata = clothsData;
    fdata = furnitureData;
    pdata = productData;

    loadData();
    on_pushButton_StockCloths_clicked();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_StockCloths_clicked()
{
    ui->listWidget_Cloths->show(); ui->listWidget_Furniture->hide(); ui->listWidget_Products->hide();
    ui->pushButton_StockCloths->setStyleSheet(ui->pushButton_StockCloths->styleSheet() + (QString("QPushButton {background-color: rgb(165, 190, 202);}")));
    ui->pushButton_StockCloths->setDisabled(true);
    ui->pushButton_StockFurniture->setStyleSheet(ui->pushButton_StockFurniture->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockFurniture->setDisabled(false);
    ui->pushButton_StockProducts->setStyleSheet(ui->pushButton_StockProducts->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockProducts->setDisabled(false);
    ui->label->setText("ID");
    ui->label_2->setText("Name");
    ui->label_3->setText("Color");
    ui->label_4->setText("Pattern");
    ui->label_5->setText("Composition");
    ui->label_6->show();
    ui->label_6->setText("Width");
    ui->label_7->show();
    ui->label_7->setText("Length");
    ui->label_8->show();
    ui->label_8->setText("Price");
}

void AdminWindow::on_pushButton_StockFurniture_clicked()
{
    ui->listWidget_Cloths->hide(); ui->listWidget_Furniture->show(); ui->listWidget_Products->hide();
    ui->pushButton_StockCloths->setStyleSheet(ui->pushButton_StockCloths->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockCloths->setDisabled(false);
    ui->pushButton_StockFurniture->setStyleSheet(ui->pushButton_StockFurniture->styleSheet() + (QString("QPushButton {background-color: rgb(165, 190, 202);}")));
    ui->pushButton_StockFurniture->setDisabled(true);
    ui->pushButton_StockProducts->setStyleSheet(ui->pushButton_StockProducts->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockProducts->setDisabled(false);
    ui->label->setText("ID");
    ui->label_2->setText("Name");
    ui->label_3->setText("Width");
    ui->label_4->setText("Length");
    ui->label_5->setText("Type");
    ui->label_6->show();
    ui->label_6->setText("Price");
    ui->label_7->hide();
    ui->label_8->hide();
}

void AdminWindow::on_pushButton_StockProducts_clicked()
{
    ui->listWidget_Cloths->hide(); ui->listWidget_Furniture->hide(); ui->listWidget_Products->show();
    ui->pushButton_StockCloths->setStyleSheet(ui->pushButton_StockCloths->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockCloths->setDisabled(false);
    ui->pushButton_StockFurniture->setStyleSheet(ui->pushButton_StockFurniture->styleSheet() + (QString("QPushButton {background-color: rgb(209, 238, 252);}")));
    ui->pushButton_StockFurniture->setDisabled(false);
    ui->pushButton_StockProducts->setStyleSheet(ui->pushButton_StockProducts->styleSheet() + (QString("QPushButton {background-color: rgb(165, 190, 202);}")));
    ui->pushButton_StockProducts->setDisabled(true);
    ui->label->setText("ID");
    ui->label_2->setText("Name");
    ui->label_3->setText("Width");
    ui->label_4->setText("Length");
    ui->label_5->setText("Price");
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
}


void AdminWindow::loadData()
{
    QList<BDItemClothsData>::iterator c_iterator;
    for (c_iterator = cdata.begin(); c_iterator != cdata.end(); c_iterator++)
    {
        BDItemClothsData c_data = *c_iterator;
        c_data.ID = c_iterator->ID;
        c_data.Name = c_iterator->Name;
        c_data.Color = c_iterator->Color;
        c_data.Pattern = c_iterator->Pattern;
        c_data.Composition = c_iterator->Composition;
        c_data.Width = c_iterator->Width;
        c_data.Length = c_iterator->Length;
        c_data.Price = c_iterator->Price;

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget_Cloths);
        BDItem *item = new BDItem(NULL, c_data);
        listWidgetItem->setSizeHint(item->sizeHint());
        ui->listWidget_Cloths->addItem(listWidgetItem);
        ui->listWidget_Cloths->setItemWidget(listWidgetItem, item);
    }

    QList<BDItemFurnitureData>::iterator f_iterator;
    for (f_iterator = fdata.begin(); f_iterator != fdata.end(); f_iterator++)
    {
        BDItemFurnitureData f_data;
        f_data.ID = f_iterator->ID;
        f_data.Name = f_iterator->Name;
        f_data.Width = f_iterator->Width;
        f_data.Length = f_iterator->Length;
        f_data.Type = f_iterator->Type;
        f_data.Price = f_iterator->Price;

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget_Furniture);
        BDItemFurniture *item = new BDItemFurniture(NULL, f_data);
        listWidgetItem->setSizeHint(item->sizeHint());
        ui->listWidget_Furniture->addItem(listWidgetItem);
        ui->listWidget_Furniture->setItemWidget(listWidgetItem, item);
    }

    QList<BDItemProductData>::iterator p_iterator;
    for (p_iterator = pdata.begin(); p_iterator != pdata.end(); p_iterator++)
    {
        BDItemProductData p_data;
        p_data.ID = p_iterator->ID;
        p_data.Name = p_iterator->Name;
        p_data.Width = p_iterator->Width;
        p_data.Length = p_iterator->Length;
        p_data.Price = p_iterator->Price;

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget_Products);
        BDItemProduct *item = new BDItemProduct(NULL, p_data);
        listWidgetItem->setSizeHint(item->sizeHint());
        ui->listWidget_Products->addItem(listWidgetItem);
        ui->listWidget_Products->setItemWidget(listWidgetItem, item);
    }
}
