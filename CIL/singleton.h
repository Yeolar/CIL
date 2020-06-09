#pragma once

#include <mutex>

namespace cil {

template <class T>
class Singleton {
 private:
  static T* instance;
  static std::once_flag initInstanceFlag;

  Singleton() = default;
  ~Singleton() = default;

  static void init() {
    instance = new T();
  }

 public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static T* getInstance() {
    std::call_once(initInstanceFlag, Singleton::init);
    return instance;
  }
};

template <class T>
T* Singleton<T>::instance = nullptr;

template <class T>
std::once_flag Singleton<T>::initInstanceFlag;

}  // namespace cil
