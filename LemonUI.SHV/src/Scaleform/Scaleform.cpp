#include "pch.hpp"
#include "Scaleform.hpp"
#include "Helpers.hpp"

namespace LemonUI
{
	Scaleform::Scaleform(const std::string& name, const Vec2& pos, const Vec2& size)
		: m_handle{ GRAPHICS::REQUEST_SCALEFORM_MOVIE(const_cast<char*>(name.c_str())) }, m_pos{ pos }, m_size{ size }
	{}
	Scaleform::Scaleform(const std::string& name) : m_handle{ GRAPHICS::REQUEST_SCALEFORM_MOVIE(const_cast<char*>(name.c_str())) }
	{}
	Scaleform::~Scaleform()
	{
		if (this->IsLoaded())
		{
			GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_handle);
		}
	}

	void Scaleform::Set(const Vec2& pos, const Vec2& size)
	{
		this->m_pos = pos;
		this->m_size = size;
	}

	bool Scaleform::IsValid() const
	{
		return this->m_handle != 0;
	}
	bool Scaleform::IsLoaded() const
	{
		return GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_handle);
	}

	void Scaleform::CallFunction(const std::string& name) const
	{
		GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(this->m_handle, name.c_str());
	}

	void Scaleform::StartFunction(const std::string& name) const
	{
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->m_handle, name.c_str());
	}

	void Scaleform::PushParam(const std::string& param) const
	{
		GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(param.c_str());
	}
	void Scaleform::PushParam(const int& param) const
	{
		GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(param);
	}
	void Scaleform::PushParam(const float& param) const
	{
		GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(param);
	}
	void Scaleform::PushParam(const bool& param) const
	{
		GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(param);
	}

	void Scaleform::FinishFunction() const
	{
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	}

	void Scaleform::DrawFullScreen() const
	{
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(this->m_handle, 255, 255, 255, 255, 0);
	}
	void Scaleform::Draw() const
	{
		GRAPHICS::DRAW_SCALEFORM_MOVIE(this->m_handle, this->m_pos.x, this->m_pos.y, this->m_size.x, this->m_size.y, 255, 255, 255, 255, 0);
	}
}