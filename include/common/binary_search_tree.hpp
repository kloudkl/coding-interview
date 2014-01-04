#ifndef CODING_INTERVIEW_BINARY_SEARCH_TREE_HPP_
#define CODING_INTERVIEW_BINARY_SEARCH_TREE_HPP_

#include "common/common.h"

namespace ci {

template<typename T>
class binary_search_tree {
 public:
  binary_search_tree(const T& key);
  virtual ~binary_search_tree();

  void inorder_traverse();
  void preorder_traverse();
  void postorder_traverse();
  virtual void visit_node();

  shared_ptr<binary_search_tree<T> > search(const T& key);
  shared_ptr<binary_search_tree<T> > search(
      shared_ptr<binary_search_tree<T> > node);
  shared_ptr<binary_search_tree<T> > search_iteratively(const T& key);
  shared_ptr<binary_search_tree<T> > search_recursively(const T& key);
  shared_ptr<binary_search_tree<T> > minimum(const T& key);
  shared_ptr<binary_search_tree<T> > maximum(const T& key);

  static shared_ptr<binary_search_tree<T> > successor(
      shared_ptr<binary_search_tree<T> > node);
  shared_ptr<binary_search_tree<T> > successor();
  static shared_ptr<binary_search_tree<T> > predecessor(
      shared_ptr<binary_search_tree<T> > node);
  shared_ptr<binary_search_tree<T> > predecessor();

  static void insert(const shared_ptr<binary_search_tree<T> > root,
                     const shared_ptr<binary_search_tree<T> > node);
  static void insert(const shared_ptr<binary_search_tree<T> > root,
                     const T& key);
  void insert(const shared_ptr<binary_search_tree<T> > node);
  void insert(const T& key);
  static void replace(const shared_ptr<binary_search_tree<T> > root,
                      const shared_ptr<binary_search_tree<T> > old_node,
                      const shared_ptr<binary_search_tree<T> > new_node);
  static void erase(const shared_ptr<binary_search_tree<T> > root,
                    const shared_ptr<binary_search_tree<T> > node);
  static void erase(const shared_ptr<binary_search_tree<T> > root,
                    const T& key);
  void erase(const shared_ptr<binary_search_tree<T> > node);
  void erase(const T& key);

 public:
  shared_ptr<binary_search_tree<T> > left;
  shared_ptr<binary_search_tree<T> > right;
  shared_ptr<binary_search_tree<T> > parent;

  T get_key() const {
    return key_;
  }

  void set_key(T key) {
    key_ = key;
  }

 private:
  T key_;
};

}  // namespace ci

#endif /* CODING_INTERVIEW_BINARY_SEARCH_TREE_HPP_ */
