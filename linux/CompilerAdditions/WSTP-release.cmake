#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WSTP64i4" for configuration "Release"
set_property(TARGET WSTP64i4 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WSTP64i4 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP64i4.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS WSTP64i4 )
list(APPEND _IMPORT_CHECK_FILES_FOR_WSTP64i4 "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP64i4.a" )

# Import target "WSTP64i4dyn" for configuration "Release"
set_property(TARGET WSTP64i4dyn APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WSTP64i4dyn PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP64i4.so"
  IMPORTED_SONAME_RELEASE "libWSTP64i4.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS WSTP64i4dyn )
list(APPEND _IMPORT_CHECK_FILES_FOR_WSTP64i4dyn "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP64i4.so" )

# Import target "WSTP32i4" for configuration "Release"
set_property(TARGET WSTP32i4 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WSTP32i4 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP32i4.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS WSTP32i4 )
list(APPEND _IMPORT_CHECK_FILES_FOR_WSTP32i4 "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP32i4.a" )

# Import target "WSTP32i4dyn" for configuration "Release"
set_property(TARGET WSTP32i4dyn APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WSTP32i4dyn PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP32i4.so"
  IMPORTED_SONAME_RELEASE "libWSTP32i4.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS WSTP32i4dyn )
list(APPEND _IMPORT_CHECK_FILES_FOR_WSTP32i4dyn "${_IMPORT_PREFIX}/CompilerAdditions/libWSTP32i4.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
