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
 *  @file GuiController.h
 */

#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <memory>
#include <TRint.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGMenu.h>
#include <TQObject.h>
#include <TGToolBar.h>
#include <TGFileDialog.h>
#include <TGStatusBar.h>
#include <TGProgressBar.h>
#include <RQ_OBJECT.h>
#include <TString.h>
#include <TRootEmbeddedCanvas.h>
#include <TGLabel.h>
#include <TBox.h>
#include <TMarker.h>
#include <TGNumberEntry.h>

#include "GuiSignalController.h"
#include "GeometryVisualizator.h"
#include "DataProcessor.h"

namespace jpet_event_display
{
  struct GUIControlls {

  Int_t eventNo;
  Int_t stepNo;
  Int_t rootEntries;
  Int_t* rootMatrices;
  bool displayFullSig;
};

  class GuiController 
  {
    RQ_OBJECT("GuiController")
  public:
    GuiController();
    ~GuiController();

    void draw();
    void run();
    
    void loadGeometry(const std::string& geometry);
    void openFile(const std::string& readFile);
    inline void fullSigDisplay() { fGUIControls->displayFullSig = !(fGUIControls->displayFullSig);}

    std::shared_ptr<TCanvas> getCanvas() { return fCanvas; }
    TRootEmbeddedCanvas* getfEcanvas() { return fEcanvas; }

    void createGraphicalElements();
    void doNext();
    void updateGUIControlls();
    void CloseWindow();

  
  private:
    //GuiController(const GuiController&) = delete;
    //GuiController& operator=(const GuiController&) = delete;

    

    std::unique_ptr<TRint> fApplication;
    std::shared_ptr<TCanvas> fCanvas;
    TGMainFrame *fMainWindow;
    TGMenuBar* fMenuBar;
    TGPopupMenu* fMenuFile;
    TRootEmbeddedCanvas *fEcanvas;
    TGLabel* fInputInfo;
    TGHProgressBar* fProgBar;
    TGNumberEntry *fNumberEntryStep;
    TGNumberEntry *fNumberEntryEventNo;
    GUIControlls* fGUIControls;

    GuiSignalController* guiSignalController = new GuiSignalController();
    GeometryVisualizator* visualizator;
    DataProcessor dataProcessor;
  };


}

#endif /*  !GUICONTROLLER_H */