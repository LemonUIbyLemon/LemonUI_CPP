#include "pch.h"
#include "ScaledText.hpp"

#include "Helpers.hpp"

#include <natives.hpp>

namespace LemonUI
{
	ScaledText::ScaledText(const char* text) : m_text{ text }
	{}
	ScaledText::ScaledText(const std::string& text) : m_text{ text.c_str() }
	{}

	void ScaledText::Draw()
	{
		if (this->m_text.empty())
		{
			return;
		}

		HUD::SET_TEXT_FONT(this->m_font);
		HUD::SET_TEXT_SCALE(1.0f, this->m_scale);
		HUD::SET_TEXT_COLOUR((int)(this->m_color.r * 255.0f), (int)(this->m_color.g * 255.0f), (int)(this->m_color.b * 255.0f), (int)(this->m_color.a * 255.0f));
		if (this->m_wrapping)
		{
			HUD::SET_TEXT_WRAP(this->m_pos.x, this->m_pos.x + this->m_wrapSize.x);
		}
		else
		{
			HUD::SET_TEXT_WRAP(0.0, 1.0);
		}
		if (this->m_align == Alignment::Center)
		{
			HUD::SET_TEXT_CENTRE(1);
		}
		else
		{
			HUD::SET_TEXT_CENTRE(0);
			HUD::SET_TEXT_RIGHT_JUSTIFY(1);
		}
		if (this->m_dropShadow)
		{
			HUD::SET_TEXT_DROP_SHADOW();
		}
		else
		{
			HUD::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		}
		if (this->m_outline)
		{
			HUD::SET_TEXT_OUTLINE();
		}

		HUD::SET_TEXT_EDGE(1, 0, 0, 0, 205);
		HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(this->m_text.c_str());

		Vec2 relativePos{};
		ToRelative(this->m_pos.x, this->m_pos.y, &relativePos.x, &relativePos.y);
		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(relativePos.x, relativePos.y, 0); // 0 correct?
	}
}