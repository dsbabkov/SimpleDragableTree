#include "TreeNode.h"
#include <set>

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

    if (position == -1){
        children_ << child;
    }
    else{
        children_.insert(position, child);
    }

    if (!lastParent.expired()){
        const auto &lockedParent = lastParent.lock();
        lockedParent->removeChild(child);
    }
    child->setParent(shared_from_this());
}

void TreeNode::insertChildren(const QList<TreeNode::ChildPtr> &newChildren, int position)
{
    if (position == -1){
        position = children_.count();
    }

    std::set<TreeNode *> oldParents;

    for (ChildPtr child: newChildren){
        ParentPtr parent = child->parent();
        if (!parent.expired()){
            LockedParentPtr lockedParent = parent.lock();
            oldParents.insert(lockedParent.get());
            lockedParent->resetChild(child->row());
        }

        children_.insert(position++, child);
    }

    for (TreeNode *oldParent: oldParents){
        oldParent->removeNullChildren();
    }
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

void TreeNode::resetChild(int number)
{
    ChildPtr &child = children_[number];
    child->setParent({});
    child.reset();
}

void TreeNode::removeNullChildren()
{
    auto it = std::remove_if(children_.begin(), children_.end(), [](ChildPtr &child){
        return !child;
    });

    children_.erase(it, children_.end());
}
