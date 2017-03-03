#include "TreeModel.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return {};
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    return {};
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
