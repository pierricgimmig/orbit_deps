cmake_minimum_required(VERSION 3.21)
project(my_project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(absl REQUIRED)
find_package(capstone REQUIRED)
find_package(grpc REQUIRED)
find_package(gtest REQUIRED)
find_package(outcome REQUIRED)
find_package(LLVM REQUIRED)
find_package(zlib REQUIRED)
find_package(openssl REQUIRED)
find_package(libssh2 REQUIRED)

if (NOT WIN32)
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

if (NOT WIN32)
    target_link_libraries(my_project PRIVATE
        volk::volk
        vulkan-headers::vulkan_headers
        vulkan-validationlayers::Vulkan::ValidationLayers
    )
endif()
