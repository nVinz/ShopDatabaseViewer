#include "bditem.h"
#include "ui_bditem.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

BDItem::BDItem(QWidget *parent, BDItemClothsData data) :
    QWidget(parent),
    ui(new Ui::BDItem)
{
    ui->setupUi(this);


    ui->label_1->setText(data.ID);
    ui->label_2->setText(data.Name);
    ui->label_3->setText(data.Color);
    ui->label_4->setText(data.Pattern);
    ui->label_5->setText(data.Composition);
    ui->label_6->setText(data.Width);
    ui->label_7->setText(data.Length);
    ui->label_8->setText(data.Price);
}

BDItem::~BDItem()
{
    delete ui;
}
