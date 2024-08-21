#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2)
{
  shared_ptr<ListNode<int>> dummy_head = make_shared<ListNode<int>>();
  auto curr = dummy_head;
  int carry = 0;

  while (L1 || L2 || carry) {
    int sum = carry + (L1 ? L1->data : 0) + (L2 ? L2->data : 0);
    curr->next = make_shared<ListNode<int>>(sum % 10);
    carry = sum / 10;
    L1 = L1 ? L1->next : nullptr;
    L2 = L2 ? L2->next : nullptr;
    curr = curr->next;
  }

  return dummy_head->next;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "int_as_list_add.cc", "int_as_list_add.tsv",
                         &AddTwoNumbers, DefaultComparator{}, param_names);
}
