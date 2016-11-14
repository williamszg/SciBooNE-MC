#define NuModeAsaadi_cxx
#include "NuModeAsaadi.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <iostream>
#include <TVector3.h>


// ### Muon Momentum Plots ###
TH1D *hMuonPx = new TH1D("hMuonPx", "#mu P_{x}", 1750, 0, 2500);
TH1D *hMuonPy = new TH1D("hMuonPy", "#mu P_{y}", 1750, 0, 2500);
TH1D *hMuonPz = new TH1D("hMuonPz", "#mu P_{z}", 1750, 0, 2500);

// ### Muon Theta Histo ###
TH1D *hMuonTheta = new TH1D("hMuonTheta", "#mu Theta ", 720, -360, 360);
TH1D *hMuonPhi   = new TH1D("hMuonPhi", "#mu #phi", 720, -360, 360);

// ### Pion Theta Histo ###
TH1D *hPionTheta = new TH1D("hPionTheta", "#pi Theta ", 720, -360, 360);
TH1D *hPionPhi   = new TH1D("hPionPhi", "#pi #phi", 720, -360, 360);

// ### Pion Momentum Plots ###
TH1D *hPionPx = new TH1D("hPionPx", "#pi P_{x}", 1750, 0, 2500);
TH1D *hPionPy = new TH1D("hPionPy", "#pi P_{y}", 1750, 0, 2500);
TH1D *hPionPz = new TH1D("hPionPz", "#pi P_{z}", 1750, 0, 2500);


// ### Opening angle between muon and pion (alpha) ###
TH1D *hAlpha = new TH1D("hAlpha", "#alpha (Opening angle between muon and pion)", 360, 0, 360);

