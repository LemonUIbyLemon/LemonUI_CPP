#include "Screen.hpp"

#include <natives.hpp>

#include "Control.hpp"
#include "SizeF.hpp"

namespace LemonUI
{
	float Screen::GetAspectRatio()
	{
		return GRAPHICS::GET_ASPECT_RATIO_(false);
	}

	PointF Screen::GetCursorPositionRelative()
	{
		float cursorX = PAD::GET_CONTROL_NORMAL(0, Control::CursorX);
		float cursorY = PAD::GET_CONTROL_NORMAL(0, Control::CursorY);

		return {cursorX, cursorY};
	}

	void Screen::ToAbsolute(const float relativeX, const float relativeY, float& absoluteX, float& absoluteY)
	{
		// Get the real width based on the aspect ratio
		const float width = 1080.0f * GetAspectRatio();

		// And save the correct values
		absoluteX = width * relativeX;
		absoluteY = 1080.0f * relativeY;
	}

	void Screen::ToRelative(const float absoluteX, const float absoluteY, float& relativeX, float& relativeY)
	{
		// Get the real width based on the aspect ratio
		const float width = 1080.0f * GetAspectRatio();

		// And save the correct values
		relativeX = absoluteX / width;
		relativeY = absoluteY / 1080.0f;
	}

	bool Screen::IsCursorInArea(const PointF& pos, const SizeF& size)
	{
		return IsCursorInArea(pos.GetX(), pos.GetY(), size.GetWidth(), size.GetHeight());
	}

	bool Screen::IsCursorInArea(const float x, const float y, const float width, const float height)
	{
		const PointF cursor = GetCursorPositionRelative();

		float realWidth, realHeight;
		ToRelative(width, height, realWidth, realHeight);
		const PointF realPos = GetRealPosition(x, y).ToRelative();
		const bool isX = cursor.GetX() >= realPos.GetX() && cursor.GetX() <= realPos.GetX() + realWidth;
		const bool isY = cursor.GetY() > realPos.GetY() && cursor.GetY() < realPos.GetY() + realHeight;
		return isX && isY;
	}

	PointF Screen::GetRealPosition(const PointF& og)
	{
		return GetRealPosition(og.GetX(), og.GetY());
	}

	PointF Screen::GetRealPosition(const float x, const float y)
	{
		float relativeX, relativeY;
		// Convert the resolution to relative
		ToRelative(x, y, relativeX, relativeY);

		// Request the real location of the position
		float realX = 0;
		float realY = 0;

		GRAPHICS::GET_SCRIPT_GFX_POSITION_(relativeX, relativeY, &realX, &realY);
		
		float absoluteX, absoluteY;
		ToAbsolute(realX, realY, absoluteX, absoluteY);
		return {absoluteX, absoluteY};
	}

	void Screen::ShowCursorThisFrame()
	{
		HUD::SET_MOUSE_CURSOR_ACTIVE_THIS_FRAME_();
	}

	void Screen::SetElementAlignment(const Alignment horizontal, const GFXAlignment vertical)
	{
		switch (horizontal)
		{
		case Alignment::Left:
			SetElementAlignment(GFXAlignment::Left, vertical);
			break;
		case Alignment::Right:
		case Alignment::Center:
			SetElementAlignment(GFXAlignment::Right, vertical);
			break;
		}
	}

	void Screen::SetElementAlignment(const GFXAlignment horizontal, const GFXAlignment vertical)
	{
		GRAPHICS::SET_SCRIPT_GFX_ALIGN(horizontal, vertical);
		GRAPHICS::SET_SCRIPT_GFX_ALIGN_PARAMS(0, 0, 0, 0);
	}

	void Screen::ResetElementAlignment()
	{
		GRAPHICS::RESET_SCRIPT_GFX_ALIGN();
	}
}
