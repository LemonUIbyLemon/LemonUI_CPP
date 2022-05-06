#include "pch.h"
#include "NativeItem.hpp"

#include "Font.hpp"

namespace LemonUI
{
	NativeItem::NativeItem(NativeMenu* parent)
	{
		this->m_parent = parent;

		this->m_text.SetFont(Font::ChaletLondon);
		this->m_text.SetScale(0.35f);

		this->m_texture.Set("commonmenu", "gradient_nav");
	}

	bool NativeItem::IsHovering() const
	{
		return this->m_parent != nullptr ? this->m_parent->SelectedItem() == this : false;
	}

	void NativeItem::Render(const Vec2& pos)
	{
		if (this->IsHovering())
		{
			this->m_texture.Render(pos, { this->m_parent->GetWidth(), this->m_height });
			this->m_text.SetColor({ 0.0f, 0.0f, 0.0f, 1.0f });
		}
		else
		{
			this->m_text.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
		}

		this->m_text.SetPos({ pos.x + 10.0f, pos.y + 2.0f });
		this->m_text.Draw();
	}
}