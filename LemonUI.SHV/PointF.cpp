#include "PointF.hpp"

namespace LemonUI
{
    PointF::PointF(const float x, const float y)
    {
        x_ = x;
        y_ = y;
    }

    bool PointF::IsEmpty()
    {
        return x_ == 0 && y_ == 0;
    }

    float PointF::GetX() const
    {
        return x_;
    }

    float PointF::GetY() const
    {
        return y_;
    }

    void PointF::SetX(const float x)
    {
        x_ = x;
    }
    
    void PointF::SetY(const float y)
    {
        y_ = y;
    }
}
