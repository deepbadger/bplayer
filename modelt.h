#ifndef MODELT_H
#define MODELT_H

#include <QAbstractTableModel>
#include <QList>
#include "info.h"

class Modelt : public QAbstractTableModel
{
Q_OBJECT
public:
    explicit Modelt(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant
                    headerData(int section, Qt::Orientation orientation, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role =
                    Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index =
                    QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index =
                    QModelIndex());

private:
        QList<_infoA> listOfA;
};

#endif // MODELT_H
