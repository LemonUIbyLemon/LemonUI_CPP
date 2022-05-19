#include "SizeF.hpp"

namespace LemonUI
{
    SizeF::SizeF(const float width, const float height)
    {
        width_ = width;
        height_ = height;
    }

    bool SizeF::IsEmpty()
    {
        return width_ == 0 && height_ == 0;
    }

    float SizeF::GetWidth() const
    {
        return width_;
    }

    float SizeF::GetHeight() const
    {
        return height_;
    }

    void SizeF::SetWidth(const float width)
    {
        width_ = width;
    }
    
    void SizeF::SetHeight(const float height)
    {
        height_ = height;
    }
}
