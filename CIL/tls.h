#pragma once

#include <vector>

#include "CIL/defs.h"

namespace cil {

class CIL_EXPORTS TLSDataContainer {
 protected:
  TLSDataContainer();
  virtual ~TLSDataContainer();

  void gatherData(std::vector<void*>& data) const;

  void* getData() const;
  void release();

 private:
  virtual void* createDataInstance() const = 0;
  virtual void deleteDataInstance(void* pData) const = 0;

  int key_;
};

// Main TLS data class
template <typename T>
class TLSData : protected TLSDataContainer {
 public:
  TLSData() {}
  ~TLSData() {
    release();
  }  // Release key and delete associated data

  T* get() const {
    return (T*)getData();
  }  // Get data assosiated with key

  // Get data from all threads
  inline void gather(std::vector<T*>& data) const {
    std::vector<void*>& dataVoid = reinterpret_cast<std::vector<void*>&>(data);
    gatherData(dataVoid);
  }

 private:
  virtual void* createDataInstance() const {
    return new T;
  }  // Wrapper to allocate data by template
  virtual void deleteDataInstance(void* pData) const {
    delete (T*)pData;
  }  // Wrapper to release data by template

  // Disable TLS copy operations
  TLSData(const TLSData&) = delete;
  TLSData& operator=(const TLSData&) = delete;
};

} // namespace cil
