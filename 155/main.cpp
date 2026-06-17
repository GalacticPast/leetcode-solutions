#include <climits>
#include <vector>

class MinStack
{
    std::vector<int> stack;
    std::vector<int> min_stack;

  public:
    MinStack()
    {
    }

    void push(int value)
    {
        stack.push_back(value);
        if (min_stack.empty())
        {
            min_stack.push_back(value);
        }
        else
        {
            if (min_stack[min_stack.size() - 1] < value)
            {
                min_stack.push_back(value);
            }
        }
    }

    void pop()
    {
        int n = stack.size();
        if (n != 0)
        {
            if (min_stack.size() != 0 && stack[n - 1] == min_stack[min_stack.size() - 1])
            {
                min_stack.pop_back();
            }
            stack.pop_back();
        }
    }

    int top()
    {
        if (stack.empty())
            return INT_MIN;
        return stack[stack.size() - 1];
    }

    int getMin()
    {
        int min = 0;
        if (min_stack.size() != 0)
        {
            min = min_stack[min_stack.size() - 1];
        }
        return min;
    }
};
