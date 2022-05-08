#pragma once
#include "Vectors.hpp"
#include "Elements/ScaledText.hpp"
#include "Elements/Texture.hpp"
#include "NativeItem.hpp"

#include <string>
#include <vector>

namespace LemonUI
{
	class NativeItem;

	class NativeMenu
	{
	public:
		NativeMenu();
		~NativeMenu();

		NativeItem* AddItem(const std::string& text);
		NativeItem* AddItem();
		void DeleteItem(int index);
		void DeleteItem(NativeItem* item);

		void GoUp();
		void GoDown();

		NativeItem* SelectedItem() const;
		int SelectedIndex() const { return this->m_itemSelected; };

		float ContentsHeight();

		float GetWidth() const { return this->m_width; }

		void SetPosition(const Vec2& pos) { this->m_pos = pos; }

		void Render();

	private:
		Vec2 m_pos{ 128, 256 };
		float m_width = 431.0f;

		bool m_hasBanner = true;

		ScaledText m_title{ "LemonUI" };
		ScaledText m_subTitle{ "Test menu" };

		Texture m_banner{};
		Texture m_background{};

		std::vector<NativeItem*> m_items{};
		int m_itemSelected = 0;
	};
}