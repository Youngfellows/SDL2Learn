#.rst:
# FeatureSummary
# --------------
#
# Macros for generating a summary of enabled/disabled features
#
#
#
# This module provides the macros feature_summary(),
# set_package_properties() and add_feature_info().  For compatibility it
# also still provides set_package_info(), set_feature_info(),
# print_enabled_features() and print_disabled_features().
#
# These macros can be used to generate a summary of enabled and disabled
# packages and/or feature for a build tree:
#
# ::
#
#     -- The following OPTIONAL packages have been found:
#     LibXml2 (required version >= 2.4), XML processing lib, <http://xmlsoft.org>
#        * Enables HTML-import in MyWordProcessor
#        * Enables odt-export in MyWordProcessor
#     PNG , A PNG image library. , <http://www.libpng.org/pub/png/>
#        * Enables saving screenshots
#     -- The following OPTIONAL packages have not been found:
#     Lua51 , The Lua scripting language. , <http://www.lua.org>
#        * Enables macros in MyWordProcessor
#     Foo , Foo provides cool stuff.
#
#
#
#
#
# ::
#
#     FEATURE_SUMMARY( [FILENAME <file>]
#                      [APPEND]
#                      [VAR <variable_name>]
#                      [INCLUDE_QUIET_PACKAGES]
#                      [FATAL_ON_MISSING_REQUIRED_PACKAGES]
#                      [DESCRIPTION "Found packages:"]
#                      WHAT (ALL | PACKAGES_FOUND | PACKAGES_NOT_FOUND
#                           | ENABLED_FEATURES | DISABLED_FEATURES)
#                    )
#
#
#
# The FEATURE_SUMMARY() macro can be used to print information about
# enabled or disabled packages or features of a project.  By default,
# only the names of the features/packages will be printed and their
# required version when one was specified.  Use SET_PACKAGE_PROPERTIES()
# to add more useful information, like e.g.  a download URL for the
# respective package or their purpose in the project.
#
# The WHAT option is the only mandatory option.  Here you specify what
# information will be printed:
#
# ``ALL``
#  print everything
# ``ENABLED_FEATURES``
#  the list of all features which are enabled
# ``DISABLED_FEATURES``
#  the list of all features which are disabled
# ``PACKAGES_FOUND``
#  the list of all packages which have been found
# ``PACKAGES_NOT_FOUND``
#  the list of all packages which have not been found
# ``OPTIONAL_PACKAGES_FOUND``
#  only those packages which have been found which have the type OPTIONAL
# ``OPTIONAL_PACKAGES_NOT_FOUND``
#  only those packages which have not been found which have the type OPTIONAL
# ``RECOMMENDED_PACKAGES_FOUND``
#  only those packages which have been found which have the type RECOMMENDED
# ``RECOMMENDED_PACKAGES_NOT_FOUND``
#  only those packages which have not been found which have the type RECOMMENDED
# ``REQUIRED_PACKAGES_FOUND``
#  only those packages which have been found which have the type REQUIRED
# ``REQUIRED_PACKAGES_NOT_FOUND``
#  only those packages which have not been found which have the type REQUIRED
# ``RUNTIME_PACKAGES_FOUND``
#  only those packages which have been found which have the type RUNTIME
# ``RUNTIME_PACKAGES_NOT_FOUND``
#  only those packages which have not been found which have the type RUNTIME
#
# With the exception of the ``ALL`` value, these values can be combined
# in order to customize the output. For example:
#
# ::
#
#    feature_summary(WHAT ENABLED_FEATURES DISABLED_FEATURES)
#
#
#
# If a FILENAME is given, the information is printed into this file.  If
# APPEND is used, it is appended to this file, otherwise the file is
# overwritten if it already existed.  If the VAR option is used, the
# information is "printed" into the specified variable.  If FILENAME is
# not used, the information is printed to the terminal.  Using the
# DESCRIPTION option a description or headline can be set which will be
# printed above the actual content.  If INCLUDE_QUIET_PACKAGES is given,
# packages which have been searched with find_package(...  QUIET) will
# also be listed.  By default they are skipped.  If
# FATAL_ON_MISSING_REQUIRED_PACKAGES is given, CMake will abort if a
# package which is marked as REQUIRED has not been found.
#
# Example 1, append everything to a file:
#
# ::
#
#    feature_summary(WHAT ALL
#                    FILENAME ${CMAKE_BINARY_DIR}/all.log APPEND)
#
#
#
# Example 2, print the enabled features into the variable
# enabledFeaturesText, including QUIET packages:
#
# ::
#
#    feature_summary(WHAT ENABLED_FEATURES
#                    INCLUDE_QUIET_PACKAGES
#                    DESCRIPTION "Enabled Features:"
#                    VAR enabledFeaturesText)
#    message(STATUS "${enabledFeaturesText}")
#
#
#
#
#
# ::
#
#     SET_PACKAGE_PROPERTIES(<name> PROPERTIES
#                            [ URL <url> ]
#                            [ DESCRIPTION <description> ]
#                            [ TYPE (RUNTIME|OPTIONAL|RECOMMENDED|REQUIRED) ]
#                            [ PURPOSE <purpose> ]
#                           )
#
#
#
# Use this macro to set up information about the named package, which
# can then be displayed via FEATURE_SUMMARY().  This can be done either
# directly in the Find-module or in the project which uses the module
# after the find_package() call.  The features for which information can
# be set are added automatically by the find_package() command.
#
# URL: this should be the homepage of the package, or something similar.
# Ideally this is set already directly in the Find-module.
#
# DESCRIPTION: A short description what that package is, at most one
# sentence.  Ideally this is set already directly in the Find-module.
#
# TYPE: What type of dependency has the using project on that package.
# Default is OPTIONAL.  In this case it is a package which can be used
# by the project when available at buildtime, but it also work without.
# RECOMMENDED is similar to OPTIONAL, i.e.  the project will build if
# the package is not present, but the functionality of the resulting
# binaries will be severly limited.  If a REQUIRED package is not
# available at buildtime, the project may not even build.  This can be
# combined with the FATAL_ON_MISSING_REQUIRED_PACKAGES argument for
# feature_summary().  Last, a RUNTIME package is a package which is
# actually not used at all during the build, but which is required for
# actually running the resulting binaries.  So if such a package is
# missing, the project can still be built, but it may not work later on.
# If set_package_properties() is called multiple times for the same
# package with different TYPEs, the TYPE is only changed to higher TYPEs
# ( RUNTIME < OPTIONAL < RECOMMENDED < REQUIRED ), lower TYPEs are
# ignored.  The TYPE property is project-specific, so it cannot be set
# by the Find-module, but must be set in the project.
#
# PURPOSE: This describes which features this package enables in the
# project, i.e.  it tells the user what functionality he gets in the
# resulting binaries.  If set_package_properties() is called multiple
# times for a package, all PURPOSE properties are appended to a list of
# purposes of the package in the project.  As the TYPE property, also
# the PURPOSE property is project-specific, so it cannot be set by the
# Find-module, but must be set in the project.
#
#
#
# Example for setting the info for a package:
#
# ::
#
#    find_package(LibXml2)
#    set_package_properties(LibXml2 PROPERTIES
#                           DESCRIPTION "A XML processing library."
#                           URL "http://xmlsoft.org/")
#
#
#
# ::
#
#    set_package_properties(LibXml2 PROPERTIES
#                           TYPE RECOMMENDED
#                           PURPOSE "Enables HTML-import in MyWordProcessor")
#    ...
#    set_package_properties(LibXml2 PROPERTIES
#                           TYPE OPTIONAL
#                           PURPOSE "Enables odt-export in MyWordProcessor")
#
#
#
# ::
#
#    find_package(DBUS)
#    set_package_properties(DBUS PROPERTIES
#      TYPE RUNTIME
#      PURPOSE "Necessary to disable the screensaver during a presentation" )
#
#
#
# ::
#
#     ADD_FEATURE_INFO(<name> <enabled> <description>)
#
# Use this macro to add information about a feature with the given
# <name>.  <enabled> contains whether this feature is enabled or not,
# <description> is a text describing the feature.  The information can
# be displayed using feature_summary() for ENABLED_FEATURES and
# DISABLED_FEATURES respectively.
#
# Example for setting the info for a feature:
#
# ::
#
#    option(WITH_FOO "Help for foo" ON)
#    add_feature_info(Foo WITH_FOO "The Foo feature provides very cool stuff.")
#
#
#
#
#
# The following macros are provided for compatibility with previous
# CMake versions:
#
# ::
#
#     SET_PACKAGE_INFO(<name> <description> [<url> [<purpose>] ] )
#
# Use this macro to set up information about the named package, which
# can then be displayed via FEATURE_SUMMARY().  This can be done either
# directly in the Find-module or in the project which uses the module
# after the find_package() call.  The features for which information can
# be set are added automatically by the find_package() command.
#
# ::
#
#     PRINT_ENABLED_FEATURES()
#
# Does the same as FEATURE_SUMMARY(WHAT ENABLED_FEATURES DESCRIPTION
# "Enabled features:")
#
# ::
#
#     PRINT_DISABLED_FEATURES()
#
# Does the same as FEATURE_SUMMARY(WHAT DISABLED_FEATURES DESCRIPTION
# "Disabled features:")
#
# ::
#
#     SET_FEATURE_INFO(<name> <description> [<url>] )
#
# Does the same as SET_PACKAGE_INFO(<name> <description> <url> )

