#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>> &L)
{
  shared_ptr<ListNode<int>> dummy_head = make_shared<ListNode<int>>(0, L);
  shared_ptr<ListNode<int>> node = dummy_head->next;

  while (node) {
    if (node->next && node->data == node->next->data) {
      node->next = node->next->next;
    } else {
      node = node->next;
    }
  }

  return dummy_head->next;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "remove_duplicates_from_sorted_list.cc",
                         "remove_duplicates_from_sorted_list.tsv",
                         &RemoveDuplicates, DefaultComparator{}, param_names);
}
