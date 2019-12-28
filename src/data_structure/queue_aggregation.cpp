/*
    Sliding Window Aggregation (Queue)
    時間計算量 各操作O(1)

    半群の列 a_0, a_1, ..., a_(n-1) を扱うキュー
    演算子*に対して， a_0 * a_1 * ... * a_(n-1) を計算可能

    Usage:
        op: 演算子*

    Verified:
        AGC 038 B Sorting a Segment
*/

#include <cassert>
#include <functional>
#include <stack>

template <typename T> class QueueAggregation {
  private:
    struct Node {
        T val, sum;
    };

    std::stack<Node> front_stack, back_stack;
    const std::function<T(T, T)> op;

  public:
    QueueAggregation(std::function<T(T, T)> op)
        : op(op), front_stack(), back_stack() {}

    bool empty() const { return front_stack.empty() && back_stack.empty(); }

    std::size_t size() const { return front_stack.size() + back_stack.size(); }

    T fold_all() const {
        assert(!empty());
        if (front_stack.empty()) {
            return back_stack.top().sum;
        } else if (back_stack.empty()) {
            return front_stack.top().sum;
        } else {
            return op(front_stack.top().sum, back_stack.top().sum);
        }
    }

    void push(const T &x) {
        if (back_stack.empty()) {
            back_stack.push({x, x});
        } else {
            T s = op(back_stack.top().sum, x);
            back_stack.push({x, s});
        }
    }

    void pop() {
        assert(!empty());
        if (front_stack.empty()) {
            front_stack.push({back_stack.top().val, back_stack.top().val});
            back_stack.pop();
            while (!back_stack.empty()) {
                T s = op(back_stack.top().val, front_stack.top().sum);
                front_stack.push({back_stack.top().val, s});
                back_stack.pop();
            }
        }
        front_stack.pop();
    }

    T front() const { return front_stack.top().val; }
};