#include "Color.hpp"

namespace LemonUI
{
    Color::Color(const std::byte r, const std::byte g, const std::byte b)
    {
        a_ = static_cast<std::byte>(0);
        r_ = r;
        g_ = g;
        b_ = b;
    }
    
    Color::Color(const std::byte a, const std::byte r, const std::byte g, const std::byte b)
    {
        a_ = a;
        r_ = r;
        g_ = g;
        b_ = b;
    }

    std::byte Color::GetA() const
    {
        return a_;
    }

    std::byte Color::GetR() const
    {
        return r_;
    }

    std::byte Color::GetG() const
    {
        return g_;
    }

    std::byte Color::GetB() const
    {
        return b_;
    }

    void Color::SetA(const std::byte a)
    {
        a_ = a;
    }

    void Color::SetR(const std::byte r)
    {
        r_ = r;
    }

    void Color::SetG(const std::byte g)
    {
        g_ = g;
    }

    void Color::SetB(const std::byte b)
    {
        b_ = b;
    }

}
