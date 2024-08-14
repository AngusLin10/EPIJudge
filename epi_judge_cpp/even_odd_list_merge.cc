#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>> &L)
{
  if (!L || !L->next)
    return L;

  auto even = L;
  auto odd = L->next;
  auto odd_head = odd;
  while (odd && odd->next) {
    even->next = odd->next;
    even = even->next;
    odd->next = even->next;
    odd = odd->next;
  }

  even->next = odd_head;
  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}
