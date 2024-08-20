#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::shared_ptr;
shared_ptr<ListNode<int>> ListPivoting(const shared_ptr<ListNode<int>> &l,
                                       int x)
{
  shared_ptr<ListNode<int>> less_head(new ListNode<int>);
  shared_ptr<ListNode<int>> eq_head(new ListNode<int>);
  shared_ptr<ListNode<int>> greater_head(new ListNode<int>);
  shared_ptr<ListNode<int>> less_list = less_head;
  shared_ptr<ListNode<int>> eq_list = eq_head;
  shared_ptr<ListNode<int>> greater_list = greater_head;
  shared_ptr<ListNode<int>> head = l;

  while (head) {
    if (head->data < x) {
      less_list->next = head;
      less_list = less_list->next;
    } else if (head->data == x) {
      eq_list->next = head;
      eq_list = eq_list->next;
    } else {
      greater_list->next = head;
      greater_list = greater_list->next;
    }
    head = head->next;
  }

  if (eq_head->next) {
    less_list->next = eq_head->next;
    eq_list->next = greater_head->next;
  } else {
    less_list->next = greater_head->next;
  }
  greater_list->next = nullptr;

  return less_head->next;
}
std::vector<int> ListToVector(const shared_ptr<ListNode<int>> &l)
{
  std::vector<int> v;
  ListNode<int> *it = l.get();
  while (it) {
    v.push_back(it->data);
    it = it->next.get();
  }
  return v;
}

void ListPivotingWrapper(TimedExecutor &executor,
                         const shared_ptr<ListNode<int>> &l, int x)
{
  std::vector<int> original = ListToVector(l);

  std::shared_ptr<ListNode<int>> pivoted_list =
      executor.Run([&] { return ListPivoting(l, x); });

  std::vector<int> pivoted = ListToVector(pivoted_list);
  enum class Mode { kLess, kEq, kGreater } mode = Mode::kLess;
  for (auto &i : pivoted) {
    switch (mode) {
    case Mode::kLess:
      if (i == x) {
        mode = Mode::kEq;
      } else if (i > x) {
        mode = Mode::kGreater;
      }
      break;
    case Mode::kEq:
      if (i < x) {
        throw TestFailure("List is not pivoted");
      } else if (i > x) {
        mode = Mode::kGreater;
      }
      break;
    case Mode::kGreater:
      if (i <= x) {
        throw TestFailure("List is not pivoted");
      }
    }
  }
  std::sort(begin(original), end(original));
  std::sort(begin(pivoted), end(pivoted));
  if (original != pivoted) {
    throw TestFailure("Result list contains different values");
  }
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l", "x"};
  return GenericTestMain(args, "pivot_list.cc", "pivot_list.tsv",
                         &ListPivotingWrapper, DefaultComparator{},
                         param_names);
}
