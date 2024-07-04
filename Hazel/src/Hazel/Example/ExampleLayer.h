#pragma once

#include "Hazel/Layer.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {

	class HAZEL_API ExampleLayer : public Layer
	{
	public:
		ExampleLayer();
		~ExampleLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		virtual void OnImGuiRender() override;
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
	};

}

