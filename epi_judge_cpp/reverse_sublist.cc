#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish)
{
  if (!L) return nullptr;
  shared_ptr<ListNode<int>> dummy = make_shared<ListNode<int>>(0, L);
  shared_ptr<ListNode<int>> p0 = dummy;
  for (int i = 0; i < start - 1; ++i)
    p0 = p0->next;

  shared_ptr<ListNode<int>> prev = nullptr, curr = p0->next;
  for (int i = 0; i < finish - start + 1; ++i) {
    shared_ptr<ListNode<int>> next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  p0->next->next = curr;
  p0->next = prev;

  return dummy->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
