#include "TreeNode.h"

TreeNode::TreeNode(const QString &name, TreeNode::ParentPtr parent)
    : name{name}
    , parent_{parent}
{
}
