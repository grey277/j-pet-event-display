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

#include "./DataProcessor.h"

namespace jpet_event_display
{

ScintillatorsInLayers DataProcessor::getActiveScintillators(const JPetTimeWindow& tWindow)
{
  auto sigChannels = tWindow.getSigChVect(); 
  ScintillatorsInLayers result;
  for(const auto& channel: sigChannels) {
    /// we need to use some mapping of those numbers but for a moment let's use those values.
    auto scinId = channel.getPM().getScin().getID();
    auto layerId = channel.getPM().getScin().getBarrelSlot().getLayer().getID();
    result[layerId].push_back(scinId);
  }
}

}
