
#pragma once

#include <memory>
#include <stack>

template <typename TokenType>
class TokenStack
{

public:

    void push(std::unique_ptr<TokenType>& value)
    {
        _stack.push(std::move(value));
    }

    void push(std::unique_ptr<TokenType>&& value)
    {
        _stack.push(std::move(value));
    }

    void pop(std::unique_ptr<TokenType>& value)
    {
        value = std::move(_stack.top());
        _stack.pop();
    }

    const std::unique_ptr<TokenType>& top() const
    {
        return _stack.top();
    }

private:

    std::stack<std::unique_ptr<TokenType>> _stack;

};