#=============================================================================
# Copyright 2007-2015 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

include("${CMAKE_CURRENT_LIST_DIR}/CMakeParseArguments.cmake")


function(ADD_FEATURE_INFO _name _enabled _desc)
  if (${_enabled})
    set_property(GLOBAL APPEND PROPERTY ENABLED_FEATURES "${_name}")
  else ()
    set_property(GLOBAL APPEND PROPERTY DISABLED_FEATURES "${_name}")
  endif ()

  set_property(GLOBAL PROPERTY _CMAKE_${_name}_DESCRIPTION "${_desc}" )
endfunction()



function(SET_PACKAGE_PROPERTIES _name _props)
  if(NOT "${_props}" STREQUAL "PROPERTIES")
    message(FATAL_ERROR "PROPERTIES keyword is missing in SET_PACKAGE_PROPERTIES() call.")
  endif()

  set(options ) # none
  set(oneValueArgs DESCRIPTION URL TYPE PURPOSE )
  set(multiValueArgs ) # none

  CMAKE_PARSE_ARGUMENTS(_SPP "${options}" "${oneValueArgs}" "${multiValueArgs}"  ${ARGN})

  if(_SPP_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unknown keywords given to SET_PACKAGE_PROPERTIES(): \"${_SPP_UNPARSED_ARGUMENTS}\"")
  endif()

  if(_SPP_DESCRIPTION)
    get_property(_info  GLOBAL PROPERTY _CMAKE_${_name}_DESCRIPTION)
    if(_info AND NOT "${_info}" STREQUAL "${_SPP_DESCRIPTION}")
      message(STATUS "Warning: Property DESCRIPTION for package ${_name} already set to \"${_info}\", overriding it with \"${_SPP_DESCRIPTION}\"")
    endif()

    set_property(GLOBAL PROPERTY _CMAKE_${_name}_DESCRIPTION "${_SPP_DESCRIPTION}" )
  endif()


  if(_SPP_URL)
    get_property(_info  GLOBAL PROPERTY _CMAKE_${_name}_URL)
    if(_info AND NOT "${_info}" STREQUAL "${_SPP_URL}")
      message(STATUS "Warning: Property URL already set to \"${_info}\", overriding it with \"${_SPP_URL}\"")
    endif()

    set_property(GLOBAL PROPERTY _CMAKE_${_name}_URL "${_SPP_URL}" )
  endif()


  # handle the PURPOSE: use APPEND, since there can be multiple purposes for one package inside a project
  if(_SPP_PURPOSE)
    set_property(GLOBAL APPEND PROPERTY _CMAKE_${_name}_PURPOSE "${_SPP_PURPOSE}" )
  endif()

  # handle the TYPE
  if(NOT _SPP_TYPE)
    set(_SPP_TYPE OPTIONAL)
  endif()

  # List the supported types, according to their priority
  set(validTypes "RUNTIME" "OPTIONAL" "RECOMMENDED" "REQUIRED" )
  list(FIND validTypes ${_SPP_TYPE} _typeIndexInList)
  if("${_typeIndexInList}" STREQUAL "-1" )
    message(FATAL_ERROR "Bad package property type ${_SPP_TYPE} used in SET_PACKAGE_PROPERTIES(). "
                        "Valid types are OPTIONAL, RECOMMENDED, REQUIRED and RUNTIME." )
  endif()

  get_property(_previousType  GLOBAL PROPERTY _CMAKE_${_name}_TYPE)
  list(FIND validTypes "${_previousType}" _prevTypeIndexInList)

  # make sure a previously set TYPE is not overridden with a lower new TYPE:
  if("${_typeIndexInList}" GREATER "${_prevTypeIndexInList}")
    set_property(GLOBAL PROPERTY _CMAKE_${_name}_TYPE "${_SPP_TYPE}" )
  endif()

