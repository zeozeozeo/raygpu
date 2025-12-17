#include <webgpu/webgpu.h>
#include "include/dawn/native/DawnNative.h"

extern "C" const WGPUChainedStruct* chainDawnStuff() {
    static dawn::native::DawnInstanceDescriptor dawnDesc = {};

    // On Windows, add System32 as an additional search path (for vulkan-1.dll etc)
#if defined(_WIN32)
    static const char* system32Path = "C:\\Windows\\System32\\";
    dawnDesc.additionalRuntimeSearchPathsCount = 1;
    dawnDesc.additionalRuntimeSearchPaths = &system32Path;
#endif

    #if !defined(NDEBUG)
        dawnDesc.backendValidationLevel = dawn::native::Full;
    #else
        dawnDesc.backendValidationLevel = dawn::native::Disabled;
    #endif
    return (WGPUChainedStruct*)&dawnDesc;
}
