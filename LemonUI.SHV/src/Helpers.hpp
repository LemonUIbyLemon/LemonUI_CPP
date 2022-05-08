#pragma once
#include "Vectors.hpp"

#include <string>

namespace LemonUI
{
	extern void ShowNotify(const std::string& message);
	extern Vec2 GetScreenResolution();
	extern float GetAspectRatio();
	extern void ToRelative(const float& absoluteX, const float& absoluteY, float* relativeX, float* relativeY);
	extern Vec2 GetRectCenter(const Vec2& pos, const Vec2& size);
	extern Vec2 GetScreenScale(const Vec2& vector);
}