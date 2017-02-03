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
 *  @file GuiSignalController.cpp
 */


#include "GuiSignalController.h"
#include <TMath.h>

namespace jpet_event_display
{

  const char *filetypes[] = {
    "All files",     "*",
    "ROOT files",    "*.root",
    "Text files",    "*.[tT][xX][tT]",
    0,               0
  };

  GuiSignalController::GuiSignalController() {
    fFileInfo = new TGFileInfo;
   }
  GuiSignalController::~GuiSignalController() { }

  void GuiSignalController::handleMenu (Int_t id) 
  {

    switch (id) {

      case M_FILE_OPEN:
      {
        TString dir("");
        fFileInfo->fFileTypes = filetypes;
        fFileInfo->fIniDir    = StrDup(dir);
        EmitVA("openFileDialog(TGFileInfo*,EFileDialogMode)",2,fFileInfo,(EFileDialogMode)kFDOpen);
      }
      break;

      case M_FILE_SAVE:
      {
        TString dir("");
        fFileInfo->fFileTypes = filetypes;
        fFileInfo->fIniDir    = StrDup(dir);
        EmitVA("openFileDialog(TGFileInfo*,EFileDialogMode)",2,fFileInfo,(EFileDialogMode)kFDSave);
      }
      break;

      case M_FILE_EXIT:
      {
        Emit("exit()");
      }
      break;
    }

    return;
  }
}