#include "hzpch.h"
#include "ExampleLayer.h"


#include "Hazel/Application.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/KeyCodes.h"

#include "imgui.h"

namespace Hazel {

	ExampleLayer::ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	ExampleLayer::~ExampleLayer()
	{
	}

	void ExampleLayer::OnAttach()
	{

	}

	void ExampleLayer::OnDetach()
	{

	}

	void ExampleLayer::OnUpdate()
	{
		
	}

	void ExampleLayer::OnImGuiRender()
	{
		ImGui::Begin("Text");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void ExampleLayer::OnEvent(Event& event)
	{
		//HZ_TRACE("{0}", event);
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("Tab key is pressed (event)!");
			HZ_TRACE("{0}", (char)e.GetKeyCode());

			event.Handled = true;
		}
	}

}