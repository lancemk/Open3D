// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <vector>

#include "Open3D/Container/Device.h"
#include "Open3D/Container/SizeVector.h"

#include "TestUtility/UnitTest.h"

namespace open3d {

class PermuteDevices : public testing::TestWithParam<Device> {
public:
    static std::vector<Device> TestCases() {
#ifdef BUILD_CUDA_MODULE
        return {
                Device("CPU:0"),
                Device("CUDA:0"),
        };
#else
        return {
                Device("CPU:0"),
        };
#endif
    }
};

class PermuteDevicePairs
    : public testing::TestWithParam<std::pair<Device, Device>> {
public:
    static std::vector<std::pair<Device, Device>> TestCases() {
#ifdef BUILD_CUDA_MODULE
        return {
                {Device("CPU:0"), Device("CPU:0")},
                {Device("CPU:0"), Device("CUDA:0")},
                {Device("CUDA:0"), Device("CPU:0")},
                {Device("CUDA:0"), Device("CUDA:0")},
        };
#else
        return {
                {Device("CPU:0"), Device("CPU:0")},
        };
#endif
    }
};

class PermuteSizesDefaultStrides
    : public testing::TestWithParam<std::pair<SizeVector, SizeVector>> {
public:
    static std::vector<std::pair<SizeVector, SizeVector>> TestCases() {
        return {
                {{}, {}},
                {{0}, {1}},
                {{0, 0}, {1, 1}},
                {{0, 1}, {1, 1}},
                {{1, 0}, {1, 1}},
                {{1}, {1}},
                {{1, 2}, {2, 1}},
                {{1, 2, 3}, {6, 3, 1}},
                {{4, 3, 2}, {6, 2, 1}},
                {{2, 0, 3}, {3, 3, 1}},
        };
    }
};

}  // namespace open3d
