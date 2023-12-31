CMAKE_MAKE_PROGRAM
------------------

Tool that can launch the native build system.
The value may be the full path to an executable or just the tool
name if it is expected to be in the ``PATH``.

The tool selected depends on the :variable:`CMAKE_GENERATOR` used
to configure the project:

* The Makefile generators set this to ``make``, ``gmake``, or
  a generator-specific tool (e.g. ``nmake`` for "NMake Makefiles").

  These generators store ``CMAKE_MAKE_PROGRAM`` in the CMake cache
  so that it may be edited by the user.

* The Ninja generator sets this to ``ninja``.

  This generator stores ``CMAKE_MAKE_PROGRAM`` in the CMake cache
  so that it may be edited by the user.

* The Xcode generator sets this to ``xcodebuild`` (or possibly an
  otherwise undocumented ``cmakexbuild`` wrapper implementing some
  workarounds).

  This generator prefers to lookup the build tool at build time
  rather than to store ``CMAKE_MAKE_PROGRAM`` in the CMake cache
  ahead of time.  This is because ``xcodebuild`` is easy to find,
  the ``cmakexbuild`` wrapper is needed only for older Xcode versions,
  and the path to ``cmakexbuild`` may be outdated if CMake itself moves.

  For compatibility with versions of CMake prior to 3.2, if
  a user or project explicitly adds ``CMAKE_MAKE_PROGRAM`` to
  the CMake cache then CMake will use the specified value.

* The Visual Studio generators set this to the full path to
  ``MSBuild.exe`` (VS >= 10), ``devenv.com`` (VS 7,8,9),
  ``VCExpress.exe`` (VS Express 8,9), or ``msdev.exe`` (VS 6).
  (See also variables
  :variable:`CMAKE_VS_MSBUILD_COMMAND`,
  :variable:`CMAKE_VS_DEVENV_COMMAND`, and
  :variable:`CMAKE_VS_MSDEV_COMMAND`.)

  These generators prefer to lookup the build tool at build time
  rather than to store ``CMAKE_MAKE_PROGRAM`` in the CMake cache
  ahead of time.  This is because the tools are version-specific
  and can be located using the Windows Registry.  It is also
  necessary because the proper build tool may depend on the
  project content (e.g. the Intel Fortran plugin to VS 10 and 11
  requires ``devenv.com`` to build its ``.vfproj`` project files
  even though ``MSBuild.exe`` is normally preferred to support
  the :variable:`CMAKE_GENERATOR_TOOLSET`).

  For compatibility with versions of CMake prior to 3.0, if
  a user or project explicitly adds ``CMAKE_MAKE_PROGRAM`` to
  the CMake cache then CMake will use the specified value if
  possible.

The ``CMAKE_MAKE_PROGRAM`` variable is set for use by project code.
The value is also used by the :manual:`cmake(1)` ``--build`` and
:manual:`ctest(1)` ``--build-and-test`` tools to launch the native
build process.
