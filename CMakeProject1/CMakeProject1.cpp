// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <iostream>
#include <string>
#include <jni.h>
#include <CL/cl.h>

#define PLATFORM_ID 0

int main() {
	std::cout << "Hello CMake." << std::endl;
	jint a = 12;

	cl_int status;
	cl_uint numPlatforms = 0;

	status = clGetPlatformIDs(0, NULL, &numPlatforms);

	if (numPlatforms == 0) {
		std::cout << "No platform detected" << std::endl;
	}
	else {
		std::cout << "Detected: " << numPlatforms << std::endl;
	}

	cl_platform_id* platforms = (cl_platform_id*) malloc(numPlatforms * sizeof(cl_platform_id));
	if (platforms == NULL) {
		std::cout << "malloc platform_id failed" << std::endl;
		return -1;
	}

	status = clGetPlatformIDs(numPlatforms, platforms, NULL);
	if (status != CL_SUCCESS) {
		std::cout << "clGetPlatformIDs failed" << std::endl;
		return -1;
	}

	std::string platformName = "";
	for (int i = 0; i < numPlatforms; i++) {
		char buf[10000];
		std::cout << "Platform: " << i << std::endl;
		status = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, sizeof(buf), buf, NULL);
		if (i == PLATFORM_ID) {
			platformName += buf;
		}
		std::cout << "\tVendor: " << buf << std::endl;
		status = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(buf), buf, NULL);
	}


	cl_uint numDevices = 0;

	cl_platform_id platform = platforms[PLATFORM_ID];
	std::cout << "Using platform: " << PLATFORM_ID << " --> " << platformName << std::endl;

	status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, NULL, &numDevices);

	cl_device_id* devices;
	if (status != CL_SUCCESS) {
		std::cout << "[WARNING] Using CPU, no GPU available" << std::endl;
		status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 0, NULL, &numDevices);
		devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
		status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, numDevices, devices, NULL);
	}
	else {
		devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
		status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, numDevices, devices, NULL);
	}

	cl_context context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);
	if (context == NULL) {
		std::cout << "Context is not NULL" << std::endl;
	}

	cl_command_queue commandQueue = clCreateCommandQueue(context, devices[0], CL_QUEUE_PROFILING_ENABLE, &status);
	if (status != CL_SUCCESS || commandQueue == NULL) {
		std::cout << "Error in create command" << std::endl;
		return -1;
	}

	return 0;
}
