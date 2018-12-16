#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGlobal>
#include <QString>
#include <iostream>
using namespace std;

extern QString user;
extern QString username;
extern int uid;

extern QString db_Type;
extern QString db_HostName;
extern QString db_DatabaseName;
extern QString db_UserName;
extern QString db_Password;

struct BDItemClothsData
{
    QString ID;
    QString Name;
    QString Color;
    QString Pattern;
    QString Composition;
    QString Width;
    QString Length;
    QString Price;
};

struct BDItemFurnitureData
{
    QString ID;
    QString Name;
    QString Width;
    QString Length;
    QString Type;
    QString Price;
};

struct BDItemProductData
{
    QString ID;
    QString Name;
    QString Width;
    QString Length;
    QString Price;
};

#endif // GLOBALS_H
