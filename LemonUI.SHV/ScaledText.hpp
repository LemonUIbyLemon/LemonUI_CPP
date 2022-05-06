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
		ScaledText(const char* text);
		ScaledText(const std::string& text);
		ScaledText() = default;

		void SetPos(const Vec2& pos) { this->m_pos = pos; }
		void SetText(const char* text) { this->m_text = const_cast<char*>(text); }
		void SetText(const std::string& text) { this->m_text = const_cast<char*>(text.c_str()); }
		void SetAlign(const Alignment& align) { this->m_align = align; }
		void SetScale(const float& scale) { this->m_scale = scale; }
		void SetColor(const Vec4& color) { this->m_color = color; }
		void SetFont(const Font& font) { this->m_font = static_cast<int>(font); }
		void SetDropShadow(const bool& value) { this->m_dropShadow = value; }
		void SetOutline(const bool& value) { this->m_outline = value; }
		void SetWrapping(const bool& value, const Vec2& size) { this->m_wrapping = value; this->m_wrapSize = size; }

		void Draw() override;

	private:
		Vec2 m_pos = GetScreenResolution();
		std::string m_text = NULL;

		int m_font = 0;
		Vec4 m_color{};
		float m_scale = 1.0f;
		Alignment m_align = Alignment::Center;

		bool m_dropShadow = false;
		bool m_outline = false;

		bool m_wrapping = false;
		Vec2 m_wrapSize{};
	};
}