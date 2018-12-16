#include "bditemproduct.h"
#include "ui_bditemproduct.h"
#include "globals.h"

BDItemProduct::BDItemProduct(QWidget *parent, BDItemProductData data) :
    QWidget(parent),
    ui(new Ui::BDItemProduct)
{
    ui->setupUi(this);

    ui->label_1->setText(data.ID);
    ui->label_2->setText(data.Name);
    ui->label_3->setText(data.Width);
    ui->label_4->setText(data.Length);
    ui->label_5->setText(data.Price);
}

BDItemProduct::~BDItemProduct()
{
    delete ui;
}
