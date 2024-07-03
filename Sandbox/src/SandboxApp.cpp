
#include <Hazel.h>
#include "Hazel/ImGui/ImGuiLayer.h"


class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}