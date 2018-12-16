#ifndef BDITEM_H
#define BDITEM_H

#include <QWidget>
#include "globals.h"

namespace Ui {
class BDItem;
}

class BDItem : public QWidget
{
    Q_OBJECT

public:
    explicit BDItem(QWidget *parent = nullptr, BDItemClothsData data = {});
    ~BDItem();

private:
    Ui::BDItem *ui;
};

#endif // BDITEM_H
