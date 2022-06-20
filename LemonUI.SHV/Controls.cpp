#include "Controls.h"

#include <natives.hpp>

namespace LemonUI
{
	bool Controls::IsUsingController()
	{
		return !PAD::IS_USING_KEYBOARD_(2);
	}

	bool Controls::IsJustPressed(const Control control)
	{
		return PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, control);
	}

	bool Controls::IsPressed(const Control control)
	{
		return PAD::IS_DISABLED_CONTROL_PRESSED(0, control);
	}

	void Controls::DisableAll(const int inputGroup)
	{
		PAD::DISABLE_ALL_CONTROL_ACTIONS(inputGroup);
	}

	void Controls::EnableThisFrame(const Control control)
	{
		PAD::ENABLE_CONTROL_ACTION(0, control);
	}

	void Controls::EnableThisFrame(const std::vector<Control>& controls)
	{
		for (const auto control : controls)
		{
			EnableThisFrame(control);
		}
	}

	void Controls::DisableThisFrame(const Control control)
	{
		PAD::DISABLE_CONTROL_ACTION(0, control, true);
	}
}
