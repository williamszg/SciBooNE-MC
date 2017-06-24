#define OldNMReinSehgal_cxx
#include "OldNMReinSehgal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265


//========================================================================
//           ### This is where the histograms are defined ###
//========================================================================

//#######################
//### Muon Histograms ###
//#######################

TH2D *hCCIncMuonTotal = new TH2D("hCCIncMuonTotal", "Total CC Inclusive Events Muon Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for muon angle and momentum
TH2D *hCCIncMuonGood = new TH2D("hCCIncMuonGood", "Good CC Inclusive Events Muon Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for good muon angle and momentum
TH2D *hCCCohMuonTotal = new TH2D("hCCCohMuonTotal", "Total CC Coh Events Muon Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for muon angle and momentum
TH2D *hCCCohMuonGood = new TH2D("hCCCohMuonGood", "Good CC Coh Events Muon Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for good muon angle and momentum
TH1D *hSteelLayer = new TH1D("hSteelLayer", "Steel Layer the Muon Stops Inside", 14, 0, 14); //This is the histogram for the steel layer that the muon stops within
TH1D *hTotalMuonMomentum = new TH1D ("hTotalMuonMomentum", "Total CC Coh Muon Momentum", 40, 0, 2500); //This is the histogram for the total CC Coh Muon Momentum
TH1D *hGoodMuonMomentumTotal = new TH1D("hGoodMuonMomentumTotal", "Total Good CC Coh Muon Momentum", 40, 0, 2500); //This is the good muon momentum for both stopped and nonstopped events
TH1D *hGoodMuonMomentumStopped = new TH1D("hGoodMuonMomentumStopped", "Good CC Coh Muon Momentum Stopped", 40, 0, 2500); //This is the good muon momentum for the stopped events
TH1D *hGoodMuonMomentumNonStopped = new TH1D("hGoodMuonMomentumNonStopped", "Good CC Coh Muon Momentum Non-Stopped", 40, 0, 2500); //This is the good muon momentum for the non-stopped events
TH1D *hTotalMuonAngle = new TH1D("hTotalMuonAngle", "Total CC Coh Muon Angle", 40, 0, 180); //This is the histogram for the total CC Coh Muon Angle
TH1D *hGoodMuonAngleTotal = new TH1D("hGoodMuonAngleTotal", "Total Good CC Coh Muon Angle", 40, 0, 180); //This is the histogram for the good muon angle both stopped and non-stopped
TH1D *hGoodMuonAngleStopped = new TH1D("hGoodMuonAngleStopped", "Good CC Coh Muon Angle Stopped", 40, 0, 180); //This is the histogram for the good muon angle for the stopped events
TH1D *hGoodMuonAngleNonStopped = new TH1D("hGoodMuonAngleNonStopped", "Good CC Coh Muon Angle Non-Stopped", 40, 0, 180); //This is the histogram for the good muon angle for the nonstopped events
TH1D *hGoodMuonAngleOutSide = new TH1D("hGoodMuonAngleOutSide", "Good CC Coh Muon Angle Out the Side of the MRD", 40, 0, 180); //This is the histogram for the good muon angle for the events where the muon traveled out the side of the MRD
TH1D *hGoodMuonMomentumOutSide = new TH1D("hGoodMuonMomentumOutSide", "Good CC Coh Muon Momentum Out the Side of the MRD", 40, 0, 2500); //This is the histogram for the good muon momentums for the events where the muon traveled out the side of the MRD
TH1D *hFourMomentumBoth = new TH1D("hFourMomentumBoth", "Four Momentum of the CC Coherent Interactions Both Stopped and Non-Stopped", 40, 0, 1); //This is the histogram for the four momentum of the CC Coh Pion interactions
TH1D *hQSquaredBoth = new TH1D("hQSquaredBoth", "Q Squared of the CC Coherent Interactions Both Stopped and Non-Stopped", 40, 0, 1); //This is the histogram for the q squared values for the different CC Coh Pion interactions
TH1D *hFourMomentumStopped = new TH1D("hFourMomentumStopped", "Four Momentum of the CC Coherent Interactions Stopped", 40, 0, 1); //This is the histogram for the four momentum of the CC Coh Pion interactions
TH1D *hQSquaredStopped = new TH1D("hQSquaredStopped", "Q Squared of the CC Coherent Interactions Stopped", 40, 0, 1); //This is the histogram for the q squared values for the different CC Coh Pion interactions
TH1D *hFourMomentumNonStopped = new TH1D("hFourMomentumNonStopped", "Four Momentum of the CC Coherent Interactions Non-Stopped", 40, 0, 1); //This is the histogram for the four momentum of the CC Coh Pion interactions
TH1D *hQSquaredNonStopped = new TH1D("hQSquaredNonStopped", "Q Squared of the CC Coherent Interactions Non-Stopped", 40, 0, 1); //This is the histogram for the q squared values for the different CC Coh Pion interactions

TH1D *hCCTotalMuonMomentum = new TH1D ("hCCTotalMuonMomentum", "Total CC Muon Momentum", 40, 0, 2500); //This is the histogram for the total CC Coh Muon Momentum
TH1D *hCCGoodMuonMomentumTotal = new TH1D("hCCGoodMuonMomentumTotal", "Total Good CC Muon Momentum", 40, 0, 2500); //This is the good muon momentum for both stopped and nonstopped events
TH1D *hCCGoodMuonMomentumStopped = new TH1D("hCCGoodMuonMomentumStopped", "Good CC Muon Momentum Stopped", 40, 0, 2500); //This is the good muon momentum for the stopped events
TH1D *hCCGoodMuonMomentumNonStopped = new TH1D("hCCGoodMuonMomentumNonStopped", "Good CC Muon Momentum Non-Stopped", 40, 0, 2500); //This is the good muon momentum for the non-stopped events
TH1D *hCCTotalMuonAngle = new TH1D("hCCTotalMuonAngle", "Total CC Muon Angle", 40, 0, 180); //This is the histogram for the total CC Coh Muon Angle
TH1D *hCCGoodMuonAngleTotal = new TH1D("hCCGoodMuonAngleTotal", "Total Good CC Muon Angle", 40, 0, 180); //This is the histogram for the good muon angle both stopped and non-stopped
TH1D *hCCGoodMuonAngleStopped = new TH1D("hCCGoodMuonAngleStopped", "Good CC Muon Angle Stopped", 40, 0, 180); //This is the histogram for the good muon angle for the stopped events
TH1D *hCCGoodMuonAngleNonStopped = new TH1D("hCCGoodMuonAngleNonStopped", "Good CC Muon Angle Non-Stopped", 40, 0, 180); //This is the histogram for the good muon angle for the nonstopped events

TH1D *hTx = new TH1D("hTx", "|t| x component", 40, 0, 1);
TH1D *hTy = new TH1D("hTy", "|t| y component", 40, 0, 1);
TH1D *hTz = new TH1D("hTz", "|t| z component", 40, 0, 1);
TH1D *hTE = new TH1D("hTE", "|t| E component", 40, 0, 1);

TH1D *h1 = new TH1D("h1", "X Vertex Distribution", 40, -25, 325);
TH1D *h2 = new TH1D("h2", "Y Vertex Distribution", 40, -25, 325);
TH1D *h3 = new TH1D("h3", "Z Vertex Distribution", 40, -25, 195);
TH2D *h4 = new TH2D("h4", "X-Y Vertex Distribution for Z > 1.4m", 117, -0.25, 3.25, 117, -0.25, 3.25);

//#######################
//### Pion Histograms ###
//#######################

TH2D *hCCIncPionTotal = new TH2D("hCCIncPionTotal", "Total CC Inclusive Events Pion Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for pion angle and momentum
TH2D *hCCIncPionGood = new TH2D("hCCIncPionGood", "Good CC Inclusive Events Pion Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for pion angle and momentum of the good events
TH2D *hCCCohPionTotal = new TH2D("hCCCohPionTotal", "Total CC Coh Events Pion Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for pion angle and momentum
TH2D *hCCCohPionGood = new TH2D("hCCCohPionGood", "Good CC Coh Events Pion Information", 40, 0, 180, 40, 0, 2000); //This is the 2D histogram for pion angle and momentum of the good events
TH1D *hPionEnergy = new TH1D("hPionEnergy", "Energy of the Pion in Total CC Coh Events", 40, 0, 2500); //This is the energy of pions that are for CC Events
TH1D *hPionMomentum = new TH1D("hPionMomentum", "Momentum of the Pion in Total CC Coh Events", 40, 0, 2500); //This is the histogram for the Pion Momentum that are for CC Events
TH1D *hPionAngle = new TH1D("hPionAngle", "Angle of the Pion in Total CC Coh Events", 40, 0, 180); //This is the histogram for the Pion Angle that are for CC Events
TH1D *hPionEnergyStopped = new TH1D("hPionEnergyStopped", "Energy of the Pions for the Stopped Muons", 40, 0, 2500); //This is the energy of the pions from the stopped muon interactions
TH1D *hPionMomentumStopped = new TH1D("hPionMomentumStopped", "Momentum of the Pion in the Stopped Muon Events", 40, 0, 2500); //This is the histogram for the Pion Momentums in the stopped muon events
TH1D *hPionAngleStopped = new TH1D("hPionAngleStopped", "Angle of the Pion in the Stopped Muon Events", 40, 0, 180); //This is the histogram for the Pion Angles for the stopped muon events
TH1D *hPionEnergyNonStopped = new TH1D("hPionEnergyNonStopped", "Energy of the Pions for the Non-Stopped Muons", 40, 0, 2500); //This is the energy of the pions from the non-stopped muon interactions
TH1D *hPionMomentumNonStopped = new TH1D("hPionMomentumNonStopped", "Momentum of the Pion in the Non-Stopped Muon Events", 40, 0, 2500); //This is the histogram for the Pion Momentums in the non-stopped muon events
TH1D *hPionAngleNonStopped = new TH1D("hPionAngleNonStopped", "Angle of the Pion in the Non-Stopped Muon Events", 40, 0, 180); //This is the histogram for the Pion Angles for the non-stopped muon events
TH1D *hPionEnergyGood = new TH1D("hPionEnergyGood", "Energy of the Pion in Good CC Coh Events", 40, 0, 2500); //This is the energy of pions that are for Good CC Events
TH1D *hPionMomentumGood = new TH1D("hPionMomentumGood", "Momentum of the Pion in Good CC Coh Events", 40, 0, 2500); //This is the histogram for the Pion Momentum that are for Good CC Events
TH1D *hPionAngleGood = new TH1D("hPionAngleGood", "Angle of the Pion in Good CC Coh Events", 40, 0, 180); //This is the histogram for the Pion Angle that are for Good CC Events

//------------------------------------------------------------------------


//========================================================================
//                ### This is the Event Selection code ###
//========================================================================

void OldNMReinSehgal::Loop()
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   int NumberEvents = 0; //This is the total number of events that occured
   int NumberMuonsPresent = 0; //This is the number of muons present in the event
   int NumberPionsPresent = 0; //This is the number of pions present in the event
   int NumberFinalStateParticles = 0; //This is the number of final state particles in the event
   int MuonCallNumber = 0; //This is the call number for the muon in the event
   int PionCallNumber = 0; //This is the call number for the pion in the event
   int NumberCCCohEvents = 0; //This is the number of CC Coherent Pion Production events that occured
   int NumberGoodEvents = 0; //This is the number of CC Coherent Pion Production events that are good
   int NumberStopped = 0; //This is the number of events that stopped within the MRD
   int NumberNotStopped = 0; //This is the number of events that did not stop within the MRD
   int NumberOutSide = 0; //This is the number of events that the muon shot out the side of the MRD
   int NumberMadeFrontMRD = 0; //This is the number of events that made it to the front of the MRD
   int CCNumberEvents = 0; //This is the number of CC events
   int CCNumberGoodEvents = 0;
   int CCNumberStopped = 0;
   int CCNumberNotStopped = 0;
   int CCNumberOutSide = 0;
   int CCNumberMadeFrontMRD = 0;
   int NeutrinoCallNumber = -99;
   int zw = 0;

   for (Long64_t jentry=0; jentry<nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
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

      for (int npart=0; npart<StdHepN; npart++) {
         if ((StdHepPdg[npart] == 13 || StdHepPdg[npart] == -13) && StdHepStatus[npart] == 1) {
            NumberMuonsPresent++; //Counts the number of final state muons in the event
            MuonCallNumber = npart; //Sets the muon call number to whatever the value of npart was for this particle in this event
         }


         if ((StdHepPdg[npart] == 211 || StdHepPdg[npart] == -211) && StdHepStatus[npart] == 1) {
            NumberPionsPresent++; //Counts the number of final state pions in the event
            PionCallNumber = npart; //Sets the pion call number to whatever the value of npart was for this particle in this event
         }


         if (StdHepStatus[npart] == 1) {
            NumberFinalStateParticles++; //Counts the number of final state particles that are within the event
         }


         if (StdHepPdg[npart] == 14 || StdHepPdg[npart] == -14) {
            NeutrinoCallNumber = npart;
         }
 

      }


      //#################
      //### CC Events ###
      //#################

      if (NumberMuonsPresent == 1 && NumberFinalStateParticles >=2) {
         CCNumberEvents++;

         TVector3 v1(StdHepP4[MuonCallNumber][0],StdHepP4[MuonCallNumber][1],StdHepP4[MuonCallNumber][2]); //TVector3 for Muon Momentum
         TVector3 v2(StdHepP4[PionCallNumber][0],StdHepP4[PionCallNumber][1],StdHepP4[PionCallNumber][2]); //TVector3 for Pion Momentum
         TVector3 v3(Xpos,Ypos,Zpos); //TVector3 for initial x, y, and z position of the muon and pion

         double s1 = v1.Dot(v1); //Squared magnitude of the muon momentum
         double s2 = v2.Dot(v2); //Squared magnitude of the pion momentum
         double s3 = v1.Dot(v2); //Dot product between the muon and pion momentums

         Double_t t1 = v1.Theta(); //Get the polar angle of the muon momentum
         Double_t t2 = v2.Theta(); //Get the polar angle of the pion momentum
         t1 = (180/PI)*t1; //Put the polar angle in degrees
         t2 = (180/PI)*t2; //Put the polar angle in degrees

         Double_t m1 = v1.Mag(); //Get the magnitude of the muon momentum
         Double_t m2 = v2.Mag(); //Get the magnitude of the pion momentum

         hCCIncMuonTotal->Fill(t1, m1*1000); //Fill the 2D Muon Total Information Histogram
         if (NumberPionsPresent >= 1) {
            hCCIncPionTotal->Fill(t2, m2*1000); //Fill the 2D Muon Total Information Histogram
         }


         hCCTotalMuonMomentum->Fill(m1*1000); //Fill the total muon momentum histogram
         hCCTotalMuonAngle->Fill(t1); //Fill the total muon angle histogram

         double muontimeZ1 = (1.7 - v3.Z())/v1.Z(); //This is the time for the muon to reach the back of the SciBar Detector
         double piontimeZ1 = (1.7 - v3.Z())/v2.Z(); //This is the time for the pion to reach the back of the SciBar Detector
         double muonXevo1 = v3.X() + v1.X()*muontimeZ1; //This is the evolution of the x position of the muon to the back of SciBar
         double pionXevo1 = v3.X() + v2.X()*piontimeZ1; //This is the evolution of the x position of the pion to the back of SciBar
         double muonYevo1 = v3.Y() + v1.Y()*muontimeZ1; //This is the evolution of the y position of the muon to the back of SciBar
         double pionYevo1 = v3.Y() + v2.Y()*piontimeZ1; //This is the evolution of the y position of the pion to the back of SciBar
         double muontimeZ2 = (1.7 + 0.55 - v3.Z())/v1.Z(); //This is the time for the muon to reach the front of the MRD  
         double piontimeZ2 = (1.7 + 0.55 - v3.Z())/v2.Z(); //This is the time for the pion to reach the front of the MRD
         double muonXevo2 = v3.X() + v1.X()*muontimeZ2; //This is the evolution of the x position of the muon to the MRD
         double pionXevo2 = v3.X() + v2.X()*piontimeZ2; //This is the evolution of the x position of the pion to the MRD
         double muonYevo2 = v3.Y() + v1.Y()*muontimeZ2; //This is the evolution of the y position of the muon to the MRD
         double pionYevo2 = v3.Y() + v2.Y()*piontimeZ2; //This is the evolution of the y position of the pion to the MRD
         double muontimeZ3 = (1.7 + 0.55 + 1.375 - v3.Z())/v1.Z(); //This is the time for the muon to reach the front of the back of the MRD  
         double piontimeZ3 = (1.7 + 0.55 + 1.375 - v3.Z())/v2.Z(); //This is the time for the pion to reach the front of the back of the MRD
         double muonXevo3 = v3.X() + v1.X()*muontimeZ3; //This is the evolution of the x position of the muon to the back of the MRD
         double pionXevo3 = v3.X() + v2.X()*piontimeZ3; //This is the evolution of the x position of the pion to the back of the MRD
         double muonYevo3 = v3.Y() + v1.Y()*muontimeZ3; //This is the evolution of the y position of the muon to the back of the MRD
         double pionYevo3 = v3.Y() + v2.Y()*piontimeZ3; //This is the evolution of the y position of the pion to the back of the MRD
         double xMRDscint = (.006/v1.Z())*v1.X(); //This is the distance traveled through a scintillator layer added to the x-direction for the muon
         double yMRDscint = (.006/v1.Z())*v1.Y(); //This is the distance traveled through a scintillator layer added to the y-direction for the muon
         double xMRDsteel = (.0508/v1.Z())*v1.X(); //This is the distance traveled through a steel layer added to the x-direction for the muon
         double yMRDsteel = (.0508/v1.Z())*v1.Y(); //This is the distance traveled through a steel layer added to the y-direction for the muon
         double lengthMuon = 100*sqrt(((1.7 - v3.Z())*(1.7 - v3.Z())) + ((muonXevo1 - v3.X())*(muonXevo1 - v3.X())) + ((muonYevo1 - v3.Y())*(muonYevo1 - v3.Y()))); //This is the length the muon traveled through the SciBar detector from beginning to end
         double lengthPion = 100*sqrt(((1.7 - v3.Z())*(1.7 - v3.Z())) + ((pionXevo1 - v3.X())*(pionXevo1 - v3.X())) + ((pionYevo1 - v3.Y())*(pionYevo1 - v3.Y()))); //This is the length the muon traveled through the SciBar detector from beginning to end
         double dEmuon = 2.04*lengthMuon; //This is the energy the muon lost traveling through the SciBar Detector
         double dEpion = 2.04*lengthPion; //This is the energy the pion lost traveling through the SciBar Detector
         double Emuon = StdHepP4[MuonCallNumber][3]*1000 - dEmuon; //Energy the muon has after leaving SciBar
         double Epion = StdHepP4[PionCallNumber][3]*1000 - dEpion; //Energy the pion has after leaving SciBar
         
         if (StdHepP4[MuonCallNumber][2]>0 && muonXevo2>0.2 && muonXevo2<2.8 && muonYevo2>0.2 && muonYevo2<2.8 && Emuon>0) {
            CCNumberMadeFrontMRD++;
            double Emuonf1 = Emuon; //Defining the muon final energy variable
            double dEmuonScint = 0; //This is the variable to be used for scintillator layer changes in energy
            double dEmuonSteel = 0; //This is the variable to be used for steel layer changes in energy
            int layerScint = 0; //The layer of scintillator the muon made it to
            int layerSteel = 0; //The layer of steel the muon made it to
            double lengthMuon1 = 0;
            double lengthMuon2 = 0;
            double muonXevo4 = muonXevo2;
            double muonYevo4 = muonYevo2;
            double muonXevo5 = muonXevo2;
            double muonYevo5 = muonYevo2;
            double timeMuonZ4 = (1.7 + 0.55 + (26*.006) + (25*.0508) - v3.Z())/v1.Z();
            double muonXevo6 = v3.X() + timeMuonZ4*v1.X();
            double muonYevo6 = v3.Y() + timeMuonZ4*v1.Y();
            double Emuonf2 = Emuon - 2.04*26*100*sqrt((.006*.006) + (xMRDscint*xMRDscint) + (yMRDscint*yMRDscint)) - 11.43*25*100*sqrt((.0508*.0508) + (xMRDsteel*xMRDsteel) + (yMRDsteel*yMRDsteel));

                     while (Emuonf1>0) {
                        layerScint++;
                        muonXevo5 = muonXevo2 + layerScint*xMRDscint + layerSteel*xMRDsteel; //Increases the x position for a new scintillator layer
                        muonYevo5 = muonYevo2 + layerScint*yMRDscint + layerSteel*yMRDsteel; //Increases the y position for a new scintillator layer
                        lengthMuon1 = 100*sqrt((.006)*(.006) + (xMRDscint)*(xMRDscint) + (yMRDscint)*(yMRDscint));
                        dEmuonScint = 2.04*lengthMuon1;
                        Emuonf1 = Emuon - layerScint*dEmuonScint - layerSteel*dEmuonSteel;

                        if (layerScint>layerSteel && Emuonf1>0) {
                           layerSteel++;
                           muonXevo4 = muonXevo2 + layerScint*xMRDscint + layerSteel*xMRDsteel; //Increases the x position for a new steel layer
                           muonYevo4 = muonYevo2 + layerScint*yMRDscint + layerSteel*yMRDsteel; //Increases the y position for a new steel layer
                           lengthMuon2 = 100*sqrt((.0508)*(.0508) + (xMRDsteel)*(xMRDsteel) + (yMRDsteel)*(yMRDsteel));
                           dEmuonSteel = 11.43*lengthMuon2;
                           Emuonf1 = Emuon - layerScint*dEmuonScint - layerSteel*dEmuonSteel;
                        }
                        

                        if (layerScint <= 26 && Emuonf1>=0 && (muonXevo5>2.8 || muonXevo5<0.2 || muonYevo5>2.8 || muonYevo5<0.2 || muonXevo4>2.8 || muonXevo4<0.2 || muonYevo4>2.8 || muonYevo4<0.2)) {
                           CCNumberOutSide++;
                           goto jmp1;
                        }


                        if (layerScint == 26 && Emuonf2>=0 && muonXevo6>=0.2 && muonXevo6<=2.8 && muonYevo6>=0.2 && muonYevo6<=2.8) {
                           CCNumberNotStopped++;
                           hCCGoodMuonMomentumNonStopped->Fill(m1*1000); //Fill the nonstopped histogram with good nonstopped muon events for muon momentum
                           hCCGoodMuonAngleNonStopped->Fill(t1); //Fill the nonstopped histogram with good nonstopped muon events for muon angle
                           //hCCIncMuonGood->Fill(t1, m1*1000); //Fill the good muon information 2d histogram 
                           if (NumberPionsPresent >= 1 && StdHepP4[PionCallNumber][2]>0) {
                              hCCIncPionGood->Fill(t2, m2*1000);
                           }


                        }


                     }


                     if (Emuonf1<=0) {
                        CCNumberGoodEvents++;
                        hCCGoodMuonMomentumTotal->Fill(m1*1000); //Fill the total good muon momentum histogram
                        hCCGoodMuonAngleTotal->Fill(t1); //Fill the total good muon angle histogram
                     }


                     jmp1:
                     if (Emuonf1<=0 && layerScint>=4  && layerScint<=26 && layerSteel<26 && muonXevo5<=2.8 && muonXevo5>=0.2 && muonYevo5<=2.8 && muonYevo5>=0.2) {
                        CCNumberStopped++;
                        if (layerSteel>=13) {
                           layerSteel = 13; //This sets the steel layer to 12 if the muon did not stop in the first 12 layers
                        }


                        hCCGoodMuonMomentumStopped->Fill(m1*1000); //Fill the good muon momentum histogram for the stopped events
                        hCCGoodMuonAngleStopped->Fill(t1); //Fill the good muon angle histogram for the stopped events
                        hCCIncMuonGood->Fill(t1, m1*1000); //Fill the good muon information 2d histogram
                        if (NumberPionsPresent >= 1 && StdHepP4[PionCallNumber][2]>0) {
                           hCCIncPionGood->Fill(t2, m2*1000);
                        }


                     }


                  }


               }


      //#####################
      //### CC Coh Events ###
      //#####################

      if (NumberMuonsPresent == 1) {
         if (NumberPionsPresent == 1) {
            if (NumberFinalStateParticles == 2) {
               if (StdHepP4[MuonCallNumber][2]>0 && StdHepP4[PionCallNumber][2]>0) {
                  NumberCCCohEvents++; //Counts the number of CC Coherent Pion Production Events that occured

                  TVector3 v1(StdHepP4[MuonCallNumber][0],StdHepP4[MuonCallNumber][1],StdHepP4[MuonCallNumber][2]); //TVector3 for Muon Momentum
                  TVector3 v2(StdHepP4[PionCallNumber][0],StdHepP4[PionCallNumber][1],StdHepP4[PionCallNumber][2]); //TVector3 for Pion Momentum
                  TVector3 v3(Xpos,Ypos,Zpos); //TVector3 for initial x, y, and z position of the muon and pion
                  TVector3 v4(StdHepP4[NeutrinoCallNumber][0],StdHepP4[NeutrinoCallNumber][1],StdHepP4[NeutrinoCallNumber][2]); //TVector3 for Neutrino Momentum

                  double s1 = v1.Dot(v1); //Squared magnitude of the muon momentum
                  double s2 = v2.Dot(v2); //Squared magnitude of the pion momentum
                  double s3 = v1.Dot(v2); //Dot product between the muon and pion momentums
                  double s4 = v4.Dot(v4); //Squared magnitude of the neutrino momentum

                  double t = ((v4.X()-v2.X()-v1.X())*(v4.X()-v2.X()-v1.X()) + (v4.Y()-v2.Y()-v1.Y())*(v4.Y()-v2.Y()-v1.Y()) + (v4.Z()-v2.Z()-v1.Z())*(v4.Z()-v2.Z()-v1.Z())) - (StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3] - StdHepP4[PionCallNumber][3])*(StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3] - StdHepP4[PionCallNumber][3]);

                  double q = ((v4.X()-v1.X())*(v4.X()-v1.X()) + (v4.Y()-v1.Y())*(v4.Y()-v1.Y()) + (v4.Z()-v1.Z())*(v4.Z()-v1.Z())) - (StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3])*(StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3]);

                  double tx = (v4.X()-v2.X()-v1.X())*(v4.X()-v2.X()-v1.X());
                  double ty = (v4.Y()-v2.Y()-v1.Y())*(v4.Y()-v2.Y()-v1.Y());
                  double tz = (v4.Z()-v2.Z()-v1.Z())*(v4.Z()-v2.Z()-v1.Z());
                  double tE = (StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3] - StdHepP4[PionCallNumber][3])*(StdHepP4[NeutrinoCallNumber][3] - StdHepP4[MuonCallNumber][3] - StdHepP4[PionCallNumber][3]);

                  Double_t t1 = v1.Theta(); //Get the polar angle of the muon momentum
                  Double_t t2 = v2.Theta(); //Get the polar angle of the pion momentum
                  t1 = (180/PI)*t1; //Put the polar angle in degrees
                  t2 = (180/PI)*t2; //Put the polar angle in degrees

                  Double_t m1 = v1.Mag(); //Get the magnitude of the muon momentum
                  Double_t m2 = v2.Mag(); //Get the magnitude of the pion momentum

                  hPionEnergy->Fill(StdHepP4[PionCallNumber][3]*1000); //Fill the Pion Energy histogram with the energy of the pion
                  hPionMomentum->Fill(m2*1000); //Fill the Pion Momentum histogram with the momentum of the pion
                  hPionAngle->Fill(t2); //Fill the Pion Angle histogram with the angle of the pion
                  hTotalMuonMomentum->Fill(m1*1000); //Fill the total muon momentum histogram
                  hTotalMuonAngle->Fill(t1); //Fill the total muon angle histogram

                  hCCCohMuonTotal->Fill(t1, m1*1000); //Fill the 2D Muon Total Information Histogram
                  if (NumberPionsPresent >= 1) {
                     hCCCohPionTotal->Fill(t2, m2*1000); //Fill the 2D Muon Total Information Histogram
                  }

                  double muontimeZ1 = (1.7 - v3.Z())/v1.Z(); //This is the time for the muon to reach the back of the SciBar Detector
                  double piontimeZ1 = (1.7 - v3.Z())/v2.Z(); //This is the time for the pion to reach the back of the SciBar Detector
                  double muonXevo1 = v3.X() + v1.X()*muontimeZ1; //This is the evolution of the x position of the muon to the back of SciBar
                  double pionXevo1 = v3.X() + v2.X()*piontimeZ1; //This is the evolution of the x position of the pion to the back of SciBar
                  double muonYevo1 = v3.Y() + v1.Y()*muontimeZ1; //This is the evolution of the y position of the muon to the back of SciBar
                  double pionYevo1 = v3.Y() + v2.Y()*piontimeZ1; //This is the evolution of the y position of the pion to the back of SciBar
                  double muontimeZ2 = (1.7 + 0.55 - v3.Z())/v1.Z(); //This is the time for the muon to reach the front of the MRD  
                  double piontimeZ2 = (1.7 + 0.55 - v3.Z())/v2.Z(); //This is the time for the pion to reach the front of the MRD
                  double muonXevo2 = v3.X() + v1.X()*muontimeZ2; //This is the evolution of the x position of the muon to the MRD
                  double pionXevo2 = v3.X() + v2.X()*piontimeZ2; //This is the evolution of the x position of the pion to the MRD
                  double muonYevo2 = v3.Y() + v1.Y()*muontimeZ2; //This is the evolution of the y position of the muon to the MRD
                  double pionYevo2 = v3.Y() + v2.Y()*piontimeZ2; //This is the evolution of the y position of the pion to the MRD
                  double muontimeZ3 = (1.7 + 0.55 + 1.375 - v3.Z())/v1.Z(); //This is the time for the muon to reach the front of the back of the MRD  
                  double piontimeZ3 = (1.7 + 0.55 + 1.375 - v3.Z())/v2.Z(); //This is the time for the pion to reach the front of the back of the MRD
                  double muonXevo3 = v3.X() + v1.X()*muontimeZ3; //This is the evolution of the x position of the muon to the back of the MRD
                  double pionXevo3 = v3.X() + v2.X()*piontimeZ3; //This is the evolution of the x position of the pion to the back of the MRD
                  double muonYevo3 = v3.Y() + v1.Y()*muontimeZ3; //This is the evolution of the y position of the muon to the back of the MRD
                  double pionYevo3 = v3.Y() + v2.Y()*piontimeZ3; //This is the evolution of the y position of the pion to the back of the MRD
                  double xMRDscint = (.006/v1.Z())*v1.X(); //This is the distance traveled through a scintillator layer added to the x-direction for the muon
                  double yMRDscint = (.006/v1.Z())*v1.Y(); //This is the distance traveled through a scintillator layer added to the y-direction for the muon
                  double xMRDsteel = (.0508/v1.Z())*v1.X(); //This is the distance traveled through a steel layer added to the x-direction for the muon
                  double yMRDsteel = (.0508/v1.Z())*v1.Y(); //This is the distance traveled through a steel layer added to the y-direction for the muon
                  double lengthMuon = 100*sqrt(((1.7 - v3.Z())*(1.7 - v3.Z())) + ((muonXevo1 - v3.X())*(muonXevo1 - v3.X())) + ((muonYevo1 - v3.Y())*(muonYevo1 - v3.Y()))); //This is the length the muon traveled through the SciBar detector from beginning to end
                  double lengthPion = 100*sqrt(((1.7 - v3.Z())*(1.7 - v3.Z())) + ((pionXevo1 - v3.X())*(pionXevo1 - v3.X())) + ((pionYevo1 - v3.Y())*(pionYevo1 - v3.Y()))); //This is the length the muon traveled through the SciBar detector from beginning to end
                  double dEmuon = 2.04*lengthMuon; //This is the energy the muon lost traveling through the SciBar Detector
                  double dEpion = 2.04*lengthPion; //This is the energy the pion lost traveling through the SciBar Detector
                  double Emuon = StdHepP4[MuonCallNumber][3]*1000 - dEmuon; //Energy the muon has after leaving SciBar
                  double Epion = StdHepP4[PionCallNumber][3]*1000 - dEpion; //Energy the pion has after leaving SciBar

                  if (fString == "16" && muonXevo2>0.2 && muonXevo2<2.8 && muonYevo2>0.2 && muonYevo2<2.8 && Emuon>0) {
                     NumberMadeFrontMRD++;
                     double Emuonf1 = Emuon; //Defining the muon final energy variable
                     double dEmuonScint = 0; //This is the variable to be used for scintillator layer changes in energy
                     double dEmuonSteel = 0; //This is the variable to be used for steel layer changes in energy
                     int layerScint = 0; //The layer of scintillator the muon made it to
                     int layerSteel = 0; //The layer of steel the muon made it to
                     double lengthMuon1 = 0;
                     double lengthMuon2 = 0;
                     double muonXevo4 = muonXevo2;
                     double muonYevo4 = muonYevo2;
                     double muonXevo5 = muonXevo2;
                     double muonYevo5 = muonYevo2;
                     double timeMuonZ4 = (1.7 + 0.55 + (26*.006) + (25*.0508) - v3.Z())/v1.Z();
                     double muonXevo6 = v3.X() + timeMuonZ4*v1.X();
                     double muonYevo6 = v3.Y() + timeMuonZ4*v1.Y();
                     double Emuonf2 = Emuon - 2.04*26*100*sqrt((.006*.006) + (xMRDscint*xMRDscint) + (yMRDscint*yMRDscint)) - 11.43*25*100*sqrt((.0508*.0508) + (xMRDsteel*xMRDsteel) + (yMRDsteel*yMRDsteel));

                     while (Emuonf1>0) {
                        layerScint++;
                        muonXevo5 = muonXevo2 + layerScint*xMRDscint + layerSteel*xMRDsteel; //Increases the x position for a new scintillator layer
                        muonYevo5 = muonYevo2 + layerScint*yMRDscint + layerSteel*yMRDsteel; //Increases the y position for a new scintillator layer
                        lengthMuon1 = 100*sqrt((.006)*(.006) + (xMRDscint)*(xMRDscint) + (yMRDscint)*(yMRDscint));
                        dEmuonScint = 2.04*lengthMuon1;
                        Emuonf1 = Emuon - layerScint*dEmuonScint - layerSteel*dEmuonSteel;

                        if (layerScint>layerSteel && Emuonf1>0) {
                           layerSteel++;
                           muonXevo4 = muonXevo2 + layerScint*xMRDscint + layerSteel*xMRDsteel; //Increases the x position for a new steel layer
                           muonYevo4 = muonYevo2 + layerScint*yMRDscint + layerSteel*yMRDsteel; //Increases the y position for a new steel layer
                           lengthMuon2 = 100*sqrt((.0508)*(.0508) + (xMRDsteel)*(xMRDsteel) + (yMRDsteel)*(yMRDsteel));
                           dEmuonSteel = 11.43*lengthMuon2; 
                           Emuonf1 = Emuon - layerScint*dEmuonScint - layerSteel*dEmuonSteel;
                        }


                        if (layerScint <= 26 && Emuonf1>=0 && (muonXevo5>2.8 || muonXevo5<0.2 || muonYevo5>2.8 || muonYevo5<0.2 || muonXevo4>2.8 || muonXevo4<0.2 || muonYevo4>2.8 || muonYevo4<0.2)) {
                           NumberOutSide++;
                           hGoodMuonMomentumOutSide->Fill(m1*1000); //Fill the good muon momentum histogram for the muons that went out the side of the MRD
                           hGoodMuonAngleOutSide->Fill(t1); //Fill the good muon angle histogram for the muons that went out the side of the MRD
                           goto jmp;
                        }


                        if (fString == "16" && layerScint == 26 && Emuonf2>=0 && muonXevo6>=0.2 && muonXevo6<=2.8 && muonYevo6>=0.2 && muonYevo6<=2.8) {
                           NumberNotStopped++;
                           hCCCohMuonGood->Fill(t1, m1*1000); //Fill the good muon information 2d histogram
                           if (NumberPionsPresent >= 1 && StdHepP4[PionCallNumber][2]>0) {
                              hCCCohPionGood->Fill(t2, m2*1000);
                           }


                           hGoodMuonMomentumNonStopped->Fill(m1*1000); //Fill the nonstopped histogram with good nonstopped muon events for muon momentum
                           hGoodMuonAngleNonStopped->Fill(t1); //Fill the nonstopped histogram with good nonstopped muon events for muon angle
                           hPionMomentumNonStopped->Fill(m2*1000);
                           hPionAngleNonStopped->Fill(t2);
                           hPionEnergyNonStopped->Fill(StdHepP4[PionCallNumber][3]*1000);
                           hFourMomentumNonStopped->Fill(t);
                           hQSquaredNonStopped->Fill(q);
                           h1->Fill(Xpos*100);
                           h2->Fill(Ypos*100);
                           h3->Fill(Zpos*100);
                           if (Zpos >= 1.4) {
                              h4->Fill(Xpos,Ypos);
                           }


                        }


                     }
                     

                     if (fString == "16" && Emuonf1<=0 && layerScint>=4) {
                        NumberGoodEvents++;
                        hGoodMuonMomentumTotal->Fill(m1*1000); //Fill the total good muon momentum histogram
                        hGoodMuonAngleTotal->Fill(t1); //Fill the total good muon angle histogram
                        hPionMomentumGood->Fill(m2*1000);
                        hPionAngleGood->Fill(t2);
                        hPionEnergyGood->Fill(StdHepP4[PionCallNumber][3]*1000);
                        hFourMomentumBoth->Fill(t);
                        hQSquaredBoth->Fill(q);
                        hTx->Fill(tx);
                        hTy->Fill(ty);
                        hTz->Fill(tz);
                        hTE->Fill(tE);
                        if (zw==0 && t>=0.2) {
                           std::cout<<"Neutrino Info: "<<" Px = "<<v4.X()<<", Py = "<<v4.Y()<<", Pz = "<<v4.Z()<<", E = "<<StdHepP4[NeutrinoCallNumber][3]<<std::endl;
                           std::cout<<"Muon Info: "<<" Px = "<<v1.X()<<", Py = "<<v1.Y()<<", Pz = "<<v1.Z()<<", E = "<<StdHepP4[MuonCallNumber][3]<<std::endl;
                           std::cout<<"Pion Info: "<<" Px = "<<v2.X()<<", Py = "<<v2.Y()<<", Pz = "<<v2.Z()<<", E = "<<StdHepP4[PionCallNumber][3]<<std::endl;
                           std::cout<<"|t| =  "<<t<<std::endl;
                           std::cout<<"Event Number = "<<jentry<<std::endl;
                           zw = 1;
                        }


                     }


                     jmp:

                     if (fString == "16" && layerScint>=4 && Emuonf1<=0 && layerScint<=26 && layerSteel<26 && muonXevo5<=2.8 && muonXevo5>=0.2 && muonYevo5<=2.8 && muonYevo5>=0.2) {
                        NumberStopped++;
                        if (layerSteel>=13) {
                           layerSteel = 13; //This sets the steel layer to 12 if the muon did not stop in the first 12 layers
                        }

                        hCCCohMuonGood->Fill(t1, m1*1000); //Fill the good muon information 2d histogram
                        if (NumberPionsPresent >= 1 && StdHepP4[PionCallNumber][2]>0) {
                           hCCCohPionGood->Fill(t2, m2*1000);
                        }


                        hSteelLayer->Fill(layerSteel); //Fill the steel layer histogram with what steel layer the muon stopped within
                        NumberMuonsPresent = 0;
                        NumberPionsPresent = 0;
                        NumberFinalStateParticles = 0;
                        hGoodMuonMomentumStopped->Fill(m1*1000); //Fill the good muon momentum histogram for the stopped events
                        hGoodMuonAngleStopped->Fill(t1); //Fill the good muon angle histogram for the stopped events
                        hPionMomentumStopped->Fill(m2*1000);
                        hPionAngleStopped->Fill(t2);
                        hPionEnergyStopped->Fill(StdHepP4[PionCallNumber][3]*1000);
                        hFourMomentumStopped->Fill(t);
                        hQSquaredStopped->Fill(q);
                        h1->Fill(Xpos*100);
                        h2->Fill(Ypos*100);
                        h3->Fill(Zpos*100);
                        if (Zpos >= 1.4) {
                           h4->Fill(Xpos,Ypos);
                        }


                     }


                  }


               }


            }


         }


      }
      

      NumberMuonsPresent = 0; //Resets a check
      NumberPionsPresent = 0; //Resets a check
      PionCallNumber = 0; //Resets a check
      MuonCallNumber = 0; //Resets a check
      NeutrinoCallNumber = -99; //Resets a check
      NumberFinalStateParticles = 0; //Resets a check
   }


   NumberEvents = nentries; //Counts the total number of events that occured in this simulation
   std::cout<<"Total Number of Simulated Events = "<<NumberEvents<<std::endl; //Prints out the number of simulated events
   std::cout<<"Number of CC Coh Pion Events = "<<NumberCCCohEvents<<std::endl; //Prints out the number of CC Coh Pion Production Events
   std::cout<<"Number with a muon that made it to the front of the MRD = "<<NumberMadeFrontMRD<<std::endl; //Prints out the number of CC Coh Pion Production Events where the muon made it to the front of the MRD
   std::cout<<"Number of Good CC Coh Pion Events = "<<NumberGoodEvents<<std::endl; //Prints out the number of good CC Coh Pion Production Events both stopped and nonstopped
   std::cout<<"Number of Good CC Coh Pion Events that stopped within the MRD = "<<NumberStopped<<std::endl;
   std::cout<<"Number of Good CC Coh Pion Events that did not stop within and did not go out the side of the MRD = "<<NumberNotStopped<<std::endl;
   std::cout<<"Number of Good CC Coh Pion Events where the muon went through the side of the MRD = "<<NumberOutSide<<std::endl;

   std::cout<<"Number of CC Pion Events = "<<CCNumberEvents<<std::endl; //Prints out the number of CC Coh Pion Production Events
   std::cout<<"Number with a muon that made it to the front of the MRD = "<<CCNumberMadeFrontMRD<<std::endl; //Prints out the number of CC Coh Pion Production Events where the muon made it to the front of the MRD
   std::cout<<"Number of Good CC Pion Events = "<<CCNumberGoodEvents<<std::endl; //Prints out the number of good CC Coh Pion Production Events both stopped and nonstopped
   std::cout<<"Number of Good CC Pion Events that stopped within the MRD = "<<CCNumberStopped<<std::endl;
   std::cout<<"Number of Good CC Pion Events that did not stop within and did not go out the side of the MRD = "<<CCNumberNotStopped<<std::endl;
   std::cout<<"Number of Good CC Pion Events where the muon went through the side of the MRD = "<<CCNumberOutSide<<std::endl;


   //########################################
   //### Preparing the histogram canvases ###
   //########################################

   TCanvas *c1 = new TCanvas("c1", "Total CC Inclusive Muon Information");
   c1->SetTicks();
   c1->SetFillColor(kWhite);
   hCCIncMuonTotal->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   hCCIncMuonTotal->GetXaxis()->CenterTitle();
   hCCIncMuonTotal->GetYaxis()->SetTitle("Muon Momentum (MeV)");
   hCCIncMuonTotal->GetYaxis()->CenterTitle();
   hCCIncMuonTotal->Draw("colz");

   TCanvas *c2 = new TCanvas("c2", "Good CC Inclusive Muon Information");
   c2->SetTicks();
   c2->SetFillColor(kWhite);
   hCCIncMuonGood->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   hCCIncMuonGood->GetXaxis()->CenterTitle();
   hCCIncMuonGood->GetYaxis()->SetTitle("Muon Momentum (MeV)");
   hCCIncMuonGood->GetYaxis()->CenterTitle();
   hCCIncMuonGood->Draw("colz");

   TCanvas *c3 = new TCanvas("c3", "Total CC Inclusive Pion Information");
   c3->SetTicks();
   c3->SetFillColor(kWhite);
   hCCIncPionTotal->GetXaxis()->SetTitle("Pion Angle (Degrees)");
   hCCIncPionTotal->GetXaxis()->CenterTitle();
   hCCIncPionTotal->GetYaxis()->SetTitle("Pion Momentum (MeV)");
   hCCIncPionTotal->GetYaxis()->CenterTitle();
   hCCIncPionTotal->Draw("colz");
 
   TCanvas *c4 = new TCanvas("c4", "Good CC Inclusive Pion Information");
   c4->SetTicks();
   c4->SetFillColor(kWhite);
   hCCIncPionGood->GetXaxis()->SetTitle("Pion Angle (Degrees)");
   hCCIncPionGood->GetXaxis()->CenterTitle();
   hCCIncPionGood->GetYaxis()->SetTitle("Pion Momentum (MeV)");
   hCCIncPionGood->GetYaxis()->CenterTitle();
   hCCIncPionGood->Draw("colz");

   TCanvas *c5 = new TCanvas("c5", "Total CC Coh Muon Information");
   c5->SetTicks();
   c5->SetFillColor(kWhite);
   hCCCohMuonTotal->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   hCCCohMuonTotal->GetXaxis()->CenterTitle();
   hCCCohMuonTotal->GetYaxis()->SetTitle("Muon Momentum (MeV)");
   hCCCohMuonTotal->GetYaxis()->CenterTitle();
   hCCCohMuonTotal->Draw("colz");

   TCanvas *c6 = new TCanvas("c6", "Good CC Coh Muon Information");
   c6->SetTicks();
   c6->SetFillColor(kWhite);
   hCCCohMuonGood->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   hCCCohMuonGood->GetXaxis()->CenterTitle();
   hCCCohMuonGood->GetYaxis()->SetTitle("Muon Momentum (MeV)");
   hCCCohMuonGood->GetYaxis()->CenterTitle();
   hCCCohMuonGood->Draw("colz");

   TCanvas *c7 = new TCanvas("c7", "Total CC Coh Pion Information");
   c7->SetTicks();
   c7->SetFillColor(kWhite);
   hCCCohPionTotal->GetXaxis()->SetTitle("Pion Angle (Degrees)");
   hCCCohPionTotal->GetXaxis()->CenterTitle();
   hCCCohPionTotal->GetYaxis()->SetTitle("Pion Momentum (MeV)");
   hCCCohPionTotal->GetYaxis()->CenterTitle();
   hCCCohPionTotal->Draw("colz");
 
   TCanvas *c8 = new TCanvas("c8", "Good CC Coh Pion Information");
   c8->SetTicks();
   c8->SetFillColor(kWhite);
   hCCCohPionGood->GetXaxis()->SetTitle("Pion Angle (Degrees)");
   hCCCohPionGood->GetXaxis()->CenterTitle();
   hCCCohPionGood->GetYaxis()->SetTitle("Pion Momentum (MeV)");
   hCCCohPionGood->GetYaxis()->CenterTitle();
   hCCCohPionGood->Draw("colz");

   TCanvas *c9 = new TCanvas("c9", "Steel Layer Imbedding");
   c9->SetTicks();
   c9->SetFillColor(kWhite);
   hSteelLayer->GetXaxis()->SetTitle("Layer Stopped In (Layer)");
   hSteelLayer->GetXaxis()->CenterTitle();
   hSteelLayer->GetYaxis()->SetTitle("Number Stopped (/13 Layers)");
   hSteelLayer->GetYaxis()->CenterTitle();
   hSteelLayer->SetLineColor(kBlue);
   hSteelLayer->Draw();

   TCanvas *c10 = new TCanvas("c10", "X Vertex Distribution");
   c10->SetTicks();
   c10->SetFillColor(kWhite);
   h1->GetXaxis()->SetTitle("Muon Initial X Position (cm)");
   h1->GetXaxis()->CenterTitle();
   h1->GetYaxis()->SetTitle("Events/Bin (0.133 events/cm)");
   h1->GetYaxis()->CenterTitle();
   h1->Draw();

   TCanvas *c11 = new TCanvas("c11", "Y Vertex Distribution");
   c11->SetTicks();
   c11->SetFillColor(kWhite);
   h2->GetXaxis()->SetTitle("Muon Initial Y Position (cm)");
   h2->GetXaxis()->CenterTitle();
   h2->GetYaxis()->SetTitle("Events/Bin (0.133 events/cm)");
   h2->GetYaxis()->CenterTitle();
   h2->Draw();

   TCanvas *c12 = new TCanvas("c12", "Z Vertex Distribution");
   c12->SetTicks();
   c12->SetFillColor(kWhite);
   h3->GetXaxis()->SetTitle("Muon Initial Z Position (cm)");
   h3->GetXaxis()->CenterTitle();
   h3->GetYaxis()->SetTitle("Events/Bin (0.235 events/cm)");
   h3->GetYaxis()->CenterTitle();
   h3->Draw();

   /*TCanvas *c13 = new TCanvas("c13", "X-Y Vertex Distribution for Z > 1.4m");
   c13->SetTicks();
   c13->SetFillColor(kWhite);
   h4->GetXaxis()->SetTitle("Initial X Position (meters)");
   h4->GetXaxis()->CenterTitle();
   h4->GetYaxis()->SetTitle("Initial Y Position (meters)");
   h4->GetYaxis()->CenterTitle();
   h4->Draw();*/


   //################################################
   //### Saving Histograms to ROOTFILES Directory ###
   //################################################

   TFile *TMuonInfo = new TFile("./ROOTFILES/totalmuoninfoOBS.root", "RECREATE");
   hCCCohMuonTotal->Write("T2D_1");
   hCCCohMuonGood->Write("G2D_1");
   hCCIncMuonTotal->Write("T2D_2");
   hCCIncMuonGood->Write("G2D_2");
   hTotalMuonMomentum->Write("TMuonMom_1");
   hGoodMuonMomentumTotal->Write("TGMuonMom_1");
   hGoodMuonMomentumStopped->Write("GMuonMomS_1");
   hGoodMuonMomentumNonStopped->Write("GMuonMomNS_1");
   hTotalMuonAngle->Write("TMuonCos_1");
   hGoodMuonAngleTotal->Write("TGMuonCos_1");
   hGoodMuonAngleStopped->Write("GMuonCosS_1");
   hGoodMuonAngleNonStopped->Write("GMuonCosNS_1");
   hCCTotalMuonMomentum->Write("CCTMuonMom_1");
   hCCTotalMuonAngle->Write("CCTMuonCos_1");
   hCCGoodMuonMomentumStopped->Write("CCGMuonMomS_1");
   hCCGoodMuonAngleStopped->Write("CCGMuonCosS_1");
   hCCGoodMuonMomentumNonStopped->Write("CCGMuonMomNS_1");
   hCCGoodMuonAngleNonStopped->Write("CCGMuonCosNS_1");
   hCCGoodMuonMomentumTotal->Write("CCTGMuonMom_1");
   hCCGoodMuonAngleTotal->Write("CCTGMuonCos_1");
   hCCCohPionTotal->Write("T2D_3");
   hCCCohPionGood->Write("G2D_3");
   hCCIncPionTotal->Write("T2D_4");
   hCCIncPionGood->Write("G2D_4");
   hPionEnergy->Write("TPionEnergy");
   hPionMomentum->Write("TPionMom");
   hPionAngle->Write("TPionAngle");
   hPionEnergyGood->Write("GPionEnergy");
   hPionMomentumGood->Write("GPionMom");
   hPionAngleGood->Write("GPionAngle");
   hPionEnergyStopped->Write("SPionEnergy");
   hPionMomentumStopped->Write("SPionMom");
   hPionAngleStopped->Write("SPionAngle");
   hPionEnergyNonStopped->Write("NSPionEnergy");
   hPionMomentumNonStopped->Write("NSPionMom");
   hPionAngleNonStopped->Write("NSPionAngle");
   hFourMomentumBoth->Write("T4B");
   hFourMomentumStopped->Write("T4S");
   hFourMomentumNonStopped->Write("T4NS");
   hQSquaredBoth->Write("Q2B");
   hQSquaredStopped->Write("Q2S");
   hQSquaredNonStopped->Write("Q2NS");
   h1->Write("Xpos");
   h2->Write("Ypos");
   h3->Write("Zpos");
   TMuonInfo->Write();
   TMuonInfo->Close();
}

//------------------------------------------------------------------------
