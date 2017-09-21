#pragma once

const int WIDTH = 800;
const int HEIGHT = 600;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

inline VkResult CreateDebugReportCallbackEXT(const VkInstance instance,
                                             const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkDebugReportCallbackEXT* pCallback)
{
	const auto func = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(
			instance, "vkCreateDebugReportCallbackEXT"));
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pCallback);
	}
	return VK_ERROR_EXTENSION_NOT_PRESENT;
}

inline void DestroyDebugReportCallbackEXT(const VkInstance instance, const VkDebugReportCallbackEXT callback,
                                          const VkAllocationCallbacks* pAllocator)
{
	const auto func = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(vkGetInstanceProcAddr(
		instance, "vkDestroyDebugReportCallbackEXT"));
	if (func != nullptr) {
		func(instance, callback, pAllocator);
	}
}

class HelloTriangleApp
{
	GLFWwindow* window;
	VkInstance instance;
	VkDebugReportCallbackEXT callback;

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();

	bool checkValidationLayerSupport();

	std::vector<const char*> getRequiredExtensions();

	void setupDebugCallback();

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugReportFlagsEXT flags,
		VkDebugReportObjectTypeEXT objType,
		uint64_t obj,
		size_t location,
		int32_t code,
		const char* layerPrefix,
		const char* msg,
		void* userData)
	{
		std::cerr << "validation layer: " << msg << std::endl;

		return VK_FALSE;
	}

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

