#pragma once
#include "NativeMenu.hpp"
#include "ScaledText.hpp"
#include "Texture.hpp"

namespace LemonUI
{
	class NativeMenu;

	class NativeItem
	{
	public:
		NativeItem(NativeMenu* parent);

		void ChangeText(const std::string& text) { this->m_text.SetText(text); }

		float GetHeight() const { return this->m_height; }
		bool IsHovering() const;

		void Render(const Vec2& pos);

	private:
		NativeMenu* m_parent = nullptr;

		float m_height = 38;
		ScaledText m_text{};
		Texture m_texture{};
	};
}