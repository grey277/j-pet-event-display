/**
 *  @copyright Copyright 2016 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <map>
#include <vector>
#include <JPetTimeWindow/JPetTimeWindow.h>

namespace jpet_event_display
{

typedef std::map<int, std::vector<int> > ScintillatorsInLayers;

class DataProcessor
{
public:
  static ScintillatorsInLayers getActiveScintillators(const JPetTimeWindow& tWindow);  
};

}

#endif /*  !DATAPROCESSOR_H */
