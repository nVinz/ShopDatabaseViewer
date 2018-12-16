#include "bditemfurniture.h"
#include "ui_bditemfurniture.h"

BDItemFurniture::BDItemFurniture(QWidget *parent, BDItemFurnitureData data) :
    QWidget(parent),
    ui(new Ui::BDItemFurniture)
{
    ui->setupUi(this);

    ui->label_1->setText(data.ID);
    ui->label_2->setText(data.Name);
    ui->label_3->setText(data.Width);
    ui->label_4->setText(data.Length);
    ui->label_5->setText(data.Type);
    ui->label_6->setText(data.Price);
}

BDItemFurniture::~BDItemFurniture()
{
    delete ui;
}
