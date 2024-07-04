
#include <Hazel.h>
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Example/ExampleLayer.h"


class Sandbox : public Hazel::Application
{
public:

	Sandbox()
	{
		PushLayer(new Hazel::ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}