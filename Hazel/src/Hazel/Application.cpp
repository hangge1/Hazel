#include "hzpch.h"
#include "Application.h"
#include "Hazel/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Hazel {


	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		HZ_CORE_OBJ_TRACE(e);
		HZ_OBJ_TRACE(e);

		while (m_Running)
		{
			HZ_OBJ_TRACE(e);
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}