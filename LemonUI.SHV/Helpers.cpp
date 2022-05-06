#include "pch.h"
#include "Helpers.hpp"

namespace LemonUI
{
	void ShowNotify(const std::string& message)
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.c_str());
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
	}

	Vec2 GetScreenResolution()
	{
		int width, height;
		GRAPHICS::GET_ACTIVE_SCREEN_RESOLUTION_(&width, &height);
		return { static_cast<float>(width), static_cast<float>(height) };
	}

	float GetAspectRatio()
	{
		return GRAPHICS::GET_ASPECT_RATIO_(0);
	}

	void ToRelative(const float& absoluteX, const float& absoluteY, float* relativeX, float* relativeY)
	{
		Vec2 currentRes = GetScreenResolution();
		float width = currentRes.y * GetAspectRatio();
		*relativeX = absoluteX / width;
		*relativeY = absoluteY / currentRes.y;
	}

	Vec2 GetRectCenter(const Vec2& pos, const Vec2& size)
	{
		return { pos.x + size.x / 2.0f, pos.y + size.y / 2.0f };
	}

	Vec2 GetScreenScale(const Vec2& vec)
	{
		Vec2 currentRes = GetScreenResolution();
		return { vec.x / currentRes.x, vec.y / currentRes.y };
	}
}