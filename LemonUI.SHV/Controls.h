#pragma once
#include <vector>

#include "Control.hpp"

/**
 * \brief Tools for dealing with controls.
 */
namespace LemonUI::Controls
{
	/**
	 * \brief Gets if the player used a controller for the last input.
	 */
	bool IsUsingController();

	/**
	 * \brief Checks if a control was pressed during the last frame.
	 * \param control The control to check.
	 * \return true if the control was pressed, false otherwise.
	 */
	bool IsJustPressed(Control control);

	/**
	 * \brief Checks if a control is currently pressed.
	 * \param control The control to check.
	 * \return true if the control is pressed, false otherwise.
	 */
	bool IsPressed(Control control);

	/**
	 * \brief Disables all of the controls during the next frame.
	 */
	void DisableAll(int inputGroup = 0);

	/**
	 * \brief Enables a control during the next frame.
	 * \param control The control to enable.
	 */
	void EnableThisFrame(Control control);

	/**
	 * \brief Enables a specific set of controls during the next frame.
	 * \param controls The controls to enable.
	 */
	void EnableThisFrame(const std::vector<Control>& controls);

	/**
	 * \brief Disables a control during the next frame.
	 * \param control The control to disable.
	 */
	void DisableThisFrame(Control control);
}