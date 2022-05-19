#pragma once

namespace LemonUI
{
    class SizeF
    {
    private:
        float width_;
        float height_;
    public:
        SizeF(float width, float height);
        bool IsEmpty();
        float GetWidth() const;
        float GetHeight() const;
        void SetWidth(float width);
        void SetHeight(float height);
    };
}
