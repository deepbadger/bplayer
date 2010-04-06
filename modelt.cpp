#include "modelt.h"

Modelt::Modelt(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int
Modelt::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);

  int i = listOfA.size();

  return i;
}

int
Modelt::columnCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);
  _infoA p;

  return 7;
}


QVariant
Modelt::data(const QModelIndex &index, int role) const
{
  int sz;

    sz = listOfA.size();


  if (!index.isValid())
    return QVariant();

  if (index.row() >= sz || index.row() < 0)
    return QVariant();

  if (role == Qt::DisplayRole)
    {

      _infoA pair = listOfA.at(index.row());


      if (index.column() == 0)
        return pair.path;
      else if (index.column() == 1)
        return pair.number;
      else if (index.column() == 2)
        return pair.name;
      else if (index.column() == 3)
        return pair.artist;
      else if (index.column() == 4)
        return pair.album;
      if (index.column() == 5)
        return pair.genre;

    }
  return QVariant();
}

QVariant
Modelt::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
    return QVariant();


  if (orientation == Qt::Horizontal)
    {
      switch (section)
        {
      case 0:
        return tr("Path");
      case 1:
        return tr("server");
      case 2:
        return tr("netname");
      case 3:
        return tr("path");

      case 4:
        return tr("remark");
      case 5:
        return tr("type");

      default:
        return QVariant();
        }
    }
  return QVariant();
}

bool
Modelt::insertRows(int position, int rows, const QModelIndex &index)
{
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++)
    {
      _infoA pair;

      listOfA.insert(position, pair);

    }

  endInsertRows();
  return true;
}

bool
Modelt::removeRows(int position, int rows, const QModelIndex &index)
{
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; ++row)
    {

      listOfA.removeAt(position);

    }

  endRemoveRows();
  return true;
}

bool
Modelt::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (index.isValid() && role == Qt::EditRole)
    {
      int row = index.row();

      _infoA p = listOfA.value(row);


      if (index.column() == 0)
        p.path = value.toString();
      else if (index.column() == 1)
        p.number = value.toInt();
      else if (index.column() == 2)
        p.name = value.toString();
      else if (index.column() == 3)
        p.artist = value.toString();
      else if (index.column() == 4)
        p.album = value.toString();
      else if (index.column() == 5)
        p.genre = value.toInt();


      else
        return false;

      listOfA.replace(row, p);

      emit
      (dataChanged(index, index));

      return true;
    }

  return false;
}

Qt::ItemFlags
Modelt::flags(const QModelIndex &index) const
{
  if (!index.isValid())
    return Qt::ItemIsEnabled;

  return QAbstractTableModel::flags(index);// | (Qt::ItemIsEditable);
}

