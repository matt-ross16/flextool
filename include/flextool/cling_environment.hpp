#pragma once

#include <base/macros.h>
#include <base/sequence_checker.h>

#include <string>
#include <vector>

namespace base { class FilePath; }

namespace cling_utils { class ClingInterpreter; }

namespace flextool {

/// \note must store data related to cling C++ interpreter
class ScopedClingEnvironment {
public:
  ScopedClingEnvironment();

  ~ScopedClingEnvironment();

  // init with provided settings
  [[nodiscard]] /* do not ignore return value */
  bool init(
    const std::vector<base::FilePath>& scriptFiles
    , const std::vector<std::string>& cling_extra_args);

public:
#if defined(CLING_IS_ON)
  std::unique_ptr<cling_utils::ClingInterpreter> clingInterpreter;

  std::vector<std::string> clingIncludePaths{".", "../"};

  std::vector<std::string> clingInterpreterArgs;
#endif // defined(CLING_IS_ON)

private:
  SEQUENCE_CHECKER(sequence_checker_);

  DISALLOW_COPY_AND_ASSIGN(ScopedClingEnvironment);
};

} // flextool
