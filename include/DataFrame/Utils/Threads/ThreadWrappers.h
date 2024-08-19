/*
Copyright (c) 2024, Hartmut Kaiser
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of Hossein Moein and/or the DataFrame nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Hossein Moein BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#ifndef HMDF_HPX

#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>

namespace hmdf {

    template <typename T>
    using future = std::future<T>;

    template <typename F>
    using packaged_task = std::packaged_task<F>;

    using future_status = std::future_status;

    using condition_variable = std::condition_variable;
    using mutex = std::mutex;
    using thread = std::thread;

    namespace this_thread {

        inline std::thread::id get_id() noexcept
        {
            return std::this_thread::get_id();
        }
    }    // namespace this_thread
}    // namespace hmdf

#else

#include <hpx/condition_variable.hpp>
#include <hpx/future.hpp>
#include <hpx/mutex.hpp>
#include <hpx/thread.hpp>

namespace hmdf {

    template <typename T>
    using future = hpx::future<T>;

    template <typename F>
    using packaged_task = hpx::packaged_task<F>;

    using future_status = hpx::future_status;

    using condition_variable = hpx::condition_variable;
    using mutex = hpx::mutex;
    using thread = hpx::thread;

    namespace this_thread {

        inline hpx::thread::id get_id() noexcept
        {
            return hpx::this_thread::get_id();
        }
    }    // namespace this_thread
}    // namespace hmdf

#endif