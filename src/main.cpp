#include <iostream>

#include <llvm/ADT/ArrayRef.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/iterator.h>
#include <llvm/ADT/iterator_range.h>
#include <llvm/BinaryFormat/COFF.h>
#include <llvm/DebugInfo/DIContext.h>
#include <llvm/DebugInfo/DWARF/DWARFContext.h>
#include <llvm/DebugInfo/DWARF/DWARFDie.h>
#include <llvm/DebugInfo/DWARF/DWARFUnit.h>
#include <llvm/Demangle/Demangle.h>
#include <llvm/Object/Binary.h>
#include <llvm/Object/COFF.h>
#include <llvm/Object/CVDebugRecord.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Object/SymbolicFile.h>
#include <llvm/Support/Casting.h>
#include <llvm/Support/Endian.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/Win64EH.h>

// Test includes from various libraries:
#include <grpc/grpc.h>
#include <gtest/gtest.h>
#include <capstone/capstone.h>
#include <outcome.hpp>
namespace outcome = OUTCOME_V2_NAMESPACE;

#include <llvm/Support/VersionTuple.h>

#include <absl/strings/str_join.h>
#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>
#include <absl/hash/hash.h>
#include <absl/meta/type_traits.h>
#include <absl/strings/str_cat.h>
#include <absl/strings/str_format.h>


#ifndef _WIN32
#include <vulkan/vulkan.h>
#include <volk.h>
#endif
#include <zlib.h>
//#include <openssl/ssl.h>
#include <libssh2.h>

int main() {
    std::cout << "All headers included successfully!" << std::endl;

     // Test gRPC linking
    grpc_init();
    std::cout << "gRPC initialized." << std::endl;
    grpc_shutdown();

    // Test GTest linking (just init)
    int argc = 1;
    char arg0[] = "test";
    char* argv[] = { arg0, nullptr };
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "GTest initialized." << std::endl;

    // Test Abseil linking
    // std::string joined = absl::StrJoin(std::vector<std::string>{"Abseil", "Link", "Test"}, " ");
    // std::cout << "Abseil string: " << joined << std::endl;

    // Test Capstone linking
    csh handle;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) == CS_ERR_OK) {
        std::cout << "Capstone disassembler opened." << std::endl;
        cs_close(&handle);
    } else {
        std::cout << "Capstone failed to open." << std::endl;
    }

    // Test Outcome linking
    outcome::result<int> res = 42;
    if (res) {
        std::cout << "Outcome result: " << res.value() << std::endl;
    }

    // Test LLVM linking
    // llvm::VersionTuple vt(1, 2, 3, 4);
    // std::cout << "LLVM VersionTuple: " << vt.getMajor() << "." << vt.getMinor() 
    //           << "." << vt.getSubminor() << "." << vt.getBuild() << std::endl;

    // Test libssh2 linking
    if (libssh2_init(0) == 0) {
        std::cout << "libssh2 initialized." << std::endl;
        libssh2_exit();
    } else {
        std::cout << "libssh2 initialization failed." << std::endl;
    }

    // Test zlib linking
    z_stream strm{};
    if (deflateInit(&strm, Z_DEFAULT_COMPRESSION) == Z_OK) {
        std::cout << "zlib deflateInit succeeded." << std::endl;
        deflateEnd(&strm);
    } else {
        std::cout << "zlib deflateInit failed." << std::endl;
    }

#ifndef _WIN32
    // Test Volk (Vulkan) linking
    if (volkInitialize() == VK_SUCCESS) {
        std::cout << "Volk initialized successfully." << std::endl;
    } else {
        std::cout << "Volk initialization failed." << std::endl;
    }

    // Test Vulkan call (just listing extensions count)
    uint32_t count = 0;
    VkResult resVulkan = vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr);
    if (resVulkan == VK_SUCCESS) {
        std::cout << "Vulkan enumerated " << count << " extension properties." << std::endl;
    } else {
        std::cout << "Vulkan enumeration failed." << std::endl;
    }
#endif

    std::cout << "All libraries tested for linking successfully!" << std::endl;
    return 0;
}
