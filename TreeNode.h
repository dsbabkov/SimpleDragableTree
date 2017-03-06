#pragma once

#include <QString>
#include <QVector>
#include <memory>

class TreeNode: public std::enable_shared_from_this<TreeNode>
{
public:
    using ChildPtr = std::shared_ptr<TreeNode>;
    using ConstChildPtr = std::shared_ptr<const TreeNode>;
    using ParentPtr = std::weak_ptr<TreeNode>;
    using ConstParentPtr = std::weak_ptr<const TreeNode>;
    using LockedParentPtr = ChildPtr;
    using ConstLockedParentPtr = ConstChildPtr;

public:
    const QString name;

public:
    explicit TreeNode(const QString &name);

    ParentPtr parent() const;
    int row() const;

    int childrenCount() const;
    void insertChild(const ChildPtr &child, int position = -1);
    void removeChild(const ChildPtr &child);
    ChildPtr child(int row) const;

private:
    void setParent(const ParentPtr &parent);
    void resetChild(int number);
    void moveChild(const ChildPtr &child, int newPosition);

private:
    ParentPtr parent_;
    QVector<ChildPtr> children_;
};
