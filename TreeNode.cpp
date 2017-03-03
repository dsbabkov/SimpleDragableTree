#include "TreeNode.h"

TreeNode::TreeNode(const QString &name, TreeNode::ParentPtr parent)
    : name{name}
    , parent_{parent}
{
    if (!parent_.expired()){
        parent.lock()->addChild(shared_from_this());
    }
}

void TreeNode::addChild(const TreeNode::ChildPtr &child)
{
    children_ << child;
}
