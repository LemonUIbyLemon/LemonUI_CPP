#pragma once
#include <cstddef>

namespace LemonUI
{
    class Color
    {
    private:
        std::byte a_;
        std::byte r_;
        std::byte g_;
        std::byte b_;
    public:
        Color(std::byte r, std::byte g, std::byte b);
        Color(std::byte a, std::byte r, std::byte g, std::byte b);
        std::byte GetA() const;
        std::byte GetR() const;
        std::byte GetG() const;
        std::byte GetB() const;
        void SetA(std::byte a);
        void SetR(std::byte r);
        void SetG(std::byte g);
        void SetB(std::byte b);
    };
}
