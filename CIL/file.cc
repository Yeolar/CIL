#include "CIL/file.h"

#include <unistd.h>
#include <cstdlib>

namespace cil {

String tempfile(const char* suffix) {
  String fname;
  const char* temp_dir = getenv("CIL_TEMP_PATH");
  char defaultTemplate[] = "/tmp/__cil_temp.XXXXXX";
  if (temp_dir == 0 || temp_dir[0] == 0) {
    fname = defaultTemplate;
  } else {
    fname = temp_dir;
    char ech = fname[fname.size() - 1];
    if (ech != '/' && ech != '\\')
      fname = fname + "/";
    fname = fname + "__cil_temp.XXXXXX";
  }
  const int fd = mkstemp((char*)fname.c_str());
  if (fd == -1)
    return String();

  close(fd);
  remove(fname.c_str());
  if (suffix) {
    if (suffix[0] != '.')
      return fname + "." + suffix;
    else
      return fname + suffix;
  }
  return fname;
}

} // namespace cil
