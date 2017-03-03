#pragma once

#include <QString>
#include <QVector>
#include <memory>

class TreeNode: public std::enable_shared_from_this<TreeNode>
{
public:
    using ChildPtr = std::shared_ptr<TreeNode>;
    using ParentPtr = std::weak_ptr<TreeNode>;

public:
    const QString name;

public:
    explicit TreeNode(const QString &name);

    int childrenCount() const;
    void addChild(const ChildPtr &child);

private:
    void setParent(const ParentPtr &parent);

private:
    ParentPtr parent_;
    QVector<ChildPtr> children_;
};
