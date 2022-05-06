#include "pch.h"
#include "NativeMenu.hpp"
#include "GameControl.hpp"

namespace LemonUI
{
	NativeMenu::NativeMenu()
	{
		this->m_title.SetFont(Font::HouseScript);
		this->m_title.SetAlign(Alignment::Center);

		this->m_subTitle.SetFont(Font::ChaletLondon);
		this->m_subTitle.SetScale(0.35f);
		this->m_subTitle.SetColor({ 93.0f, 182.0f, 229.0f, 255.0f });

		this->m_banner.Set("commonmenu", "interaction_bgd");
		this->m_background.Set("commonmenu", "gradient_bgd");
	}

	NativeMenu::~NativeMenu()
	{
		for (NativeItem* i : this->m_items)
		{
			delete i;
		}
	}

	NativeItem* NativeMenu::AddItem()
	{
		NativeItem* item = new NativeItem(this);
		this->m_items.push_back(item);
		return item;
	}
	NativeItem* NativeMenu::AddItem(const std::string& name)
	{
		NativeItem* item = this->AddItem();
		item->ChangeText(name);
		return item;
	}

	void NativeMenu::DeleteItem(int index)
	{
		if (index < 0 || index >= this->m_items.size())
		{
			return;
		}

		delete this->m_items[index];
		this->m_items.erase(this->m_items.begin() + index);
	}
	void NativeMenu::DeleteItem(NativeItem* item)
	{
		std::vector<NativeItem*>::iterator it = std::find(this->m_items.begin(), this->m_items.end(), item);
		if (it != this->m_items.end())
		{
			this->m_items.erase(it);
		}
		delete item;
	}

	void NativeMenu::GoUp()
	{
		this->m_itemSelected--;
		if (this->m_itemSelected < 0)
		{
			this->m_itemSelected = (int)this->m_items.size() - 1;
		}

		AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
		AUDIO::RELEASE_SOUND_ID(AUDIO::GET_SOUND_ID());
	}
	void NativeMenu::GoDown()
	{
		this->m_itemSelected++;
		if (this->m_itemSelected >= this->m_items.size())
		{
			this->m_itemSelected = 0;
		}

		AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
		AUDIO::RELEASE_SOUND_ID(AUDIO::GET_SOUND_ID());
	}

	NativeItem* NativeMenu::SelectedItem() const
	{
		return (this->m_itemSelected < 0 || this->m_itemSelected >= this->m_items.size()) ? nullptr : this->m_items[this->m_itemSelected];
	}

	float NativeMenu::ContentsHeight()
	{
		float ret = 0.0f;
		for (NativeItem* item : this->m_items)
		{
			ret += item->GetHeight();
		}

		return ret;
	}

	void NativeMenu::Render()
	{
		if (this->m_items.size() > 0)
		{
			if (PAD::IS_CONTROL_JUST_PRESSED(0, (int)GameControl::GC_PhoneUp))
			{
				this->GoUp();
			}
			else if (PAD::IS_CONTROL_JUST_PRESSED(0, (int)GameControl::GC_PhoneDown))
			{
				this->GoDown();
			}
		}

		Vec2 cursor = this->m_pos;
		if (this->m_hasBanner)
		{
			Vec2 titleRender{ cursor.x + (this->m_width / 2.0f), cursor.y + 20.0f };
			this->m_title.SetPos(titleRender);
			this->m_title.Draw();
			this->m_banner.Render(cursor, { this->m_width, 107.0f });
			cursor = { cursor.x, cursor.y + 107.0f };
		}

		Vec2 subTitleRender{ cursor.x + 10.0f, cursor.y + 2.0f };
		this->m_subTitle.SetPos(subTitleRender);
		this->m_subTitle.Draw();
		cursor = { cursor.x, cursor.y + 37.0f };

		this->m_background.Render(cursor, { this->m_width, this->ContentsHeight() });

		for (int i = 0; i < this->m_items.size(); i++)
		{
			NativeItem* item = this->m_items[i];
			item->Render(cursor);
			cursor = { cursor.x, cursor.y + item->GetHeight() };
		}
	}
}