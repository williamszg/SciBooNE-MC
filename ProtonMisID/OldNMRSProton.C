#define OldNMRSProton_cxx
#include "OldNMRSProton.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

//-----------------------------|
//---       Histograms      ---|
//-----------------------------|

TH1D *h = new TH1D("h", "", 100, 0, 100);

//-----------------------------|


//-----------------------------|
//---  Constant Parameters  ---|
//-----------------------------|

int protonpdg = 2212;

//-----------------------------|


//===========================================|
//              Event Selection              |
//===========================================|

void OldNMRSProton::Loop()
{

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   //----------------------------------------|
   //---     Event Counters/Register      ---|
   //----------------------------------------|

   int nEvents = 0;
   int nEventsWithProton = 0;
   int nProtons = 0;
   int ProtonRegister = 99;

   //----------------------------------------|

   for (Long64_t jentry=0; jentry<nentries; jentry++)
   {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      nEvents++;
      if (nEvents%1000 == 0) {std::cout<<"Event = "<<nEvents<<std::endl;} //Event print out every 1000 events

      TRandom3 *randX = new TRandom3();
      TRandom3 *randY = new TRandom3();
      TRandom3 *flat = new TRandom3();
      randX->SetSeed(jentry/2);
      randY->SetSeed(jentry*jentry);
      flat->SetSeed(jentry*jentry*jentry);
      double Xpos = randX->Gaus(1.5,1.3);
      while (Xpos<0 || Xpos>3.0) { Xpos = randX->Gaus(1.5,1.3); }
      double Ypos = randY->Gaus(1.5,1.05);
      while (Ypos<0 || Ypos>3.0) { Ypos = randY->Gaus(1.5,1.05); }
      double Zpos = flat->Uniform(0,1.7);

      for (int npart=0; npart<StdHepN; npart++)
      {

         if (StdHepPdg[npart] == protonpdg && StdHepStatus[npart] == 1) 
	 {

            nProtons++;
	    ProtonRegister = npart;

	 } //<--- Close if statement


      } //<--- Close loop over particles in event


      if (nProtons > 0) 
      { 

         nEventsWithProton++; 
	 nProtons = 0;

      } //<--- Close amount of events with proton loop


   } //<--- Close jentry for loop


   std::cout<<"Number of Events with at least a single proton in final state = "<<nEventsWithProton<<std::endl;
} //<--- Close void loop

//===========================================|
