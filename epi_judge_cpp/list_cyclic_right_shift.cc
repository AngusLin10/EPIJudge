#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k)
{
  if (L == nullptr || k == 0)
    return L;

  auto tail = L;
  int len = 1;
  while (tail->next) {
    tail = tail->next;
    ++len;
  }
  tail->next = L;
  for (int i = 0; i < len - k % len; ++i) {
    tail = tail->next;
  }

  auto new_head = tail->next;
  tail->next = nullptr;

  return new_head;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(
      1, make_shared<ListNode<int>>(
             2, make_shared<ListNode<int>>(
                    3, make_shared<ListNode<int>>(
                           4, make_shared<ListNode<int>>(5, nullptr)))));
  shared_ptr<ListNode<int>> result = CyclicallyRightShiftList(L, 2);
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
