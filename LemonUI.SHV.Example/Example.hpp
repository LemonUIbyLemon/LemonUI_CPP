#pragma once

#include <Helpers.hpp>
#include <ScaledText.hpp>

class Example
{
private:
	LemonUI::ScaledText* m_scaledText = nullptr;

public:
	void RenderScaledText()
	{
		if (this->m_scaledText == nullptr)
		{
			return;
		}
		LemonUI::Vec2 currentRes = LemonUI::GetScreenResolution();
		this->m_scaledText->SetPos({ currentRes.x / 2, currentRes.y - 60 });
		this->m_scaledText->Draw();
	}

	void DeleteCreateScaledText()
	{
		if (this->m_scaledText == nullptr)
		{
			this->m_scaledText = new LemonUI::ScaledText{ "Created with LemonUI.SHV by EntenKoeniq" };
			this->m_scaledText->SetScale(0.35f);
			this->m_scaledText->SetDropShadow(true);
		}
		else
		{
			delete this->m_scaledText;
			this->m_scaledText = nullptr;
		}
	}
};

extern Example* _pGame = nullptr;