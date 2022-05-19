#pragma once

namespace LemonUI
{
    class PointF
    {
    private:
        float x_;
        float y_;
    public:
        PointF(float x, float y);
        bool IsEmpty();
        float GetX() const;
        float GetY() const;
        void SetX(float x);
        void SetY(float y);
    };
}
