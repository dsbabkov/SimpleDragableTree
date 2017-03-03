#include "TreeModel.h"
#include "TreeNode.h"

using namespace std;

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
    , rootNode_{std::make_shared<TreeNode>("ROOT_NODE")}
{
    fillTreeWithData();
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

void TreeModel::fillTreeWithData()
{
    const std::vector<TreeNode::ChildPtr> groups = {
        make_shared<TreeNode>("Group 0"),
        make_shared<TreeNode>("Group 1"),
        make_shared<TreeNode>("Group 2")
    };

    for (TreeNode::ChildPtr group: groups){
        rootNode_->addChild(group);

        for(int i = 0; i < 5; ++i){
            group->addChild(
                        make_shared<TreeNode>(QStringLiteral("Item %1 of %2").arg(i).arg(group->name))
                        );
        }
    }
}
