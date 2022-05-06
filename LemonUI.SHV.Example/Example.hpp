#pragma once

#include <Helpers.hpp>
#include <ScaledText.hpp>
#include <Scaleform.hpp>
#include <NativeMenu.hpp>

#include <string>

class Example
{
private:
	LemonUI::ScaledText* m_scaledText = nullptr;
	LemonUI::Scaleform m_scaleform{ "mp_mm_card_freemode", { 0.122f, 0.3f }, { 0.28f, 0.6f } };
    LemonUI::NativeMenu m_menu{};

	bool m_scaleformFocus = false;

public:
    void InitMenu()
    {
        LemonUI::Vec2 currentRes = LemonUI::GetScreenResolution();
        this->m_menu.SetPosition({ currentRes.x / 2, currentRes.y / 2 });
        this->m_menu.AddItem("The first item");
        this->m_menu.AddItem("The second item");
        this->m_menu.AddItem("The last item");
        this->m_menu.AddItem("Go back");
    }
    void RenderMenu()
    {
        this->m_menu.Render();
    }

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

    void RenderScaleform()
    {
        if (!this->m_scaleformFocus)
        {
            return;
        }

        this->m_scaleform.StartFunction("SET_DATA_SLOT_EMPTY");
        this->m_scaleform.PushParam(0);
        this->m_scaleform.FinishFunction();

        this->m_scaleform.StartFunction("SET_DATA_SLOT");
        this->m_scaleform.PushParam(0);
        this->m_scaleform.PushParam(std::string("16ms"));
        this->m_scaleform.PushParam(std::string("EntenKoeniq"));
        this->m_scaleform.PushParam(116);
        this->m_scaleform.PushParam(0);
        this->m_scaleform.PushParam(0);
        this->m_scaleform.PushParam(std::string(""));
        this->m_scaleform.PushParam(std::string(""));
        this->m_scaleform.PushParam(2);
        this->m_scaleform.PushParam(std::string(""));
        this->m_scaleform.PushParam(std::string(""));
        this->m_scaleform.PushParam(std::string(" "));
        this->m_scaleform.FinishFunction();

        this->m_scaleform.StartFunction("SET_TITLE");
        this->m_scaleform.PushParam(std::string("Player list"));
        this->m_scaleform.PushParam(std::string("1 players"));
        this->m_scaleform.FinishFunction();

        this->m_scaleform.CallFunction("DISPLAY_VIEW");

        this->m_scaleform.Draw();
    }

    void FocusScaleform()
    {
        this->m_scaleformFocus = !this->m_scaleformFocus;
    }
};

extern Example* _pGame = nullptr;