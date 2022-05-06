#include "pch.h"
#include "Texture.hpp"
#include "Helpers.hpp"

namespace LemonUI
{
	Texture::Texture(const std::string& dict, const std::string& name) : m_dict{ dict }, m_name{ name }
	{}

	Vec2 Texture::GetSize() const
	{
		Vector3 result = GRAPHICS::GET_TEXTURE_RESOLUTION(this->m_dict.c_str(), this->m_name.c_str());
		return { result.x, result.y };
	}

	void Texture::Set(const std::string& dict, const std::string& name)
	{
		this->m_dict = dict;
		this->m_name = name;

		this->EnsureLoaded();
	}

	void Texture::EnsureLoaded() const
	{
		if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(this->m_dict.c_str()))
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(this->m_dict.c_str(), 1);
		}
	}

	void Texture::Render(const Vec2& pos) const
	{
		this->Render(pos, this->GetSize(), 0.0f, { 255.0f });
	}
	void Texture::Render(const Vec2& pos, const Vec2& size) const
	{
		this->Render(pos, size, 0.0f, { 255.0f });
	}
	void Texture::Render(const Vec2& pos, const Vec2& size, const float& heading) const
	{
		this->Render(pos, size, heading, { 255.0f });
	}
	void Texture::Render(const Vec2& pos, const Vec2& size, const float& heading, const Vec4& color) const
	{
		this->EnsureLoaded();

		Vec2 spos = GetScreenScale(GetRectCenter(pos, size));
		Vec2 ssize = GetScreenScale(size);

		GRAPHICS::DRAW_SPRITE(this->m_dict.c_str(), this->m_name.c_str(), spos.x, spos.y, ssize.x, ssize.y, heading, (int)(color.r * 255.0f), (int)(color.g * 255.0f), (int)(color.b * 255.0f), (int)(color.a * 255.0f), 0); // 0 correct?
	}
}