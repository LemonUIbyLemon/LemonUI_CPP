#pragma once
#include "IDrawable.hpp"

namespace LemonUI
{
	/// <summary>
	/// Scaleforms are 2D Adobe Flash-like objects.
	/// </summary>
	class IScaleform : public IDrawable
	{
	public:
		/// <summary>
		/// Draws the Scaleform in full screen.
		/// </summary>
		virtual void DrawFullScreen() const = 0;
	};
}
