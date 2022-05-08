#include "pch.h"
#include "ScaledText.hpp"

#include "Helpers.hpp"

namespace LemonUI
{
	ScaledText::ScaledText(const std::string& text) : m_text{ text.c_str() }
	{}

	void ScaledText::Draw() const
	{
		if (this->m_text.empty())
		{
			return;
		}

		Vec2 relativePos{};
		ToRelative(this->m_pos.x, this->m_pos.y, &relativePos.x, &relativePos.y);

		HUD::SET_TEXT_FONT(this->m_font);
		HUD::SET_TEXT_SCALE(1.0f, this->m_scale);
		HUD::SET_TEXT_COLOUR((int)m_color.r, (int)m_color.g, (int)m_color.b, (int)m_color.a);
		if (this->m_wrapping)
		{
			switch (this->m_align)
			{
			case Alignment::Left:
				HUD::SET_TEXT_WRAP(relativePos.x, relativePos.x + this->m_wrapSize.x);
				break;
			case Alignment::Center:
				HUD::SET_TEXT_WRAP(relativePos.x - (this->m_wrapSize.x * 0.5f), relativePos.x + (this->m_wrapSize.x * 0.5f));
				break;
			case Alignment::Right:
				HUD::SET_TEXT_WRAP(relativePos.x - this->m_wrapSize.x, relativePos.x);
				break;
			}
		}
		else if (this->m_align == Alignment::Right)
		{
			HUD::SET_TEXT_WRAP(0.0f, relativePos.x);
		}
		HUD::SET_TEXT_JUSTIFICATION((int)this->m_align);

		if (this->m_dropShadow)
		{
			HUD::SET_TEXT_DROP_SHADOW();
		}
		
		if (this->m_outline)
		{
			HUD::SET_TEXT_OUTLINE();
		}

		HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(this->m_text.c_str());

		HUD::END_TEXT_COMMAND_DISPLAY_TEXT(relativePos.x, relativePos.y, 0); // 0 correct?

		// TODO
		if (this->m_background)
		{
			float textLength = (float)this->m_text.size() / 100;
			GRAPHICS::DRAW_RECT(relativePos.x, relativePos.y, textLength, 0.056f, (int)m_bgColor.r, (int)m_bgColor.g, (int)m_bgColor.b, (int)m_bgColor.a, 0);
		}
	}
}