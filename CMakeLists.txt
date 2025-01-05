cmake_minimum_required(VERSION 3.21)
project(my_project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(absl REQUIRED)
find_package(capstone REQUIRED)
find_package(gRPC REQUIRED)
find_package(GTest REQUIRED)
find_package(outcome REQUIRED)
find_package(LLVM REQUIRED)
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Libssh2 REQUIRED)

if (WITH_VULKAN_DEPS)
    find_package(volk REQUIRED)
    find_package(vulkan-headers REQUIRED)
    find_package(vulkan-validationlayers REQUIRED)
endif()

add_executable(my_project src/main.cpp)
target_link_libraries(my_project PRIVATE
    abseil::abseil
    capstone::capstone
    gRPC::grpc++
    GTest::gtest
    outcome::outcome
    llvm-core::llvm-core
    ZLIB::ZLIB
    OpenSSL::Crypto
    OpenSSL::SSL
    Libssh2::libssh2
)

if (WITH_VULKAN_DEPS)
    target_link_libraries(my_project PRIVATE
        volk::volk
        vulkan-headers::vulkan_headers
        vulkan-validationlayers::Vulkan::ValidationLayers
    )
endif()