void NuModeAsaadi::Loop()
{


if (fChain == 0) return;

Long64_t nentries = fChain->GetEntriesFast();

Long64_t nbytes = 0, nb = 0;


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0;

int nCohPionEvents = 0;

for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
   
   // ### Load this entry ###
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   // if (Cut(ientry) < 0) continue;
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 500 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
   
   // ### Set a random seed for X and Y vertex position ###
   TRandom3 *randX = new TRandom3();
   randX->SetSeed(jentry);
   TRandom3 *randY = new TRandom3();
   randY->SetSeed(jentry/nbytes);
   
   // ### Set a random seed for Z position ###
   TRandom3 *flat = new TRandom3();
   flat->SetSeed(jentry);
   
   // ### Declaring the vertex position ###
   double Xpos = randX->Gaus(1.5,2.5);
   double Ypos = randY->Gaus(1.5,2.5);
   double Zpos = flat->Uniform(0,3);
   
   // ### Counting the number of final state 
   int nMuons = 0;
   int nPions = 0;
   int nFinalStatePart = 0;
   
   int muonNumber = 0;
   int pionNumber = 0;
   
   // ### Loop over all particles in the event ####
   for(int npart = 0; npart < StdHepN; npart++)
      {
      
      // ### Check that there is a final state muon in the event ####
      if ( (StdHepPdg[npart] == 13 || StdHepPdg[npart] == -13) && StdHepStatus[npart] == 1 )
         {
	 nMuons++;
	 muonNumber = npart;
	 }//<---End checking if there is a muon
	 
      // ### Check that there is a final state muon in the event ####
      if ( (StdHepPdg[npart] == 211 || StdHepPdg[npart] == -211) && StdHepStatus[npart] == 1 )
         {
	 nPions++;
	 pionNumber = npart;
	 }//<---End checking if there is a pion
	 
      // ################################################	 
      // ### Checking all other final state particles ###
      // ################################################
      if(StdHepStatus[npart] == 1)
         {
	 nFinalStatePart++;
	 }//<---counting all final state particles
      
      }//<---End npart loop
   
   // ###################################################
   // ### Checking that this is a Coherent Pion Event ###
   // ### nMuons == 1
   // ### nPions == 1
   // ### nFinalState == 2
   // ###################################################
   if(nMuons == 1 && nPions == 1 && nFinalStatePart == 2)
      {
      nCohPionEvents++;
      
      // ### Define a unit vector pointed along the beam axis ###
      TVector3 z_hat(0,0,1);
      
      // ### Grab the muons momentum vector ###
      TVector3 P_muon;
      
      P_muon.SetX(StdHepP4[muonNumber][0]*1000); //<--- x 1000 to convert to MeV
      P_muon.SetY(StdHepP4[muonNumber][1]*1000); //<--- x 1000 to convert to MeV
      P_muon.SetZ(StdHepP4[muonNumber][2]*1000); //<--- x 1000 to convert to MeV
      
      
      hMuonPx->Fill(P_muon.X());
      hMuonPy->Fill(P_muon.Y());
      hMuonPz->Fill(P_muon.Z());
      
      float Phi_muon = 0;
      float Theta_muon = 0;
      // ####################################
      // ### Calculate Theta for the muon ###
      // ####################################
      Theta_muon = acos(z_hat.Dot(P_muon)/P_muon.Mag());
      
      // ##################################
      // ### Calculate Phi for the muon ###
      // ##################################
      if( P_muon.Y() > 0 && P_muon.X() > 0 ){ Phi_muon = atan(P_muon.Y()/P_muon.X()); }
      else if( P_muon.Y() > 0 && P_muon.X() < 0 ){ Phi_muon = atan(P_muon.Y()/P_muon.X())+3.141592654; }
      else if( P_muon.Y() < 0 && P_muon.X() < 0 ){ Phi_muon = atan(P_muon.Y()/P_muon.X())+3.141592654; }
      else if( P_muon.Y() < 0 && P_muon.X() > 0 ){ Phi_muon = atan(P_muon.Y()/P_muon.X())+6.28318; }
      else if( P_muon.Y() == 0 && P_muon.X() == 0 ){ Phi_muon = 0; }//defined by convention
      else if( P_muon.Y() == 0 )
         {
         if( P_muon.X() > 0 ){ Phi_muon = 0; }

         else{ Phi_muon = 3.141592654; }

         }
      else if( P_muon.X() == 0 )
         {
         if( P_muon.Y() > 0 ){ Phi_muon = 3.141592654/2; }
         else{ Phi_muon = 3.141592654*3/2; }

         }
      
      // #####################################
      // ### Filling Muon Angle Histograms ###
      // #####################################
      hMuonTheta->Fill(Theta_muon* (180.0/3.141592654));
      hMuonPhi->Fill(Phi_muon* (180.0/3.141592654));
      
      // ### Grab the Pions momentum vector ###
      TVector3 P_pion;
      P_pion.SetX(StdHepP4[pionNumber][0]*1000); //<--- x 1000 to convert to MeV
      P_pion.SetY(StdHepP4[pionNumber][1]*1000); //<--- x 1000 to convert to MeV
      P_pion.SetZ(StdHepP4[pionNumber][2]*1000); //<--- x 1000 to convert to MeV
      
      hPionPx->Fill(P_pion.X());
      hPionPy->Fill(P_pion.Y());
      hPionPz->Fill(P_pion.Z());
      
      float Phi_pion = 0;
      float Theta_pion = 0;
      
      // ####################################
      // ### Calculate Theta for the pion ###
      // ####################################
      Theta_pion = acos(z_hat.Dot(P_pion)/P_pion.Mag());
      
      // ##################################
      // ### Calculate Phi for the pion ###
      // ##################################
      if( P_pion.Y() > 0 && P_pion.X() > 0 ){ Phi_pion = atan(P_pion.Y()/P_pion.X()); }
      else if( P_pion.Y() > 0 && P_pion.X() < 0 ){ Phi_pion = atan(P_pion.Y()/P_pion.X())+3.141592654; }
      else if( P_pion.Y() < 0 && P_pion.X() < 0 ){ Phi_pion = atan(P_pion.Y()/P_pion.X())+3.141592654; }
      else if( P_pion.Y() < 0 && P_pion.X() > 0 ){ Phi_pion = atan(P_pion.Y()/P_pion.X())+6.28318; }
      else if( P_pion.Y() == 0 && P_pion.X() == 0 ){ Phi_pion = 0; }//defined by convention
      else if( P_pion.Y() == 0 )
         {
         if( P_pion.X() > 0 ){ Phi_pion = 0; }

         else{ Phi_pion = 3.141592654; }

         }
      else if( P_pion.X() == 0 )
         {
         if( P_pion.Y() > 0 ){ Phi_pion = 3.141592654/2; }
         else{ Phi_pion = 3.141592654*3/2; }

         }
      
      // #####################################
      // ### Filling Muon Angle Histograms ###
      // #####################################
      hPionTheta->Fill(Theta_pion * (180.0/3.141592654));
      hPionPhi->Fill(Phi_pion * (180.0/3.141592654));
      
      
      // ###################################################################
      // ### Calculating the opening angle between the muon and the pion ###
      // ###################################################################
      
      // ##########################################################
      // ### Defining unit vectors for the Muon and Pion tracks ###
      // ##########################################################
      TVector3 theUnitVector_Muon;
      TVector3 theUnitVector_Pion;
	 
      // === Muon Unit Vector ===
      theUnitVector_Muon.SetX(sin(Theta_muon)*cos(Phi_muon));
      theUnitVector_Muon.SetY(sin(Theta_muon)*sin(Phi_muon));
      theUnitVector_Muon.SetZ(cos(Theta_muon));
    
      // === Pion Unit Vector ===
      theUnitVector_Pion.SetX(sin(Theta_pion)*cos(Phi_pion));
      theUnitVector_Pion.SetY(sin(Theta_pion)*sin(Phi_pion));
      theUnitVector_Pion.SetZ(cos(Theta_pion));
      
      
      // #########################################################
      // ### Calculating the angle between Muon and Pion Track ###
      // #########################################################
      float alpha = ( acos(theUnitVector_Muon.Dot(theUnitVector_Pion)) )* (180.0/3.141592654);
      
      hAlpha->Fill(alpha);
      
      
      
      }//<---End Coherent Pion
   
   }//<---End jentry loop
   
   
std::cout<<"==================================================================="<<std::endl;
std::cout<<"Total Number of Events		= "<<nTotalEvents<<std::endl;
std::cout<<"Total Number of Coh-Pion Events 	= "<<nCohPionEvents<<std::endl;
std::cout<<"==================================================================="<<std::endl;



TFile myfile("NuMu_histos.root","RECREATE");

hMuonTheta->Write();
hMuonPhi->Write();
hPionTheta->Write();
hPionPhi->Write();
hMuonPx->Write();
hMuonPy->Write();
hMuonPz->Write();
hPionPx->Write();
hPionPy->Write();
hPionPz->Write();
hAlpha->Write();

}
