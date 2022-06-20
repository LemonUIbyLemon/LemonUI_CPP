#pragma once
#include "Alignment.hpp"
#include "PointF.hpp"

namespace LemonUI
{
	class SizeF;
}

/**
 * \brief Contains a set of tools to work with the screen information.
 */
namespace LemonUI::Screen
{
	/**
	 * \brief Represents the internal alignment of screen elements.
	 */
	enum GFXAlignment
	{
		/**
		 * \brief Vertical Alignment to the Bottom.
		 */
		Bottom = 66,
		/**
		 * \brief Vertical Alignment to the Top.
		 */
		Top = 84,
		/**
		 * \brief Centered Vertically or Horizontally.
		 */
		Center = 67,
		/**
		 * \brief Horizontal Alignment to the Left.
		 */
		Left = 76,
		/**
		 * \brief Horizontal Alignment to the Right.
		 */
		Right = 82
	};

	/**
	 * \brief The Aspect Ratio of the screen resolution.
	 */
	float GetAspectRatio();

	/**
	 * \brief The location of the cursor on screen between 0 and 1.
	 */
	PointF GetCursorPositionRelative();

	/**
	 * \brief Converts a relative resolution into one scaled to 1080p.
	 * \param relativeX The relative value of X.
	 * \param relativeY The relative value of Y.
	 * \param absoluteX The value of X scaled to 1080p.
	 * \param absoluteY The value of Y scaled to 1080p.
	 */
	void ToAbsolute(float relativeX, float relativeY, float& absoluteX, float& absoluteY);

	/**
	 * \brief Converts a relative resolution into one scaled to 1080p.
	 * \param absoluteX The 1080p based X coord.
	 * \param absoluteY The 1080p based Y coord.
	 * \param relativeX The value of X converted to relative.
	 * \param relativeY The value of Y converted to relative.
	 */
	void ToRelative(float absoluteX, float absoluteY, float& relativeX, float& relativeY);

	/**
	 * \brief Checks if the cursor is inside of the specified area.
	 * \param pos The start of the area.
	 * \param size The size of the area to check.
	 * \return true if the cursor is in the specified bounds, false otherwise.
	 */
	bool IsCursorInArea(const PointF& pos, const SizeF& size);

	/**
	 * \brief Checks if the cursor is inside of the specified area.
	 * \param x The start X position.
	 * \param y The start Y position.
	 * \param width The height of the search area from X.
	 * \param height The height of the search area from Y.
	 * \return true if the cursor is in the specified bounds, false otherwise.
	 */
	bool IsCursorInArea(float x, float y, float width, float height);

	/**
	 * \brief Converts the specified position into one that is aware of 'SetElementAlignment(GFXAlignment, GFXAlignment)'.
	 * \param og The original 1080p based position.
	 * \return A new 1080p based position that is aware of the the Alignment.
	 */
	PointF GetRealPosition(const PointF& og);

	/**
	 * \brief Converts the specified position into one that is aware of 'SetElementAlignment(GFXAlignment, GFXAlignment)'.
	 * \param x The 1080p based X position.
	 * \param y The 1080p based Y position.
	 * \return A new 1080p based position that is aware of the the Alignment.
	 */
	PointF GetRealPosition(float x, float y);

	/**
	 * \brief Shows the cursor during the current game frame.
	 */
	void ShowCursorThisFrame();

	/**
	 * \brief Sets the alignment of game elements like 'Elements.ScaledRectangle', 'Elements.ScaledText' and 'Elements.ScaledTexture'.
	 * \param horizontal The Horizontal alignment of the items.
	 * \param vertical The vertical alignment of the items.
	 */
	void SetElementAlignment(Alignment horizontal, GFXAlignment vertical);

	/**
	 * \brief Sets the alignment of game elements like 'Elements.ScaledRectangle', 'Elements.ScaledText' and 'Elements.ScaledTexture'.
	 * \param horizontal The Horizontal alignment of the items.
	 * \param vertical The vertical alignment of the items.
	 */
	void SetElementAlignment(GFXAlignment horizontal, GFXAlignment vertical);

	/**
	 * \brief Resets the alignment of the game elements.
	 */
	void ResetElementAlignment();
}