endfunction()



function(_FS_GET_FEATURE_SUMMARY _property _var _includeQuiet)

  set(_type "ANY")
  if("${_property}" MATCHES "REQUIRED_")
    set(_type "REQUIRED")
  elseif("${_property}" MATCHES "RECOMMENDED_")
    set(_type "RECOMMENDED")
  elseif("${_property}" MATCHES "RUNTIME_")
    set(_type "RUNTIME")
  elseif("${_property}" MATCHES "OPTIONAL_")
    set(_type "OPTIONAL")
  endif()

  if("${_property}" MATCHES "PACKAGES_FOUND")
    set(_property "PACKAGES_FOUND")
  elseif("${_property}" MATCHES "PACKAGES_NOT_FOUND")
    set(_property "PACKAGES_NOT_FOUND")
  endif()


  set(_currentFeatureText "")
  get_property(_EnabledFeatures  GLOBAL PROPERTY ${_property})

  foreach(_currentFeature ${_EnabledFeatures})

    # does this package belong to the type we currently want to list ?
    get_property(_currentType  GLOBAL PROPERTY _CMAKE_${_currentFeature}_TYPE)
    if(NOT _currentType)
      set(_currentType OPTIONAL)
    endif()

    if("${_type}" STREQUAL ANY  OR  "${_type}" STREQUAL "${_currentType}")

      # check whether the current feature/package should be in the output depending on whether it was QUIET or not
      set(includeThisOne TRUE)
      # skip QUIET packages, except if they are REQUIRED or INCLUDE_QUIET_PACKAGES has been set
      if((NOT "${_currentType}" STREQUAL "REQUIRED") AND NOT _includeQuiet)
        get_property(_isQuiet  GLOBAL PROPERTY _CMAKE_${_currentFeature}_QUIET)
        if(_isQuiet)
          set(includeThisOne FALSE)
        endif()
      endif()
      get_property(_isTransitiveDepend
        GLOBAL PROPERTY _CMAKE_${_currentFeature}_TRANSITIVE_DEPENDENCY
      )
      if(_isTransitiveDepend)
        set(includeThisOne FALSE)
      endif()

      if(includeThisOne)

        set(_currentFeatureText "${_currentFeatureText}\n * ${_currentFeature}")
        get_property(_info  GLOBAL PROPERTY _CMAKE_${_currentFeature}_REQUIRED_VERSION)
        if(_info)
          set(_currentFeatureText "${_currentFeatureText} (required version ${_info})")
        endif()
        get_property(_info  GLOBAL PROPERTY _CMAKE_${_currentFeature}_DESCRIPTION)
        if(_info)
          set(_currentFeatureText "${_currentFeatureText} , ${_info}")
        endif()
        get_property(_info  GLOBAL PROPERTY _CMAKE_${_currentFeature}_URL)
        if(_info)
          set(_currentFeatureText "${_currentFeatureText} , <${_info}>")
        endif()

        get_property(_info  GLOBAL PROPERTY _CMAKE_${_currentFeature}_PURPOSE)
        foreach(_purpose ${_info})
          set(_currentFeatureText "${_currentFeatureText}\n   ${_purpose}")
        endforeach()

      endif()

    endif()

  endforeach()
  set(${_var} "${_currentFeatureText}" PARENT_SCOPE)
