#pragma once

#include "Hazel/Core/Base.h"
#include "Hazel/Core/KeyCodes.h"
#include "Hazel/Core/MouseCodes.h"


namespace Hazel {

	//Input 接口类
	//通过暴露public static方法，获得平台相关的调用接口！
	class Input
	{
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		virtual ~Input() = default;
	public:
		inline static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }
		inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		Input() = default;

		virtual bool IsKeyPressedImpl(KeyCode key) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode  button) = 0;

		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Scope<Input> s_Instance;
	};

}