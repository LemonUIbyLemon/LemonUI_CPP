#pragma once
#include "IDrawable.hpp"
#include "Alignment.hpp"
#include "Font.hpp"
#include "Vectors.hpp"
#include "Helpers.hpp"

#include <string>

namespace LemonUI
{
	class ScaledText : public IDrawable
	{
	public:
		ScaledText(const std::string& text);
		ScaledText() = default;

		void SetPos(const Vec2& pos) { this->m_pos = pos; }
		void SetText(const std::string& text) { this->m_text = text; }
		void SetAlign(const Alignment& align) { this->m_align = align; }
		void SetScale(const float& scale) { this->m_scale = scale; }
		void SetColor(const Vec4& color) { this->m_color = color; }
		void SetFont(const Font& font) { this->m_font = (int)font; }
		void SetDropShadow(const bool& value) { this->m_dropShadow = value; }
		void SetOutline(const bool& value) { this->m_outline = value; }
		void SetWrapping(const bool& value, const Vec2& size) { this->m_wrapping = value; this->m_wrapSize = size; }
		void SetBackground(const bool& value) { this->m_background = value; }
		void SetBackgroundPos(const Vec2& pos) { this->m_bgPos = pos; }
		void SetBackgroundSize(const Vec2& size) { this->m_bgSize = size; }
		void SetBackgroundColor(const Vec4& color) { this->m_bgColor = color; }

		void Draw() const override;

	private:
		Vec2 m_pos = GetScreenResolution();
		std::string m_text = "";

		int m_font = 0;
		Vec4 m_color{ 255.0f, 255.0f, 255.0f, 255.0f };
		float m_scale = 1.0f;
		Alignment m_align = Alignment::Left;

		bool m_dropShadow = false;
		bool m_outline = false;

		bool m_wrapping = false;
		Vec2 m_wrapSize{};

		bool m_background = false;
		Vec2 m_bgPos{};
		Vec2 m_bgSize{};
		Vec4 m_bgColor{ 75.0f };
	};
}