#if defined(__APPLE__)

#include "DeviceMgrMacOS.h"

#include <tuple> // for std::ignore

MAA_TOOLKIT_DEVICE_NS_BEGIN

size_t DeviceMgrMacOS::find_device(std::string_view adb_path)
{
    // TODO
    std::ignore = adb_path;
    return 0;
}

MAA_TOOLKIT_DEVICE_NS_END

#endif