endfunction()



function(FEATURE_SUMMARY)
# CMAKE_PARSE_ARGUMENTS(<prefix> <options> <one_value_keywords> <multi_value_keywords> args...)
  set(options APPEND INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
  set(oneValueArgs FILENAME VAR DESCRIPTION)
  set(multiValueArgs WHAT)

  CMAKE_PARSE_ARGUMENTS(_FS "${options}" "${oneValueArgs}" "${multiValueArgs}"  ${_FIRST_ARG} ${ARGN})

  if(_FS_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unknown keywords given to FEATURE_SUMMARY(): \"${_FS_UNPARSED_ARGUMENTS}\"")
  endif()

  if(NOT _FS_WHAT)
    message(FATAL_ERROR "The call to FEATURE_SUMMARY() doesn't set the required WHAT argument.")
  endif()

  set(validWhatParts "ENABLED_FEATURES"
                     "DISABLED_FEATURES"
                     "PACKAGES_FOUND"
                     "PACKAGES_NOT_FOUND"
                     "OPTIONAL_PACKAGES_FOUND"
                     "OPTIONAL_PACKAGES_NOT_FOUND"
                     "RECOMMENDED_PACKAGES_FOUND"
                     "RECOMMENDED_PACKAGES_NOT_FOUND"
                     "REQUIRED_PACKAGES_FOUND"
                     "REQUIRED_PACKAGES_NOT_FOUND"
                     "RUNTIME_PACKAGES_FOUND"
                     "RUNTIME_PACKAGES_NOT_FOUND")

  list(FIND validWhatParts "${_FS_WHAT}" indexInList)
  if(NOT "${indexInList}" STREQUAL "-1")
    _FS_GET_FEATURE_SUMMARY( ${_FS_WHAT} _featureSummary ${_FS_INCLUDE_QUIET_PACKAGES} )
    set(_fullText "${_FS_DESCRIPTION}${_featureSummary}\n")
    if (("${_FS_WHAT}" STREQUAL "REQUIRED_PACKAGES_NOT_FOUND") AND _featureSummary)
      set(requiredPackagesNotFound TRUE)
    endif()

  else()
    if("${_FS_WHAT}" STREQUAL "ALL")

      set(allWhatParts "ENABLED_FEATURES"
                       "RUNTIME_PACKAGES_FOUND"
                       "OPTIONAL_PACKAGES_FOUND"
                       "RECOMMENDED_PACKAGES_FOUND"
                       "REQUIRED_PACKAGES_FOUND"

                       "DISABLED_FEATURES"
                       "RUNTIME_PACKAGES_NOT_FOUND"
                       "OPTIONAL_PACKAGES_NOT_FOUND"
                       "RECOMMENDED_PACKAGES_NOT_FOUND"
                       "REQUIRED_PACKAGES_NOT_FOUND"
      )

    else()
      set(allWhatParts)
      foreach(part ${_FS_WHAT})
        list(FIND validWhatParts "${part}" indexInList)
        if(NOT "${indexInList}" STREQUAL "-1")
          list(APPEND allWhatParts "${part}")
        else()
          if("${part}" STREQUAL "ALL")
            message(FATAL_ERROR "The WHAT argument of FEATURE_SUMMARY() contains ALL, which cannot be combined with other values.")
          else()
            message(FATAL_ERROR "The WHAT argument of FEATURE_SUMMARY() contains ${part}, which is not a valid value.")
          endif()
        endif()
      endforeach()
    endif()

    set(title_ENABLED_FEATURES               "The following features have been enabled:")
    set(title_DISABLED_FEATURES              "The following features have been disabled:")
    set(title_PACKAGES_FOUND                 "The following packages have been found:")
    set(title_PACKAGES_NOT_FOUND             "The following packages have not been found:")
    set(title_OPTIONAL_PACKAGES_FOUND        "The following OPTIONAL packages have been found:")
    set(title_OPTIONAL_PACKAGES_NOT_FOUND    "The following OPTIONAL packages have not been found:")
    set(title_RECOMMENDED_PACKAGES_FOUND     "The following RECOMMENDED packages have been found:")
    set(title_RECOMMENDED_PACKAGES_NOT_FOUND "The following RECOMMENDED packages have not been found:")
    set(title_REQUIRED_PACKAGES_FOUND        "The following REQUIRED packages have been found:")
    set(title_REQUIRED_PACKAGES_NOT_FOUND    "The following REQUIRED packages have not been found:")
    set(title_RUNTIME_PACKAGES_FOUND         "The following RUNTIME packages have been found:")
    set(title_RUNTIME_PACKAGES_NOT_FOUND     "The following RUNTIME packages have not been found:")

    set(_fullText "${_FS_DESCRIPTION}")
    foreach(part ${allWhatParts})
      set(_tmp)
      _FS_GET_FEATURE_SUMMARY( ${part} _tmp ${_FS_INCLUDE_QUIET_PACKAGES})
      if(_tmp)
        set(_fullText "${_fullText}\n-- ${title_${part}}\n${_tmp}\n")
        if("${part}" STREQUAL "REQUIRED_PACKAGES_NOT_FOUND")
          set(requiredPackagesNotFound TRUE)
        endif()
      endif()
    endforeach()
  endif()

  if(_FS_FILENAME)
    if(_FS_APPEND)
      file(APPEND "${_FS_FILENAME}" "${_fullText}")
    else()
      file(WRITE  "${_FS_FILENAME}" "${_fullText}")
    endif()

  else()
    if(NOT _FS_VAR)
      message(STATUS "${_fullText}")
    endif()
  endif()

  if(_FS_VAR)
    set(${_FS_VAR} "${_fullText}" PARENT_SCOPE)
  endif()

  if(requiredPackagesNotFound  AND  _FS_FATAL_ON_MISSING_REQUIRED_PACKAGES)
    message(FATAL_ERROR "feature_summary() Error: REQUIRED package(s) are missing, aborting CMake run.")
  endif()

endfunction()


# The stuff below is only kept for compatibility

function(SET_PACKAGE_INFO _name _desc)
  set(_url "${ARGV2}")
  set(_purpose "${ARGV3}")
  set_property(GLOBAL PROPERTY _CMAKE_${_name}_DESCRIPTION "${_desc}" )
  if(NOT _url STREQUAL "")
    set_property(GLOBAL PROPERTY _CMAKE_${_name}_URL "${_url}" )
  endif()
  if(NOT _purpose STREQUAL "")
    set_property(GLOBAL APPEND PROPERTY _CMAKE_${_name}_PURPOSE "${_purpose}" )
  endif()
endfunction()



function(SET_FEATURE_INFO)
  SET_PACKAGE_INFO(${ARGN})
endfunction()



function(PRINT_ENABLED_FEATURES)
  FEATURE_SUMMARY(WHAT ENABLED_FEATURES  DESCRIPTION "Enabled features:")
endfunction()



function(PRINT_DISABLED_FEATURES)
  FEATURE_SUMMARY(WHAT DISABLED_FEATURES  DESCRIPTION "Disabled features:")
endfunction()
