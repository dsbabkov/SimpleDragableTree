#include "TreeNode.h"

TreeNode::TreeNode(const QString &name)
    : name{name}
    , parent_{}
{
}

void TreeNode::addChild(const TreeNode::ChildPtr &child)
{
    children_ << child;
    child->setParent(shared_from_this());
}

void TreeNode::setParent(const TreeNode::ParentPtr &parent)
{
    parent_ = parent;
}
