#include "list_node.h"
#include "test_framework/generic_test.h"

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L)
{
  shared_ptr<ListNode<int>> slow = L;
  shared_ptr<ListNode<int>> fast = L;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  shared_ptr<ListNode<int>> first_half_head = L;
  shared_ptr<ListNode<int>> second_half_head = nullptr;
  while (slow) {
    auto temp = slow->next;
    slow->next = second_half_head;
    second_half_head = slow;
    slow = temp;
  }

  while (first_half_head && second_half_head) {
    if (first_half_head->data != second_half_head->data) {
      return false;
    }
    first_half_head = first_half_head->next;
    second_half_head = second_half_head->next;
  }

  return true;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "is_list_palindromic.cc",
                         "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                         DefaultComparator{}, param_names);
}
