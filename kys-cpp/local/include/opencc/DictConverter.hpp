/*
 * Open Chinese Convert
 *
 * Copyright 2010-2017 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Common.hpp"

namespace opencc {
/**
* Converts a dictionary from a format to another.
* @ingroup opencc_cpp_api
*/
OPENCC_EXPORT void ConvertDictionary(const string inputFileName, const string outputFileName,
                       const string formatFrom, const string formatTo);
}
