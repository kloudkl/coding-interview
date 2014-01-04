#include "common/binary_search_tree.hpp"

#include <iostream>
#include "common/common.h"

namespace ci {
template<typename T>
binary_search_tree<T>::binary_search_tree(const T& key)
    : key_(key) {
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

template<typename T>
binary_search_tree<T>::~binary_search_tree() {
}

template<typename T>
void binary_search_tree<T>::inorder_traverse() {
  left->inorder_traverse();
  visit_node();
  right->inorder_traverse();
}

template<typename T>
void binary_search_tree<T>::preorder_traverse() {
  visit_node();
  left->inorder_traverse();
  right->inorder_traverse();
}

template<typename T>
void binary_search_tree<T>::postorder_traverse() {
  left->inorder_traverse();
  right->inorder_traverse();
  visit_node();
}

template<typename T>
void binary_search_tree<T>::visit_node() {
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::search(const T& key) {
  return search_iteratively(key);
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::search(
    shared_ptr<binary_search_tree<T> > node) {
  return search(node->get_key());
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::search_iteratively(
    const T& key) {
  shared_ptr<const binary_search_tree<T> > node(this);
  while (node != nullptr && key != node->get_key()) {
    if (key < key_) {
      node = left;
    } else {
      node = right;
    }
  }
  return node;
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::search_recursively(
    const T& key) {
  if (key == key_) {
    return shared_ptr<const binary_search_tree<T> >(this);
  } else if (key < key_) {
    return left->search_recursively();
  } else {
    return right->search_recursively();
  }
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::minimum(
    const T& key) {
  shared_ptr<const binary_search_tree<T> > node(this);
  while (node != nullptr) {
    node = node->left;
  }
  return node;
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::maximum(
    const T& key) {
  shared_ptr<const binary_search_tree<T> > node(this);
  while (node != nullptr) {
    node = node->right;
  }
  return node;
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::successor(
    shared_ptr<binary_search_tree<T> > node) {
  if (node->right != nullptr) {
    return node->right->minimum();
  }
  shared_ptr<binary_search_tree<T> > trail = node->parent;
  shared_ptr<const binary_search_tree<T> > current = node;
  while (trail != nullptr && current == trail->right) {
    current = trail;
    trail = trail->parent;
  }
  return trail;

}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::successor() {
  return successor(shared_ptr<binary_search_tree<T> >(this));
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::predecessor(
    shared_ptr<binary_search_tree<T> > node) {
  if (node->left != nullptr) {
    return node->left->maxmimum();
  }
  shared_ptr<const binary_search_tree<T> > trail = node->parent;
  shared_ptr<const binary_search_tree<T> > current = node;
  while (trail != nullptr && current == trail->left) {
    current = trail;
    trail = trail->parent;
  }
  return trail;
}

template<typename T>
shared_ptr<binary_search_tree<T> > binary_search_tree<T>::predecessor() {
  return predecessor(shared_ptr<binary_search_tree<T> >(this));
}

template<typename T>
void binary_search_tree<T>::insert(
    const shared_ptr<binary_search_tree<T> > root,
    const shared_ptr<binary_search_tree<T> > node) {
  shared_ptr<const binary_search_tree<T> > trail = nullptr;
  shared_ptr<const binary_search_tree<T> > current = root;
  while (current != nullptr) {
    trail = current;
    if (node->get_key() < current->get_key()) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  node->parent = trail;
  if (trail == nullptr) {
    root = node;
  } else if (node->get_key() < trail->get_key()) {
    trail->left = node;
  } else {
    trail->right = node;
  }
}

template<typename T>
void binary_search_tree<T>::insert(
    const shared_ptr<binary_search_tree<T> > node) {
  insert(shared_ptr<binary_search_tree<T> >(this), node);
}

template<typename T>
void binary_search_tree<T>::insert(const T& key) {
  insert(shared_ptr<binary_search_tree<T> >(this),
         make_shared<binary_search_tree<T> >(key));
}

template<typename T>
void binary_search_tree<T>::replace(
    const shared_ptr<binary_search_tree<T> > root,
    const shared_ptr<binary_search_tree<T> > old_node,
    const shared_ptr<binary_search_tree<T> > new_node) {
  if (old_node->parent == nullptr) {
    root = new_node;
  } else if (old_node == old_node->parent->left) {
    old_node->parent->left = new_node;
  } else {
    old_node->parent->right = new_node;
  }
  if (new_node != nullptr) {
    new_node->parent = old_node->parent;
  }
}

template<typename T>
void binary_search_tree<T>::erase(
    const shared_ptr<binary_search_tree<T> > root,
    const shared_ptr<binary_search_tree<T> > node) {
  if (node->left == nullptr) {
    replace(root, node, node->right);
  } else if (node->right == nullptr) {
    replace(root, node, node->left);
  } else {
    shared_ptr<binary_search_tree<T> > min_node = node->right->minimum();
    if (min_node->parent != node) {
      replace(root, min_node, min_node->right);
      min_node->right = node->right;
      min_node->right->parent = min_node;
    }
    replace(root, node, min_node);
    min_node->left = node->left;
    min_node->left->parent = min_node;
  }
}

template<typename T>
void binary_search_tree<T>::erase(const shared_ptr<binary_search_tree<T> > root,
                                  const T& key) {
  erase(root, make_shared<binary_search_tree<T> >(key));
}

template<typename T>
void binary_search_tree<T>::erase(
    const shared_ptr<binary_search_tree<T> > node) {
  erase(shared_ptr<binary_search_tree<T> >(this), node);
}

template<typename T>
void binary_search_tree<T>::erase(const T& key) {
  erase(make_shared<binary_search_tree<T> >(key));
}

}  // namespace ci
