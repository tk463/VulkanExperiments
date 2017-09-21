#pragma once

const int WIDTH = 800;
const int HEIGHT = 600;

class HelloTriangleApp
{
	GLFWwindow* window;
	VkInstance instance;

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();

public:
	HelloTriangleApp();
	~HelloTriangleApp();

	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}
};

