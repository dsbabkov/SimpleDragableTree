#include "TreeNode.h"

TreeNode::TreeNode(const QString &name)
    : name{name}
    , parent_{}
{
}

TreeNode::ParentPtr TreeNode::parent() const
{
    return parent_;
}

int TreeNode::row() const
{
    if (parent_.expired()){
        return -1;
    }

    return parent_.lock()->children_
            .indexOf(std::const_pointer_cast<TreeNode>(shared_from_this()));
}

int TreeNode::childrenCount() const
{
    return children_.count();
}

void TreeNode::addChild(const TreeNode::ChildPtr &child, int position)
{
    const ParentPtr lastParent = child->parent();
    if (!lastParent.expired()){
        const auto &lockedParent = lastParent.lock();
        lockedParent->removeChild(child);
    }

    if (position == -1){
        children_ << child;
    }
    else{
        children_.insert(position, child);
    }
    child->setParent(shared_from_this());
}

void TreeNode::removeChild(const TreeNode::ChildPtr &child)
{
    const int pos = children_.indexOf(child);
    if (pos != -1){
        children_.takeAt(pos)->setParent({});
    }
}

TreeNode::ChildPtr TreeNode::child(int row) const
{
    return children_.at(row);
}

void TreeNode::setParent(const TreeNode::ParentPtr &parent)
{
    parent_ = parent;
}
